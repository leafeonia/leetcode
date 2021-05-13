class Solution {
public:
    bool hasSameTree(TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A) return false;
        if (A->val != B->val) return false;
        return hasSameTree(A->left, B->left) && hasSameTree(A->right, B->right);
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A  || !B) return false;
        if (A->val == B->val && hasSameTree(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};