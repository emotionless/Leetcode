class Solution {

    void dfs(int ind, char pre, StringBuilder sb, List<String> myList) {
        if (ind == 0) {
            myList.add(sb.toString());
            return;
        }
        if (myList.size() > 100) return;
        for (char ch = 'a'; ch < 'd'; ch++) {
            if (ch != pre) {
                sb.append(ch);
                dfs(ind - 1, ch, sb, myList);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        return;
    }

    public String getHappyString(int n, int k) {
        List<String> myList = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        dfs(n, '0', sb, myList);
        if (k > myList.size()) return "";
        return myList.get(k - 1);
    }
}