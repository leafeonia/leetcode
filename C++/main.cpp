#include "solution.cpp"
using namespace std;


int main() {

    vector<int> pre({1,2,3,4,5,6,7,8});
    vector<int> in({3,2,4,1,6,7,5,8});
    Solution solution;
    solution.buildTree(pre, in);
    return 0;
}