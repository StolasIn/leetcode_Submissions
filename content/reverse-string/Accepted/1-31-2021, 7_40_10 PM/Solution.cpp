// https://leetcode.com/problems/reverse-string

class Solution {
public:
    int n;
    void rev(vector<char>& s,int x){
        if(x>((n-1)/2)) return;
        rev(s,x+1);
        swap(s[x],s[n-x-1]);
    }
    void reverseString(vector<char>& s) {
        if(s.size()==0) return;
        n=s.size();
        rev(s,0);
        return;
    }
};