#include <stdio.h>

int main(void) {
    int N, D;
    int ans, rem;

    scanf("%d%d", &N, &D);

    ans = N / (D * 2 + 1);
    rem = N % (D * 2 + 1);

    if (rem != 0) {
        ans = ans + 1;
    }

    printf("%d\n", ans);

    return 0;
}