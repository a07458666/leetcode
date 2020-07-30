class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) 
	{
		int len = board.size();
		vector<vector<bool>> row(len, vector<bool>(len + 1, false));
		vector<vector<bool>> col(len, vector<bool>(len + 1, false));
		vector<vector<bool>> block(len, vector<bool>(len + 1, false));
		int k = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (board[i][j] == '.')
					continue;
				int val = board[i][j] - 49;
				if (!row[i][val])
					row[i][val] = true;
				else
					return false;
				if (!col[j][val])
					col[j][val] = true;
				else
					return false;
				k = i / 3 + (j / 3 * 3);
				if (!block[k][val])
					block[k][val] = true;
				else
					return false;
			}
		}
		return true;
	}
};