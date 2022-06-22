// https://leetcode.com/problems/course-schedule-ii

class Solution {
public:
    int time=0;
    vector<vector<int>> dag;
    vector<bool> vis;
    struct node{
        int ver,fin;  
    };
    vector<node> so;
    static bool cmp(node a,node b){
        return a.fin>b.fin;
    }
    void dfs(int x){
        time++;
        for(auto i : dag[x]){
            if(vis[i]==false){
                dfs(i);
                vis[i]=true;
            }
        }
        time++;
        so[x].ver=x;
        so[x].fin=time;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        if(pre.size()==0){
            return vector<int>(1,0);
        }
        dag.resize(num);
        so.resize(num);
        vector<int> ans;
        vis=vector<bool>(num,false);
        int m=pre.size();
        for(int i=0;i<m;i++){
            dag[pre[i][1]].emplace_back(pre[i][0]);
        }
        for(int i=0;i<num;i++)
            if(vis[i]==false)
                dfs(i);
        sort(so.begin(),so.end(),cmp);
        for(int i=0;i<num;i++){
            ans.emplace_back(so[i].ver);
        }
        return ans;
    }
};