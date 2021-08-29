class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (auto& itv: intervals) {
            if (!pq.empty() && itv[0] >= pq.top()) pq.pop();
            pq.push(itv[1]);
        }
        return pq.size();
    }
};

// [  ]
//   [  ]
//     [      ]
//   [         ]
//       [      ]
//         [  ]