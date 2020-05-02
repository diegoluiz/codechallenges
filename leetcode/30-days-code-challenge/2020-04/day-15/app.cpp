#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        long mult = 1;
        int s = nums.size();
        vector<int> output(nums.size());

        for (int i = 0; i < s; i++)
        {
            output[i] = mult;
            mult *= nums[i];
        }

        mult = 1;
        for (int i = s - 1; i >= 0; i--)
        {
            output[i] *= mult;
            mult *= nums[i];
        }

        return output;
    }
};

int main()
{
    vector<tuple<vector<int>, vector<int>>> cases = {
        {{1, 2, 3, 4}, {24, 12, 8, 6}},
        {{0, 1, 2, 3, 4}, {24, 0, 0, 0}},
        {{0, 1, 2, 3, 0}, {0, 0, 0, 0}}};

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<int> input, output;

        tie(input, output) = cases[i];

        auto res = Solution().productExceptSelf(input);

        string outputText = "";
        string resText = "";
        for (auto o : output)
            outputText += to_string(o) + ", ";

        for (auto o : res)
            resText += to_string(o) + ", ";

        cout << "Case " << i << " (Expected " << outputText << "): " << resText << endl;
    }

    return 0;
}
