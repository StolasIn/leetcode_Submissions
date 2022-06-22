// https://leetcode.com/problems/design-an-ordered-stream

class OrderedStream {
public:
    vector<string> v;
    int now;
    OrderedStream(int n) {
        v.assign(n,"");
        now = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey-1] = value;
        vector<string> ans;
        if(v[idKey-1]!=""){
            int i=now;
            while(i<v.size() && v[i]!=""){
                ans.emplace_back(v[i]);
                i++;
            }
            now = i;
            return ans;
        }
        else{
            return {};
        }
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */