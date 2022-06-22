// https://leetcode.com/problems/corporate-flight-bookings

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int> ans(n+1,0);
        for(auto& t : book){
            ans[t[0]-1]+=t[2];
            ans[t[1]]-=t[2];
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        ans.pop_back();
        return ans;
    }
};