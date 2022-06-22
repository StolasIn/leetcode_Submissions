// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
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
                mi=min(mi,r-l);
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
        cout<<mi<<endl;
        return "";
    }
};