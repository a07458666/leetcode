class Solution {
public:
	int searchInsert(vector<int>& nums, int target) 
	{
		int ans = 0;
		int head = 0;
		int tail = nums.size();
		int mid = 0;
		if (nums.empty())
			return ans;
		else if (target < nums.front())
			return 0;
		else if (target > nums.back())
			return nums.size();
		while (true)
		{
			mid = (head + tail) / 2;
			if (nums[mid] == target)
			{
				ans = mid;
				break;
			}
			else if (nums[mid] > target && tail != mid)
				tail = mid;
			else if (head != mid)
				head = mid;
			else
			{
				ans = head + 1;
				break;
			}	
		}
		return ans;
	}
};