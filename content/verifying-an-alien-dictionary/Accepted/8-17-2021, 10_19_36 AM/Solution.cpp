// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    int ord[128];
    bool cmp(string& a,string& b){
        int m=min(a.size(),b.size());
        for(int i=0;i<m;i++){
            if(ord[a[i]]<ord[b[i]]){
                return true;
            }
            else if(ord[a[i]]>ord[b[i]]){
                return false;
            }
        }
        if(a.size()>b.size()){
            return false;
        }
        return true;
    }
    bool isAlienSorted(vector<string>& words, string& order) {
        for(int i=0;i<order.size();i++){
            ord[order[i]]=i;
        }
        for(int i=1;i<words.size();i++){
            if(!cmp(words[i-1],words[i])){
                return false;
            }
        }
        return true;
    }
};