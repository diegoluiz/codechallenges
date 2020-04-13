#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> sums = {{0, -1}};
        int sum = 0;
        int maxLength = 0;
        int ini;
        for (auto i = 0; i < nums.size(); i++)
        {
            int num = nums[i] == 0 ? -1 : 1;
            sum += num;

            if (sums.find(sum) == sums.end())
            {
                sums[sum] = i;
            }
            else
            {
                ini = sums[sum];
                maxLength = max(maxLength, i - ini);
            }
        }

        return maxLength;
    }
};

int main()
{
    vector<pair<vector<int>, int>> cases = {
        {{0, 1, 0}, 2},
        {{0, 1, 1}, 2},
        {{0, 1}, 2},
        {{0, 0, 1, 0, 0}, 2},
        {{0, 1, 0, 0, 1, 1, 0}, 6},
        {{0, 1, 0, 0, 0, 0, 0}, 2},
        {{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 16}};

    for (auto i = 0; i < cases.size(); i++)
    {
        auto input = cases[i].first;
        auto res = Solution().findMaxLength(cases[i].first);
        cout << "Case " << i << " (Expected " << cases[i].second << "): " << res << endl;
    }

    return 0;
}
