// https://leetcode.com/problems/merge-k-sorted-lists

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
class node implements Comparable<node>{
    int siz;
    ListNode ptr;
    node(){}
    node(int size,ListNode l){
        this.siz=size;
        this.ptr=l;
    }
    @Override
    public int compareTo(node a){
        return this.siz-a.siz;
    }
}
class Solution {
    public int size(ListNode l){
        int ans=0;
        ListNode tmp=l;
        while(tmp!=null){
            ans++;
            tmp=tmp.next;
        }
        return ans;
    }
    public node merge(node c,node d){
        ListNode a=c.ptr;
        ListNode b=d.ptr;
        ListNode tmp=new ListNode();
        ListNode head=tmp;
        while(a!=null || b!=null){
            if(a==null){
                tmp.val=b.val;
                b=b.next;
                if(b!=null){
                    tmp.next=new ListNode();
                    if(b!=null) tmp=tmp.next;
                }
            }
            else if(b==null){
                tmp.val=a.val;
                a=a.next;
                if(a!=null){
                    tmp.next=new ListNode();
                    tmp=tmp.next;
                }
            }
            else{
                if(a.val>b.val){
                    tmp.val=b.val;
                    b=b.next;
                    tmp.next=new ListNode();
                    tmp=tmp.next;
                }
                else{
                    tmp.val=a.val;
                    a=a.next;
                    tmp.next=new ListNode();
                    tmp=tmp.next;
                }
            }
        }
        return new node(c.siz+d.siz,head);
    }
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<node> pq=new PriorityQueue<node>();
        for(int i=0;i<lists.length;i++){
            int s=size(lists[i]);
            if(s!=0) pq.add(new node(s,lists[i]));
        }
        while(pq.size()>1){
            node t1=pq.poll();
            node t2=pq.poll();
            pq.add(merge(t1,t2));
        }
        if(pq.size()==0 || pq.peek().siz==0) return null;
        return pq.peek().ptr;
    }
}