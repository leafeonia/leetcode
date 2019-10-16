#include "solution.cpp"
using namespace std;


int main(){
    Solution sol;
    cout << sol.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>");
    return 0;
}
