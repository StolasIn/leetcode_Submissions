// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
 public:
  NumArray(vector<int>& nums) {
    nums_ = nums;
    n_ = nums.size();
    tree_ = vector<int>(n_ + 1, 0);
    for (int i = 0; i < n_; i++) {
      updateInternal(i, nums[i]);
    }
  }

  void update(int i, int val) {
    int diff = val - nums_[i];
    nums_[i] = val;
    updateInternal(i, diff);
  }

  void updateInternal(int i, int diff) {
    ++i;
    while (i <= n_) {
      tree_[i] += diff;
      i += (i & -i);
    }
  }

  int sumRange(int i, int j) { return sum(j) - sum(i - 1); }
  int sum(int i) {
    ++i;
    int sum = 0;
    while (i > 0) {
      sum += tree_[i];
      i -= (i & -i);
    }
    return sum;
  }

 private:
  vector<int> tree_;
  vector<int> nums_;
  int n_;
};