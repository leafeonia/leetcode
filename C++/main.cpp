#include "solution.cpp"
using namespace std;

int main(){
    TicTacToe* obj = new TicTacToe(3);
    cout << obj->move(0,0,1) << endl;
    cout << obj->move(0,2,2) << endl;
    cout << obj->move(2,2,1) << endl;
    cout << obj->move(1,1,2) << endl;
    cout << obj->move(2,0,1) << endl;
    cout << obj->move(1,0,2) << endl;
    cout << obj->move(1,2,2) << endl;
    return 0;
}