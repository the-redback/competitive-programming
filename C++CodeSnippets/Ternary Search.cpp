
/*
    some points are given initially. Now, we have to find a area consists
    with K,L no points and third one which area is equal or gretter than S.

*/

int ternary_search(int k, int l, int s) {
    int low = 0, high = v.size() - 1;
    int midleft, midright;

    while (high - low > 3) {
        midleft = low + (high - low) / 3 ;
        midright = high - (high - low ) / 3;

        int area1 = area(k, l, midleft);
        int area2 = area(k, l, midright);

        if ( area1 < area2 )
            low = midleft ;
        else
            high = midright ;
    }

    for (int i = low; i <= high; i++) {
        int temp = area(k, l, i);
        if (s <= temp )
            return i + 1;
    }
    return 0;
}
