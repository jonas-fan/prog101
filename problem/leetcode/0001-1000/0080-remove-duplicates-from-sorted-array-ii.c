int removeDuplicates(int * nums, int numsSize) {
    int out = 0;
    int seen[200001] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        const int index = nums[i] + 10000;

        if (seen[index] < 2) {
            nums[out++] = nums[i];
        }

        seen[index]++;
    }

    return out;
}
