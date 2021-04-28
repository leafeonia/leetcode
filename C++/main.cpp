#include "solution.cpp"
using namespace std;


int main() {
    Solution solution;
    vector<int> v{1,5,9,1,5,9};
    cout << solution.containsNearbyAlmostDuplicate(v,2,3);

    return 0;
}