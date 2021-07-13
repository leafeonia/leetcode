#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    class Trie {
    public:
        /** Initialize your data structure here. */
        Trie(vector<vector<char>> board) {
            m = board.size();
            n = board[0].size();
            root = new TrieNode();
            bd = board;
        }

        class TrieNode {
        public:
            TrieNode() {
                next = vector<TrieNode*> (26, NULL);
                isEnd = false;
            }

            bool isEnd;
            vector<TrieNode*> next;
        };

        /** Inserts a word into the trie. */
        void insert(string word) {
            TrieNode* cur = root;
            while (word.length()) {
                int idx = word[0] - 'a';
                if (!cur->next[idx]) {
                    cur->next[idx] = new TrieNode();
                }
                cur = cur->next[idx];
                word = word.substr(1);
            }
            cur->isEnd = true;
        }

        void dfs(int x, int y, TrieNode* root, vector<string>& ret, string s) {
            int idx = bd[x][y] - 'a';
            if (!root->next[idx]) return;
            if (root->isEnd) ret.push_back(s);
            for (int i = 0;i < 4;i++) {
                int x2 = x + dire[i][0];
                int y2 = y + dire[i][1];
                if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) continue;
                dfs(x2, y2, root->next[idx], ret, s + bd[x][y]);
            }
        }

        vector<string> search(int x, int y) {
            vector<string> ret;
            dfs(x, y, root, ret, "");
            return ret;
        }

        vector<vector<char>> bd;
        int m, n;
        TrieNode* root;
        vector<vector<int>> dire = {{1,0},{-1,0},{0,1},{0,-1}};
    };

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tr = new Trie(board);
        for (auto& word: words) {
            tr->insert(word);
        }
        vector<string> ans;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                for (auto res: tr->search(i, j)) ans.push_back(res);
            }
        }
        return ans;
    }



};