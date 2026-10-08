int fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    n = n*fatorial(n-1);

    return n;
}