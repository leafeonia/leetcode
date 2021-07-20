class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        arr.push_back(0);
        arr.insert(arr.begin(), 0);
        int n = arr.size();
        stack<int> s1, s2;
        s1.push(0);
        s2.push(n - 1);
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1; i < n; i++) {
            while (!s1.empty() && arr[i] <= arr[s1.top()]) { // for contiguous same numbers, only count in one direction 
                right[s1.top()] = i;
                s1.pop();
            }
            s1.push(i);
        }
        for (int i = n - 2; i >= 0; i--) {
            while (!s2.empty() && arr[i] < arr[s2.top()]) {
                left[s2.top()] = i;
                s2.pop();
            }
            s2.push(i);
        }
        int ans = 0;
        for (int i = 1;i < n;i++) {
            ans = ((long long)ans + (arr[i] * (long long)(i - right[i]) * (left[i] - i)) % MOD) % MOD;
        }
        return ans;
    }
};

// [0 2 3 1 5 6 4 0] right[1] = 3 right[2] = 3 right[3] = 7 right[4] = 6 right[5] = 6 right[6] = 7
//                   left[1] = 0  left[1] = 2  left[3] = 0  left[4] = 3  left[5] = 4  left[6] = 3
//                   [2][2 3] 1*2 [3] 1*1      3*4             