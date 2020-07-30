class Solution {
public:
	bool isMatch(string s, string p) 
	{
		if (p.empty())
			return s.empty();
		bool isStar = p.size() >= 2 && p[1] == '*' ? true : false;
		bool canCut = !s.empty() && (s[0] == p[0] || p[0] == '.');

		if (isStar)
		{
			return canCut && isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
		}
		else
		{
			return  canCut && isMatch(s.substr(1), p.substr(1));
		}

		return false;
	}
};