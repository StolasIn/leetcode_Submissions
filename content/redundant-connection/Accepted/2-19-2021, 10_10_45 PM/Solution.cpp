// https://leetcode.com/problems/redundant-connection

class dset{
    public:
        dset(int x){
            parent=vector<int>(x,-1);
        }
        void union_node(int x,int y){
            int x1=find(x);
            int y1=find(y);
            if(x1==y1 && x1!=-1) return;
            if(parent[x1]>parent[y1]){
                parent[y1]+=parent[x1];
                parent[x1]=y1;
            }
            else{
                parent[x1]+=parent[y1];
                parent[y1]=x1;
            }
        }
        int find(int x){
            int x1=x;
            while(parent[x]>=0){
                x=parent[x];
            }
            int x2;
            while(parent[x1]>=0){
                x2=x1;
                x1=parent[x1];
                parent[x2]=x;
            }
            return x;
        }
        int set_size(int x){
            return -parent[find(x)];
        }
        void print_parent(){
            for(int i=0;i<parent.size();i++){
                printf("%3d",i);
            }
            cout<<endl;
            for(int i=0;i<parent.size();i++){
                printf("%3d",parent[i]);
            }
            cout<<endl;
        }
    private:    
        vector<int> parent;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int ma=-INT_MAX;
        int m=edges.size();
        vector<int> ans(2);
        for(int i=0;i<m;i++){
            ma=max(ma,max(edges[i][0],edges[i][1]));
        }
        dset s=dset(ma+1);
        for(int i=0;i<m;i++){
            if(s.find(edges[i][0])==s.find(edges[i][1])){
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
            }
            s.union_node(edges[i][0],edges[i][1]);
        }
        return ans;
    }
};