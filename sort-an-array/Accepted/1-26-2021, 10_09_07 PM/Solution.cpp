// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    struct node{
            int real,div;
        };
        int con=256;
        void count_sort(vector<node>& arr){
            int n=arr.size();
            vector<node> ans;
            vector<vector<node>> d(con);
            for(int i=0;i<n;i++){
                d[arr[i].div%con].emplace_back(node{arr[i].real,arr[i].div/con});
            }
            for(int i=0;i<con;i++){
                ans.insert(ans.end(),d[i].begin(),d[i].end());
            }
            arr.clear();
            arr.assign(ans.begin(),ans.end());
        }
        void radix_sort(vector<node>& arr){
            for(int i=0;i<3;i++){
                count_sort(arr);
            }
        }
    vector<int> sortArray(vector<int>& nums) {
            int n=nums.size();
            vector<node> arr;
            vector<int> ans;
            for(int i=0;i<n;i++){
                arr.emplace_back(node{nums[i]+50000,nums[i]+50000});
            }
            radix_sort(arr);
        for(int i=0;i<n;i++){
            ans.emplace_back(arr[i].real-50000);
        }
        return ans;
    }
};