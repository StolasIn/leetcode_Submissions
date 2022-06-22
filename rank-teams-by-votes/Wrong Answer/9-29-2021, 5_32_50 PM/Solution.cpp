// https://leetcode.com/problems/rank-teams-by-votes

struct node{
    char c;
    int val;
    bool operator<(const node a) const {
        if(a.val==val){
            return a.c>c;
        }
        return a.val<val;
    }
};
class Solution {
public:
    string rankTeams(vector<string>& vot) {
        vector<int> v(26,0);
        vector<node> sor;
        string str="";
        int cnt;
        for(int i=0;i<vot.size();i++){
            cnt=0;
            for(int j=vot[i].size()-1;j>=0;j--){
                v[vot[i][j]-'A']+=(++cnt);
            }
        }
        for(int i=0;i<26;i++){
            sor.emplace_back(node{(char)(i+'A'),v[i]});
        }
        sort(sor.begin(),sor.end());
        for(int i=0;i<sor.size();i++){
            if(sor[i].val>0)
                str+=sor[i].c;
        }
        return str;
    }
};