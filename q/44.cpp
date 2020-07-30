class Solution {
public:
		bool isMatch(string s, string p)
	{
		int s_index = 0;
		int p_index = 0;
		string reP = "";
		for (int i = 0; i < p.size(); ++i)
		{
			if (i == 0 || !(p[i] == p[i - 1] && p[i] == '*'))
				reP.push_back(p[i]);
		}
		p = reP;
		if (s.empty() && p.empty())
			return true;
		if (p.size() == 1 && p[0] == '*')
			return true;
		if (s.empty() || p.empty())
			return  false;
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int i = 1; i < p.size(); ++i)
		{
				dp[0][i] = dp[0][i - 1] && p[i - 1] == '*';
		}
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = 1; j <= p.size(); ++j)
			{
				if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
				}
			}
		}
		return dp[s.size()][p.size()];
	}
};