#include <stdio.h>
#include <stdlib.h>

void permut(int vus[], int nbVus, int nonVus[], int nbNonVus){
    if(nbNonVus==0) { // if nonVus is empty
        int i;
        for(i = 0; i < nbVus; i++)
        {
            printf("%d ", vus[i]); 
        }
        printf("\n ");  
    }
    else {
        int j;
        for(j=0; j < nbNonVus; j++) {
            vus[nbVus] = nonVus[j];
            int temp = nonVus[nbNonVus-1];
            nonVus[j] = temp;
            permut(vus, nbVus+1, nonVus, nbNonVus-1);
            nonVus[j] = vus[nbVus];
            nonVus[nbNonVus-1] = temp;
            vus[nbVus] = 0;
        }
    }
}

int main(){
    int nbSommets, i;
    scanf("%d",&nbSommets);
    int vus[nbSommets], nonVus[nbSommets-1];
    vus[0] = 0;
    for (i=0; i<nbSommets-1; i++)
        nonVus[i] = i+1;
    permut(vus,1,nonVus,nbSommets-1);
}
