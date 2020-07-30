class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) 
	{
		if (matrix.empty()) return {};
		int left = 0;
		int top = 0;
		int bot = matrix.size();
		int right = matrix[0].size();
		vector<int> ans(matrix[0]);
		int x = right - 1;
		int y = 0;
		int dir = 0;
		while (ans.size() < matrix.size() * matrix[0].size())
		{
			if (dir == 0)
			{
				if (x + 1 >= right)
				{
					dir = (dir + 1) % 4;
					top++;
					continue;
				}
				else
					x++;
			}
			else if (dir == 1)
			{
				if (y + 1 >= bot)
				{
					dir = (dir + 1) % 4;
					right--;
					continue;
				}
				else
					y++;
			}
			else if (dir == 2)
			{
				if (x - 1 < left)
				{
					dir = (dir + 1) % 4;
					bot--;
					continue;
				}
				else
					x--;

			}
			else if (dir == 3)
			{
				if (y - 1 < top)
				{
					dir = (dir + 1) % 4;
					left++;
					continue;
				}
				else
					y--;
			}
			ans.push_back(matrix[y][x]);
		}
		return ans;
	}
};