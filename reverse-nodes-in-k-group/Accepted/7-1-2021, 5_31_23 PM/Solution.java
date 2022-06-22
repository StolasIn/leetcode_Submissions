// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    public ListNode reverseKGroup(ListNode head, int k) {
        int[] arr=new int[k];
        ListNode l,r,now=head;
        while(true){
            l=r=now;
            boolean flag=false;
            for(int i=0;i<k;i++){
                if(r==null){
                    flag=true;
                    break;
                }
                arr[i]=r.val;
                r=r.next;
            }
            if(flag==true) break;
            for(int i=k-1;i>=0;i--){
                l.val=arr[i];
                l=l.next;
            }
            now=r;
        }
        return head;
    }
}