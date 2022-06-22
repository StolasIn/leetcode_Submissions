// https://leetcode.com/problems/replace-the-substring-for-balanced-string

class Solution {
public:
    int balancedString(string s) {
        int m=s.size();
        int bal=s.size()/4;
        int cnt=0;
        int arr[128]={0};
        for(int i=0;i<m;i++){
            arr[s[i]]++;
        }
        cnt+=abs(bal-arr['Q']);
        cnt+=abs(bal-arr['W']);
        cnt+=abs(bal-arr['E']);
        cnt+=abs(bal-arr['R']);
        return cnt/2;
    }
};