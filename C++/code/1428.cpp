/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimensions = binaryMatrix.dimensions();
        int m = dimensions[0];
        int n = dimensions[1];
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            bool found = false;
            for (int i = 0; i < m; i++) {
                if (binaryMatrix.get(i, mid) == 1) {
                    found = true;
                    break;
                }
            }
            if (found) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        bool found = false;
        for (int i = 0; i < m; i++) {
            if (binaryMatrix.get(i, n - 1) == 1) {
                found = true;
                break;
            }
        }
        if (!found) return -1;
        return left;
    }
};

// [   0    ]
// [   0    ]
// [   0    ]