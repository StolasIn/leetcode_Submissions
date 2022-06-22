// https://leetcode.com/problems/two-sum

class node{
    int num;
    int id;
    public node (int a,int b) 
	{ 
		this.num = a; 
		this.id=b;
	} 
}
class nodeSort implements Comparator<node> 
{ 
	public int compare(node a, node b)
	{ 
		return a.num - b.num; 
	} 
} 
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] v=new int[2];
        node[] t=new node[nums.length];
        for(int i=0;i<nums.length;i++){
            t[i]=new node(nums[i],i);
        }
        Arrays.sort(t,new nodeSort());
        int l=0,r=nums.length-1;
        while(r>l){
            if(t[l].num+t[r].num==target){
                v[0]=t[l].id;
                v[1]=t[r].id;
                return v;
            }
            else if(t[l].num+t[r].num>target){
                r--;
            }
            else{
                l++;
            }
        }
        return v;
    }
}