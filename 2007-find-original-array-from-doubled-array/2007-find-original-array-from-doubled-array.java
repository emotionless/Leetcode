class Solution {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        if (n%2 == 1) return new int[0];
        Arrays.sort(changed);
        Map<Integer, Integer> counter = new HashMap<>();
        int[] result = new int[n/2];
        int ind = n/2;
        for (int i = n - 1; i >= 0; i--) {
            if (!counter.containsKey(changed[i])) {
                counter.put(changed[i], 1);
            } else {
                counter.put(changed[i], counter.get(changed[i]) + 1);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (counter.get(changed[i]) == 0) {
                continue;
            }
            if (changed[i]%2 == 1 || !counter.containsKey(changed[i]/2) || counter.get(changed[i]/2) == 0) return new int[0];
            counter.put(changed[i], counter.get(changed[i]) - 1);
            counter.put(changed[i]/2, counter.get(changed[i]/2) - 1);
            result[--ind] = changed[i]/2;
        }
        return result;
    }
}