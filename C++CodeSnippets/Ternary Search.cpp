/*
    some points are given initially. Now, we have to find a area consists
    with K,L no points and third one which area is equal or gretter than S.

*/

int ternarySearch(int k, int l, int s) {
    int low = 0;
    int high = v.size() - 1;

    while (high - low > 3) {

        int midLeft = low + (high - low) / 3;
        int midRight = high - (high - low) / 3;

        int areaLeft = area(k, l, midLeft);
        int areaRight = area(k, l, midRight);

        if (areaLeft < areaRight) {
            low = midLeft;
        } else {
            high = midRight;
        }
    }

    for (int i = low; i <= high; i++) {
        if (area(k, l, i) >= s) {
            return i;
        }
    }

    return -1;
}