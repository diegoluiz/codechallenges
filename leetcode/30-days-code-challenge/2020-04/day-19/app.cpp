#include <iostream>
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
    int search(vector<int> &nums, int target)
    {
        int s = nums.size();
        if (s == 0)
            return -1;

        int ini = 0;
        int fin = s - 1;
        int mid = (fin - ini) / 2;

        while (true)
        {
            if (ini < s && target == nums[ini])
                return ini;

            if (fin >= 0 && target == nums[fin])
                return fin;

            if (mid >= 0 && mid < s && target == nums[mid])
                return mid;

            if (ini >= fin)
                return -1;

            if (nums[ini] < nums[mid])
            {
                if (target < nums[ini])
                {
                    ini = mid + 1;
                    fin = fin - 1;
                    mid = (fin + ini) / 2;
                }
                else if (target > nums[ini] && target < nums[mid])
                {
                    ini = ini + 1;
                    fin = mid - 1;
                    mid = (fin + ini) / 2;
                }
                else if (target > nums[mid])
                {
                    ini = mid + 1;
                    fin = fin - 1;
                    mid = (fin + ini) / 2;
                }
            }
            else
            {
                if (target > nums[fin])
                {
                    ini = ini + 1;
                    fin = mid - 1;
                    mid = (fin + ini) / 2;
                }
                else if (target < nums[fin] && target > nums[mid])
                {
                    ini = mid + 1;
                    fin = fin - 1;
                    mid = (fin + ini) / 2;
                }
                else if (target < nums[mid])
                {
                    ini = ini + 1;
                    fin = mid - 1;
                    mid = (fin + ini) / 2;
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<tuple<tuple<vector<int>, int>, int>> cases = {
        // {{{3, 1}, 2}, -1},
        // {{{5, 1, 2, 3, 4}, 1}, 1},
        // {{{4, 5, 6, 7, 0, 1, 2}, 0}, 4},
        // {{{4, 5, 6, 7, 0, 1, 2}, 3}, -1},
        // {{{3, 4, 5, 6, 7, 8, 0, 1, 2}, 8}, 5},
        // {{{3, 4, 5, 6, 7, 8, 0, 1, 2}, 0}, 6},
        // {{{3, 4, 5, 6, 7, 8, 0, 1, 2}, 6}, 3},
        // {{{6, 7, 8, 0, 1, 2, 3, 4, 5}, 0}, 3},
        // {{{6, 7, 8, 0, 1, 2, 3, 4, 5}, 7}, 1},
        // {{{6, 7, 8, 0, 1, 2, 3, 4, 5}, 3}, 6},
        // {{{6, 7, 8, 0, 1, 2, 3, 4, 5}, 4}, 7},
        {{{57, 58, 59, 62, 63, 66, 68, 72, 73, 74, 75, 76, 77, 78, 80, 81, 86, 95, 96, 97, 98, 100, 101, 102, 103, 110, 119, 120, 121, 123, 125, 126, 127, 132, 136, 144, 145, 148, 149, 151, 152, 160, 161, 163, 166, 168, 169, 170, 173, 174, 175, 178, 182, 188, 189, 192, 193, 196, 198, 199, 200, 201, 202, 212, 218, 219, 220, 224, 225, 229, 231, 232, 234, 237, 238, 242, 248, 249, 250, 252, 253, 254, 255, 257, 260, 266, 268, 270, 273, 276, 280, 281, 283, 288, 290, 291, 292, 294, 295, 298, 299, 4, 10, 13, 15, 16, 17, 18, 20, 22, 25, 26, 27, 30, 31, 34, 38, 39, 40, 47, 53, 54}, 30}, 113},
    };

    for (auto i = 0; i < cases.size(); i++)
    {
        tuple<vector<int>, int> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().search(get<0>(input), get<1>(input));

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected " << output << "): " << res << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
