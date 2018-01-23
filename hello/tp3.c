// Library
#include <stdio.h>
#include <stdlib.h>

//include header
#include"tp3.h"

// function
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
    element->nombre = 0;
    element->suivant = NULL;/* il n'y a pas de 2ème donnée donc
     le contenu du pointeur *suivant est nul */

    //initialisation du pointeur contenu dans la structure liste
    liste->premier = element;

    return liste;
}

void insertion(Liste *liste, int nvNombre)
//pour fonctionner il faut la liste de contrôle et le nvNombre à ajouter
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    //La valeur du nombre de la struct "nouveau" vaut le "nvNombre"
    nouveau->nombre = nvNombre;

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
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
