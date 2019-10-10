
//  Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }

}

class myInt{
    int val;
    myInt(){val = 0;}
    myInt(int i){val = i;}
}
class Solution {
    public int count(TreeNode cur, myInt min, myInt max){
        if(cur == null) return 0;
        if(cur.left == null && cur.right == null){
            min.val = cur.val;
            max.val = cur.val;
            return 1;
        }
        myInt lmin = new myInt();
        myInt lmax = new myInt();
        myInt rmin = new myInt();
        myInt rmax = new myInt();
        int left = count(cur.left, lmin, lmax);
        int right = count(cur.right, rmin, rmax);
        if(left == -1 || right == -1) return -1;
        if(cur.val <= lmax.val || cur.val >= rmin.val) return -1;

        return 0;
    }

    public int largestBSTSubtree(TreeNode root) {
        myInt min = new myInt();
        myInt max = new myInt();
        count(root,min,max);
        return 0;
    }
}