// https://leetcode.com/problems/longest-common-prefix

class Solution {
    public String longestCommonPrefix(String[] strs) {
        String s=strs[0];
        String str=new String("");
        for(int i=1;i<strs.length;i++){
            int m=Math.min(s.length(),strs[i].length());
            str="";
            for(int j=0;j<m;j++){
                if(s.charAt(j)==strs[i].charAt(j)){
                    str=str+s.charAt(j);
                }
                else{
                    break;
                }
            }
            s=str;
            if(s=="") return "";
        }
        return s;
    }
}