// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        HashMap<Integer,ListNode> map=new HashMap<Integer,ListNode>();
        ListNode tmp=head;
        int cnt=1;
        while(tmp!=null){
            map.put(cnt,tmp);
            tmp=tmp.next;
            cnt++;
        }
        if(n!=0) map.get(cnt-n-1).next=map.get(cnt-n+1);
        else map.get(cnt-1).next=null;
        return head;
    }
}