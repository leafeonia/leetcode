#include "solution.cpp"
using namespace std;


int main() {
    Solution solution;
    vector<vector<char>> v{
            {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}

    };
    vector<string> v2{"oath", "pea", "eat", "rain"};
    solution.findWords(v, v2);

    return 0;
}