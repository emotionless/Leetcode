class NumberContainers {

    public NumberContainers() {
        currentNumber.clear();
        boxes.clear();
    }
    
    public void change(int index, int number) {
        currentNumber.put(index, number);
        SortedSet<Integer> box = boxes.getOrDefault(number, new TreeSet<Integer>());
        box.add(index);
        boxes.put(number, box);
    }
    
    public int find(int number) {
        SortedSet<Integer> box = boxes.getOrDefault(number, new TreeSet<Integer>());
        if (box.isEmpty()) return -1;  // Prefer isEmpty() over size() == 0 for readability
        Iterator<Integer> iterator = box.iterator();
        while (iterator.hasNext()) {
            Integer current = iterator.next();  // Save the next value
            if (currentNumber.get(current) != number) {
                iterator.remove();  // Safely remove the current element
            } else {
                return current.intValue();  // Return the matching value
            }
        }
        return -1;
    }

    private HashMap<Integer, Integer> currentNumber = new HashMap<>();
    private HashMap<Integer, SortedSet<Integer>> boxes = new HashMap<>();
}

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers obj = new NumberContainers();
 * obj.change(index,number);
 * int param_2 = obj.find(number);
 */