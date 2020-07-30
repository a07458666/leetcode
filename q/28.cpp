class Solution {
public:
	int strStr(string haystack, string needle)
	{
		if (needle.empty())	return 0;
		int needleLen = needle.size();
		for (int i = 0; i < haystack.size(); ++i)
		{
			if (haystack[i] == needle[0])
			{
				if (haystack.substr(i, needleLen) == needle)
					return i;
			}
		}
		return -1;
	}
};