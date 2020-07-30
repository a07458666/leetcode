class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> ans(2, -1);
		int head = 0;
		int tail = nums.size();
		int pos = 0;
		if (nums.empty() || target > nums.back() || target < nums.front())
			return ans;
		while (true)
		{
			pos = (head + tail) / 2;
			if (nums[pos] == target)
			{
				ans[0] = pos;
				ans[1] = pos;
				while (ans[0] > 0)
				{
					if (nums[ans[0] - 1] == target)
						ans[0]--;
					else
						break;
				}
				while (ans[1] < nums.size() - 1)
				{
					if (nums[ans[1] + 1] == target)
						ans[1]++;
					else
						break;
				}
				break;
			}
			else if (nums[pos] > target && tail != pos)
				tail = pos;
			else if (head != pos)
				head = pos;
			else
				break;
		} 
		return ans;
	}
};