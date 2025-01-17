class Solution {
    int solve(int[] derived, int next) {
        for (int i = 0; i < derived.length; i++) {
            next = next ^ derived[i];
        }
        return next;
    }
    public boolean doesValidArrayExist(int[] derived) {
        return solve(derived, 1) == 1 || solve(derived, 0) == 0;
    }
}

/*

a1 a2   a2 a3   a3 a4   a4 a1

0 1 0

1 0 1
1 1 0

0 1 0


1 0
 */