// https://leetcode.com/problems/rank-teams-by-votes

struct node{
    char c;
    string s;
    bool operator<(node& a){
        if(a.s==s) return a.c>c;
        return a.s>s;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& v) {
        unordered_map<char,string> map;
        vector<node> vec;
        string ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                map[v[i][j]]+=(char)(j);
            }
        }
        for(auto& i : map){
            sort(i.second.begin(),i.second.end());
            vec.emplace_back(node{i.first,i.second});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ans+=vec[i].c;
        }
        return ans;
    }
};