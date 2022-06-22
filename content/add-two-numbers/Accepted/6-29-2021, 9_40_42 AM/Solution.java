// https://leetcode.com/problems/add-two-numbers

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode t1=l1;
        ListNode t2=l2;
        ListNode ans=new ListNode();
        ListNode res=ans;
        int car=0;
        while(true){
            int sum=0;
            if(t1!=null){
                sum+=t1.val;
                t1=t1.next;
            }
            if(t2!=null){
                sum+=t2.val;
                t2=t2.next;
            }
            ans.val=(sum+car)%10;
            if(sum+car>9){
                car=1;
            }
            else{
                car=0;
            }
            if(t1==null && t2==null) break;
            ans.next = new ListNode();
            ans=ans.next;
        }
        if(car==1){
            ans.next = new ListNode();
            ans=ans.next;
            ans.val=1;
        }
        return res;
    }
}