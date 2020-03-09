#include "solution.cpp"
using namespace std;


int main() {

    vector<vector<int>> v({{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}});
    Solution solution;
    cout << solution.findNumberIn2DArray(v,20);
    return 0;
}