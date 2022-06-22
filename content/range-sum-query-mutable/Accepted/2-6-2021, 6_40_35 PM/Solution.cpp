// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    NumArray(vector<int>& nums) {
        m=nums.size();
        int tmp;
        sto.assign(nums.begin(),nums.end());
        fenwick.resize(m+1);
        for(int i=1;i<=m;i++){
            fenwick[i]=nums[i-1];
        }
        for(int i=1;i<=m;i++){
            tmp=i;
            tmp+=(tmp&(-tmp));
            while(tmp<=m){
                fenwick[tmp]+=sto[i-1];
                tmp+=(tmp&(-tmp));
            }
        }
    }
    void update(int index, int val) {
        int tmp=val-sto[index];
        sto[index]=val;
        index++;
        while(index<=m){
            fenwick[index]+=tmp;
            index+=(index&(-index));
        }
    }
    int sum(int ind){
        int sum=0;
        while(ind>=1){
            sum+=fenwick[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }
    int sumRange(int left, int right) {
        if(left==0){
            return sum(right+1);
        }
        else{
            return sum(right+1)-sum(left);
        }
    }
private:
    vector<int> fenwick;
    vector<int> sto;
    int m;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */