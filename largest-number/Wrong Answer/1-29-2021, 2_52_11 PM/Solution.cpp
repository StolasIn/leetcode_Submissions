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
        vector<string> s;
        string ans="";
        int n=nums.size();
        for(int i=0;i<n;i++){
            stringstream ss;
            ss<<nums[i];
            s.emplace_back(ss.str());
        }
        sort(s.begin(),s.end(),cmp);
        for(int i=0;i<n;i++){
            ans+=s[i];
            cout<<s[i]<<" ";
        }
        return ans;
    }
};