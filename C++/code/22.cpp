#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(vector<string> list){
        int cnt = 0;
        for(string s: list){
            if(s == "(") cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> origin;
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            origin.push_back("(");
        }
        for (int i = 0; i < n; ++i) {
            origin.push_back(")");
        }
        do{
            if(valid(origin)){
                string s = "";
                for(string st: origin) s += st;
                ans.push_back(s);
            }
        }while (next_permutation(origin.begin(), origin.end()));
        return ans;
    }
};

int main(){
    Solution solution;
    vector<string> ret = solution.generateParenthesis(3);
    for(string s: ret) cout << s << endl;
    return 0;
}

