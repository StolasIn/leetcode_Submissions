// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==1) return 1;
        int l=0,r=0;
        int cnt=0,ma=0;
        int[] check=new int[128];
        Arrays.fill(check,0);
        while(r<s.length()){
            if(cnt==0){
                ma=Math.max(ma,r-l);
                if(check[s.charAt(r)]>=1){
                    cnt=1;
                }
                check[s.charAt(r)]++;
                r++;
            }
            else{
                if(check[s.charAt(l)]==2){
                    cnt=0;
                }
                check[s.charAt(l)]--;
                l++;
            }
        }
        return ma;
    }
}