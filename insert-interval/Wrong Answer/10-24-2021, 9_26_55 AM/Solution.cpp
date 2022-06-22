// https://leetcode.com/problems/insert-interval

bool cmp(vector<int>& a,vector<int>& b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& n) {
        if(in.size()==0){
            return {n};
        }
        sort(in.begin(),in.end());
        int m=in.size();
        if(n[0]>in[m-1][1]){
            in.emplace_back(n);
            return in;
        }
        vector<vector<int>> ans;
        bool flag;
        for(int i=0;i<in.size();i++){
            if(in[i][1]>=n[0]){
                flag=true;
                for(int j=i;j<in.size();j++){
                    if(in[j][0]>n[1]){
                        ans.emplace_back(vector<int>{in[i][0],max(in[j-1][1],n[1])});
                        i=j;
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    in[i][1]=max(in[i][1],n[1]);
                }
            }
            ans.emplace_back(in[i]);
        }
        return ans;
    }
};