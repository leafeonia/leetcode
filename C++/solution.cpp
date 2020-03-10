#include <bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root){
        if(!root) return 0;
        return sumNumbers_(root);
    }
    int sumNumbers_(TreeNode* root) {
        if(!root) return -1;
        int left = sumNumbers(root->left);
        int right = sumNumbers(root->right);
        int leftCount, rightCount;
        leftCount = rightCount = 0;
        int temp = left;
        while(temp){
            temp /= 10;
            leftCount++;
        }
        temp = right;
        while(temp){
            temp /= 10;
            rightCount++;
        }

        //case 0
        leftCount = max(leftCount, 1);
        rightCount = max(rightCount, 1);
        int ret = 0;
        if(left != -1) ret += (root->val) * pow(10,leftCount) + left;
        if(right != -1) ret += (root->val) * pow(10,rightCount) + right;
        if(left == -1 && right == -1) ret = root->val;
        return ret;
    }
};