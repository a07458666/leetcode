class Solution {
public:
	string simplifyPath(string path) 
	{
		string ans;
		vector<string> d;
		int posBegin = 0;
		int posEnd = 0;
		int pointCount = 0;
		bool hasS = false;
		string dName;
		while (posBegin < path.size())
		{
			dName.clear();
			pointCount = 0;
			posBegin = path.find_first_not_of("/", posBegin);
			if (posBegin == -1)
				break;
			posEnd = path.find_first_of("/", posBegin + 1);
			if (posEnd == -1)
				posEnd = path.size();
			hasS = false;
			for (int i = posBegin; i < posEnd; ++i)
			{
				
				if (path[i] == '.')
					pointCount++;
				else
					hasS = true;
				dName.push_back(path[i]);
			}
			if (hasS)
				d.push_back(dName);
			else if (d.size() > 0 && pointCount == 2)
				d.pop_back();
			else if (pointCount == 3)
				d.push_back("...");
			posBegin = posEnd + 1;
		}
		for (int i = 0; i < d.size(); ++i)
		{
			ans += '/';
			ans += d[i];
		}
		if (ans.empty())
			ans.push_back('/');
		return ans;
	}
};