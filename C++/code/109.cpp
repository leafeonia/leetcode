/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* cur;
    
    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* left = build(l, mid - 1);
        TreeNode* ret = new TreeNode(cur->val);
        cur = cur->next;
        TreeNode* right = build(mid + 1, r);
        ret->left = left;
        ret->right = right;
        return ret;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        cur = head;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }
        cur = head;
        return build(0, length - 1);
    }
};