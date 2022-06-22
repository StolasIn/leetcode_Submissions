// https://leetcode.com/problems/reverse-linked-list

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
    public ListNode reverseList(ListNode head) {
        ListNode x = null;
        ListNode y = head;
        ListNode z;
        while(y!=null){
            z=y.next;
            y.next=x;
            x=y;
            y=z;
        }
        return x;
    }
}