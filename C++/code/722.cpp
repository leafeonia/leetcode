#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        int status = 0;
        bool ban = false;
        string newline;
        for(auto it = source.begin();it != source.end();it++){
            for(int i = 0;i < (*it).length();i++){
                if(status == 2){
                    if(i < (*it).length() - 1 && (*it).substr(i,2) == "*/"){
                        if(ban) ban = false;
                        else{
                            status = 0;
                            i += 2;
                        }
                    }
                }
                else if(status == 0 && i < (*it).length() - 1 && (*it).substr(i,2) == "//") status = 1;
                else if(status == 0 && i < (*it).length() - 1 && (*it).substr(i,2) == "/*") {
                    status = 2;
                    if(i < (*it).length() - 2 && (*it)[i+2] == '/') ban = true;
                }
                if(status == 0 && i < (*it).length()) newline += (*it)[i];
            }
            if(status != 2 && !newline.empty()) {
                ans.push_back(newline);
                newline = "";
            }
            if(status == 1) status = 0;
        }
        return ans;
    }
};