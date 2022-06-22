// https://leetcode.com/problems/longest-common-prefix

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s=strs[0];
        String str=new String("");
        for(int i=1;i<strs.length;i++){
            while(strs[i].indexOf(s)!=0){
                s=s.substring(0,s.length()-1);
            }
            if(s=="") return "";
        }
        return s;
    }
}