// https://leetcode.com/problems/rank-teams-by-votes

struct node{
    char c;
    vector<int> v;
    bool operator<(node& a){
        for(int i=0;i<v.size();i++){
            if(a.v[i]<v[i]) return true;
            else if(a.v[i]>v[i]) return false;
        }
        return a.c>c;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& v) {
        int k=v[0].size();
        vector<vector<int>> map(26,vector<int>(k+1,0));
        vector<node> vec;
        string ans;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                map[v[i][j]-'A'][j]++;
                map[v[i][j]-'A'][k]=1;
            }
        }
        for(int i=0;i<26;i++){
            if(map[i][k]==1) vec.emplace_back(node{(char)(i+'A'),map[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ans+=vec[i].c;
        }
        return ans;
    }
};