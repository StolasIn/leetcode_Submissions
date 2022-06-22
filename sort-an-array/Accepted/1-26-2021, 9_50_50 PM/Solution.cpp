// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    struct node{
            int real,div;
        };
        int con=256;
        void count_sort(list<node>& arr){
            int n=arr.size();
            list<node> ans;
            vector<list<node>> d(con);
            for(auto i : arr){
                d[i.div%con].emplace_back(node{i.real,i.div/con});
            }
            for(int i=0;i<con;i++){
                ans.insert(ans.end(),d[i].begin(),d[i].end());
            }
            arr.clear();
            arr.assign(ans.begin(),ans.end());
        }
        void radix_sort(list<node>& arr){
            for(int i=0;i<3;i++){
                count_sort(arr);
            }
        }
    vector<int> sortArray(vector<int>& nums) {
            int n=nums.size();
            list<node> arr;
            vector<int> ans;
            for(int i=0;i<n;i++){
                arr.emplace_back(node{nums[i]+50000,nums[i]+50000});
            }
            radix_sort(arr);
            for(auto i : arr){
                ans.emplace_back(i.real-50000);
            }
        return ans;
    }
};