int searchInsert(int * nums, int numsSize, int target) {
    int begin = 0;
    int end = numsSize;

    while (begin < end) {
        const int index = (begin + end) >> 1;

        if (nums[index] == target) {
            return index;
        } else if (nums[index] < target) {
            begin = index + 1;
        } else {
            end = index;
        }
    }

    return begin;
}
