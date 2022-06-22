// https://leetcode.com/problems/implement-strstr

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack=="" && needle=="") return 0;
        int ans;
        bool f=false;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                ans=i;
                f=true;
                for(int j=0;j<needle.size();j++){
                    if(i+j>=haystack.size()){
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