// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool isVowel(char c){
        c|=32;              //Converting char to lower case using bitwise OR
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); 
    }
    
    bool halvesAreAlike(string s) {
        int count=0;
        
        for(int i=0;i<s.length()/2;i++){
            count+=isVowel(s[i]);
        }
        
        for(int i=s.length()/2;i<s.length();i++){
            count-=isVowel(s[i]);
        }
        return (count==0);
    }
};