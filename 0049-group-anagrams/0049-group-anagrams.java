class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int len = strs.length;
        List<Pair<String, Integer>> pairList = new ArrayList<Pair<String, Integer>>();
        
        for (int i = 0; i < len; i++) {
            String str = strs[i];
            char[] ar = str.toCharArray();
            Arrays.sort(ar);
            String sorted = String.valueOf(ar);
            pairList.add(new Pair<String, Integer>(sorted, i));
        }
        
        Collections.sort(pairList, new Comparator<Pair<String, Integer>>() {
            @Override
            public int compare(Pair<String, Integer> o1, Pair<String, Integer> o2) {
                return o1.getKey().compareTo(o2.getKey());
            }
        });
        List<List<String>> anagrams = new ArrayList<List<String>>();
        for (int i = 0; i < len; i++) {
            List<String> tmp = new ArrayList<>();
            int j = i;
            for (j = i; j < len; j++)  {
                if (pairList.get(i).getKey().equals(pairList.get(j).getKey())) {
                    tmp.add(strs[pairList.get(j).getValue()]);
                } else {
                    break;
                }
            }
            i = j - 1;
            anagrams.add(tmp);
        }
        return anagrams;
    }
}