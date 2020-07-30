class Solution {
public:
	int romanToInt(string s) {
		vector<string> mappingStr = { "M" , "CM" , "D" , "CD" , "C" , "XC" ,  "L", "XL" , "X" , "IX" , "V" ,"IV", "I" };
		vector<int> mappingNum = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		
		int ans = 0;
		int indexStr = 0;
		string tempStr = "";
		for (int i = 0; i < mappingStr.size(); ++i)
		{
			int len = mappingStr[i].size();
			while (indexStr < s.size())
			{
				if (mappingStr[i] == s.substr(indexStr, len))
				{
					ans += mappingNum[i];
					indexStr += len;
				}
				else
				{
					break;
				}
			}
		}
		return ans;
	}
};