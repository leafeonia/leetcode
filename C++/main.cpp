#include "solution.cpp"
using namespace std;


int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    Solution solution;
    solution.sumNumbers(root);
    return 0;
}