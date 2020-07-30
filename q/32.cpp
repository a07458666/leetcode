class Solution {
public:
		int longestValidParentheses(string s)
	{
		vector<string> stackVal;
		vector<int> stackPos;
		vector<int> dp(s.size(), 0);
		int maxLen = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				stackVal.push_back("(");
				stackPos.push_back(i);
			}
			else if (s[i] == ')' && !stackVal.empty())
			{
				if (stackPos.back() == 0)
					dp[i] = dp[i - 1] + 2;
				else
					dp[i] = dp[i - 1] + dp[stackPos.back() - 1] + 2;
				maxLen = dp[i]  > maxLen ? dp[i] : maxLen;
				stackVal.pop_back();
				stackPos.pop_back();
				
			}
		}
		return maxLen;
	}
};