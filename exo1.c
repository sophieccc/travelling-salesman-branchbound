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
            if(nonVus[j]!=-1) {
                vus[nbVus] = nonVus[j];
                nonVus[j] = -1;
                nbNonVus--;
                permut(vus, nbVus+1, nonVus, nbNonVus);
                nonVus[j] = vus[nbVus];
                nbNonVus++;
                vus[nbVus] = 0;
            }
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