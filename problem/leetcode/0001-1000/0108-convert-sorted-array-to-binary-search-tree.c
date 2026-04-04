/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct TreeNode * makeTree(int * nums, int begin, int end) {
    if (begin >= end) {
        return NULL;
    }

    const int mid = (begin + end) >> 1;
    struct TreeNode * out = calloc(1, sizeof(struct TreeNode));

    out->val = nums[mid];
    out->left = makeTree(nums, begin, mid);
    out->right = makeTree(nums, mid + 1, end);

    return out;
}

struct TreeNode * sortedArrayToBST(int * nums, int numsSize) {
    return makeTree(nums, 0, numsSize);
}
