class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.size() <= 1)
			return nums.size();
		int ans = 1;
		int p = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] != p)
			{
                nums[ans] = nums[i];
				ans++;
				p = nums[i];
			}
		}
		return ans;
	}
};