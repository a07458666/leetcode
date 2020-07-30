class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalSize = nums1.size() + nums2.size();
		int index1 = 0;
		int index2 = 0;
		int current = 0;
		double ans = 0;
		vector<int> tempNum((totalSize / 2) + 2, -1);
		while (current < (double)totalSize / 2 + 1)
		{
			if (index2 < nums2.size() && (index1 == nums1.size() || nums1[index1] >= nums2[index2]))
			{
				tempNum[current] = nums2[index2];
				index2++;
			}
			else if (index1 < nums1.size() && (index2 == nums2.size() || nums1[index1] < nums2[index2]))
			{
				tempNum[current] = nums1[index1];
				index1++;
			}
			current++;

		}
		if (totalSize % 2 == 0)
			ans = (double)(tempNum[current - 1] + tempNum[current - 2]) / 2;
		else
			ans = tempNum[current - 2];
		return ans;
	}
};