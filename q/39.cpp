class Solution 
{
	vector<vector<int>> ans;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
	{
        sort(candidates.begin(), candidates.end());
		re(candidates, target, {}, 0);
		return ans;
	}

	void re(vector<int>& candidates, int target, vector<int> use, int start)
	{
		for (int i = start; i < candidates.size(); ++i)
		{
			if (candidates[i] == target)
			{
				use.push_back(candidates[i]);
				ans.push_back(use);
				break;
			}
			else if (candidates[i] < target)
			{
				use.push_back(candidates[i]);
				re(candidates, target - candidates[i], use, i);
				use.pop_back();
			}
			else
			{
				break;
			}
		}
		
	}
};