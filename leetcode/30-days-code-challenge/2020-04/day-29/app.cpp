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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int m = INT_MIN;
    int maxPathSumRec(TreeNode *root)
    {
        int mL = INT_MIN;
        int mR = INT_MIN;
        if (root->left)
            mL = maxPathSumRec(root->left);

        if (root->right)
            mR = maxPathSumRec(root->right);

        int localM = root->val + max(mR, 0) + max(mL, 0);
        m = max(m, localM);

        return root->val + max(max(mL, mR), 0);
    }

    int maxPathSum(TreeNode *root)
    {
        int a = maxPathSumRec(root);
        return max(m, a);
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto *input = new TreeNode(1);
    input->left = new TreeNode(2);
    input->right = new TreeNode(3);
    auto res = Solution().maxPathSum(input);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Case 1 (Expected 6): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();

    input = new TreeNode(-10);
    input->left = new TreeNode(9);
    input->right = new TreeNode(20);
    input->right->left = new TreeNode(15);
    input->right->right = new TreeNode(7);
    res = Solution().maxPathSum(input);

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 2 (Expected 42): " << res << ". Took: " << elapsed.count() << endl;

    return 0;
}
