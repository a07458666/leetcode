class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> ans;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
			return ans;

		for (int i = 0; i < len; i++)
		{
			int head = i + 1;
			int tail = len - 1;
			int target = nums[i];
			if (i > 0 && target == nums[i - 1]) continue;
			while (target <= 0 && head < tail)
			{
				int addNum = nums[head] + nums[tail];
				if (addNum == -target)
				{
					ans.push_back(vector<int>{ target, nums[head], nums[tail] });
					head++;
					tail--;
				}
				else if (addNum < -target)
					head++;
				else
					tail--;
			}
		}
		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		return ans;
	}
};
