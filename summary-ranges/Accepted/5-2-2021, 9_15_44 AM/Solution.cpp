// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& num) {
        vector<string> ans;
        if(num.size()==0){
            return ans;
        }
        int m=num.size();
        int key=num[0];
        string str=to_string(num[0]);
        bool flag=false;
        for(int i=1;i<m;i++){
            if(num[i]==key+1){
                flag=true;
                key++;
            }
            else{
                if(flag==true){
                    str+="->";
                    str+=to_string(num[i-1]);
                }
                flag=false;
                ans.emplace_back(str);
                str=to_string(num[i]);
                key=num[i];
            }
        }
        if(flag==true){
            str+="->";
            str+=to_string(num[num.size()-1]);
        }
        ans.emplace_back(str);
        return ans;
    }
};