#include <limits.h>

double max(double a, double b)
{
	return a > b ? a : b;
}

double min(double a, double b)
{
	return a < b ? a : b;
}

/**
 * instead of combining two arrays, sorting them, and getting the median,
 * we can use binary search to find the mid point in both arrays
 *
 * l1 and r1 are the numbers around the mid point of the first array, l2 and r2 are of the second
 * array
 *
 * if l1 <= r2, it means the number to the left of the midpoint of the first array is smaller than
 * the number to the right side of the midpoint of the second array
 *
 * if l1 <= r2 and l2 <= r1, it means we've found the midpoint and the
 * left and right sides of both arrays are balanced
 */
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
	// perform binary search on the smaller array to minimise search space.
	// swap if nums1 is larger.
	if (nums1Size > nums2Size)
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);

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
	high = nums1Size;
	total = nums1Size + nums2Size;
	while (low <= high)
	{
		mid1 = (low + high) / 2;
		mid2 = ((total + 1) / 2) - mid1;

		l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
		r1 = (mid1 < nums1Size) ? nums1[mid1] : INT_MAX;

		l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
		r2 = (mid2 < nums2Size) ? nums2[mid2] : INT_MAX;

		if (l1 <= r2 && l2 <= r1)
		{
			if (total % 2)
				return (max(l1, r1));
			else
				return ((max(l1, r1) + min(l2, r2)) / 2.0);
		}
		else if (l1 > r2)
			high = mid1 - 1;
		else
			low = mid1 + 1;
	}
	return (0);
}
