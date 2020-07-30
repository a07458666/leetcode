class Solution {
public:
	int lengthOfLastWord(string s) 
	{
		reverse(s.begin(), s.end());
		int pos_not = s.find_first_not_of(" ", 0);
		if (pos_not == -1)
			pos_not = s.size();
		int pos = s.find_first_of(" ", pos_not);
		if (pos == -1)
			pos = s.size();
		return pos - pos_not;
	}
};