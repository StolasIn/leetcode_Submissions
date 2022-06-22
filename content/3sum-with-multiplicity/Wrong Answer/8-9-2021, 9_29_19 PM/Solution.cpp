// https://leetcode.com/problems/3sum-with-multiplicity

class Solution {
public:
    int m=1e9+7;
    vector<vector<int>> Sum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return kSum(nums, target, 0, 3);
}
vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
    vector<vector<int>> res;
    if (start == nums.size() || nums[start] * k > target || target > nums.back() * k)
        return res;
    if (k == 2)
        return twoSum(nums, target, start);
    for (int i = start; i < nums.size(); ++i)
        if (i == start || nums[i - 1] != nums[i])
            for (auto &set : kSum(nums, target - nums[i], i + 1, k - 1)) {
                res.push_back({nums[i]});
                res.back().insert(end(res.back()), begin(set), end(set));
            }
    return res;
}
vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
    vector<vector<int>> res;
    int lo = start, hi = nums.size() - 1;
    while (lo < hi) {
        int sum = nums[lo] + nums[hi];
        if (sum < target || (lo > start && nums[lo] == nums[lo - 1]))
            ++lo;
        else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi + 1]))
            --hi;
        else
            res.push_back({ nums[lo++], nums[hi--]});
    }
    return res;
}
    int c(int a,int b){
        int ans=1;
        bool flag=false;
        if(a==b) return 1;
        for(int i=a;i>b;i--){
            ans*=i;
            if(ans>=m && !flag){
                for(int i=b;i>=2;i--){
                    ans/=i;
                }
                flag=true;
            }
            else{
                ans%=m;
            }
        }
        if(flag==false){
            for(int i=b;i>=2;i--){
                ans/=i;
            }
        }
        return ans;
    }
    int threeSumMulti(vector<int>& arr, int target) {
        int ans=0;
        sort(arr.begin(),arr.end());
        auto v=Sum(arr,target);
        unordered_map<int,int> map;
        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }
        for(auto i : v){
            if(i[0]==i[1] && i[1]==i[2]){
                ans+=c(map[i[0]],3);
            }
            else if(i[0]==i[1]){
                ans+=c(map[i[0]],2)*map[i[2]];  
            }
            else if(i[1]==i[2]){
                ans+=c(map[i[1]],2)*map[i[0]];
            }
            else{
                ans+=map[i[0]]*map[i[1]]*map[i[2]];
            }
        }
        return ans;
    }
};