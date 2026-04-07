int majorityElement(int * nums, int numsSize) {
    int out = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == out) {
            count++;
        } else if (count > 0) {
            count--;
        } else {
            out = nums[i];
            count = 1;
        }
    }

    return out;
}
