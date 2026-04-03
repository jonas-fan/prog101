int removeElement(int * nums, int numsSize, int val) {
    int out = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            continue;
        }

        nums[out++] = nums[i];
    }

    return out;
}
