class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);
        Queue<Integer> waiting = new LinkedList<>();
        TreeSet<Integer> visited = new TreeSet<>();
        int ind = 0;
        int lastCap = 0;
        for (int bus : buses) {
            while (ind < passengers.length && passengers[ind] <= bus) {
                waiting.add(passengers[ind]);
                ind++;
            }
            int items = capacity;
            lastCap = items;
            while (items > 0 && waiting.size() > 0) {
                if (waiting.size() > 0) {
                    visited.add(waiting.poll());
                    lastCap--;
                }
                items--;
            }
        }
        int lastBus = buses[buses.length - 1];
        if (lastCap > 0 && !visited.contains(lastBus)) return lastBus;
        int last = visited.last() + 1;
        Iterator<Integer> iterator = visited.descendingIterator();
        while(iterator.hasNext()) {
            int cur = iterator.next();
            if ((cur + 1) != last) {
                return last - 1;
            }
            last = cur;
        }
        return last - 1;
    }
}