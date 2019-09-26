import java.util.*;

class Solution {
    public List<List<Integer>> ans = new LinkedList<>();
    public void solve(ArrayList<Integer> cur, ArrayList<Integer> left){
        if(cur.isEmpty()) {
            ans.add(left);
            return;
        }
        for (Integer i: cur){
            ArrayList<Integer> next_cur = new ArrayList<>(cur);
            next_cur.remove(i);
            ArrayList<Integer> next_left = new ArrayList<>(left);
            next_left.add(i);
            solve(next_cur, next_left);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        Arrays.sort(nums);
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i: nums){
            arrayList.add(i);
        }
        ArrayList<Integer> blank = new ArrayList<>();
        solve(arrayList, blank);
        return ans;
    }
}