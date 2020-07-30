class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		if (obstacleGrid.empty())
			return 0;
		vector<vector<long long>>count(obstacleGrid.size(), vector<long long>(obstacleGrid[0].size(), 0));
		if (obstacleGrid[0][0] != 1)
			count[0][0] = 1;
		for (int i = 0; i < obstacleGrid.size(); ++i)
		{
			for (int j = 0; j < obstacleGrid[0].size(); ++j)
			{
				if (obstacleGrid[i][j] == 1)
					continue;
				if (i > 0 && j > 0)
					count[i][j] = count[i - 1][j] + count[i][j - 1];
				else if (i > 0)
					count[i][j] = count[i - 1][j];
				else if (j > 0)
					count[i][j] = count[i][j - 1];
			}
		}
		return count.back().back();
	}
};