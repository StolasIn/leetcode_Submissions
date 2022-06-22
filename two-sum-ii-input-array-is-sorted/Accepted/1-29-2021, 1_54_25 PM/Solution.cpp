// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int fir,sec;
        vector<int> ans(2);
        int front1=0,back1=num.size()-1;
        while(front1!=back1){
            if(num[front1]+num[back1]>t){
                back1--;
            }
            else if(num[front1]+num[back1]<t){
                front1++;
            }
            else{
                break;
            }
        }
        ans[0]=front1+1;
        ans[1]=back1+1;
        return ans;
    }
};