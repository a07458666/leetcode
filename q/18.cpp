class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int>> ans;
		int len = nums.size();
		if (nums.empty() || len < 4)
			return ans;
		sort(nums.begin(), nums.end());

		for (int left = 0; left < len; ++left)
		{
			for (int right = len - 1; right > left; --right)
			{
				int head = left + 1;
				int tail = right - 1;
				if (left > 0 && nums[left] == nums[left - 1]) continue;
				if (right < len - 1 && nums[right] == nums[right + 1]) continue;
				while (head < tail)
				{
					int addNum = nums[left] + nums[head] + nums[tail] + nums[right];
					if (addNum == target)
					{
						ans.push_back(vector<int>{  nums[left], nums[head], nums[tail], nums[right] });
						head++;
						tail--;
					}
					else if (addNum < target)
						head++;
					else
						tail--;
				}
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
};