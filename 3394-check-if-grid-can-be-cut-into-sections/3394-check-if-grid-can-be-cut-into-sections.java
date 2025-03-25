class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        int sz = rectangles.length;
        int[][] xaxis = new int[sz][2];
        int[][] yaxis = new int[sz][2];
        int ind = 0;
        for (int[] rect : rectangles) {
            // System.out.println(ind);
            xaxis[ind][0] = rect[0];
            xaxis[ind][1] = rect[2];
            yaxis[ind][0] = rect[1];
            yaxis[ind][1] = rect[3];
            ind++;
        }
        Arrays.sort(xaxis, (a, b) -> Integer.compare(a[0], b[0]));
        Arrays.sort(yaxis, (a, b) -> Integer.compare(a[0], b[0]));
        
        int cntx = 0;
        int cnty = 0;
        int lastx = xaxis[0][1];
        int lasty = yaxis[0][1];
        for (int i = 0; i < sz; i++) {
            // System.out.println(lastx + " " + xaxis[i][0] + " " + xaxis[i][1]);
            if (xaxis[i][0] < lastx) {
                lastx = Math.max(lastx, xaxis[i][1]);
            } else {
                cntx++;
                lastx = xaxis[i][1];
            }
            if (yaxis[i][0] < lasty) {
                lasty = Math.max(lasty, yaxis[i][1]);
            } else {
                cnty++;
                lasty = yaxis[i][1];
            }
        }
        System.out.println(cntx + " " + cnty);
        return cntx > 1 || cnty > 1;
    }
}