void swap(int * lhs, int * rhs) {
    const int tmp = *lhs;

    *lhs = *rhs;
    *rhs = tmp;
}

void moveZeroes(int * nums, int numsSize) {
    int * pos = &nums[0];

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            swap(&nums[i], pos);
            pos++;
        }
    }
}
