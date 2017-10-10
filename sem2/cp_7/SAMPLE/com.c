#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main(void) {
	float _Complex b;
    float pReal;
    float pImag;
    char sign;
    if (scanf("%f%c%fi",&pReal,&sign,&pImag)==3) {
        if( sign == '-' ) {
            pImag *= -1;
        }
        b = pReal + pImag*I;
        printf("%.3f%+.3fi\n",creal(b),cimag(b));
    } else {
        printf("Failed to read complex.\n");
    }
    return 0;
}
