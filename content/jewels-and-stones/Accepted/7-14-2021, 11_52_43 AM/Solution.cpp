// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string j, string s) {
        int cnt=0;
        int arr[128];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<s.size();i++){
            arr[s[i]]++;
        }
        for(auto i : j){
            cnt+=arr[i];
        }
        return cnt;
    }
};