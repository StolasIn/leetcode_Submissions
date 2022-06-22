// https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0){
            return false;
        }
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        while(!m.empty()){
            int t = m.begin()->first;
            //cout<<t<<endl;
            if(m[t]>1){
                m[t]--;
            }
            else{
                m.erase(t);   
            }
            for(int i=0;i<k-1;i++){
                t++;
                if(m.find(t)==m.end()) return false;
                if(m[t]>1){
                    m[t]--;
                }
                else{
                    m.erase(t);   
                }
            }
        }
        return true;
    }
};