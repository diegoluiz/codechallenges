#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define all(x) (x).begin(), (x).end()
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        if (rows < 1)
            return 0;

        int cols = matrix[0].size();

        int i, j;
        int aux[rows][cols];

        for (i = 0; i < rows; i++)
            aux[i][0] = matrix[i][0] == '0' ? 0 : 1;

        for (j = 0; j < cols; j++)
            aux[0][j] = matrix[0][j]== '0' ? 0 : 1;

        for (i = 1; i < rows; i++)
        {
            for (j = 1; j < cols; j++)
            {
                if (matrix[i][j] == '1')
                    aux[i][j] = min(aux[i][j - 1], min(aux[i - 1][j], aux[i - 1][j - 1])) + 1;
                else
                    aux[i][j] = 0;
            }
        }

        int max_of_s = INT_MIN;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (max_of_s < aux[i][j])
                {
                    max_of_s = aux[i][j];
                }
            }
        }

        return max_of_s * max_of_s;
    }
};

int main()
{
    vector<vector<char>> empty = {};
    vector<tuple<vector<vector<char>>, int>> cases = {
        {{{'1', '0', '1', '0', '0'},
          {'1', '0', '1', '1', '1'},
          {'1', '1', '1', '1', '1'},
          {'1', '0', '0', '1', '0'}},
         4},
        {empty, 0}};

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<vector<char>> input;
        int output;

        tie(input, output) = cases[i];
        auto res = Solution().maximalSquare(input);
        cout << "Case " << i << " (Expected " << output << "): " << res << endl;
    }

    return 0;
}
