// https://leetcode.com/problems/palindrome-linked-list

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
    public boolean isPalindrome(ListNode head) {
        ArrayList<Integer> arr = new ArrayList<Integer>();
        ListNode tmp = head;
        while(tmp!=null){
            arr.add(tmp.val);
            tmp=tmp.next;
        }
        int m=arr.size()-1;
        for(int i=0;i<m/2;i++){
            if(arr.get(i)!=arr.get(m-i)){
                return false;
            }
        }
        return true;
    }
}