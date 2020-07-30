class Solution {
public:
	string intToRoman(int num) 
	{
		string ans = "";
		vector<string> str = { "I", "V", "IX", "IV",
								"X", "L", "XC", "XL",
								"C", "D", "CM","CD",
								"M" };
		int temp = 0;
		int typeCount = 4;
		for (int i = 0; i < 4; i++)
		{
			string tempStr = "";
			temp = num % 10;
			num /= 10;
			if (temp == 9)
			{
				tempStr = tempStr + str[2 + (i * typeCount)];
			}
			else if (temp == 4)
			{
				temp -= 4;
				tempStr = tempStr + str[3 + (i * typeCount)];
			}
			else if (temp >= 5)
			{
				temp -= 5;
				tempStr = tempStr + str[1 + (i * typeCount)];
				while (temp > 0)
				{
					temp--;
					tempStr = tempStr + str[0 + (i * typeCount)];
				}
			}
			else
			{
				while (temp > 0)
				{
					temp--;
					tempStr = tempStr + str[0 + (i * typeCount)];
				}
			}
			ans = tempStr + ans;
		}
		return ans;
	}
};