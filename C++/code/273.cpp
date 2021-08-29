class Solution {
public:
    vector<string> dict1{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> dict2{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string solve(int num) {
        string ans;
        if (num == 0) return ans;
        
        if (num / 100 > 0) ans += dict1[num / 100] + " Hundred";
        if (num % 100 == 0) return ans;
        if (num / 100 > 0) ans += " ";
        int tenth = num / 10 % 10;
        int oneth = num % 10;
        if (tenth < 2) ans += dict1[tenth * 10 + oneth];
        else {
            ans += dict2[tenth];
            if (oneth) ans+= " " + dict1[oneth];
        }
        return ans;
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        // 2,147,483,647
        string ans;
        string ret1 = solve(num / 1000000000);
        if (!ret1.empty()) ans += ret1 + " Billion ";
        string ret2 = solve(num / 1000000 % 1000);
        if (!ret2.empty()) ans += ret2 + " Million ";
        string ret3 = solve(num / 1000 % 1000);
        if (!ret3.empty()) ans += ret3 + " Thousand ";
        string ret4 = solve(num % 1000);
        if (!ret4.empty()) ans += ret4 + " ";
        ans.pop_back();
        return ans;
    }
};