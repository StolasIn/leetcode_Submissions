// https://leetcode.com/problems/word-break

class Solution {
public:
    bool flag=false;
    void check(unordered_map<char,vector<string>>& map,string s,int x){
        if(x==s.size()){
            flag=1;
            return;
        }
        if(flag==0){
            auto iter = map.find(s[x]);
            if(iter!=map.end()){
                int siz=iter->second.size();
                for(int i=0;i<siz;i++){
                    if(iter->second[i]==s.substr(x,siz)){
                        check(map,s,x+siz);
                    }
                }
            }
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char,vector<string>> map;
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i][0]].push_back(wordDict[i]);
        }
        check(map,s,0);
        return flag;
    }
};