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
    int longestCommonSubsequence(string text1, string text2)
    {
        int text1Size = text1.size();
        int text2Size = text2.size();
        int L[text1Size + 1][text2Size + 1];

        for (int i = 0; i <= text1Size; i++)
        {
            for (int j = 0; j <= text2Size; j++)
            {
                if (i == 0 || j == 0)
                {
                    L[i][j] = 0;
                }
                else if (text1[i - 1] == text2[j - 1])
                {
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else
                {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }

        int index = L[text1Size][text2Size];
        string lcs(index, ' ');

        int i = text1Size, j = text2Size;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                lcs[index - 1] = text1[i - 1];
                i--;
                j--;
                index--;
            }
            else if (L[i - 1][j] > L[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }

        return lcs.size();
    }
};

int main()
{
    vector<int> empty = {};
    vector<tuple<vector<string>, int>> cases = {
        {{"abcde", "ace"}, 3},
        {{"abc", "abc"}, 3},
        {{"abc", "def"}, 0},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<string> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().longestCommonSubsequence(input[0], input[1]);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
