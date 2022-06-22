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
        vector<string> vs;
        for(int i=0;i<ss[0].size();i++){
            string s = "";
            for(int j=0;j<ss.size();j++){
                s+=ss[j][i];
            }
            vs.emplace_back(s);
        }
        for(int i=0;i<vs.size();i++){
            if(iss1(vs[i])==false){
                cnt++;
            }
        }
        return cnt;
    }
};