#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MT.h"

int main (void) {
    int screen = 2, cls = 3, m = 10, b = 0, im = m * m, ax0 = 0, ay0 = 100, ss, sf, s0, s1;
    int jp1, jm1, ip1, im1;
    int s[20][20], r[5][2];
    double jj = 0.25;

    init_genrand ((unsigned) time (NULL));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ss = 1;

            if (genrand_real1() > 0.5) {
                ss = -1;
            }

            s[i][j] = ss;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%d\t", s[i][j]);
        }
        printf ("\n");
    }

    return 0;
}