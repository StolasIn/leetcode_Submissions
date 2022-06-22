// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        int n1=n;
        vector<int> v;
        int cnt=0;
        while(n!=0){
            v.emplace_back(n%10);
            n/=10;
        }
        reverse(v.begin(),v.end());
        next_permutation(v.begin(),v.end());
        int ans=0;
        long long int pro=1;
        for(int i=v.size()-1;i>=0;i--){
            ans+=v[i]*pro;
            pro*=10;
        }
        cout<<ans<<endl;
        if(ans<=n1) return -1;
        return ans;
    }
};