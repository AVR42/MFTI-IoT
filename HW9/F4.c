void print_digit(char s[]) {
    int count[10] = {}, i = 0;
    while (s[i])
        if (s[i] >= '0' && s[i] <= '9')
            count[s[i++]-'0']++;
        else i++;

    for (i = 0; i < 10; i++)
        if (count[i])
            printf("%d %d\n", i, count[i]);
}
