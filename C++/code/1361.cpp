class Solution {
public:
    int dfs(int root, vector<int>& leftChild, vector<int>& rightChild) {
        if (root == -1) return 0;
        return 1 + dfs(leftChild[root], leftChild, rightChild) + dfs(rightChild[root], leftChild, rightChild);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indeg(n, 0);
        for (int i = 0; i < n; i++) {
            int left = leftChild[i], right = rightChild[i];
            if (left != -1) {
                if (indeg[left]) return false;
                indeg[left]++;
            }
            if (right != -1) {
                if (indeg[right]) return false;
                indeg[right]++;
            }
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (!indeg[i]) {
                if (root == -1) root = i;
                else return false;
            }
        }
        return dfs(root, leftChild, rightChild) == n;
    }
    
    
};