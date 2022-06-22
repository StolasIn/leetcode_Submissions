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
        ListNode curr = headA;
        int hA=0;
        int hB=0;
        
        while(curr!=null){
            curr=curr.next;
            hA++;
        }
        
        curr = headB;
         while(curr!=null){
            curr=curr.next;
            hB++;
        }
        
        
        
        if(hA>hB){
            while(hA!=hB){
              headA=headA.next;
            hA--;  
            }
            
        }
        
        
        if(hB>hA){
            while(hB!=hA){
               headB=headB.next;
            hB--; 
            }
            
        }
        
        while(headA!=headB){
           headA=headA.next;
            headB=headB.next;
        }
        
        
        
        
        
        
        
      return headA;  
    }
}