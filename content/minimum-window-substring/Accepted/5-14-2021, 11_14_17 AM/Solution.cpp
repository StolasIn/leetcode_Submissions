// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        deque<char> d;
        deque<char> ans;
        int l=0,r=0;
        int arr[128];
        int cnt[128];
        int c=0;
        int f=0;
        for(int i=0;i<128;i++){
            arr[i]=0;
            cnt[i]=0;
        }
        int mi=INT_MAX;
        int m=s.size();
        int n=t.size();
        for(int i=0;i<n;i++){
            if(arr[t[i]]==0) f++;
            arr[t[i]]++;
        }
        while(r<=m){
            if(c<f){
                d.push_back(s[r]);
                if(cnt[s[r]]<arr[s[r]]-1){
                    cnt[s[r]]++;
                    r++;
                }
                else if(cnt[s[r]]==arr[s[r]]-1){
                    cnt[s[r]]++;
                    r++;
                    c++;
                }
                else{
                    cnt[s[r]]++;
                    r++;
                }
            }
            else{
                if(r-l<mi){
                    mi=r-l;
                    ans=d;
                }
                d.pop_front();
                if(cnt[s[l]]==arr[s[l]]){
                    c--;
                    cnt[s[l]]--;
                    l++;
                }
                else{
                    cnt[s[l]]--;
                    l++;
                }
            }
        }
        string a="";
        for(auto i : ans){
            a+=i;
        }
        return a;
    }
};