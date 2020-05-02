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
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> sums;

        int s = nums.size();
        int sum = 0;
        int res = 0;

        for (auto n : nums)
        {
            sum += n;
            if (sum == k)
                ++res;

            if (sums.find(sum - k) != sums.end())
                res += (sums[sum - k]);

            ++sums[sum];
        }

        return res;
    }
};

int main()
{
    vector<tuple<tuple<vector<int>, int>, int>> cases = {
        {{{1}, 0}, 0},
        {{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0}, 55},
        {{{-1, -1, 1}, 0}, 1},
        {{{-1, -1, 1}, 1}, 1},
        {{{1, 1, -1, 1, 1}, 0}, 4},
        {{{1, 1, 1}, 2}, 2},
        {{{1, 1, 1, 1}, 2}, 3},
        {{{1, 1, 1, 2, 2}, 2}, 4},
        {{{1, 1, -1, 1, 1}, 2}, 4},
        {{{1, 1, -1, 1, 1, 0}, 2}, 6},
        {{{0, 1, 1, -1, 1, 1}, 2}, 6},
        {{{-791, 145, 97, -13, 577, -515, -953, -813, -451, 522, 669, 635, 709, 311, -15, -981, -837, 512, -349, 325, 561, -763, -718, 281, 895, 711, 507, -708, 999, -162, -230, -786, -178, 829, -761, 402, -865, -621, 157, 690, 537, 955, -769, -244, 369, -664, 331, 652, -432, 789, 50, 885, -838, -955, 602, 721, -239, -265, -459, 416, -618, 959, 740, -644}, 129}, 8},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        tuple<vector<int>, int> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().subarraySum(get<0>(input), get<1>(input));

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
