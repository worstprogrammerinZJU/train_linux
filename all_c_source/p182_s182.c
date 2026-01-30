#include <stdio.h>
int main(void) {
    int n, r, p, c;
    int i, j, k, l;
    int a[51], b[51];

    while (1) {
        scanf("%d %d ", &n, &r);
        if (!n && !r) break;

        for (i = 0; i < n; i++) a[i] = i + 1;

        for (i = 0; i < r; i++) {
            scanf("%d %d ", &p, &c);

            for (j = 0; j < c; j++) b[j] = a[n - p - c + 1 + j];
            for (j = 0; j < p - 1; j++) a[n - p - c + 1 + j] = a[n - p + j + 1];
            for (j = n - p - c + 1 + j, k = 0; k < c; j++, k++) {
                a[j] = b[k];
            }
        }
        printf("%d\n", a[n - 1]);
    }
    return 0;
}