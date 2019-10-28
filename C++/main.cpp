#include "solution.cpp"
using namespace std;

void print(vector<string> v){
    for(auto s: v) cout << s << ",";
    cout << endl;
}
int main() {
    vector<string> v1({"i love you","island","iroman","i love leetcode"});
    vector<int> v2({5,3,2,2});
    AutocompleteSystem *obj = new AutocompleteSystem(v1, v2);
    print(obj->input('i'));
    print(obj->input(' '));
    print(obj->input('a'));
    print(obj->input('#'));
    print(obj->input('i'));
    print(obj->input(' '));
    print(obj->input('a'));
    print(obj->input('#'));
    print(obj->input('i'));
    print(obj->input(' '));
    print(obj->input('a'));
    print(obj->input('#'));
    return 0;
}