/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode baby= head;
        if (head == null) return false;
        else if (head.next == head) return true;
        ListNode giant = head.next;
        while (baby != giant) {
            baby = baby.next;
            if (giant == null || giant.next == null) return false;
            giant = giant.next;
            if (giant.next == null) return false;
            giant = giant.next;
        }
        return true;
    }
}