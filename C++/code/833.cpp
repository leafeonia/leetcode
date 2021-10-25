class Solution {
public:
    class Dict {
    public:
        Dict(int i, string s, string t): idx(i), s(s), t(t){}
        int idx;
        string s, t;
        bool operator < (const Dict& d) {return idx < d.idx;}
    };
    
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        
        int diff = 0, n = indices.size();
        vector<Dict> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Dict(indices[i], sources[i], targets[i]));
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int idx = v[i].idx + diff;
            if (s.substr(idx, v[i].s.length()) == v[i].s) {
                s.replace(s.begin() + idx, s.begin() + idx + v[i].s.length(), v[i].t);
                diff += v[i].t.length() - v[i].s.length();
            }
        }
        return s;
    }
};