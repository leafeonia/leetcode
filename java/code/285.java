/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode ans = null;
    int id;
    int status = 0;
    public void inorder(TreeNode cur){
        if(cur == null) return;
        if(cur.left != null) inorder(cur.left);
        if(status == 1){
            ans = cur;
            status = 2;
        }
        if(cur.val == id) status = 1;
        if(cur.right != null) inorder(cur.right);


    }
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        id = p.val;
        inorder(root);
        return ans;
    }
}