// https://leetcode.com/problems/rank-teams-by-votes

struct node{
    char c;
    string s;
    bool operator<(node& a){
        if(a.s=="" || s=="") return false;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>a.s[i]){
                ans++;
            }
        }
        if(ans==s.size()/2){
            sort(s.begin(),s.end());
            sort(a.s.begin(),a.s.end());
            return s<a.s;
        }
        return ans<(s.size()/2);
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
            vec.emplace_back(node{i.first,i.second});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            ans+=vec[i].c;
        }
        return ans;
    }
};