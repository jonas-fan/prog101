static int max(int lhs, int rhs) {
    return (lhs < rhs) ? rhs : lhs;
}

int maxProfit(int * prices, int pricesSize) {
    int out = 0;
    int peak = 0;

    for (int i = pricesSize - 1; i >= 0; i--) {
        peak = max(peak, prices[i]);
        out = max(out, peak - prices[i]);
    }

    return out;
}
