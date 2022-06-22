// https://leetcode.com/problems/longest-common-prefix

class Solution {
    public String max_match(String s,String c){
        String str=new String("");
        int m=Math.min(s.length(),c.length());
        for(int i=0;i<m;i++){
            if(s.charAt(i)==c.charAt(i)){
                str=str+s.charAt(i);
            }
            else{
                break;
            }
        }
        return str;
    }
    public String longestCommonPrefix(String[] strs) {
        String s=strs[0];
        for(int i=1;i<strs.length;i++){
            s=max_match(s,strs[i]);
            if(s=="") return "";
        }
        return s;
    }
}