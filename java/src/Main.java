

public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();
//        int a[][] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        TreeNode t1 = new TreeNode(3);
        TreeNode t2 = new TreeNode(2);
        TreeNode t3 = new TreeNode(4);
        TreeNode t4 = new TreeNode(1);
        TreeNode t5 = new TreeNode(8);
        TreeNode t6 = new TreeNode(7);
        t1.left = t2;
        t1.right = t3;
        t3.left = t4;
        t2.left = t2.right = t3.right = t4.left = t4.right = null;
//        t1.right = t3;
//        t2.left = t4;
//        t2.right = t5;
//        t3.right = t6;
//        t3.left = null;
//        t4.left = t4.right = t5.left = t5.right = t6.left = t6.right = null;
        System.out.println(solution.largestBSTSubtree(t1));
    }
}

