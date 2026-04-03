int removeDuplicates(int * nums, int numsSize) {
    int out = 0;
    int seen[201] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        if (seen[nums[i] + 100]) {
            continue;
        }

        seen[nums[i] + 100] = 1;
        nums[out++] = nums[i];
    }

    return out;
}
