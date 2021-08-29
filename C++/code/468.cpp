class Solution {
public:
    string validIPAddress(string IP) {
        int cnt1 = 0, cnt2 = 0;
        for (char ch: IP) {
            if (ch == '.') cnt1++;
            if (ch == ':') cnt2++;
        }
        if (!(cnt1 == 3 && cnt2 == 0) && !(cnt1 == 0 && cnt2 == 7)) return "Neither";
        if (cnt1 == 3 && check4(IP)) return "IPv4";
        if (cnt2 == 7 && check6(IP)) return "IPv6";
        return "Neither";
    }
    
    bool check4(string IP) {
        while (IP.find('.') != string::npos) {
            int idx = IP.find('.');
            if (idx == 0 || idx > 3) return false;
            string sub = IP.substr(0, idx);
            IP = IP.substr(idx + 1);
            if (sub != "0" && sub[0] == '0') return false;
            for (char ch: sub) {
                if (!isdigit(ch)) return false;
            }
            int num = stoi(sub);
            if (num > 255) return false;
        }
        if (IP.length() == 0 || IP.length() > 3) return false;
        if (IP != "0" && IP[0] == '0') return false;
        for (char ch: IP) {
            if (!isdigit(ch)) return false;
        }
        int num = stoi(IP);
        if (num > 255) return false;
        return true;
    }
    
    bool check6(string IP) {
        while (IP.find(':') != string::npos) {
            int idx = IP.find(':');
            if (idx == 0 || idx > 4) return false;
            string sub = IP.substr(0, idx);
            IP = IP.substr(idx + 1);
            for (char ch: sub) {
                if (!(('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))) return false;
            }
        }
        if (IP.length() == 0 || IP.length() > 4) return false;
        for (char ch: IP) {
            if (!(('0' <= ch && ch <= '9') || ('a' <= ch && ch <= 'f') || ('A' <= ch && ch <= 'F'))) return false;
        }
        return true;
    }
};