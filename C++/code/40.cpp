class Solution {
    vector<vector<int> > ans;
    vector<int> input;
public:
    void dfs(int index, int val, vector<int> &list){
        if(val == 0){
            ans.push_back(list);
            return;
        }
        if(val < 0 || index >= input.size()){
            return;
        }
        for(int i = index;i < input.size();i++){
            if(i > index && input[i] == input[i-1]){
                continue;
            }
            list.push_back(input[i]);
            dfs(i+1, val - input[i], list);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        input = candidates;
        sort(input.begin(), input.end());
        vector<int> v;
        dfs(0, target, v);
        return ans;
    }
};