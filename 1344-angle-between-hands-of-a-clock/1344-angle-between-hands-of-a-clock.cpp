class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minute = minutes * 6;
        double hou = (hour % 12) * 30 + minutes * 0.5;
        double dif = abs(hou - minute);
        return min(dif, 360 - dif);
    }
};