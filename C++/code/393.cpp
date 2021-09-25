class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int idx = 0;
        while (idx < n) {
            int num = data[idx] & 0xff;
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                if (num & (1 << (7 - i))) cnt++;
                else break;
            }
            if (cnt == 1 || (cnt == 4 && num & 8)) return false;
            idx++;
            if (cnt) {
                for (int i = 0; i < cnt - 1; i++) {
                    if (idx + i >= n) return false;
                    if ((data[idx + i] >> 6) ^ 2) return false;
                }
                idx += cnt - 1;
            }
        }
        return true;
    }
};