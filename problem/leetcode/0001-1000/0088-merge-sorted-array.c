void merge(int * nums1, int nums1Size, int m, int * nums2, int nums2Size, int n) {
    int * out = nums1;

    while ((m > 0) || (n > 0)) {
        const int index = m + n - 1;

        if (m <= 0) {
            out[index] = nums2[n - 1];
            n--;
        } else if (n <= 0) {
            out[index] = nums1[m - 1];
            m--;
        } else if (nums1[m - 1] < nums2[n - 1]) {
            out[index] = nums2[n - 1];
            n--;
        } else {
            out[index] = nums1[m - 1];
            m--;
        }
    }
}
