// https://leetcode.com/problems/minimum-absolute-difference

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio (false);
        cin.tie (nullptr);
        sort(arr.begin(),arr.end());
        int mi=INT_MAX;
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]<mi){
                ans.clear();
                ans.emplace_back(vector<int>{arr[i-1],arr[i]});
                mi=arr[i]-arr[i-1];
            }
            else if(arr[i]-arr[i-1]==mi){
                ans.emplace_back(vector<int>{arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};