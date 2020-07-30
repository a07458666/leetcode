class Solution {
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int lenRow = matrix.size() / 2;
		int lenCol = 0;
		if (matrix.size() % 2 == 0)
			lenCol = matrix.size() / 2;
		else
			lenCol = (matrix.size() + 1) / 2;
			
		int size = matrix.size() - 1;
		for (int i = 0; i < lenRow; ++i)
		{
			for (int j = 0; j < lenCol; ++j)
			{
				swap(matrix[i][j], matrix[j][size - i]);
				swap(matrix[i][j], matrix[size - i][size - j]);
				swap(matrix[i][j], matrix[size - j][i]);
			}
		}
	}
};