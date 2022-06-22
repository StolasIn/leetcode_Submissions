// https://leetcode.com/problems/two-sum

class Solution {
public:
    struct node{
        int data,rank;  
    };
    static bool cmp(node a,node b){
        return a.data<b.data;
    }
    vector<int> twoSum(vector<int>& nums, int t) {
        int sum;
        vector<int> ans;
        int m=nums.size();
        vector<node> num(m);
        for(int i=0;i<m;i++){
            num[i]=node{nums[i],i};
        }
        sort(num.begin(),num.end(),cmp);
        int l=0,r=m-1;
        while(r>l){
            if(num[l].data+num[r].data==t){
                ans.emplace_back(num[l].rank);
                ans.emplace_back(num[r].rank);
                break;
            }
            else if(num[l].data+num[r].data>t){
                r--;
            }
            else if(num[l].data+num[r].data<t){
                l++;
            }
        }
        return ans;
    }
};