// https://leetcode.com/problems/intersection-of-two-linked-lists

public class Solution {
    public ListNode getIntersectionNode(ListNode heada, ListNode headb) {
        int la=0,lb=0;
        ListNode tmp = heada;
        while(tmp!=null){
            la++;
            tmp=tmp.next;
        }
        tmp = headb;
        while(tmp!=null){
            lb++;
            tmp=tmp.next;
        }
        if(la>lb){
            while(la>lb){
                heada=heada.next;
                la--;
            }
        }
        else if(lb>la){
            while(lb>la){
                headb=headb.next;
                lb--;
            }
        }
        while(heada!=headb){
            heada=heada.next;
            headb=headb.next;
        }
        return heada;
    }
}