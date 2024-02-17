class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer> pqLadder = new PriorityQueue<>();
        for (int i = 0; i < heights.length - 1; i++) {
            if (heights[i] < heights[i + 1]) {
                // System.out.println(i + " " + heights[i]);
                pqLadder.add((heights[i + 1] - heights[i]));
                heights[i] = heights[i + 1];
            }
            if (pqLadder.size() > ladders) {
                bricks -= pqLadder.poll();
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.length - 1;
    }
}