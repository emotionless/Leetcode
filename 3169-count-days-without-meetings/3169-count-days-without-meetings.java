class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int n = meetings.length;
        for (int i = 0; i < n; i++) {
            int j = i;
            int last = meetings[i][1];
            while (j < n && meetings[j][0] <= last) {
                last = Math.max(last, meetings[j][1]);
                j++;
            }
            days -= (last - meetings[i][0] + 1);
            i = j - 1;
        }
        return days;
    }
}