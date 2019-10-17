#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string code){
        stack<string> tags;
        string status = "begin";
        string buf;
        if(code.empty() || code[0] != '<') return false;
        for (int i = 1; i < code.length(); ++i) {
            if(status == "begin"){
                if(code[i] == '>'){
                    if(buf.length() < 1 || buf.length() > 9) return false;
                    for(auto c: buf){
                        if(c < 'A' || c > 'Z') return false;
                    }
                    tags.push(buf);
                    buf = "";
                    status = "normal";
                }
                else buf += code[i];
            }
            else if(status == "normal"){
                if(tags.empty()) return false;
                if(code[i] == '<'){
                    buf = "";
                    status = "tag_start";
                }
            }

            else if(status == "tag_start"){
                if(code[i] == '/' && buf.empty()) status = "tag_end";
                else if(code[i] == '>'){
                    if(buf.length() < 1 || buf.length() > 9) return false;
                    for(auto c: buf){
                        if(c < 'A' || c > 'Z') return false;
                    }
                    tags.push(buf);
                    buf = "";
                    status = "normal";
                }
                else if(i < code.length() - 7 && code.substr(i,8) == "![CDATA["){
                    status = "CDATA";
                    i += 7;
                }
                else buf += code[i];
            }
            else if(status == "tag_end"){
                if(code[i] == '>'){
                    if(tags.empty()) return false;
                    string start = tags.top();
                    if(start != buf) return false;
                    tags.pop();
                    status = "normal";
                }
                else buf += code[i];
            }
            else if(status == "CDATA"){
                if(i < code.length() - 2 && code.substr(i,3) == "]]>"){
                    status = "normal";
                    i += 2;
                }
            }
        }
        if(status != "normal") return false;
        if(!tags.empty()) return false;
        return true;
    }
};