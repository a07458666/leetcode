class Solution {
public:
	string getPermutation(int n, int k) 
	{
		string ans = "";
		k--;
		map<int, int> factorial;
		vector<int> temp;
		factorial[1] = 1;
		for (int i = 2; i <= n; ++i)
			factorial[i] = factorial[i - 1] * i;
		for (int i = 0; i < n; ++i)
			temp.push_back(i + 1);
		for (int i = 1; i < n; ++i)
		{
			ans.push_back(temp[k / factorial[n - i]] + '0');
			temp.erase(temp.begin() + k / factorial[n - i], temp.begin() + k / factorial[n - i] + 1);
			k = k % factorial[n - i];
		}
		ans.push_back(temp[0] + '0');
		return ans;
	}
};