class Solution {
public:
    vector<unordered_map<string, int>> dfa{
        {{"digit", 1}, {"sign", 2}, {"dot", 3}},
        {{"digit", 1}, {"dot", 4}, {"e", 5}},
        {{"digit", 1}, {"dot", 3}},
        {{"digit", 4}},
        {{"digit", 4}, {"e", 5}},
        {{"sign", 6}, {"digit", 7}},
        {{"digit", 7}},
        {{"digit", 7}}
    };
    
    bool isNumber(string s) {
        int state = 0;
        string group;
        
        for (char ch: s) {
            if (isdigit(ch)) group = "digit";
            else if (ch == '+' || ch == '-') group = "sign";
            else if (ch == 'e' || ch == 'E') group = "e";
            else if (ch == '.') group = "dot";
            else return false;
            if (dfa[state].find(group) == dfa[state].end()) return false;
            state = dfa[state][group];
        }
        return state == 1 || state == 4 || state == 7;
    }
};

/*
 {0}(start): (0-9) {1};  (+-) {2};  (.) {3} ; 
 {1}: (0-9) {1};  (.) {4};  (Ee) {5};
 {2}: (0-9) {1};  (.) {3};
 {3}: (0-9) {4};
 {4}: (0-9) {4}; (Ee) {5};
 {5}: (+-) {6}; (0-9) {7};
 {6}: (0-9) {7};
 {7}: (0-9) {7};
 
 
0 --(0-9)--> 1
 |           ^
 |          (0-9)
 |           |
 L---(+-)--> 2
 |           |
 |          (.)
 |           v
 L---(.) --> 3


*/