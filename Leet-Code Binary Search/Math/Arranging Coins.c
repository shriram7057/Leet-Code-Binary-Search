int arrangeCoins(int n) {
    long long left = 0, right = n;
    int ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long coins = mid * (mid + 1) / 2;

        if (coins <= n) {
            ans = mid;          // mid rows can be completed
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
