public class Main {

    public static void main(String[] args) {
        Solution solution = new Solution();
        int a[][] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        solution.rotate(a);
        for (int[] b: a){
            for (int c: b){
                System.out.print(c);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}

