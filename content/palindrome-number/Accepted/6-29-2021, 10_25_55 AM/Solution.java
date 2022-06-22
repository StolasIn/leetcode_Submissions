// https://leetcode.com/problems/palindrome-number

class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        String s=Integer.toString(x);
        int m=s.length()-1;
        for(int i=0;i<(m+1)/2;i++){
            if(s.charAt(i)!=s.charAt(m-i)){
                return false;
            }
        }
        return true;
    }
}