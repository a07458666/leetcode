class Solution {
public:
	int totalNQueens(int n)
	{
		int ans = 0;
		vector<bool> col(n, false);
		vector<bool> slashL(2 * n, false);
		vector<bool> slashR(2 * n, false);

		reQueens(ans, col, slashL, slashR, 0);

		return ans;
	}

	void reQueens(int& ans,vector<bool>& col, vector<bool>& slashL, vector<bool>& slashR, int level)
	{
		int n = col.size();
		if (level == n)
		{
			ans++;
			return;
		}
		else if (level > n)
			return;

		for (int i = 0; i < n; ++i)
		{
			int z = level + i;
			int w = level - i + n - 1;
			if (check(col, slashL, slashR, level, i))
			{
				col[i] = slashL[z] = slashR[w] = true;
				reQueens(ans, col, slashL, slashR, level + 1);
				col[i] = slashL[z] = slashR[w] = false;
			}
		}
	}

	bool check(vector<bool>& col, vector<bool>& slashL, vector<bool>& slashR, int rowIndex, int colIndex)
	{
		int z = rowIndex + colIndex;
		int w = rowIndex - colIndex + col.size() - 1;
		if (col[colIndex] || slashL[z] || slashR[w])
			return false;
		else
			return true;
	}
};