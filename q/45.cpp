class Solution {
public:
	int jump(vector<int>& nums) 
	{
		int ans = 0;
		int index = 0;
		while (index < nums.size() - 1)
		{
			int max_val = 0;
			int max_pos = 0;
			for (int j = nums[index]; j > 0; --j)
			{
				int pos = index + j;
				if (pos >= nums.size() - 1)
					return ans + 1;
				if (nums[pos] + pos > max_val)
				{
					max_val = nums[pos] + pos;
					max_pos = pos;
				}
			}
			ans++;
			index = max_pos;
		}
		return ans;
	}
};
