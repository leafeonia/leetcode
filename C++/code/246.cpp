class Solution {
public:
    bool isStrobogrammatic(string num) {
        int left = 0, right = num.length() - 1;
        while (left <= right) {
            switch (num[left] - '0') {
                case 0:
                case 1:
                case 8:
                    if (num[right] != num[left]) return false;
                    break;
                case 6:
                case 9:
                    if (num[left] -'0' + num[right] - '0' != 15) return false;
                    break;
                default:
                    return false;
            }
            left++;
            right--;
        }
        return true;
    }
};