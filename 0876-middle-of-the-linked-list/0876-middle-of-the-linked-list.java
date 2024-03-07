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
    public ListNode middleNode(ListNode head) {
        if (head.next == null) return head;
        ListNode baby = head;
        ListNode giant = head.next;
        while (giant != null) {
            if (giant.next == null || giant.next.next == null) break;
            giant = giant.next;
            giant = giant.next;
            baby = baby.next;
        }
        return baby.next;
    }
}