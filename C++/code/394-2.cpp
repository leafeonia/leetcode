class Solution {
public:
    string solve(string& s, int& index) {
        string ret;
        
        // (abc) k[def] m[ghi] (jkl)

        while (index < s.length() && s[index] != ']') { // end of a level is marked by ] or end of s
            if (isalpha(s[index])) {
                ret += s[index++];
            } else {
                string num;
                while (isdigit(s[index])) {
                    num += s[index++];
                }
                int number = stoi(num);
                
                // skip '['
                index++;
                
                string s2 = solve(s, index);
                
                // skip ']'
                index++;
                
                while(number--) ret += s2;
            }
        }
        
        return ret;
    }
    string decodeString(string s) {
        int index = 0;
        return solve(s, index);
    }
};