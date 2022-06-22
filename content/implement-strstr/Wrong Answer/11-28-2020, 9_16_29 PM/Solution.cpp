// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int ans;
        int n=haystack.size();
        int m=needle.size();
        bool f=false;
        for(int i=0;i<m;i++){
            if(haystack[i]==needle[0]){
                ans=i;
                f=true;
                for(int j=0;j<m;j++){
                    if(i+j>=n){
                        f=false;
                        break;
                    }
                    if(haystack[i+j]!=needle[j]){
                        f=false;
                        break;
                    }
                }
            }
            if(f) break;
        }
        if(f) return ans;
        else return -1;
    }
};