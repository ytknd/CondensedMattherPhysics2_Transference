#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "MT.h"


int main (void) {
    int spin_state, hamiltonian, sum_spin = 0, mesh = 10, monte_carlo_step = 500;
    int spin[mesh][mesh];
    double boltmann_temperature = 0.01, reversal_check, random;

    init_genrand ((unsigned) time (NULL));

    for (int i = 0; i < mesh; i++) {
        for (int j = 0; j < mesh; j++) {
            spin_state = 1;

            if (genrand_real1() > 0.5) {
                spin_state = -1;
            }

            spin[i][j] = spin_state;
        }
    }

    for (int i = 0; i < mesh; i++) {
        for (int j = 0; j < mesh; j++) {

            spin[0][j] = 0;
            spin[mesh -1][j] = 0;
            spin[i][0] = 0;
            spin[i][mesh -1] = 0;
        }
    }

    for (int kk = 0; kk < monte_carlo_step; kk++) {
        for (int i= 1; i < mesh - 1; i++) {
            for(int j = 1; j < mesh - 1; j++) {
                hamiltonian = 2 * spin[i][j] * (spin[i - 1][j] + spin[i + 1][j] + spin[i][j - 1] + spin[i][j + 1]);

                reversal_check = exp(-hamiltonian / boltmann_temperature);
                random = genrand_real1();

                if (reversal_check > random) {
                    spin[i][j] *= -1;
                }
            }
        }
    }

    for (int i = 0; i < mesh; i++) {
        for (int j = 0; j < mesh; j++) {
            printf ("%d\t", spin[i][j]);
        }
        printf ("\n");
    }
    printf ("\n");

    for (int i = 0; i < mesh; i++) {
        for (int j = 0; j < mesh; j++) {
            sum_spin += spin[i][j];
        }
    }
    printf ("%d\n", sum_spin);

    return 0;
}