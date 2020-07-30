class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;
		string ans = "";
		int pos = 0;
		int numRowsIndex = 0;
		bool isEdge = true;
		while (ans.size() != s.size())
		{
			ans += s[pos];
			if (numRowsIndex == 0 || (numRowsIndex == numRows - 1))
				pos += ((2 * numRows) - 2);
			else
			{
				if (isEdge)
					pos += (numRows - (numRowsIndex + 1)) * 2;
				else
					pos += numRowsIndex * 2;
				isEdge = !isEdge;
			}
			if (pos > s.size() - 1)
			{
				isEdge = true;
				numRowsIndex++;
				pos = numRowsIndex;
			}
		}

		return ans;
	}
};