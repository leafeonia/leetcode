#include "solution.cpp"
using namespace std;


int main() {
    Solution solution;
    vector<vector<int>> v{
    {1,1},{1,2},{2,1},{2,2}

    };
    //vector<string> v2{"oath", "pea", "eat", "rain"};
    cout << solution.latestDayToCross(2, 2, v);

    return 0;
}