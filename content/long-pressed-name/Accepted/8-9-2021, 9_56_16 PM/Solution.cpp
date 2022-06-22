// https://leetcode.com/problems/long-pressed-name

struct node{
    char c;
    int f;
};
class Solution {
public:
    vector<node> ch(string& s){
        char now=s[0];
        int cnt=1;
        vector<node> v;
        for(int i=1;i<s.size();i++){
            if(s[i]!=now){
                v.emplace_back(node{now,cnt});
                cnt=1;
                now=s[i];
            }
            else{
                cnt++;
            }
        }
        v.emplace_back(node{now,cnt});
        return v;
    }
    bool cmp(vector<node>& a,vector<node>& b){
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i].c!=b[i].c) return false;
            if(a[i].f>b[i].f) return false;
        }
        return true;
    }
    bool isLongPressedName(string name, string typed) {
        auto t1 = ch(name);
        auto t2 = ch(typed);
        return cmp(t1,t2);
    }
};