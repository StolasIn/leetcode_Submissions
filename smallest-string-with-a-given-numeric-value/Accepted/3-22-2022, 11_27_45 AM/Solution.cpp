// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value

class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n--){
            if(26*n<k){
                ans+=(char)(k-26*n+'a'-1);
                for(int i=0;i<n;i++){
                    ans+='z';
                }
                break;
            }
            ans+='a';
            k--;
        }
        return ans;
    }
};