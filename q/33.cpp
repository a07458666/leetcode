class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		if (nums.empty())
			return -1;
		int pos = nums.size() / 2;
		int tail = nums.back();
		int head = nums.front();
		int move = pos;
		if (target == head)
			return 0;
		if (target == tail)
			return nums.size() - 1;
		while (true)
		{
			move = max(move / 2, 1);
			if (nums[pos] == target)
				return pos;
			else if (nums[pos] > head && target > head && nums[pos] > target)
				pos -= move;
			else if (nums[pos] < head && (target > head || nums[pos] > target))
				pos -= move;
			else
				pos += move;
				
			if (pos <= 0 || pos >= nums.size())
				return -1;
			if (nums[pos - 1] < nums[pos] && target < nums[pos] && nums[pos - 1] < target)
				return -1;
			if (nums[pos - 1] > nums[pos] && (target > nums[pos - 1] || target < nums[pos]))
				return -1;
		}
	}
};