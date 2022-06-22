// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    bool isp(string& s,int l,int r){
        while(r>l){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    vector<vector<string>> re(string& s,int l,int r){
        if(l==r-1){
            return {{string(1,s[l])}};
        }
        vector<vector<string>> ans;
        vector<vector<string>> tmp;
        for(int i=1;i<=r-l;i++){
            //cout<<l<<' '<<i<<' '<<s.substr(l,i)<<endl;
            if(isp(s,l,l+i-1)){
                //cout<<1<<endl;
                tmp = re(s,l+i,r);
                if(tmp.size()!=0){
                    for(int j=0;j<tmp.size();j++){
                        int t = ans.size();
                        ans.emplace_back(vector<string>());
                        ans[t].emplace_back(s.substr(l,i));
                        for(int k=0;k<tmp[j].size();k++){
                            ans[t].emplace_back(tmp[j][k]);
                        }
                    }
                }
                else{
                    //cout<<l<<' '<<i<<' '<<r<<endl;
                    if(isp(s,l,r-1)){
                        int t = ans.size();
                        ans.emplace_back(vector<string>());
                        ans[t].emplace_back(s.substr(l));
                    }
                }
            }
        }
        return ans;
    }
    vector<vector<string>> partition(string s) {
        return re(s,0,s.size());
    }
};