#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** cout;
int dmin;
int pcc = INFINITY;

int nextRand(int iseed){
    // Postcondition : retourne le prochain entier selon une suite pseudo-aleatoire avec la graine iseed
    int i = 16807 * (iseed % 127773) - 2836 * (iseed / 127773);
    if (i > 0) iseed = i;
    else iseed = 2147483647 + i;
    return iseed;
}

int** creeCout(int n){
    // retourne une matrice cout telle que pour tout i,j appartenant à [0,n-1], cout[i][j] = cout de l'arc (i,j)
    int** cout;
    int coutMax = 1000;
    int iseed = 1;
    cout = (int**) malloc(n*sizeof(int*));
    for (int i=0; i<n; i++){
        cout[i] = (int*) malloc(n*sizeof(int));
        for (int j=0; j<n; j++){
            if (i == j) cout[i][j] = coutMax+1;
            else {
                iseed = nextRand(iseed);
                cout[i][j] = 1 + iseed % coutMax;
            }
        }
    }
    return cout;
}

int getBound(int dernier[],int nonVus[] ,int nbNonVus){
    return ((nbNonVus+1) * dmin);
}

void permut(int vus[], int nbVus, int nonVus[], int nbNonVus, int longueur){
    int bound = getBound(vus,nonVus,nbNonVus);
    if(bound>pcc) {
        return;
    }
    if(nbNonVus==0) { // if nonVus is empty
        longueur+=cout[vus[nbVus-1]][vus[0]];
        if(longueur<pcc) {
            pcc = longueur;
        }
       // printf("%d \n", longueur); 
    }
    else {
        int j;
        for(j=0; j < nbNonVus; j++) {
            vus[nbVus] = nonVus[j];
            int temp = nonVus[nbNonVus-1];
            nonVus[j] = temp;
            longueur+=cout[vus[nbVus-1]][vus[nbVus]];
            permut(vus, nbVus+1, nonVus, nbNonVus-1, longueur);
            longueur-=cout[vus[nbVus-1]][vus[nbVus]];
            nonVus[j] = vus[nbVus];
            nonVus[nbNonVus-1] = temp;
            vus[nbVus] = 0;
        }
    }
}

int smallest_arc(int n)
{
   int min = cout[0][0];
   int x,y;

   for (x = 0; x < n; x++)
   {
       for (y = 0; y < n-1; y++)
       {
           if (min > cout[x][y])
           {
               min = cout[x][y];
           }
       } 
   }  

   return min;
}

int main(){
    int nbSommets;
    scanf("%d",&nbSommets);
    cout = creeCout(nbSommets);
    int vus[nbSommets];
    int nonVus[nbSommets-1];
    for (int i=0; i<nbSommets-1; i++) nonVus[i] = i+1;
    vus[0] = 0;
    dmin = smallest_arc(nbSommets);
    permut(vus,1,nonVus,nbSommets-1,0);
    printf("pcc pour %d: %d ", nbSommets, pcc);
}

