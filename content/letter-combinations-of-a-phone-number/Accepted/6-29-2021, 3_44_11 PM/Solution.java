// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
    String[] strs=new String[]{"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    List<String> ans=new ArrayList<>();
    public void re(String s,String res,int it){
        if(it==s.length()){
            ans.add(res);
            return;
        }
        for(int i=0;i<strs[s.charAt(it)-'0'].length();i++){
            res=res+strs[s.charAt(it)-'0'].charAt(i);
            re(s,res,it+1);
            res=res.substring(0,res.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        if(digits.length()==0) return ans;
        String s=new String("");
        re(digits,s,0);
        return ans;
    }
}