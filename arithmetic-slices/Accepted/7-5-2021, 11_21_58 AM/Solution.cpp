// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2) return 0;
        vector<int> v;
        int cnt=2;
        int key=1001;
        int ans=0;
        int m=nums.size();
        for(int i=1;i<m;i++){
            if(nums[i]-nums[i-1]==key){
                cnt++;
            }
            else{
                key=nums[i]-nums[i-1];
                v.emplace_back(cnt);
                cnt=2;
            }
        }
        v.emplace_back(cnt);
        /*for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;*/
        for(int i=0;i<v.size();i++){
            for(int j=3;j<=v[i];j++){
                ans+=v[i]-(j-1);
            }
        }
        return ans;
    }
};