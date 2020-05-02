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
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int len = s.length();
        string o = "";
        int totalShift = 0;
        for (auto s : shift)
            totalShift += ((s[0] == 0 ? -1 : 1) * s[1]);

        totalShift = (totalShift % len) * -1;

        totalShift = totalShift >= 0 ? totalShift : len + totalShift;

        for (int i = 0; i < len; i++)
        {
            o += s[(i + totalShift) % len];
        }
        return o;
    }
};

int main()
{
    vector<tuple<string, vector<vector<int>>, string>> cases = {
        {"abc", {{0, 1}, {1, 2}}, "cab"},
        {"abc", {{0, 3}, {1, 2}}, "bca"},
        {"abcdefg", {{1, 1}, {1, 1}, {0, 2}, {1, 3}}, "efgabcd"},
        {"yisxjwry", {{1, 8}, {1, 4}, {1, 3}, {1, 6}, {0, 6}, {1, 4}, {0, 2}, {0, 1}}, "yisxjwry"}};

    for (auto i = 0; i < cases.size(); i++)
    {
        string input, output;
        vector<vector<int>> shifts;

        tie(input, shifts, output) = cases[i];

        auto res = Solution().stringShift(input, shifts);
        cout << "Case " << i << " (Expected " << output << "): " << res << endl;
    }

    return 0;
}
