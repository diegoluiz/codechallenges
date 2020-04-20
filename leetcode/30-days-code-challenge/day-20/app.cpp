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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        auto root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode *node = root;
            int value = preorder[i];
            while (node != nullptr)
            {
                if (value < node->val)
                {
                    if (node->left != nullptr)
                    {
                        node = node->left;
                    }
                    else
                    {
                        node->left = new TreeNode(value);
                        node = nullptr;
                    }
                }
                else
                {
                    if (node->right != nullptr)
                    {
                        node = node->right;
                    }
                    else
                    {
                        node->right = new TreeNode(value);
                        node = nullptr;
                    }
                }
            }
        }

        return root;
    }
};

int main()
{
    vector<tuple<vector<int>, int>> cases = {
        {{8, 5, 1, 7, 10, 12}, 8}};

    for (auto i = 0; i < cases.size(); i++)
    {
        vector<int> input;
        int output;

        tie(input, output) = cases[i];
        auto start = std::chrono::high_resolution_clock::now();

        auto res = Solution().bstFromPreorder(input);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        cout << "Case " << i << " (Expected root" << output << "). Root:: " << res->val << ". Took: " << elapsed.count() << endl;
    }

    return 0;
}
