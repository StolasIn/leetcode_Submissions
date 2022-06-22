// https://leetcode.com/problems/word-break

class Solution {
public:
    bool flag=false;
    void check(unordered_map<char,vector<string>>& map,string s,int x){
        if(x==s.size()){
            flag=1;
            return;
        }
        //cout<<s[x]<<endl;
        auto iter = map.find(s[x]);
        if(iter!=map.end()){
            for(int i=0;i<iter->second.size();i++){
                //cout<<iter->second[i]<<" "<<s.substr(x,x+iter->second[i].size())<<" "<<iter->second[i].size()<<" "<<s<<" "<<x<<endl;
                //if(iter->second[i]==s.substr(x,x+iter->second[i].size())){
                    check(map,s,x+iter->second[i].size());
                //}
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