#include "solution.cpp"
using namespace std;


int main() {
    vector<vector<int>> v{{2,4,3},{6,5,2}};
    Solution solution;
    cout << solution.hasValidPath(v);
    return 0;
}