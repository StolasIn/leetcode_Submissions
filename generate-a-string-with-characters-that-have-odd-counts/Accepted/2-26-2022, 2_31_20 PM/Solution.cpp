// https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts

class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n%2==0){
            ans+='a';
            for(int i=0;i<n-1;i++){
                ans+='b';
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans+='b';
            }
        }
        return ans;
    }
};