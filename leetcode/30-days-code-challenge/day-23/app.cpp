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
    int rangeBitwiseAnd(int m, int n)
    {
        long output = m;

        for (uint i = output + 1; i <= n; i++)
        {
            output &= i;
            if (output == 0)
                return 0;
        }

        return output;
    }
};

int main()
{
    vector<int> empty = {};
    vector<tuple<vector<int>, int>> cases = {
        {{5, 7}, 4},
        {{0, 1}, 0},
        {{0, 0}, 0},
        {{1, 1}, 1},
        {{3, 3}, 3},
        {{8, 3}, 0},
        {{2147483646, 2147483647}, 2147483646},
        {{2147483647, 2147483647}, 2147483647},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<int> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().rangeBitwiseAnd(input[0], input[1]);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
