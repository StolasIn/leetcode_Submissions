// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool check(vector<int>& p,int m,int h){
        if(m==0) return false;
        int use=0;
        for(int i=0;i<p.size();i++){
            use+=(p[i]/m);
            if(p[i]%m!=0){
                use+=1;
            }
        }
        return use<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=0,r=*max_element(piles.begin(),piles.end());
        int mid;
        int ans=1e9;
        while(r>=l){
            mid=(r+l)/2;
            if(check(piles,mid,h)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};