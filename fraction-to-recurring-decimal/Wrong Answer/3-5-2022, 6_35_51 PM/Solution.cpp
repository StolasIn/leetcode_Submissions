// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        double m = (double)n/d;
        string ans = "";
        map<int,int> map;
        ans += to_string((int)m);
        m -= (int)m;
        if(fabs(m-0)>1e-6){
            ans+='.';
        }
        else{
            return ans;
        }
        int cnt = ans.size();
        while(fabs(m-0)>1e-6){
            if(map.find((int)m)!=map.end() && (int)m!=0){
                ans.insert(map[(int)m],"(");
                ans+=')';
                break;
            }
            map[(int)m] = cnt++;
            m -= (int)m;
            m*=10;
            if(fabs(m-0)<1e-6){
                break;
            }
            ans += to_string((int)m);
        }
        return ans;
    }
};