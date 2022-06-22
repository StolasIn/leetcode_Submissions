// https://leetcode.com/problems/largest-number

class Solution {
public:
    static bool cmp(string a,string b){
        string u=a+b;
        string v=b+a;
        if(u>v)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        int cnt=0;
        vector<string> s;
        string ans="";
        int n=nums.size();
        for(int i=0;i<n;i++){
            stringstream ss;
            ss<<nums[i];
            s.emplace_back(ss.str());
            if(nums[i]!=0) cnt++;
        }
        if(cnt==0) return "0";
        sort(s.begin(),s.end(),cmp);
        for(int i=0;i<n;i++){
            ans+=s[i];
        }
        return ans;
    }
};