#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool valid(string s){
        return s[0] != '0' && 1 <= stoi(s) && stoi(s) <= 26;
    }
    bool sanity_check(string s){
        if (s.find("00") != string::npos || s.find("30") != string::npos || s.find("40") != string::npos ||
            s.find("50") != string::npos || s.find("60") != string::npos || s.find("70") != string::npos ||
            s.find("80") != string::npos || s.find("90") != string::npos ||s[0] == '0') return false;
        return true;
    }
    int numDecodings(string s) {
        if (!sanity_check(s)) return 0;
        int n = s.length();
        if (n == 1) return stoi(s) >= 1;
        long long* dp = new long long[n+1];
        dp[0] = dp[1] = 1;
        dp[2] = ((valid(s.substr(0,2)) && s[1] != '0') ? 2 : 1);
        for (int i = 3; i <= n; ++i) {
            if (!valid(s.substr(i-2,2))) dp[i] = dp[i-1];
            else{
                if (s[i-1] == '0'){
                    dp[i] = dp[i-1];
                    if(valid(s.substr(i-3,2))) dp[i] -= dp[i-3];
                }
                else{
                    dp[i] = 2 * dp[i-2];
                    if (valid(s.substr(i-3,2))) dp[i] += dp[i-3];
                }
            }
        }
        return dp[n];
    }
};
//
// Created by maoym on 2019/10/5.
//


//
// Created by maoym on 2019/10/5.
//

