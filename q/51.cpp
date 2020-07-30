class Solution {
public:
	vector<vector<string>> solveNQueens(int n) 
	{
		vector<vector<string>> ans;
		vector<string> board(n, string(n, '.'));
		for (int i = 0; i < n; ++i)
		{
			board[0][i] = 'Q';
			reQueens(ans, board, 1);
			board[0][i] = '.';

		}
		return ans;
	}

	void reQueens(vector<vector<string>>& ans, vector<string>& board, int level)
	{
		int n = board.size();
		if (level == n)
		{
			ans.push_back(board);
			return;
		}
		else if (level > n)
			return;

		for (int i = 0; i < n; ++i)
		{
			if (check(board, level, i))
			{
				board[level][i] = 'Q';
				reQueens(ans, board, level + 1);
				board[level][i] = '.';

			}
		}
	}

	bool check(vector<string>& board, int row, int col)
	{
		for (int i = 0; i <col; ++i)
			if (board[row][i] == 'Q')	return false;
		for (int i = 0; i < board.size(); ++i)
			if (board[i][col] == 'Q')	return false;
		int x = row - 1;
		int y = col - 1;
		while (x >= 0 && y >= 0)
		{
			if (board[x][y] == 'Q') return false;
			x--;
			y--;
		}
		x = row - 1;
		y = col + 1;
		while (x >= 0 && y < board.size())
		{
			if (board[x][y] == 'Q') return false;
			x--;
			y++;
		}
		return true;
	}
};