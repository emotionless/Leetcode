class Solution {
    
    public int toInteger(String num) {
        return Integer.parseInt(num, 2);
    }
    
    public String addZero(String num, int len) {
        while (num.length() < len) {
            num = "0" + num;
        }
        return num;
    }
    
    public String findDifferentBinaryString(String[] nums) {
        TreeSet<Integer> sortedList = new TreeSet<>();
        for (String num : nums) {
            sortedList.add(toInteger(num));
        }
        int index = 0;
        for (Integer num : sortedList) {
            if (num != index) {
                return addZero(Integer.toBinaryString(index), nums[0].length());
            }
            index++;
        }
        return addZero(Integer.toBinaryString(nums.length), nums[0].length());
    }
}