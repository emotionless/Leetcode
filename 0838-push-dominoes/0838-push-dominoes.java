class Solution {
    public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        int[] left = new int[n];
        int[] right = new int[n];
        int pre = -1;
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < n; i++) {
            char ch = dominoes.charAt(i);
            if (ch == 'L') {
                pre = -1;
            } else if (ch == 'R') {
                pre = i;
            }
            right[i] = pre;
        }
        pre = -1;
        for (int i = n-1; i >= 0; i--) {
            char ch = dominoes.charAt(i);
            if (ch == 'R') {
                pre = -1;
            } else if (ch == 'L') {
                pre = i;
            }
            left[i] = pre;
        }

        for (int i = 0; i < n; i++) {
            if (left[i] == -1 && right[i] == -1) {
                sb.append('.');
            } else if (left[i] == -1) {
                sb.append('R');
            } else if (right[i] == -1) {
                sb.append('L');
            } else {
                int dl = left[i] - i;
                int dr = i - right[i];
                if (dl == dr) {
                    sb.append('.');
                } else if (dl < dr) {
                    sb.append('L');
                } else {
                    sb.append('R');
                }
            }
        }

        return sb.toString();
        
    }
}