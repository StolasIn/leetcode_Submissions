// https://leetcode.com/problems/word-break

class Solution {
public:
    int siz;
    bool check(unordered_map<char,vector<string>>& map,string& s,int x,vector<bool>& dp,vector<bool>& vis){
        if(x==s.size()){
            return true;
        }
        if(vis[s.size()-x]==true) return dp[s.size()-x];
        vis[s.size()-x]=true;
        auto iter = map.find(s[x]);
        if(iter!=map.end()){
            for(int i=0;i<iter->second.size();i++){
                siz=iter->second[i].size();
                if(iter->second[i]==s.substr(x,siz)){
                    dp[s.size()-x] = check(map,s,x+siz,dp,vis);
                    if(dp[s.size()-x]==true) return true;
                }
            }
        }
        return dp[s.size()-x];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char,int> map1;
        vector<bool> dp(s.size()+1,false);
        vector<bool> vis(s.size()+1,false);
        unordered_map<char,vector<string>> map;
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i][0]].push_back(wordDict[i]);
        }
        return check(map,s,0,dp,vis);
    }
};