// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    bool iss1(string& s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i]>s[i+1]){
                return false;
            }
        }
        return true;
    }
    bool iss2(string& s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i]<s[i+1]){
                return false;
            }
        }
        return true;
    }
    int minDeletionSize(vector<string>& ss) {
        int cnt = 0;
        for(int i=0;i<ss.size();i++){
            if(iss1(ss[i])==false && iss2(ss[i])==false){
                cnt++;
            }
        }
        return cnt;
    }
};