#include <bits/stdc++.h>
using namespace std;
struct column{
    int height, index;
    column(int h,int i){height = h;index = i;}
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<column> s;
        int ans = 0;
        for(int i = 0;i < heights.size();i++){
            column newcol(heights[i], i);
            ans = max(ans, heights[i]);
            while(!s.empty() && heights[i] <= s.top().height){
                ans = max(ans, s.top().height * (i - s.top().index));
                s.pop();
            }
            s.push(newcol);
        }
        return ans;
    }
};