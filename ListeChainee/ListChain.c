// Library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//include header
#include"ListChain.h"

// function

void Saisie(Liste *liste)
{
    int taille = 0, i = 0;
    int age_saisie;
    char nom_saisie[10]= "desnos";
    char prenom_saisie[10] = "vincent";
    char ville_saisie[20] = "perigueux";



    printf("Combien de nombre voulez vous saisir : ");
    scanf(" %d", &taille);

    for (i = 1;i <= taille; i++)
    {
        //printf("gsiohgj = %s", nom_saisie);
        printf("Saisissez l' age %d\n", i);
        scanf(" %d", &age_saisie);

        printf("Saisissez le Nom %d\n", i);
        scanf(" %s", nom_saisie);

        printf("Saisissez le Prenom %d\n", i);
        scanf(" %s", prenom_saisie);

        printf("Saisissez la Ville %d\n", i);
        scanf(" %s", ville_saisie);

        insertion(liste, age_saisie, nom_saisie, prenom_saisie, ville_saisie);
        //insertion(liste, 11, "Marie");
    }
}


Liste *initialisation()
{
    /* Creation de la structure de contrôle et le
    premier élément de la liste.*/
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));
    //Cas d'erreur
    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //initialisation des données contenues dans la structure element
    element->age = 0;
    element->suivant = NULL;/* il n'y a pas de 2ème donnée donc
     le contenu du pointeur *suivant est nul */

    //initialisation du pointeur contenu dans la structure liste
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvAge, char *nvNom[], char *nvPrenom[], char *nvVille[])
//pour fonctionner il faut la liste de contrôle et le nvNombre à ajouter
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //La valeur du nombre de la struct "nouveau" vaut le "nvNombre"
    nouveau->age = nvAge;
    strcpy( nouveau->nom, nvNom);
    strcpy( nouveau->prenom, nvPrenom);
    strcpy( nouveau->ville, nvVille);
    //nouveau->*nom = *nvNom;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;//le contenu du pointeur suivant vaut le premier de liste
    // le contenu du pointeur "premier" vaut "nouveau"
    liste->premier = nouveau;
}

void suppression(Liste *liste)
//il faut seulement la liste de controle
//cette fonction supprimer le 1er element
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        /*on creee l'element *aSuprimer qui
        va pointer sur la première valeur */
        Element *aSupprimer = liste->premier;

        /* le pointeur du 1er element de la
        liste pointe sur le suivant*/
        liste->premier = liste->premier->suivant;
        //supression de l'element aSupprimer
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("Age = %d Nom = %s Prenom = %s Ville = %s -> \n", actuel->age, actuel->nom, actuel->prenom, actuel->ville);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
