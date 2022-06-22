// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    bool cmp(string& a,string& b){
        if(a.size()!=b.size()) return false;
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        int m=a.size();
        for(int i=0;i<m;i++){
            if(map1.find(a[i])==map1.end() && map2.find(b[i])==map2.end()){
                map1[a[i]]=b[i];
                map2[b[i]]=a[i];
            }
            else{
                if(map1.find(a[i])!=map1.end() && map2.find(b[i])!=map2.end()){
                    if(map1[a[i]]!=b[i] || map2[b[i]]!=a[i]) return false;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& w, string& p) {
        int m=p.size();
        int n=w.size();
        vector<string> ans;
        for(int i=0;i<w.size();i++){
            if(cmp(w[i],p)){
                ans.emplace_back(w[i]);
            }
        }
        return ans;
    }
};