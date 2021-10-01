class Solution {
public:
    string lead(string num) {
        if(num.length() == 1) return "0" + num;
        return num;
    }
    string nextClosestTime(string time) {
        set<int> digits;
        set<int> nums;
        string hour = time.substr(0,2);
        string minute = time.substr(3,2);
        int smallest = 99;
        for (int i = 0; i < 5; i++) {
            if (i == 2) continue;
            digits.insert(time[i] - '0');
        }
        for (int digit: digits) {
            for (int digit2: digits) {
                smallest = min(smallest, digit * 10 + digit2);
                nums.insert(digit * 10 + digit2);
            }
        }
        string str = to_string(smallest);
        auto it = nums.upper_bound(stoi(minute));
        if (it != nums.end() && *it < 60) {
            return hour + ":" + lead(to_string(*it));
        }
        it = nums.upper_bound(stoi(hour));
        if (it != nums.end() && *it < 24) {
            return lead(to_string(*it)) + ":" + lead(str); // smallest minute
        }
        return lead(str) + ":" + lead(str);
    }
};