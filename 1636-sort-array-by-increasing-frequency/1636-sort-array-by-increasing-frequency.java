class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> list = new LinkedList<Map.Entry<Integer, Integer>> (count.entrySet());
        Collections.sort(list, (a, b) -> {
            if (a.getValue() == b.getValue()) {
                return b.getKey().compareTo(a.getKey());
            }
            return a.getValue().compareTo(b.getValue());
        });
        int[] res = new int[nums.length];
        int ind = 0;
        for (Map.Entry<Integer, Integer> entry : list) {
            int value = entry.getValue();
            while (value > 0) {
                res[ind++] = entry.getKey();
                value--;
            }
        }
        return res;
    }
}