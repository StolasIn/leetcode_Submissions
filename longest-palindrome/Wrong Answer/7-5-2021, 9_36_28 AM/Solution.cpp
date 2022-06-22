// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int check[128];
        int ans=0;
        bool flag=false;
        memset(check,0,sizeof(check));
        for(int i=0;i<s.size();i++){
            check[s[i]]++;
        }
        for(int i='a';i<='z';i++){
            if(check[i]==0) continue;
            if(check[i]%2==0){
                ans+=check[i];
            }
            else{
                if(flag==false){
                    ans+=check[i];
                    flag=true;
                }
                else{
                    ans+=check[i]-1;
                }
            }
        }
        return ans;
    }
};