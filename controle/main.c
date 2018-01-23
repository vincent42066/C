#include <stdio.h>
#include <stdlib.h>

typedef struct carte
{
int valeur;
int couleur;
}Carte;

void initjeu(Carte jeu[])
{
    int couleur=0;
    for(int i=0;i<=7;i++)
    {
        jeu[i].valeur = i;

        if (((i % 7) == 0) && i!=0)
        {
        couleur ++;// lorsque on depace 1/4 puis 2/4, etc couleur++
        }
        jeu[i].couleur = couleur;

    }

}

int alea32()
{
    return rand() % (31 - 0 + 1);//nb alea entre 0 et 31
}

void permutte (Carte *carte1, Carte *carte2)
{
 int temp_couleur = carte1->couleur;
 int temp_carte =  carte1->valeur;
 //permutattion des cartes
 carte1->valeur = carte2->valeur;
 carte1->couleur = carte2->couleur;
  carte2->valeur = temp_carte;
 carte2->couleur = temp_couleur;


}

void melange(Carte *jeu[])
{
int nb_permute = 50;

while(nb_permute>0)
{
        //permutation de 2 cartes aléatoire
   permutte(jeu[alea32()], jeu[alea32()]);
    nb_permute --;
}
}

void affiche_carte(Carte X)
{
char type_carte[][10] = {
  "As",
  "Roi",
  "Dame",
  "Valet",
  "10",
  "9",
  "8",
  "7"
};

char type_couleur[][10] = {
  "Coeur",
  "Pique",
  "Carreau",
  "Trefle"
};
int couleur = X.couleur;
int carte = X.valeur;
printf(" Carte = %s \n", type_carte[carte%7]);// 1/4 des cartes du jeu sont différentes
printf("Couleur = %s \n", type_couleur[couleur]);//

}

void affiche(Carte jeu[], int N)
{
for(int i = 0; i<N; i++)
{
    affiche_carte(jeu[i]);
}

}

void distribution(Carte jeu[], Carte jeu1[], Carte jeu2[])
{
int i1 =0;
int i2 = 0;
for(int i=0;i<=31;i++)
{
    if(i%2 ==0)//pair
    {
    jeu1[i1]= jeu[i];
    i1++;
    }
    if(i%2 ==1)//impair
    {
    jeu1[i2]= jeu[i];
    i2++;
    }
}

}

void jouer1coup( Carte jeu1[], Carte jeu2[], int *N1, int *N2)
{}

int main()
{



 Carte jeu[32];
 Carte jeu1[32];
 Carte jeu2[32];
 int N1 = 15;
 int N2 = 15;
 initjeu(jeu);
 affiche_carte(jeu[6]);
 srand(12500);
    return 0;
}
