class Solution {
public:
	bool canJump(vector<int>& nums) 
	{
		vector<bool> canGo(nums.size(), false);
		int max_val = 0;
		int max_pos = 0;
		if (nums.empty()) return false;
		if (nums.size() == 1) return true;
		while(max_pos < nums.size())
		{
			int i = max_pos;
			for (int j = 1; j <= nums[i]; ++j)
			{
				if (i + j + nums[i + j] >= nums.size() - 1)
					return true;
				if (i + j + nums[i + j] > max_val)
				{
					max_val = i + j + nums[i + j];
					max_pos = i + j;
				}
			}
			if (max_val >= nums.size() - 1)
				return true;
			if (i == max_pos)
				return false;
		}
		return false;
	}
};