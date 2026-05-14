from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1_size = len(nums1)
        nums2_size = len(nums2)

        if nums1_size > nums2_size:
            return self.findMedianSortedArrays(nums2, nums1)

        low = 0
        high = nums1_size
        total = nums1_size + nums2_size

        while low <= high:
            mid1 = (low + high) // 2
            mid2 = (total + 1) // 2 - mid1

            l1 = nums1[mid1 - 1] if mid1 > 0 else float('-inf')
            l2 = nums1[mid1] if mid1 < nums1_size else float('inf')

            r1 = nums2[mid2 - 1] if mid2 > 0 else float('-inf')
            r2 = nums2[mid2] if mid2 < nums2_size else float('inf')

            if l1 <= r2 and r1 <= l2:
                if total % 2:
                    return max(l1, r1)
                else:
                    return (max(l1, r1) + min(l2, r2)) / 2.0
            elif l1 > r2:
                high = mid1 - 1
            else:
                low = mid1 + 1
        return 0
