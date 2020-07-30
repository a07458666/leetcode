class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		vector<vector<int>> ans;
		int tail = 1;
		if (intervals.empty())
		{
			ans.push_back(newInterval);
			return ans;
		}
		if (intervals.front()[0] > newInterval[1])
		{
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		if (intervals.back()[1] < newInterval[0])
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		int i;
		for (i = 0; i < intervals.size(); ++i)
		{
			if (check(newInterval, intervals[i]))
			{
				intervals[i][1] = max(intervals[i][1], newInterval[1]);
				intervals[i][0] = min(intervals[i][0], newInterval[0]);
				ans.insert(ans.end(), intervals.begin(), intervals.begin() + i);
				while (i + tail < intervals.size() && check(intervals[i], intervals[i + tail]))
				{
					intervals[i][1] = max(intervals[i][1], intervals[i + tail][1]);
					intervals[i][0] = min(intervals[i][0], intervals[i + tail][0]);
					tail++;
				}
				ans.push_back(intervals[i]);
				if (tail != intervals.size())
					ans.insert(ans.end(), intervals.begin() + i + tail, intervals.end());
				break;
			}
			else if (i > 0 &&
				newInterval[0] > intervals[i - 1][1] &&
				newInterval[0] < intervals[i][0] &&
				newInterval[1] > intervals[i - 1][1] &&
				newInterval[0] < intervals[i][0])
			{
				ans.insert(ans.end(), intervals.begin(), intervals.begin() + i);
				ans.push_back(newInterval);
				ans.insert(ans.end(), intervals.begin() + i, intervals.end());
				break;
			}
		}
		return ans;
	}

	bool check(vector<int>& x, vector<int> y)
	{
		return 
			(x[1] >= y[0] && x[1] <= y[1]) ||
			(x[0] >= y[0] && x[0] <= y[1]) ||
			(x[1] >= y[0] && x[0] <= y[0]) ||
			(x[1] >= y[1] && x[0] <= y[1]);
	}
};