class Solution {
public:
    int lengthLongestPath(string input) {
        unordered_map<int,int> mp;
        mp[-1] = 0;
        istringstream ss(input);
        string cur;
        int ans = 0;
        while (getline(ss, cur, '\n')) {
            int depth = cur.find_last_of('\t');
            string filename = depth == string::npos ? cur : cur.substr(depth);
            if (filename.find('.') == string::npos) { //dir
                mp[depth] = mp[depth - 1] + filename.length();
            } else {
                ans = max(ans, mp[depth - 1] + (int)filename.length());
            }
        }
        return ans;
    }
};