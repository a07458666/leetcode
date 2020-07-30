class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) 
	{
		vector<string> ans;
		string temp = "";
		int count = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			if (temp.size() == 0)
			{
				count++;
				temp += words[i];
			}
			else if (temp.size() + words[i].size() + 1 <= maxWidth)
			{
				temp += ' ';
				temp += words[i];
				count++;
			}
			else
			{
				if (temp.find_first_of(' ', 0) == -1)
					fillRightBlank(temp, maxWidth);
				else
					fillBlank(temp, maxWidth, count);
				ans.push_back(temp);
				temp.clear();
				count = 0;
				--i;
			}
		}
		fillRightBlank(temp, maxWidth);
		ans.push_back(temp);
		return ans;
	}

	void fillBlank(string &s, int maxWidth, int wordCount)
	{
		int blankTol = maxWidth - s.size();
		int blankBase = blankTol / (wordCount - 1);
		int overBlank = blankTol % (wordCount - 1);
		int pos = 0;
		string str;
		for (int i = 0; i < wordCount - 1; ++i)
		{
			pos = s.find_first_not_of(' ', pos);
			pos = s.find_first_of(' ', pos);
			if (i < overBlank)
				str.assign(blankBase + 1, ' ');
			else
				str.assign(blankBase, ' ');
			s.insert(s.begin() + pos, str.begin(), str.end());
		}
	}

	void fillRightBlank(string &s, int maxWidth)
	{
		string str(maxWidth - s.size(), ' ');
		s.insert(s.end(), str.begin(), str.end());
	}
};