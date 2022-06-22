// https://leetcode.com/problems/valid-parentheses

class Solution {
    public boolean isValid(String s) {
        Stack st = new Stack();
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('|| s.charAt(i)=='[' || s.charAt(i)=='{'){
                st.push(s.charAt(i));
            }
            else{
                if(s.charAt(i)==')' && st.peek().equals('(')){
                    st.pop();
                }
                else if(s.charAt(i)==']' && st.peek().equals('[')){
                    st.pop();
                }
                else if(s.charAt(i)=='}' && st.peek().equals('{')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()!=0){
            return false;
        }
        else{
            return true;
        }
    }
}