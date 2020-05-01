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
    int size;
    bool isValidSequence(TreeNode *root, vector<int> &arr, int idx)
    {
        if (idx >= size)
            return false;

        int value = arr[idx];
        if (root->val != value)
            return false;

        bool r;
        if (root->left != nullptr)
        {
            r = isValidSequence(root->left, arr, idx + 1);
            if (r)
                return true;
        }

        if (root->right != nullptr)
        {
            r = isValidSequence(root->right, arr, idx + 1);
            if (r)
                return true;
        }

        return (root->left == nullptr) && (root->right == nullptr) && (idx == size - 1);
    }

    bool isValidSequence(TreeNode *root, vector<int> &arr)
    {
        size = arr.size();
        return isValidSequence(root, arr, 0);
    }
};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    auto *input = new TreeNode(0);

    input->left = new TreeNode(1);
    input->left->left = new TreeNode(0);
    input->left->left->right = new TreeNode(1);
    input->left->right = new TreeNode(1);
    input->left->right->left = new TreeNode(0);
    input->left->right->right = new TreeNode(0);

    input->right = new TreeNode(0);
    input->right->left = new TreeNode(0);

    vector<int> arr = {0, 1, 0, 1};

    auto res = Solution().isValidSequence(input, arr);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Case 1 (Expected true): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();

    input = new TreeNode(0);

    input->left = new TreeNode(1);
    input->left->left = new TreeNode(0);
    input->left->left->right = new TreeNode(1);
    input->left->right = new TreeNode(1);
    input->left->right->left = new TreeNode(0);
    input->left->right->right = new TreeNode(0);

    input->right = new TreeNode(0);
    input->right->left = new TreeNode(0);

    arr = {0, 0, 1};

    res = Solution().isValidSequence(input, arr);

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 2 (Expected false): " << res << ". Took: " << elapsed.count() << endl;

    start = std::chrono::high_resolution_clock::now();

    input = new TreeNode(0);

    input->left = new TreeNode(1);
    input->left->left = new TreeNode(0);
    input->left->left->right = new TreeNode(1);
    input->left->right = new TreeNode(1);
    input->left->right->left = new TreeNode(0);
    input->left->right->right = new TreeNode(0);

    input->right = new TreeNode(0);
    input->right->left = new TreeNode(0);

    arr = {0, 1, 1};

    res = Solution().isValidSequence(input, arr);

    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;

    cout << "Case 3 (Expected false): " << res << ". Took: " << elapsed.count() << endl;

    return 0;
}
