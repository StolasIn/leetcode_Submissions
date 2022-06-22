// https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution {
public:
    int canBeTypedWords(string s, string b) {
        stringstream ss(s);
        string tmp;
        int ans = 0;
        int arr[128] = {0};
        for(int i=0;i<b.size();i++){
            arr[b[i]]++;
        }
        while(ss>>tmp){
            for(int i=0;i<tmp.size();i++){
                if(arr[tmp[i]]!=0){
                    ans--;
                    break;
                }
            }
            ans++;
        }
        return ans;
    }
};