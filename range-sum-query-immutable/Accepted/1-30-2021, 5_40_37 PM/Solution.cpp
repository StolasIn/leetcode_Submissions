// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> prefixsum;
    int m;
    NumArray(vector<int>& nums) {
        m=nums.size();
        int sum=0;
        prefixsum=vector<int>(m);
        for(int i=0;i<m;i++){
            sum+=nums[i];
            prefixsum[i]=sum;
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0) return prefixsum[j];
        else return prefixsum[j]-prefixsum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */