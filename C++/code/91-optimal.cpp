#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int pre = 1, cur = 1;
        for (int i = 1; i < s.length(); ++i) {
            if(s[i] == '0'){
                if (s[i-1] != '1' && s[i-1] != '2') return 0;
                cur = pre;
            }
            else{
                if (s[i-1] == '1' || (s[i-1] == '2'  && s[i] >= '1' && s[i] <= '6')){
                    cur = pre + cur;
                    pre = cur - pre;
                }
                else pre = cur;
            }
        }
        return cur;
    }
};//
// Created by maoym on 2019/10/5.
//

