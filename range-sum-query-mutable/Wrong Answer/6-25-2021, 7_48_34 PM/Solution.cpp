// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int> bit;
    vector<int> n;
    NumArray(vector<int>& nums) {
        n.assign(nums.begin(),nums.end());
        bit.resize(nums.size()+1);
        for(int i=1;i<bit.size();i++){
            for(int j=i;j<bit.size();){
                bit[j]+=nums[i-1];
                j+=(j&(-j));
            }
        }
    }
    
    void update(int index, int val) {
        int v=val-n[index];
        bit[index+1]+=v;
        index+=((index+1)&(-index-1))+1;
        for(int j=index;j<bit.size();){
            bit[j]+=v;
            j+=(j&(-j));
        }
        for(auto i:bit){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    int sumRange(int left, int right) {
        int l=0,r=0;
        for(int i=left;i>0;){
            l+=bit[i];
            i-=(i&(-i));
        }
        for(int i=right+1;i>0;){
            r+=bit[i];
            i-=(i&(-i));
        }
        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */