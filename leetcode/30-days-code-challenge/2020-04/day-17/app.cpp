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
private:
    int xLength = 0;
    int yLength = 0;

public:
    bool isIsland(vector<vector<char>> &grid, int x, int y)
    {
        if (x < 0 || y < 0 || x > xLength - 1 || y > yLength - 1 || grid[y][x] == 2)
            return false;

        if (grid[y][x] == 0 || grid[y][x] == 48)
        {
            grid[y][x] = 2;
            return false;
        }

        grid[y][x] = 2;

        isIsland(grid, x + 1, y);
        isIsland(grid, x - 1, y);
        isIsland(grid, x, y + 1);
        isIsland(grid, x, y - 1);

        return true;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        yLength = grid.size();

        if (yLength == 0)
            return 0;

        xLength = grid[0].size();
        for (int y = 0; y < yLength; y++)
        {
            for (int x = 0; x < xLength; x++)
            {
                if (grid[y][x] == 2)
                    continue;

                if (isIsland(grid, x, y))
                    islands++;
            }
        }

        return islands;
    }
};

int main()
{
    vector<vector<char>> empty = {};
    vector<tuple<vector<vector<char>>, int>> cases = {
        {{{1, 1, 1, 1, 0},
          {1, 1, 0, 1, 0},
          {1, 1, 0, 0, 0},
          {0, 0, 0, 0, 0}},
         1},
        {{{1, 1, 0, 0, 0},
          {1, 1, 0, 0, 0},
          {0, 0, 1, 0, 0},
          {0, 0, 0, 1, 1}},
         3},
        {empty, 0}};

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<vector<char>> input;
        int output;

        tie(input, output) = cases[i];
        auto res = Solution().numIslands(input);
        cout << "Case " << i << " (Expected " << output << "): " << res << endl;
    }

    return 0;
}
