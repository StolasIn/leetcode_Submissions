// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0;
        int m=nums.size();
        if(m==1) return 0;
        for(int i=0;i<m-1;){
            //cout<<i<<endl;
            cnt++;
            int t=nums[i];
            int ma=-1,s;
            for(int j=i;j<=i+nums[i];j++){
                if(j>=m-1){
                    s=j;
                    break;   
                }
                //cout<<j<<" "<<nums[j]<<endl;
                if(ma<j+nums[j]){
                    ma=j+nums[j];
                    s=j;
                }
            }
            //cout<<s<<endl;
            i=s;
        }
        cout<<endl;
        return cnt;
    }
};