// https://leetcode.com/problems/rank-teams-by-votes

struct node{
    char id;
    string str;
    bool operator<(const node& a) const {
        int ans=0;
        for(int i=0;i<str.size();i++){
            if(a.str[i]>str[i]){
                ans++;
            }
        }
        if(ans==str.size()/2){
            return id<a.id;
        }
        return ans>str.size()/2;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<node> v;
        string str;
        string s;
        string ans;
        for(int i=0;i<votes[0].size();i++){
            str+=votes[0][i];
        }
        sort(str.begin(),str.end());
        for(int i=0;i<votes[0].size();i++){
            s="";
            for(int j=0;j<votes.size();j++){
                s+=votes[j][i];
            }
            v.emplace_back(node{str[i],s});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans+=v[i].id;
        }
        return ans;
    }
};