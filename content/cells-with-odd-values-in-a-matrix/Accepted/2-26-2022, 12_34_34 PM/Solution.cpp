// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& ind) {
        vector<int> row(m,0);
        vector<int> col(n,0);
        int ans = 0;
        for(int i=0;i<ind.size();i++){
            row[ind[i][0]]++;
            col[ind[i][1]]++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<row[i]+col[j]<<' ';
                if((row[i]+col[j])%2==1){
                    ans++;
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};