void sort_even_odd(int n, int a[]) {
    int even_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            even_count++;
        }
    }

    int temp[n];
    int even_pos = 0;
    int odd_pos = even_count;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[even_pos++] = a[i];
        } else {
            temp[odd_pos++] = a[i];
        }
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}
