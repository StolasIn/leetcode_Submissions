// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

struct pa{
    int f,l;
};
bool operator<(pa a,pa b){
    return a.f+a.l>b.f+b.l;
}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pa> pq;
        vector<vector<int>> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                pq.push(pa{nums1[i],nums2[j]});
            }
        }
        for(int i=0;i<k;i++){ 
            auto tmp=pq.top();
            pq.pop();
            ans.emplace_back(vector<int>{tmp.f,tmp.l});
        }
        return ans;
    }
};