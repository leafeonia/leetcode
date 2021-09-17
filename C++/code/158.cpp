/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int buffidx = 0;
    int cnt = 0;
    char buff[4];
    int read(char *buf, int n) {
        int idx = 0;
        while (idx < n) {
            if (buffidx == 0) {
                cnt = read4(buff);
            }
            if (cnt == 0) break;
            while (idx < n && buffidx < cnt) {
                buf[idx++] = buff[buffidx++];
            }
            if (buffidx == cnt) buffidx = 0;
        }
        return idx;
    }
};