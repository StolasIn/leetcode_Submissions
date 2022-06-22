// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    int m;
    int dp[20010];
    bool re(int item,int remain,vector<int>& n){
        if(remain==0)return true;
        if(item>=m || remain<0) return false;
        if(dp[remain]!=-1){
            return dp[remain];
        }
        return dp[remain]=re(item+1,remain-n[item],n)||re(item+1,remain,n);
    }
    bool canPartition(vector<int>& n) {
        int sum = 0;
        m = n.size();
        for(int i=0;i<m;i++){
            sum+=n[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum/=2;
        for(int i=0;i<=sum;i++){
            dp[i]=-1;
        }
        return re(0,sum,n);
    }
};