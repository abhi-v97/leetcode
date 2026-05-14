#include <algorithm>
#include <limits.h>
#include <vector>

class Solution
{
public:
	double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
	{
		if (nums1.size() > nums2.size())
			return (findMedianSortedArrays(nums2, nums1));

		int low;
		int high;
		int mid1;
		int mid2;
		int l1;
		int l2;
		int r1;
		int r2;
		int total;

		low = 0;
		high = nums1.size();
		total = nums1.size() + nums2.size();

		while (low <= high)
		{
			mid1 = (low + high) >> 1;
			mid2 = ((total + 1) >> 1) - mid1;

			l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
			l2 = (mid1 < nums1.size()) ? nums1[mid1] : INT_MAX;

			r1 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
			r2 = (mid2 < nums2.size()) ? nums2[mid2] : INT_MAX;

			if (l1 <= r2 && r1 <= l2)
			{
				if (total % 2)
					return (std::max(l1, r1));
				else
					return ((std::max(l1, r1) + std::min(l2, r2)) / 2.0);
			}
			else if (l1 > r2)
				high = mid1 - 1;
			else
				low = mid1 + 1;
		}
		return (0);
	}
};

