#include <stdio.h>
#define DAYS 365

int main(void) {
    int n, i;
    int nyuyoku_ticket[DAYS], pool_ticket[DAYS];
    int nyuyoku_member[DAYS], pool_member[DAYS];
    int seiki_ryoukin[DAYS], waribiki_ryoukin[DAYS], saiyasune[DAYS];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &nyuyoku_ticket[i], &pool_ticket[i],
              &nyuyoku_member[i], &pool_member[i]);
        if (nyuyoku_member[i] >= 5 && pool_member[i] >= 2) {
            seiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) +
                                 (pool_ticket[i] * pool_member[i])) *
                                8) /
                               10;
            saiyasune[i] = seiki_ryoukin[i];
        } else if (nyuyoku_member[i] >= 5) {
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) +
                               (pool_ticket[i] * pool_member[i]);
            waribiki_ryoukin[i] = (((nyuyoku_ticket[i] * nyuyoku_member[i]) +
                                    (pool_ticket[i] * 2)) *
                                   8) /
                                  10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
                saiyasune[i] = waribiki_ryoukin[i];
            } else {
                saiyasune[i] = seiki_ryoukin[i];
            }
        } else if (pool_member[i] >= 2) {
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) +
                               (pool_ticket[i] * pool_member[i]);
            waribiki_ryoukin[i] =
                (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) *
                 8) /
                10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
                saiyasune[i] = waribiki_ryoukin[i];
            } else {
                saiyasune[i] = seiki_ryoukin[i];
            }
        } else {
            seiki_ryoukin[i] = (nyuyoku_ticket[i] * nyuyoku_member[i]) +
                               (pool_ticket[i] * pool_member[i]);
            waribiki_ryoukin[i] =
                (((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) / 10;
            if (seiki_ryoukin[i] >= waribiki_ryoukin[i]) {
                saiyasune[i] = waribiki_ryoukin[i];
            } else {
                saiyasune[i] = seiki_ryoukin[i];
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d\n", saiyasune[i]);
    }
    return 0;
}