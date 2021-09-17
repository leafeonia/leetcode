class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m1 = 360.0 * minutes / 60;
        double m2 = 360.0 * hour / 12 + 30.0 * minutes / 60;
        return abs(m1 - m2) > 180 ? 360 - abs(m1 - m2) : abs(m1 - m2);
    }
};