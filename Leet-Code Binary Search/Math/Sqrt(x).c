int mySqrt(int x) {
    if (x < 2) return x;

    long long left = 1, right = x / 2;
    int ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == x) {
            return (int)mid;
        } else if (square < x) {
            ans = mid;        // mid is a valid candidate
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
