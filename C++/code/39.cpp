class Solution {
private:
    vector<vector<int>> ans;
    vector<int> mCandidates;
public:
    void dfs(int index, int valueLeft, vector<int>& list){
        if(valueLeft == 0){
            ans.push_back(list);
            return;
        }
        if(index >= mCandidates.size() || valueLeft < 0){
            return;
        }
        dfs(index + 1, valueLeft, list);
        for(int i = 1;i <= valueLeft / mCandidates[index];i++){
            list.push_back(mCandidates[index]);
            dfs(index + 1, valueLeft - i * mCandidates[index], list);
        }
        for(int i = 1;i <= valueLeft / mCandidates[index];i++){
            list.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty()){
            return ans;
        }
        mCandidates = candidates;
        vector<int> v;
        dfs(0, target, v);
        return ans;
    }
};