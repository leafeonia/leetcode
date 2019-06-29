#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int> ans){
        long long ret = 0;
        if(ans.size()>10){
            return (sign >= 0  ? 2147483647 : -2147483648);
        }
        for(int j = ans.size();j > 0 ;j--){
            long long weight = pow(10,j-1);
            ret += ans[ans.size()-j]*weight;
        }
        if(sign >= 0){
            if(ret > 2147483647) return 2147483647;
            return ret;
        }
        else{
            ret = -ret;
            if(ret < -2147483648) return -2147483648;
            return ret;
        }
    }
    int myAtoi(string str) {
        bool num = false;
        vector<int> ans;
        for(int i = 0;i < str.length();i++){
            if(num == false && sign == 0 && str[i] == ' ') continue;
            if(str[i] == '+'){
                if(sign != 0) return solve(ans);
                sign = 1;
                continue;
            }
            if(str[i] == '-'){
                if(sign != 0) return solve(ans);
                sign = -1;
                continue;
            }
            if(!num && str[i] >= '0' && str[i] <= '9') {
                num = true;
                if(sign == 0) sign = 1;
            }
            if(!num) return 0;
            if(str[i]>='0' && str[i]<='9') {
                if(!(ans.size() == 0 && str[i] == '0'))
                    ans.push_back(str[i]-'0');
            }
            else return solve(ans);
        }
        return solve(ans);
    }

private:
    int sign = 0;
};