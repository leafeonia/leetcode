#include "solution.cpp"
using namespace std;


int main() {
    vector<vector<char>> v ({{'A','B','C','E'},{'S','F','C','S'}});
    Solution solution;
    cout << solution.exist(v, "ABFB");

    return 0;
}