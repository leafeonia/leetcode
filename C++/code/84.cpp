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
        s.push(column(-1,-1));
        int ans = 0;
        for(int i = 0;i < heights.size();i++){
            column newcol(heights[i], i);
            ans = max(ans, heights[i]);
            while(heights[i] <= s.top().height){
                int h = s.top().height;
                int ind = s.top().index;
                s.pop();
                ans = max(ans, h * (i - s.top().index - 1));
            }
            s.push(newcol);
        }
        return ans;
    }
};