class Solution {

    void removeOne(TreeMap<Integer, Integer> tm, int key) {
        int cnt = tm.get(key);
        if (cnt == 1) tm.remove(key);
        else tm.put(key, cnt - 1);
    }

    boolean isPossible(int ind, int[] tasks, int[] workers, int pills, int strength) {
        int j = workers.length - 1;
        TreeMap<Integer, Integer> tm = new TreeMap<>();

        for (int worker : workers) {
            tm.put(worker, tm.getOrDefault(worker, 0) + 1);
        }
        for (int i = ind; i >= 0; i--) {
            // System.out.println(i + " size " + tm.size());
            if (tm.size() == 0) return false;
            // System.out.println(tm.lastKey());
            if (tm.lastKey() >= tasks[i]) {
                removeOne(tm, tm.lastKey());
            } else {
                Integer key = tm.ceilingKey(tasks[i] - strength);
                System.out.println(key);
                if (key == null) return false;
                if (pills == 0) return false;
                pills--;
                removeOne(tm, key);
            }
            // System.out.println(tm);
        }
        return true;
    }

    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        int st = 0, ed = tasks.length - 1;
        Arrays.sort(tasks);
        int ans = -1;
        while (st <= ed ) {
            int mid = (st + ed) / 2;
            if (isPossible(mid, tasks, workers, pills, strength)) {
                ans = mid;
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
        return ans + 1;
    }
}

/**

[5,5,8,9,9]
[1,2,4,6,6]

 */