class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int length = encoded.size();
        int xor_except_first = 0;
        for(int i = 1;i < length;i += 2){
            xor_except_first ^= encoded[i];
        }
        int xor_all = (length / 2 + 1) % 2;  // length = 2 => 1^2^3 = 0, length = 4 => 1^2^3^4^5 = 1, length = 6 => 1^2^3^4^5^6^7 = 0
        vector<int> result;
        result.push_back(xor_all ^ xor_except_first);
        for(int i = 0;i < length;i++){
            result.push_back(result.back() ^ encoded[i]);
        }
        return result;
    }
};