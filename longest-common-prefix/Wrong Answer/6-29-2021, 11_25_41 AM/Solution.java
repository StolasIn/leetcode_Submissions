// https://leetcode.com/problems/longest-common-prefix

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s=strs[0];
        String str=new String("");
        for(int i=1;i<strs.length;i++){
            for(int j=0;j<strs[i].length() && j<s.length();j++){
                if(strs[i].charAt(j)!=s.charAt(j)){
                    s=s.substring(0,j);
                    break;
                }
            }
            if(s=="") return "";
        }
        return s;
    }
}