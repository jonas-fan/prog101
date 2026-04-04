static int * reverse(int * array, int size) {
    for (int i = 0; i < (size >> 1); i++) {
        const int tmp = array[i];

        array[i] = array[size - i - 1];
        array[size - i - 1] = tmp;
    }

    return array;
}

int * plusOne(int * digits, int digitsSize, int * returnSize) {
    *returnSize = 0;

    int * out = (int *)calloc(digitsSize + 1, sizeof(int));
    int carry = 1;

    for (int i = digitsSize - 1; i >= 0; i--) {
        const int digit = digits[i] + carry;

        out[(*returnSize)++] = digit % 10;
        carry = digit / 10;
    }

    if (carry) {
        out[(*returnSize)++] = carry;
    }

    return reverse(out, *returnSize);
}
