// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        int now = 0;
        int cnt = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        if(sum%3!=0) return false;
        sum/=3;
        for(int i=0;i<arr.size();i++){
            now+=arr[i];
            if(now==sum){
                cnt++;
                now=0;
            }
        }
        return cnt>=3;
    }
};