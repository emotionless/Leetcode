class Solution {
public:
    double angleClock(int hour, int minutes) {
        if (hour == 12) hour = 0;
        double angle = minutes * 6 - hour * 30 - (minutes/12.0) * 6.0;
        if (angle < 0.0) angle *= -1;
        return min(angle, 360 - angle);
    }
};