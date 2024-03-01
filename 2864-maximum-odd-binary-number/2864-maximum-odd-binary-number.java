class Solution {
    public String maximumOddBinaryNumber(String s) {
        char[] sArray = s.toCharArray();
        Arrays.sort(sArray);
        for (int i = 0; i < sArray.length; i++) {
            if (sArray[i] == '1') {
                char tmp = sArray[i];
                sArray[i] = sArray[0];
                sArray[0] = tmp;
                break;
            }
        }
        String str = new String(sArray);
        return new StringBuilder(str).reverse().toString();
    }
}