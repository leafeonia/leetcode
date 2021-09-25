class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int le = s.length();
        bool flag = false;
        for (int i = le - 2; i >= 0 && !flag; i--) {
            if (s[i] < s[i + 1]) {
                for (int j = le - 1; j > i; j--) {
                    if (s[i] < s[j]) {
                        swap(s[i], s[j]);
                        reverse(s.begin() + i + 1, s.end());
                        flag = true;
                        break;
                    }
                }
            }
        }
        if ((le == 10 && s > "2147483647") || stoi(s) == n) return -1;
        return stoi(s);
    }
    
    //2431->3124
};