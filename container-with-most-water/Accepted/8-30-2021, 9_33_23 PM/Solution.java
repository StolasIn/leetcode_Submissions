// https://leetcode.com/problems/container-with-most-water

class Solution {
    public int maxArea(int[] h) {
        int l=0,r=h.length-1;
        int ma=-1;
        while(r>l){
            ma=Math.max(ma,Math.min(h[l],h[r])*(r-l));
            if(h[l]>h[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return ma;
    }
}