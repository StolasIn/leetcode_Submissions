// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    long long int factorial(int a){
        int sum=1;
        for(int i=1;i<=a;i++) sum*=i;
        return sum;
    }
    long long int com(int a,int b){
        int sum=1;
        if(b>a/2){
            for(int i=a;i>b;i--){
                sum*=i;
            }
            return sum/factorial(a-b);
        }
        else{
            for(int i=a;i>a-b;i--){
                sum*=i;
            }
            return sum/factorial(b);
        }
    }
    vector<int> getRow(int row) {
        vector<int> ans;
        if(row==0){
            ans.emplace_back(1);
            return ans;
        }
        if(row==1){
            ans.emplace_back(1);
            ans.emplace_back(1);
            return ans;
        }
        ans.emplace_back(1);
        if(row%2==1){
            for(int i=1;i<(row+1)/2;i++){
                ans.emplace_back(com(row,i));
            }
            for(int i=(row+1)/2;i<row;i++){
                ans.emplace_back(ans[row-i]);
            }
        }
        else{
            for(int i=1;i<(row)/2;i++){
                ans.emplace_back(com(row,i));
            }
            ans.emplace_back(com(row,(row/2)));
            for(int i=(row)/2-1;i>=1;i--){
                ans.emplace_back(ans[i]);
            }
        }
        ans.emplace_back(1);
        return ans;
    }
};