int missingNumber(int * nums, int numsSize) {
    int out = ((1 + numsSize) * numsSize) >> 1;

    for (int i = 0; i < numsSize; i++) {
        out -= nums[i];
    }

    return out;
}
