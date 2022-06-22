// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string ans = "";
        map<int,int> map;
        long int r = n%d;
        ans += to_string(n/d);
        if (r==0) {
            return ans;
        }
        ans += '.';
        if(r<0){
            r*=-1;
        }
        while(r!=0){
            if(map.find(r)!=map.end()){
                ans.insert(map[r],"(");
                ans+=')';
                break;
            }
            map[r] = ans.size();
            r*=10;
            ans += to_string(r/d);
            r%=d;
        }
        return ans;
    }
};