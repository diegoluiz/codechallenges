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

class BinaryMatrix
{
public:
    vector<vector<int>> matrix;

    BinaryMatrix(vector<vector<int>> m)
    {
        matrix = m;
    }

    int get(int x, int y)
    {
        return matrix[x][y];
    }
    vector<int> dimensions()
    {
        vector<int> o{(int)matrix.size(), (int)matrix[0].size()};
        return o;
    }
};

class Solution
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dim = binaryMatrix.dimensions();
        int max = dim[1] - 1;
        bool found = false;

        for (int i = 0; i < dim[0]; i++)
        {
            int num = binaryMatrix.get(i, max);
            while (num == 1)
            {
                found = true;
                if (max <= 0)
                {
                    return 0;
                }

                max--;
                
                num = binaryMatrix.get(i, max);
            }
        }

        return found ? (max + 1) : -1;
    }
};

int main()
{
    vector<tuple<vector<vector<int>>, int>> cases = {
        {{{0, 0}, {1, 1}}, 0},
        {{{0, 0}, {0, 1}}, 1},
        {{{0, 0}, {0, 0}}, -1},
        {{{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}}, 1},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<vector<int>> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto bm = BinaryMatrix(input);
        auto res = Solution().leftMostColumnWithOne(bm);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
