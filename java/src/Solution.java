import static java.lang.Math.max;

class Solution {
    public static int lengthOfLongestSubstring(String s) {
        int ret = 0;
        int i = 0,j = 0;
        while(j < s.length()){
            String sub = s.substring(i,j);
            if(sub.contains(String.valueOf(s.charAt(j)))) i++;
            else j++;
            ret = max(ret,j - i);
        }
        ret = max(ret,j - i);
        return ret;


        /*inefficient version*/
//        int ret = 0;
//        String sub = "";
//        for (int i = 0;i < s.length();i++){
//            for (int j = i;j < s.length();j++){
//                String ch = String.valueOf(s.charAt(j));
//                if(sub.contains(ch)){
//                    ret = max(sub.length(),ret);
//                    sub = "";
//                    break;
//                }
//                else{
//                    sub += ch;
//                }
//            }
//
//        }
//        ret = max(sub.length(),ret);
//        return ret;
    }
}

