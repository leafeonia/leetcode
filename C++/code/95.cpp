#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<vector<TreeNode*> > > dp;

    void solve(int start,int finish){
        if(start == finish) {
            dp[start][finish].push_back(new TreeNode(start+1));
            return;
        }

        
        for(int i = start;i <= finish;i++){
            vector<TreeNode*> temp;
            if(i == start) {
                TreeNode* root = new TreeNode(i+1);
                temp.push_back(root);
            }
            else{
                for(auto ele: dp[start][i-1]){
                    TreeNode* root = new TreeNode(i+1);
                    root->left = ele;
                    temp.push_back(root);
                }
            }
            if(i == finish){
                for(auto ele: temp){
                    TreeNode* root = new TreeNode(i+1);
                    root->left = ele->left;
                    dp[start][finish].push_back(root);
                }
            }
            else{
                for(auto ele: temp){
                    for(auto ele2: dp[i+1][finish]){
                        TreeNode* root = new TreeNode(i+1);
                        root->left = ele->left;
                        root->right = ele2;
                        dp[start][finish].push_back(root);
                    }
                }
            }
        }

    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            vector<TreeNode*> empty;
            return empty;
        }
        dp.resize(n);
        for(int i = 0;i < n;i++) dp[i].resize(n);
        for(int length = 0;length < n;length++){
            for(int i = 0;i + length < n;i++){
                solve(i, i+length);
            }
        }
        return dp[0][n-1];
    }


};