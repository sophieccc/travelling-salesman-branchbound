#include <stdio.h>
#include <stdlib.h>

int** cout;
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

void permut(int vus[], int nbVus, int nonVus[], int nbNonVus, int longueur){
    /*
     Variable globale :
     - pour tout couple de sommets (i,j), cout[i][j] = cout pour aller de i vers j
     Entree :
     - nonVus[0..nbNonVus-1] = sommets non visites
     - vus[0..nbVus-1] = sommets visites
     Precondition :
     - nbVus > 0 et Vus[0] = 0 (on commence toujours par le sommet 0)
     - longueur = somme des couts des arcs du chemin <vus[0], vus[1], ..., vus[nbVus-1]>
     Postcondition : affiche les longueurs de tous les circuits commençant par vus[0..nbVus-1] et se terminant par les sommets de nonVus[0..nbNonVus-1] (dans tous les ordres possibles), suivis de 0
     */
    // ECRIVEZ VOTRE CODE ICI :-)
}

int main(){
    int nbSommets;
    scanf("%d",&nbSommets);
    cout = creeCout(nbSommets);
    int vus[nbSommets];
    int nonVus[nbSommets-1];
    for (int i=0; i<nbSommets-1; i++) nonVus[i] = i+1;
    vus[0] = 0;
    permut(vus,1,nonVus,nbSommets-1,0);
}

