#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

#define all(x) (x).begin(), (x).end()


class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        std::make_heap(all(stones));

        int a, b, c;
        while (stones.size() > 1)
        {
            a = stones.front();
            std::pop_heap(all(stones));
            stones.pop_back();

            b = stones.front();
            std::pop_heap(all(stones));
            stones.pop_back();

            c = abs(a - b);
            if (c > 0)
            {
                stones.push_back(c);
                std::push_heap(all(stones));
            }
        }

        return stones.size() > 0 ? stones.front() : 0;
    }
};

int main()
{
    vector<int> input = {2, 7, 4, 1, 8, 1};

    auto res = Solution().lastStoneWeight(input);
    cout << "Result: " << res << endl;

    return 0;
}
