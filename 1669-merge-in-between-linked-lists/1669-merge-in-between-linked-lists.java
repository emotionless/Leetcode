/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


class Solution {
    
    ListNode lastNode(ListNode list) {
        if (list.next == null) return list;
        return lastNode(list.next);
    }

    ListNode getNodeForPosition(ListNode list, int pos) {
        while (pos > 0) {
            list = list.next;
            pos--;
        }
        return list;
    }
    
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode bLast = getNodeForPosition(list1, b + 1);
        ListNode last = lastNode(list2);
        if (a == 0) {
            last.next = bLast;
            return list2;
        }
        ListNode aLast = getNodeForPosition(list1, a - 1);
        aLast.next = list2;
        last.next = bLast;
        return list1;
    }
}