// https://leetcode.com/problems/matchsticks-to-square

class Solution {
public:
    int sum;
    bool flag;
    void dfs(vector<bool>& vis,vector<int>& st,int a,int b){
        cout<<a<<" "<<b<<endl;
        if(b==2 && a==sum){
            flag=true;
            return;
        }
        else{
            if(a==sum){
                b++;
                a=0;
            }
            for(int i=0;i<st.size();i++){
                bool t=vis[i];
                vis[i]=true;
                if(t==false) dfs(vis,st,a+st[i],b);
                vis[i]=false;
            }
        }
    }
    bool makesquare(vector<int>& st) {
        sum=0;
        int m=st.size();
        vector<bool> vis(m,false);
        int ma=-1;
        for(int i=0;i<m;i++){
            sum+=st[i];
            ma=max(ma,st[i]);
        }
        sum/=4;
        if(ma>sum || sum%4!=0) return false;
        flag=false;
        dfs(vis,st,0,0);
        return flag;
    }
};