// https://leetcode.com/problems/happy-number

class Solution {
public:
    bool isHappy(int n) {
        vector<int> arr;
        int sum;
        sum=n;
        while(sum>=10){
            arr.clear();
            for(;sum!=0;){
                arr.emplace_back(sum%10);
                sum/=10;
            }
            sum=0;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i]*arr[i];
            }
        }
        if(sum==1 || sum==7) return true;
        else return false;
    }
};