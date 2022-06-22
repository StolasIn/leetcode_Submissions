// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int> fenwick;
    vector<int> sto;
    int m;
    NumArray(vector<int>& nums) {
        if(nums.empty()==true) return;
        m=nums.size();
        int tmp;
        sto.assign(nums.begin(),nums.end());
        fenwick.resize(m+1);
        for(int i=0;i<m;i++){
            up(i,nums[i]);
        }
    }
    void update(int index, int val) {
        int tmp=val-sto[index];
        sto[index]=val;
        up(index,tmp);
    }
    void up(int i, int diff) {
    ++i;
    while (i <= m) {
      fenwick[i] += diff;
      i += (i & -i);
    }
  }
    int sum(int ind){
        int sum=0;
        while(ind>=1){
            sum+=fenwick[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }
    int sumRange(int left, int right) {
        if(sto.empty()==true) return 0;
        if(left==0){
            return sum(right+1);
        }
        else{
            return sum(right+1)-sum(left);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */