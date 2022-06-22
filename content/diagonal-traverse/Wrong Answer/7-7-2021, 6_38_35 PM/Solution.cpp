// https://leetcode.com/problems/diagonal-traverse

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int l=0,r=0;
        int cnt=1;
        vector<int> ans;
        int m=mat.size();
        for(int i=0;i<m;i++){
            int l1=l,r1=r;
            if(cnt%2==0){
                while(l1>=0 && r1>=0 && l1<m && r1<m){
                    ans.emplace_back(mat[l1][r1]);
                    l1++;
                    r1--;
                }
            }
            else{
                swap(l1,r1);
                while(l1>=0 && r1>=0 && l1<m && r1<m){
                    ans.emplace_back(mat[l1][r1]);
                    l1--;
                    r1++;
                }
            }
            r++;
            cnt++;
        }
        l=1,r=m-1;
        for(int i=0;i<m-1;i++){
            int l1=l,r1=r;
            if(cnt%2==0){
                while(l1>=0 && r1>=0 && l1<m && r1<m){
                    ans.emplace_back(mat[l1][r1]);
                    l1++;
                    r1--;
                }
            }
            else{
                swap(l1,r1);
                while(l1>=0 && r1>=0 && l1<m && r1<m){
                    ans.emplace_back(mat[l1][r1]);
                    l1--;
                    r1++;
                }
            }
            l++;
            cnt++;
        }
        return ans;
    }
};