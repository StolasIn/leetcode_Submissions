// https://leetcode.com/problems/data-stream-as-disjoint-intervals

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    bool arr[10010];
    int ma=-1;
    SummaryRanges() {
        memset(arr,false,sizeof(arr));
    }
    
    void addNum(int val) {
        arr[val]=true;
        ma=max(ma,val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int key=0;
        for(;key<=ma;key++){
            if(arr[key]) break;
        }
        for(int i=key;i<=ma+1;){
            if(arr[i]){
                i++;
            }
            else{
                ans.emplace_back(vector<int>{key,i-1});
                key=i;
                for(;key<=ma+1;key++){
                    if(arr[key]) break;
                }
                if(key>=ma+1) break;
                i=key;
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */