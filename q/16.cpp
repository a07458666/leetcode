
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.size() < 3)
			return 0;
		int ans = nums[0] + nums[1] + nums[2];

		for (int i = 0; i < len; i++)
		{
			int head = i + 1;
			int tail = len - 1;
			int val = nums[i];
			if (i > 0 && val == nums[i - 1]) continue;
			while (head < tail)
			{
				int addNum = nums[head] + nums[tail];
				if (addNum + val == target)
				{
					return target;
				}
				else 
				{
					if (abs(addNum + val - target) < abs(ans - target))
					{
						ans = addNum + val;
					}

					if (addNum + val < target)
						head++;
					else
						tail--;
				}
			}
		}
		return ans;
	}
};