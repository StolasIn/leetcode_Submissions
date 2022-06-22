// https://leetcode.com/problems/3sum

class Solution {
    public List<List<Integer>> twosum(int[] arr,int beg,int tar){
        int l=beg,r=arr.length-1;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        while(r>l){
            if(arr[l]+arr[r]>tar){
                r--;
            }
            else if(arr[l]+arr[r]<tar){
                l++;
            }
            else{
                List<Integer> tmp = new ArrayList<Integer>(Arrays.asList(arr[l],arr[r]));
                ans.add(tmp);
                l++;
                r--;
                while(l<arr.length && arr[l]==arr[l-1]) l++;
                while(r>=0 && arr[r]==arr[r+1]) r--;
            }
        }
        return ans;
    }
    public List<List<Integer>> ksum(int[] arr,int k,int beg,int tar){
        if(k==2){
            return twosum(arr,beg,tar);
        }
        else{
            List<List<Integer>> ans = new ArrayList<List<Integer>>();
            for(int i=beg;i<arr.length;i++){
                if(i!=0 && arr[i]==arr[i-1]) continue;
                List<List<Integer>> tmp = ksum(arr,k-1,i+1,tar-arr[i]);
                for(List<Integer> t: tmp){
                    t.add(arr[i]);
                    ans.add(t);
                }
            }
            return ans;
        }
    }
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        return ksum(nums,3,0,0);
    }
}