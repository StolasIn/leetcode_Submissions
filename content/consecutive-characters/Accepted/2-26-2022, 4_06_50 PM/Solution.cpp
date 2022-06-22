// https://leetcode.com/problems/consecutive-characters

class Solution {
public:
    int maxPower(string s) {
        int cnt = 0;
        int ma = -1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                cnt++;
            }
            else{
                ma = max(ma,cnt);
                cnt = 0;
            }
        }
        ma = max(ma,cnt);
        return ma+1;
    }
};