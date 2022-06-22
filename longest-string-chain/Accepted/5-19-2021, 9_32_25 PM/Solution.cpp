// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    static bool cmp(string& a,string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& w) {
        unordered_map<string,int> map;
        sort(w.begin(),w.end(),cmp);
        for(auto i : w){
            map[i]=0;
        }
        int m=w.size();
        string str,tmp;
        for(int i=m-1;i>=0;i--){
            tmp=w[i];
            for(int j=0;j<tmp.size();j++){
                str=tmp.substr(0,j)+tmp.substr(j+1);
                if(map.find(str)!=map.end()){
                    map[str]=max(map[tmp]+1,map[str]);
                }
            }
        }
        int ma=0;
        for(auto i : map){
            ma=max(ma,i.second);
        }
        return ma+1;
    }
};