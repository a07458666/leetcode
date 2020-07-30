class Solution {
public:
	bool isValid(string s) 
	{
		vector<char> stack;
		map<int, int> mapping
		{ 
			{ '{' , '}' },
			{ '(' , ')' },
			{ '[' , ']' }
		};
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')
			{
				stack.push_back(s[i]);
			}
			else
			{
				if (stack.size() > 0 && mapping[stack.back()] == s[i])
					stack.pop_back();
				else
					return false;
			}
		}
		return stack.empty();
	}
};