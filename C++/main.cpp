#include "solution.cpp"
using namespace std;


int main() {
    Solution solution;
    vector<int> v{1,2,3};
    //vector<string> v2{"oath", "pea", "eat", "rain"};
    cout << solution.minSessions(v, 3);

    return 0;
}