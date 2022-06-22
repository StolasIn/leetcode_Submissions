// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.equals("")) return 0;
        int[] ch = new int[128];
        Arrays.fill(ch,0);
        int l=0,r=0;
        boolean flag=false;
        int m = s.length();
        int ans=1;
        while(r<m){
            if(flag==false){
                ans=Math.max(ans,r-l);
                if(ch[s.charAt(r)]==1){
                    flag=true;
                }
                ch[s.charAt(r)]++;
                r++;
            }
            else{
                if(ch[s.charAt(l)]==2){
                    flag=false;
                }
                ch[s.charAt(l)]--;
                l++;
            }
        }
        if(flag==false){
            ans=Math.max(ans,r-l);
        }
        return ans;
    }
}