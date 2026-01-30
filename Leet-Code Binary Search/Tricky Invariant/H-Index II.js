var hIndex = function(citations) {
    const n = citations.length;
    let left = 0, right = n - 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        const h = n - mid;

        if (citations[mid] >= h) {
            right = mid - 1;   // try to find a smaller index
        } else {
            left = mid + 1;
        }
    }

    return n - left;
};
