class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int n = digits.length;
        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k || digits[k]%2==1) continue;
                    set.add(digits[i]*100 + digits[j]*10 + digits[k]);
                }
            }
        }
        return set.stream().mapToInt(Integer::intValue).toArray();
    }
}