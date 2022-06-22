// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int> fenwick;
    vector<int> sto;
    int m;
    NumArray(vector<int>& nums) {
        m=nums.size();
        int tmp;
        sto=nums;
        fenwick.resize(m+1,0);
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
    int sum(int i){
        ++i;
        int sum = 0;
        while (i > 0) {
          sum += fenwick[i];
          i -= (i & -i);
        }
        return sum;
    }
    int sumRange(int left, int right) {
       return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */