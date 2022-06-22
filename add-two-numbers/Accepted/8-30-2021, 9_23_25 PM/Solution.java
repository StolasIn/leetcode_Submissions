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
    int carry(int x){
        return x>=10? 1:0;
    }
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode();
        ListNode res = ans;
        int c=0;
        while(l1!=null || l2!=null){
            if(l1!=null && l2!=null){
                ans.next=new ListNode((l1.val+l2.val+c)%10);
                c=carry(l1.val+l2.val+c);
                l1=l1.next;
                l2=l2.next;
                ans=ans.next;
            }
            else if(l1!=null){
                ans.next=new ListNode((l1.val+c)%10);
                c=carry(l1.val+c);
                l1=l1.next;
                ans=ans.next;
            }
            else{
                ans.next=new ListNode((l2.val+c)%10);
                c=carry(l2.val+c);
                l2=l2.next;
                ans=ans.next;
            }
        }
        if(c!=0){
            ans.next=new ListNode(c);
        }
        return res.next;
    }
}