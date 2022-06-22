// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    unordered_map<string,bool> st;
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
            if(st.find(words[i])!=st.end()){
                if(st[words[i]]) cnt++;
                continue;
            }
            if(check(s,words[i],0,0)){
                cnt++;
                st[words[i]]=true;
            }
            else{
                st[words[i]]=false;
            }
        }
        return cnt;
    }
};