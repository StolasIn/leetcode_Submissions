// https://leetcode.com/problems/4sum

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        
        return anySum(nums, 0, 4, target);
    }
    
    List<List<Integer>> anySum(int nums[], int start, int k, int target) {
        List<List<Integer>> answer = new ArrayList<>();
        if(k == 2) {
            answer = twoSum(nums, start, target);
        } else {
            for (int i = start; i<nums.length - (k - 1); i++) {
                if(i > start && nums[i] == nums[i - 1]) continue;
                List<List<Integer>> temp = anySum(nums, i + 1, k-1, target-nums[i]);
                for(List<Integer> t : temp) {
                       t.add(0, nums[i]);
                } 
                answer.addAll(temp);
            }
            
        }
        return answer;
    }
    
    private List<List<Integer>> twoSum(int [] nums, int start, int target) {
        int end = nums.length-1;
        List<List<Integer>> twoSumList = new ArrayList<>();
        
        while(start<end) {
            if(nums[start]+nums[end] == target) {
                List<Integer> nestedList = new ArrayList<>();
                nestedList.add(nums[start]);
                nestedList.add(nums[end]);
                twoSumList.add(nestedList);
                while(start < end && nums[start+1] == nums[start]) start++;
                while(start < end && nums[end-1] == nums[end]) end--;
                start++;
                end--;
            } else if(nums[start]+nums[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        
        return twoSumList;
    }
}