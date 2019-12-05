class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> st;
        map<TreeNode*, bool> mp;
        st.push(root);
        long long rec = -10000000000;
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            if(!cur) continue;
            if(mp.find(cur) == mp.end()){
                mp[cur] = true;
                st.push(cur->right);
                st.push(cur);
                st.push(cur->left);
            }
            else{
                if(cur->val <= rec) return false;
                rec = cur->val;
            }
        }
        return true;
    }
};