class Solution {
public:
	bool isNumber(string s) 
	{
		if (s.empty())
			return false;
		string rs(s);
		reverse(rs.begin(), rs.end());
		int pos_not = s.find_first_not_of(" ", 0);
		if (pos_not == -1)
			return false;
		int pos_not_re =s.size() - rs.find_first_not_of(" ", 0);
		bool hasSymol = false;
		bool hasExp = false;
		bool hasPoint = false;
		bool hasNum = false;
		bool isZero = false;
		for (int i = pos_not; i < pos_not_re; ++i)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				if (!hasSymol && !hasNum)
					hasSymol = true;
				else
					return false;
			}
			else if (s[i] == 'e')
			{
				if (!hasExp && hasNum)
				{
					hasExp = true;
					hasSymol = false;
					hasPoint = true;
					hasNum = false;
					isZero = false;
				}
				else
					return false;
			}
			else if (s[i] == '.')
			{
				if (!hasPoint)
				{
					hasPoint = true;
					isZero = false;
					hasSymol = true;
				}
				else
					return false;
			}
			else if (s[i] == ' ')
			{
				return false;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				hasNum = true;
				if (s[i] == '0')
				{
					isZero = true;
				}
			}
			else
				return false;
		}
		if (hasExp && !hasNum)
		{
			return false;
		}
		if (!hasNum)
		{
			return false;
		}
		return true;
	}
};