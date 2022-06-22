// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isval(string str){
        int m=str.size();
        for(int i=0;i<(m+1)/2;i++){
            if(str[i]!=str[m-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str="";
        int m=s.size();
        for(int i=0;i<m;i++){
            if(isalpha(s[i])){
                str+=tolower(s[i]);
            }
        }
        cout<<str<<endl;
        return isval(str);
    }
};