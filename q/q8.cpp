class Solution {
public:
	int myAtoi(string str) {
		int sign = 1;
		bool triggerFist = false;
		int ans = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (!triggerFist)
			{
				if (str[i] == ' ')
					continue;
				else if (str[i] == '-')
				{
					sign = -1;
					triggerFist = true;
				}
                else if (str[i] == '+')
				{
					triggerFist = true;
				}
				else if (str[i] >= '0' && str[i] <= '9')
				{
					triggerFist = true;
					ans += (str[i] - '0');
				}
                else
				{
					return 0;
				}
			}
			else
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					if (abs(ans) > INT32_MAX / 10)
						return sign > 0 ? INT32_MAX : INT32_MIN;
					ans *= 10;
					if (abs(ans) > INT32_MAX - abs(str[i] - '0'))
						return sign > 0 ? INT32_MAX : INT32_MIN;
					ans += (str[i] - '0');
				}
				else
				{
					return ans * sign;
				}
			}
		}
		return ans * sign;
	}
};