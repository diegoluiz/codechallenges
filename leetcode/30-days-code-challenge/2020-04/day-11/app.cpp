#include <iostream>
#include <stack>
#include <limits.h>

using namespace std;

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
    int deepest = 0;
    int deepCalc(TreeNode *root)
    {
        if (root == NULL) 
            return 0;
        

        int ldepth = deepCalc(root->left);
        int rdepth = deepCalc(root->right);

        deepest = max(deepest, ldepth + rdepth);
        
        return max(ldepth, rdepth) +1 ;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        deepCalc(root);
        return deepest;
    }
};
auto speedup = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main()
{
    auto tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right = new TreeNode(3);

    auto res = Solution().diameterOfBinaryTree(tree);
    cout << "Result: " << res << endl;

    return 0;
}
