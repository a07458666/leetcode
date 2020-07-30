class Solution {
public:
	vector<vector<bool>> row;
	vector<vector<bool>> col;
	vector<vector<bool>> block;
	int len;
	bool solved;
	void solveSudoku(vector<vector<char>>& board)
	{
		solved = false;
		len = board.size();
		row.assign(len, vector<bool>(len + 1, true));
		col.assign(len, vector<bool>(len + 1, true));
		block.assign(len, vector<bool>(len + 1, true));
		int k = 0;
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (board[i][j] == '.')
				{
					continue;
				}
				int val = board[i][j] - 48;
				k = i / 3 + (j / 3 * 3);
				UseData(board, i, j, k, val);
			}
		}
		re(board, 0);
		return;
	}

	void re(vector<vector<char>>& board,int pos)
	{
		if (pos >= len * len)
		{
			solved = true;
			return;
		}			

		int i = pos % len;
		int j = pos / len;

		if (board[i][j] != '.')
		{
			re(board, pos + 1);
		}
		else
		{
			int k = i / 3 + (j / 3 * 3);
			for (int val = 1; val < len + 1; ++val)
			{
				if (checkNum(i, j, k, val))
				{
					UseData(board, i, j, k, val);
					re(board, pos + 1);
					if (!solved)
						backData(board, i, j, k, val);
				}
			}
		}
		return ;
	}

	bool checkNum(int row_index, int col_index, int block_index, int val)
	{
		return row[row_index][val] && col[col_index][val] && block[block_index][val];
	}

	void backData(vector<vector<char>>& board, int i, int j,int k, int val)
	{
		row[i][val] = true;
		col[j][val] = true;
		block[k][val] = true;
		board[i][j] = '.';
	}

	void UseData(vector<vector<char>>& board, int i, int j, int k, int val)
	{
		row[i][val] = false;
		col[j][val] = false;
		block[k][val] = false;
		board[i][j] = val + 48;
	}
};