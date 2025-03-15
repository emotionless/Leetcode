class Solution {
    public int minCapability(int[] nums, int k) {
        if (nums.length == 1) return nums[0];
        PriorityQueue<Node> pq = new PriorityQueue<>();
        for (int i = 0; i < nums.length; i++) {
            pq.add(new Node(nums[i], i));
        }
        boolean[] visited = new boolean[nums.length];
        int ans = 0;
        while (k > 0) {
            k--;
            while (pq.size() > 0) {
                Node top = pq.poll();
                if (isOkay(top.getIndex(), visited)) {
                    visited[top.getIndex()] = true;
                    ans = top.getValue();
                    break;
                }
            }
        }
        return ans;
    }

    boolean isOkay(int index, boolean[] visited) {
        if (index == 0) {
            return visited[index + 1] == false;
        } else if (index == (visited.length - 1)) {
            return visited[index - 1] == false;
        } else {
            return visited[index - 1] == false && visited[index + 1] == false;
        }
    }
}

class Node implements Comparable<Node> {
    int value;
    int index;

    public Node(int mvalue, int mindex) {
        value = mvalue;
        index = mindex;
    }

    int getValue() {
        return value;
    }

    int getIndex() {
        return index;
    }

    @Override
    public int compareTo(Node other) {
        // Sorting based on 'value' (Min-Heap behavior)
        return Integer.compare(this.value, other.value);
    }
}