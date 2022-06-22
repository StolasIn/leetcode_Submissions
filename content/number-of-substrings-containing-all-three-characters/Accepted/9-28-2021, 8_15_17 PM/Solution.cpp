// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={0},r=0,sum=0,ans=0;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            while(arr[0] && arr[1] && arr[2]){
                sum+=1;
                arr[s[r++]-'a']--;
            }
            ans+=sum;
        }
        return ans;
    }
};