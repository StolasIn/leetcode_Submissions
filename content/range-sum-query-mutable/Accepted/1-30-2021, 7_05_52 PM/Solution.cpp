// https://leetcode.com/problems/range-sum-query-mutable

class NumArray {
public:
    vector<int> fenwick;
    vector<int> sto;
    int m;
    NumArray(vector<int>& nums) {
        if(nums.empty()==true) return;
        m=nums.size();
        int tmp;
        sto.assign(nums.begin(),nums.end());
        fenwick.resize(m+1);
        for(int i=1;i<=m;i++){
            fenwick[i]=nums[i-1];
        }
        for(int i=1;i<=m;i++){
            tmp=i;
            tmp+=lowbit(tmp);
            while(tmp<=m){
                fenwick[tmp]+=sto[i-1];
                tmp+=lowbit(tmp);
            }
        }
    }
    int lowbit(int x){
        return (x&(-x));
    }
    void update(int index, int val) {
        int tmp=sto[index];
        tmp=val-tmp;
        sto[index]+=tmp;
        index++;
        while(index<=m){
            fenwick[index]+=tmp;
            index+=lowbit(index);
        }
    }
    int sum(int ind){
        int sum=0;
        while(ind>=1){
            sum+=fenwick[ind];
            ind-=lowbit(ind);
        }
        return sum;
    }
    int sumRange(int left, int right) {
        if(sto.empty()==true) return 0;
        if(left==0){
            return sum(right+1);
        }
        else{
            return sum(right+1)-sum(left);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */