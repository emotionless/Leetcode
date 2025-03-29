import java.util.PriorityQueue;

class Pair {
    int first, second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {

    int getScore(int num) {
        int cnt = 0;
        for (int i = 2; i*i <= num; i++) {
            if (num%i == 0) {
                while (num%i == 0) {
                    num /= i;
                }
                cnt++;
            }
        }
        if (num > 1) cnt++;
        return cnt;
    }

    long powerGen(long a, long b, long c) {
        long result = 1;
        a = a % c; // Reduce a within modulo c
        
        while (b > 0) {
            // If b is odd, multiply a with result
            if ((b & 1) == 1) {
                result = (result * a) % c;
            }
            // Square a and reduce mod c
            a = (a * a) % c;
            b >>= 1; // Divide b by 2
        }
        return result;
    }


    public int maximumScore(List<Integer> nums, int k) {
        long MOD = 1000000007;
        int n = nums.size();
        int[] score = new int[n];
        long[] left = new long[n];
        long[] right = new long[n];
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Integer.compare(b.first, a.first));
        for (int i = 0; i < n; i++) {
            score[i] = getScore(nums.get(i));
            pq.add(new Pair(nums.get(i), i));
        }
        left[0] = 1;
        Stack<Pair> stack = new Stack<>();
        stack.push(new Pair(score[0], 0));
        for (int i = 1; i < n; i++) {
            while (stack.size() > 0 && stack.peek().first < score[i]) {
                stack.pop();
            }
            if (stack.size() == 0) {
                left[i] = i + 1;
            } else {
                left[i] = i - stack.peek().second;
            }
            stack.push(new Pair(score[i], i));
        }
        stack.clear();


        right[n-1] = 1;
        
        stack.push(new Pair(score[n-1], n-1));
        for (int i = n-2; i >= 0; i--) {
            while (stack.size() > 0 && stack.peek().first <= score[i]) {
                stack.pop();
            }
            if (stack.size() == 0) {
                right[i] = n - i ;
            } else {
                right[i] = stack.peek().second - i;
            }
            stack.push(new Pair(score[i], i));
        }
        stack.clear();
        
        long ans = 1;
        while (!pq.isEmpty() && k > 0) {
            Pair p = pq.poll();
            long value = p.first;
            int ind = p.second;
            long times = left[ind] * right[ind];
            long mn = Math.min(times, (long)k);
            k -= mn;
            // System.out.println(value + " " + mn + " " + left[ind] + " " + right[ind]);
            ans = (ans * powerGen(value, mn, MOD)) % MOD;
        }
        
        return (int)ans;
    }
}

/**

1 2 3 4 0 1 2 3 4 5 6
1234 321

111 11

 */