class Solution {
public:
	vector<vector<int>> generateMatrix(int n) 
	{
		int dir = 0;
		int x = 0;
		int y = 0;
		vector<vector<int>> ans(n, vector<int>(n, 0));
		for (int i = 1; i <= n * n; ++i)
		{
			ans[x][y] = i;
			if (dir == 0)
			{
				y++;
				if (y >= n || ans[x][y] != 0)
				{
					y--;
					dir = (dir + 1) % 4;
					x++;
				}
			}
			else if (dir == 1)
			{
				x++;
				if (x >= n || ans[x][y] != 0)
				{
					x--;
					dir = (dir + 1) % 4;
					y--;
				}
			}
			else if (dir == 2)
			{
				y--;
				if (y < 0 || ans[x][y] != 0)
				{
					y++;
					dir = (dir + 1) % 4;
					x--;
				}
			}
			else if (dir == 3)
			{
				x--;
				if (x < 0 || ans[x][y] != 0)
				{
					x++;
					dir = (dir + 1) % 4;
					y++;
				}
			}
		}
		return ans;
	}
};