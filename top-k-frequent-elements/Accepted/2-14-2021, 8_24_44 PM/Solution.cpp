// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<pair<int,long long>> v;
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            v.emplace_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(),[](pair<int,long long> a,pair<int,long long> b){
            return a.first>b.first;
        });
        for(int i=0;i<k;i++){
            ans.emplace_back(v[i].second);
        }
        return ans;
    }
};