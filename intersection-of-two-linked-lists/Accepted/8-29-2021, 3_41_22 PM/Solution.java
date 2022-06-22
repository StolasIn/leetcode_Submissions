// https://leetcode.com/problems/intersection-of-two-linked-lists

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode heada, ListNode headb) {
        HashSet<ListNode> s = new HashSet<ListNode>();
        ListNode a = heada;
        ListNode b = headb;
        while(a!=null){
            s.add(a);
            a=a.next;
        }
        while(b!=null){
            if(s.contains(b)){
                return b;
            }
            b=b.next;
        }
        return null;
    }
}