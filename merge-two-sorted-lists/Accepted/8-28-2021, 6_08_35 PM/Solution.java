// https://leetcode.com/problems/merge-two-sorted-lists

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null && l2==null) return l1;
        else if(l1==null) return l2;
        else if(l2==null) return l1;
        ListNode ans = new ListNode();
        ListNode tmp = ans;
        while(l1!=null || l2!=null){
            if(l1==null){
                ans.val=l2.val;
                l2=l2.next;
                if(l1!=null || l2!=null) ans.next=new ListNode(); 
            }
            else if(l2==null){
                ans.val=l1.val;
                l1=l1.next;
                if(l1!=null || l2!=null) ans.next=new ListNode(); 
            }
            else{
                if(l1.val<l2.val){
                    ans.val=l1.val;
                    l1=l1.next;
                }
                else{
                    ans.val=l2.val;
                    l2=l2.next;
                }
                if(l1!=null || l2!=null) ans.next=new ListNode();
            }
            ans=ans.next;
        }
        return tmp;
    }
}