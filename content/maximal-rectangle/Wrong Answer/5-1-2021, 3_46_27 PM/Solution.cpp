// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& ma) {
        int m=ma.size();
        if(m==0) return 0;
        int n=ma[0].size();
        if(m==1 && n==1 && ma[0][0]=='1') return 1; 
        int pre[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    pre[i][j]=0;
                }
                else{
                    pre[i][j]=ma[i-1][j-1]-'0';
                }
            }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
            }
        }
        
        /*for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cout<<pre[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<endl;
        int max1=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=i+1;k<=m;k++){
                    for(int q=j+1;q<=n;q++){
                        int tmp=pre[k][q]-pre[i][q]-pre[k][j]+pre[i][j];
                        //cout<<i<<" "<<j<<" "<<k<<" "<<q<<" "<<tmp<<endl;
                        if(tmp==(k-i)*(q-j)){
                            max1=max(max1,tmp);
                        }
                    }
                }
            }
        }
        return max1;
    }
};