// https://leetcode.com/problems/container-with-most-water

class Solution {
    public int maxArea(int[] h) {
        int l=0,r=h.length-1;
        int ma=0;
        while(r>l){
            ma=Math.max(ma,Math.min(h[r],h[l])*(r-l));
            if(h[r]<h[l]){
                r--;
            }
            else{
                l++;
            }
        }
        return ma;
    }
}