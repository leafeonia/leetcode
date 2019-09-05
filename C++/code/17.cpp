#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<string, string> mp = {
            {"2", "abc"},
            {"3", "def"},
            {"4", "ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"}
    };
    vector<string> extend(string digits){
        vector<string> v;
        if (digits.length() == 1){
            v.clear();
            for(char ch: mp[digits]){
                string s = string(1, ch);
                v.push_back(s);
            }
            return v;
        }
        v = extend(digits.substr(1));
        string digit = digits.substr(0,1);
        vector<string> ret;
        for(string s: v){
            for(char ch: mp[digit]){
                string tmp = s;
                ret.push_back(tmp.insert(0,string(1,ch)));
            }
        }
        return ret;

    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() < 1){
            vector<string> ret;
            ret.clear();
            return ret;
        }
        return extend(digits);
    }
};

int main(){
    Solution solution;
    vector<string> ret = solution.letterCombinations("23");
    for(string s: ret) cout << s << endl;
    return 0;
}
//
// Created by maoym on 2019/9/5.
//

