// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters

class Solution {
public:
    struct node{
      int fre,first,last;  
    };
    int longestSubstring(string s, int k) {
        vector<node> v(128,node{0,0,0});
        int m=s.size();
        int min1=INT_MAX,max1=-INT_MAX;
        bool flag=false;
        for(int i=0;i<m;i++){
            v[s[i]].fre++;
            if(v[s[i]].fre==1) v[s[i]].first=i;
            v[s[i]].last=i;
        }
        for(int i='a';i<='z';i++){
            if(v[i].fre>=k){
                min1=min(min1,v[i].first);
                max1=max(max1,v[i].last);
                flag=true;
            }
        }
        return flag==true ? max1-min1+1 : 0;
    }
};