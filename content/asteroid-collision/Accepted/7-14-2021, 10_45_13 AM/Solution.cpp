// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    bool col(vector<int>& st){
        if(st.size()<=1) return false;
        int a=st.back();
        st.pop_back();
        int b=st.back();
        st.pop_back();
        if(a<0 && b>0){
            if(abs(a)>abs(b)){
                st.emplace_back(a);
                return true;
            }
            else if(abs(a)<abs(b)){
                st.emplace_back(b);
                return true;
            }
            else{
                return false;
            }
        }
        else{
            st.emplace_back(b);
            st.emplace_back(a);
        }
        return false;
    }
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> st;
        int m=as.size();
        int t;
        for(int i=0;i<m;i++){
            st.emplace_back(as[i]);
            while(col(st));
        }
        return st;
    }
};