class Solution 
{
public:
	int firstMissingPositive(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		int target = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] <= 0)
				continue;
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] == target)
				target++;
			else
				break;
		}
		return target;
	}
};