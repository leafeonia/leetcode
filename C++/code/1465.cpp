class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        hc.push_back(0);
        hc.push_back(h);
        vc.push_back(0);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int hmax = 0, vmax = 0;
        for (int i = 0;i < hc.size() - 1; i++) {
            hmax = max(hmax, hc[i + 1] - hc[i]);
        }
        for (int i = 0; i < vc.size() - 1; i++) {
            vmax = max(vmax, vc[i + 1] - vc[i]);
        }
        return (long long)hmax * (long long)vmax % 1000000007;
    }
};