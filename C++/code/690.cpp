/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int answer;
    map<int, Employee*> mp;
    void dfs(int id){
        if (mp.find(id) == mp.end()) return;
        answer += mp[id]->importance;
        for(auto sub: mp[id]->subordinates) dfs(sub);
    }
    int getImportance(vector<Employee*> employees, int id) {
        answer = 0;
        for(auto& employee: employees) {
            mp[employee->id] = employee;
        }
        dfs(id);
        return answer;
    }
};