class Solution {
public:

	bool CheckPalindrome(int begin, int end, string &s)
	{
		int index = 0;
		while (index < (end - begin + 1) / 2)
		{
			if (s[begin + index] != s[end - index])
				return false;
			index++;
		}
		return true;
	}

	string longestPalindrome(string s) 
	{
		if (s.size() <= 1)
			return s;
		int len = s.size();
		int ** strLen;
		string revS(s);
		reverse(revS.begin(), revS.end());
		strLen = new int * [len];
		int ansPos[2] = { 0,0 };
		int maxAnsLen = 0;
		for (int i = 0; i < len; i++)
		{
			strLen[i] = new int[len];
		}
		
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (s[i] == revS[j])
				{
					if (i == 0 || j == 0)
					{
						strLen[i][j] = 1;
					}
					else
					{
						strLen[i][j] = strLen[i - 1][j - 1] + 1;
					}
					if (strLen[i][j] > maxAnsLen)
					{
						if (CheckPalindrome(i - strLen[i][j] + 1, i, s))
						{
							maxAnsLen = strLen[i][j];
							ansPos[0] = i - strLen[i][j] + 1;
							ansPos[1] = i;
						}
					}
				}
				else
				{
					strLen[i][j] = 0;
				}
			}
		}
		
		//showAns(strLen, len);
		for (int i = 0; i < len; i++)
		{
			delete[] strLen[i];
		}
		delete[] strLen;
		return s.substr(ansPos[0], ansPos[1] - ansPos[0] + 1);
	}
};