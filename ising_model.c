#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "MT.h"

int main (void) {
    int screen = 2, cls = 3, m = 10, b = 0, im = m * m, ax0 = 0, ay0 = 100, ss, sf, s0, s1, sum_spin;
    int jp1, jm1, ip1, im1, imax = 10, jmax = 10;
    int s[20][20], r[5][2];
    double kt = 10, ex, random;

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

            s[0][j] = 1;
            s[m -1][j] = 1;
            s[i][0] = 1;
            s[i][m -1] = 1;
        }
    }

    for (int kk = 0; kk < 500; kk++) {
        for (int i= 1; i < m - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                sf = 2 * s[i][j] * (s[i - 1][j] + s[i + 1][j] + s[i][j - 1] + s[i][j + 1]);

                ex = exp(-sf / kt);
                random = genrand_real1();

                if (ex > random) {
                    s[i][j] *= -1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf ("%d\t", s[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum_spin += s[i][j];
        }
    }
    printf ("%d\n", sum_spin);

    return 0;
}