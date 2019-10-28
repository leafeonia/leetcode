#include <bits/stdc++.h>
using namespace std;

struct info{
    string sentence;
    int times;
    info(string s, int t){sentence = s; times = t;}
    bool operator < (const info& i2){
        return (times == i2.times ? sentence < i2.sentence : times > i2.times);
    }
};

class AutocompleteSystem {
public:
    vector<info> v;
    string cur;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for(int i = 0;i < times.size();i++){
            v.push_back(info(sentences[i], times[i]));
        }
        cur = "";
        sort(v.begin(), v.end());
    }

    vector<string> input(char c) {
        vector<string> ret;
        if(c == '#') {
            bool found = false;
            for(auto it = v.begin(); it != v.end(); it++){
                if((*it).sentence == cur) {
                    (*it).times++;
//                    sort(v.begin(), v.end());
                    while(it != v.begin() && (*(it - 1) > *it)) {
                        iter_swap(it,it-1);
                        it--;
                    }
                    found = true;
                    break;
                }
            }
            if(!found) {
                v.push_back(info(cur,1));
                sort(v.begin(), v.end());
            }

            cur = "";
            return ret;
        }
        int cnt = 0;
        cur += c;
        int le = cur.length();
        for(auto s: v){
            if(s.sentence.length() >= le && s.sentence.substr(0, le) == cur){
                ret.push_back(s.sentence);
                cnt++;
                if(cnt == 3) break;
            }
        }
        return ret;

    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */