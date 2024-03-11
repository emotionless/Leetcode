class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            hashMap.put(order.charAt(i), i);
        }
        
        char[] toArray = s.toCharArray();
        Character[] charArray = new Character[toArray.length];
        for (int i = 0; i < toArray.length; i++) {
            charArray[i] = toArray[i];
        }
        Arrays.sort(charArray, new Comparator<Character>() {
            @Override
            public int compare(Character o1, Character o2) {
                return hashMap.getOrDefault(o1, 34) - hashMap.getOrDefault(o2, 34);
            }
        });
        
        StringBuilder builder = new StringBuilder();
        
        for (Character ch : charArray) {
            builder.append(ch);
        }
        
        return builder.toString();
    }
}