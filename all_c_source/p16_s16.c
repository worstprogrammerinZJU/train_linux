#include <stdio.h>

#define gc() getchar_unlocked()

int in() {
    int n = 0, c = gc();
    do n = 10 * n + (c & 0xf);
    while ((c = gc()) >= '0');
    return n;
}

int f1[100], f2[100];

void calc(int n) {
    int k = n % 10;
    while (n >= 10) n /= 10;
    ++f1[10 * k + n], ++f2[n * 10 + k];
}

int main() {
    int i, N, ans;

    N = in();
    while (N) calc(N--);

    ans = 0;
    for (i = 0; i < 100; ++i) ans += f1[i] * f2[i];
    printf("%d\n", ans);
    return 0;
}