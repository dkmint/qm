#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define hbar 1.05459e-34
#define m 9.109534e-31
#define e_0 1.602189e-19

int main()
{
    float dE = 1e-3*e_0;
    float dz = 1e-10;
    float E;
    float psi0, psi1, psi2;
    float z;
    char filename[9];
    FILE *Fout;

    Fout = fopen("Epsi.csv", "w");
    
    for(E=0; E < e_0; E += dE) {
        psi0 = 0;
        psi1 = 1;
        for(z = dz; z < 100e-10; z += dz) {
            psi2 = (2 * m * (dz / hbar) * (dz / hbar) * (e_0 * (z / 100e-10) * (z / 100e-10) - E) + 2) * psi1 - psi0;
            psi0 = psi1;
            psi1 = psi2;
        }
        fprintf(Fout, "%e, %e\n", E/(1e-3*e_0), psi2);
    }
    fclose(Fout);
    return 0;
}

