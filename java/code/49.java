import java.util.*;

class Solution {
    public String sort(String s){
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList();
        HashMap<String, List<String>> mp = new HashMap<>();
        for (String s: strs){
            List<String> list = mp.get(sort(s));
            if(list == null){
                list = new ArrayList<>();
                list.add(s);
                mp.put(sort(s), list);
            }
            else{
                list.add(s);
            }
        }
        for (Map.Entry<String, List<String>> entry: mp.entrySet()){
            List<String> value = entry.getValue();
            ans.add(value);
        }
        return ans;
    }
}