#include "solution.cpp"
using namespace std;


int main(){
    //Solution sol;
    Excel* obj = new Excel(5, 'E');
    cout << obj->get(1,'A') << endl;
    obj->set(1,'A',2);
    cout << obj->get(1,'A') << endl;
    vector<string> v;
    v.push_back("A1");
    v.push_back("A1");
    cout << obj->sum(2,'B',v) << endl;
    v.clear();
    v.push_back("B2");
    v.push_back("A1:B2");
    cout << obj->sum(3,'C',v) << endl;
//    obj->set(2,'B',2);
//    cout << obj->get(3,'C') << endl;
    return 0;
}
