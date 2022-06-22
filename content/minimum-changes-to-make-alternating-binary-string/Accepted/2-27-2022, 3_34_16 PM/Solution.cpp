// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

class Solution {
public:
    int minOperations(string s) {
       int cnt1=0,cnt2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(i%2==0){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
            else{
                if(i%2==0){
                    cnt2++;
                }
                else{
                    cnt1++;
                }
            }
        }
        return min(cnt1,cnt2);
    }
};