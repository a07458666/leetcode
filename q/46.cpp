class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> ans;
		if (nums.empty())
			return ans;
		map<int, int> nums_count;
		for (int i = 0; i < nums.size(); ++i)
		{
			nums_count[nums[i]]++;
		}
		rePermute(nums_count, &ans, {});
		return ans;
	}

	void rePermute(map<int, int> nums_count, vector<vector<int>>* ans, vector<int> currect)
	{
		if (nums_count.empty())
		{
			ans->push_back(currect);
		}
		else
		{
			for (std::map<int, int>::iterator it = nums_count.begin(); it != nums_count.end(); it++)
			{
				int val = it->first;
				map<int, int> temp(nums_count);
				temp[val]--;
				if (temp[val] == 0)
					temp.erase(val);
				currect.push_back(val);
				rePermute(temp, ans, currect);
				currect.pop_back();
			}
		}
	}
};