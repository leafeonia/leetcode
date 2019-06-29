class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < int(nums.size()) - 2; ++i) {   //nums.size是unsigned long型，若其值小于2，则数组越界
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size()-1;
            while(j <= k){
                if(nums[j]+nums[k]+nums[i] < 0) j++;
                else if(nums[i]+nums[j]+nums[k] > 0) k--;
                else{
                    ans.push_back(vector<int>({nums[i],nums[j],nums[k]}));
                    while(nums[j+1] == nums[j]) j++;
                    while(nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                }
            }
        }
        return ans;
    }


};