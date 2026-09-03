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
    public void reorderList(ListNode head) {

        if (head == null || head.next == null)
            return;

        ListNode slow = head;
        ListNode fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        ListNode prev = null;
        ListNode curr = slow.next;

        slow.next = null;

        while (curr != null) {
            ListNode next = curr.next;

            curr.next = prev;
            prev = curr;
            curr = next;
        }
        ListNode temp1 = head;
        ListNode temp2 = prev;

        while (temp2 != null) {
            ListNode frontNext = temp1.next;
            ListNode rearNext = temp2.next;

            temp1.next = temp2;
            temp2.next = frontNext;

            temp1 = frontNext;
            temp2 = rearNext;
        }
    }
}