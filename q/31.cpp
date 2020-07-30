class Solution {
public:
	void nextPermutation(vector<int>& nums) 
	{
		if (nums.size() <= 1)
			return;
		int swapVal = nums.back();
		int swapPos = nums.size() - 1;
		int pos = 0;
		int swapTarget = -1;

		for (pos = nums.size() - 2; pos >= 0; --pos)
		{
			if (nums[pos] < nums[pos + 1])
			{
				swapTarget = pos + 1;
				for (int j = pos + 2; j < nums.size(); ++j)
				{
					if (nums[j] < nums[swapTarget] && nums[j] > nums[pos])
					{
						swapTarget = j;
					}
				}
				break;
			}	
		}
		if (swapTarget == -1)
			sort(nums.begin(), nums.end());
		else
		{
			swap(nums[pos], nums[swapTarget]);
			sort(nums.begin() + pos + 1, nums.end());
		}
	}
};