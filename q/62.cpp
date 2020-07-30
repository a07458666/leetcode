class Solution {
public:
	int uniquePaths(int m, int n) 
	{
		if (m == 0 || n == 0)
			return 0;
		vector <vector<int>> pathCount(m, vector<int>(n, 0));
		pathCount[0][0] = 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i > 0 && j > 0)
					pathCount[i][j] = pathCount[i - 1][j] + pathCount[i][j - 1];
				else if (i > 0)
					pathCount[i][j] = pathCount[i - 1][j];
				else if (j > 0)
					pathCount[i][j] = pathCount[i][j - 1];
			}
		}
		return pathCount[m - 1][n - 1];
	}
};