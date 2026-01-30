var findMedianSortedArrays = function(nums1, nums2) {
    if (nums1.length > nums2.length) {
        return findMedianSortedArrays(nums2, nums1);
    }

    let m = nums1.length, n = nums2.length;
    let left = 0, right = m;

    while (left <= right) {
        let i = Math.floor((left + right) / 2);
        let j = Math.floor((m + n + 1) / 2) - i;

        let maxLeftA = (i === 0) ? -Infinity : nums1[i - 1];
        let minRightA = (i === m) ? Infinity : nums1[i];

        let maxLeftB = (j === 0) ? -Infinity : nums2[j - 1];
        let minRightB = (j === n) ? Infinity : nums2[j];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            if ((m + n) % 2 === 0) {
                return (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2;
            } else {
                return Math.max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }
};
