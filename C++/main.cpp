#include "solution.cpp"
using namespace std;


int main() {
    Solution solution;
    vector<vector<int>> v{{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    cout << solution.leastBricks(v);

    return 0;
}