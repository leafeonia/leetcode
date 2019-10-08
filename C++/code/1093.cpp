#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int mini = 256;
        int maxi = -1;
        int most_record = -1;
        int most = 0;
        long long avg = 0;
        long long cntsum = 0;
        long long cnt = 0;
        long long sum = 0;
        double mid = 0;
        for(auto c: count) cntsum += c;
        for (int i = 0; i < count.size(); ++i) {
            if(count[i] > 0) {
                maxi = i;
                mini = min(mini,i);
                if(count[i] > most_record) {
                    most = i;
                    most_record = count[i];
                }
                sum += i * count[i];
                if(cntsum % 2){
                    if(cnt < (cntsum + 1) / 2 && (cntsum + 1) / 2 <= cnt + count[i]){
                        mid = i;
                    }
                }
                else{
                    if(cnt + count[i] == cntsum / 2) mid = i;
                    else if(cnt == cntsum / 2) mid = (mid + i) / 2;
                    else if(cnt < cntsum / 2 && cnt + count[i] >= cntsum / 2 + 1) mid = i;
                }
                cnt += count[i];
            }
        }
        vector<double> ans({double(mini),double(maxi),double(sum)/cntsum,mid,double(most)});
        return ans;
    }
};//
// Created by maoym on 2019/10/8.
//

