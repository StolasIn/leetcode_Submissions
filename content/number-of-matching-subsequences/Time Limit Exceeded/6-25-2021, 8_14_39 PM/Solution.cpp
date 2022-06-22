// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    bool check(string& s,string& s1,int i,int j){
        if(j==s1.size()){
            return true;
        }
        if(i>=s.size()) return false;
        if(s[i]==s1[j]){
            return check(s,s1,i+1,j+1);
        }
        else{
            return check(s,s1,i+1,j);
        }
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int m=words.size();
        int cnt=0;
        for(int i=0;i<m;i++){
            if(check(s,words[i],0,0)){
                cnt++;
            }
        }
        return cnt;
    }
};