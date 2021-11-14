#include <math.h>
#include "pav_analysis.h"
#include <stdio.h>

float compute_power(const float *x, unsigned int N) {
    //completar (nos debe devolver la potencia en dB)
    float P= 1.e-9;

    for(int i=0; i<N; i++){
        P+=x[i]*x[i]; //*32767*32767;
    }
    return 10*log10(P/N);
}

float compute_am(const float *x, unsigned int N) {
    float A=0;
    for(int i=0; i<N; i++){
        
        A+=fabs(x[i]);

        /*if(x[i]<0){
            A+=x[i]*(-1);
        } else {
            A+=x[i];
        }*/
    }
    return A/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float Z=0;

    for (int i = 1; i < N; i++){
        
        if((x[i]<0 && x[i-1]<0) || (x[i]>0 && x[i-1]>0)){
            Z+=0;
        }else{
            Z += 1;
        }

        /*if(x[i]<0){
            sign[0]=-1;
        } else{
            sign[0]=1;
        }

        if(x[i-1]<0){
            sign[1]=-1;
        } else {                
            sign[1]=1;
        } 

        if(sign[0]!=sign[1]){
            ind=1;
        } else {
            ind=0;
        }*/

    }

    Z=((fm/2)*Z)/(N-1);

    return Z;
}
