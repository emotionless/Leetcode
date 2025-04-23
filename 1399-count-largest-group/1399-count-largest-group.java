class Solution {
    public int countLargestGroup(int n) {
        HashMap<Integer, Integer> count = new HashMap<>();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int sum = sod(i);
            int pre = count.getOrDefault(sum, 0);
            count.put(sum, pre + 1);
            ans = Math.max(ans, pre + 1);
        }
        int res = 0;
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            if (entry.getValue() == ans) {
                res++;
            }
        }
        return res;
    }

    int sod(int n) {
        int s = 0;
        while (n > 0) {
            s += n%10;
            n /= 10;
        }
        return s;
    }
}