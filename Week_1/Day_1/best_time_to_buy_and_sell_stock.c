int maxProfit(int* prices, int pricesSize) {
    int min = prices[0];
    int diff = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < min) min = prices[i];
        int temp = prices[i] - min;
        if (temp > diff) diff = temp;
    }

    return diff;
}
