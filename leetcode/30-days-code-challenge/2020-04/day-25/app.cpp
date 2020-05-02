#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <string>
#include <chrono>

using namespace std;

#define all(x) (x).begin(), (x).end()
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int s = nums.size();
        if (s < 2)
            return true;

        int gapSize = 0;
        for (int i = s - 1; i >= 0; --i)
        {
            if (nums[i] == 0)
            {
                ++gapSize;
            }
            else if (gapSize > 0)
            {
                if (nums[i] > gapSize || i + nums[i] == s - 1)
                    gapSize = 0;
                else
                    ++gapSize;
            }
        }

        return gapSize == 0;
    }
};

int main()
{
    vector<int> empty = {};
    vector<tuple<vector<int>, bool>> cases = {
        {{2, 3, 1, 1, 4}, true},
        {{2, 0, 0}, true},
        {{3, 2, 1, 0, 4}, false},
        {{0}, true},
        {empty, true}
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<int> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().canJump(input);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
