// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {







	int a;

	list<int> ans;

    list<int> arr[3];

    bool b[3]={0};




	for(int i=0;i<a;i++){


        b[nums[i]]=true;

        arr[nums[i]].emplace_back(nums[i]);

	}

	for(int i=0;i<3;i++){

		if(b[i])

          copy(arr[i].begin(),arr[i].end(),back_inserter(ans));

        nums=vector<int>(ans.begin(),ans.end());
	}

}
    }
};