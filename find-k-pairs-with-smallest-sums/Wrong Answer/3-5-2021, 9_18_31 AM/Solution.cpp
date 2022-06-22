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
        if(nums1.empty() || nums2.empty()) return ans;
        int cnt=0;
        while(cnt<nums1.size() && cnt<nums2.size()){
            for(int i=cnt;i<nums2.size();i++){
                pq.push(pa{nums1[cnt],nums2[i]});
            }
            cnt++;
            for(int i=cnt;i<nums1.size();i++){
                pq.push(pa{nums1[i],nums2[cnt-1]});
            }
            cnt++;
            if(pq.size()>k) break;
        }
        for(int i=0;i<k;i++){
            auto tmp=pq.top();
            pq.pop();
            ans.emplace_back(vector<int>{tmp.f,tmp.l});
        }
        return ans;
    }
};