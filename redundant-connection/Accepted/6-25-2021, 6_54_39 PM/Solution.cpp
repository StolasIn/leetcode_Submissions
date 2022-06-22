// https://leetcode.com/problems/redundant-connection

class dset{
public:
    dset(){}
    dset(int x){
        parent=vector<int>(x,-1);
    }
    void union_node(int x,int y){
        int m=find(x);
        int n=find(y);
        if(m==n && m!=-1) return;
        if(parent[m]>parent[n]){
            parent[n]+=parent[m];
            parent[m]=n;
        }
        else{
            parent[m]+=parent[n];
            parent[n]=m;
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
    void resize(int x){
        parent.assign(x+1,-1);
    }
private:
    vector<int> parent;
};
class Solution {
public:
    dset t;
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int m=e.size();
        t.resize(1000);
        for(int i=0;i<m;i++){
            if(t.find(e[i][0])==t.find(e[i][1])){
                return e[i];
            }
            t.union_node(e[i][0],e[i][1]);
        }
        return e[0];
    }
};