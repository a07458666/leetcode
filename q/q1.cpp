class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans(2,1);
		map<int, int> hashTable;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (hashTable.count(target - nums[i]) > 0)
			{
				ans[0] = hashTable[target - nums[i]];
				ans[1] = i;
				return ans;
			}
			hashTable[nums[i]] = i;
		}
		return ans;
    }
};