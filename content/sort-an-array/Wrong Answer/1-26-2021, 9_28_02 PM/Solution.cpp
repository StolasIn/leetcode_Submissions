// https://leetcode.com/problems/sort-an-array

class Solution {
public:
    struct node{
            int real,div;
        };
        int max1=-1;
        int con=256;
        void count_sort(vector<node>& arr){
            int n=arr.size();
            vector<node> ans;
            vector<vector<node>> d(con);
            for(int i=0;i<n;i++){
                d[arr[i].div%con].push_back(node{arr[i].real,arr[i].div/10});
                arr[i].div/=con;
            }
            for(int i=0;i<con;i++){
                ans.insert(ans.end(),d[i].begin(),d[i].end());
            }
            arr.clear();
            arr.assign(ans.begin(),ans.end());
        }
        void radix_sort(vector<node>& arr){
            int j;
            for(j=0;max1!=0;j++) max1/=con;
            for(int i=0;i<j;i++){
                count_sort(arr);
            }
        }
    vector<int> sortArray(vector<int>& nums) {
            int n=nums.size();
            vector<node> arr(n);
            vector<int> ans;
            for(int i=0;i<n;i++){
                arr[i].real=nums[i]+50000;
                arr[i].div=arr[i].real;
                max1=max(max1,arr[i].real);
            }
            radix_sort(arr);
        for(int i=0;i<arr.size();i++){
            ans.push_back(arr[i].real-50000);
        }
        return ans;
    }
};