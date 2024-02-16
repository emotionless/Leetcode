import java.util.Map.Entry;
import java.util.*;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            hashMap.put(arr[i], hashMap.getOrDefault(arr[i], 0) + 1);
        }
        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(hashMap.entrySet());
        list.sort((o1, o2) -> o1.getValue().compareTo(o2.getValue()));
        int size = list.size();
        for (Map.Entry<Integer, Integer> entry : list) {
            k -= entry.getValue();
            if (k < 0) {
                return size;
            }
            size--;
        }
        
        return 0;
    }
}