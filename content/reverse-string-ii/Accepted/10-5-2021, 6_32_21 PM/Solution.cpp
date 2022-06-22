// https://leetcode.com/problems/reverse-string-ii

class Solution {
public:
    string reverseStr(string s, int k) {
        if(k>=s.size()){
            reverse(s.begin(),s.end());
            return s;
        }
        for(int i=0;i<s.size();i+=2*k){
            if(i+k>=s.size()){
                reverse(s.begin()+i,s.end());
                break;
            }
            reverse(s.begin()+i,s.begin()+i+k);
        }
        return s;
    }
};