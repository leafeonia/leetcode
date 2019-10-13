#include "solution.cpp"
using namespace std;


int main(){
    Solution sol;
    vector<string> source({"e/*/eabeea/*///*c*////*dc*//bcadcde/*/acbe//*d/*/*//ae//*dc//*cc//*//*eaebb*//"});
    vector<string> ans = sol.removeComments(source);
    for(auto line: ans) cout << line << endl;
    return 0;
}
//e/*/eabeea/*///*c*////*dc*//bcadcde/*/acbe//*d/*/*//ae//*dc//*cc//*//*eaebb*//
//["/*/dadb/*/aec*////*//*ee*//*//b*////*badbda//*bbacdbbd*//ceb//*cdd//**//de*////*","ec//*//*eebd/*/*//*////*ea/*/bc*//cbdacbeadcac/*/cee*//bcdcdde*//adabeaccdd//*","ddadbede//*//*/*/ac/*/ea//*bbeb/*/ea//*a//*//*cdbeb*//ab/*/abde/*//*/d//**////*",,