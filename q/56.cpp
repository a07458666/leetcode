class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) 
	{
		vector<vector<int>> ans;
		if (intervals.size() <= 1) return intervals;
		int head = 0;
		int tail = 1;
		sort(intervals.begin(), intervals.end());
		while (tail < intervals.size())
		{
			if (check(intervals[head], intervals[tail]))
			{
				intervals[head][1] = max(intervals[tail][1], intervals[head][1]);
				intervals[head][0] = min(intervals[tail][0], intervals[head][0]);
			}
			else
			{
				ans.push_back(intervals[head]);
				head = tail;
			}
			tail++;
		}
		ans.push_back(intervals[head]);
		return ans;
	}

	bool check(vector<int>& x, vector<int>& y)
	{
		return (x[1] >= y[0] && x[0] <= y[0]);
	}
};