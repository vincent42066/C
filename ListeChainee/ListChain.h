#ifndef LISTCHAIN_H_INCLUDED
#define LISTCHAIN_H_INCLUDED
// type definition

/* cette structure permet de stocker l'element qu'on veut
mais aussi elle connait l'adresse de l'element suivant */
typedef struct Element Element;
struct Element
{
    //Données
    int age;
    char nom[10];
    char prenom[10];
    char ville[10];



    Element *suivant;
};

/*C'est la structure de contrôle qui contient un
pointeur vers le premier element de la liste "Element"*/
typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

// function prototype
Liste *initialisation(void);
void insertion(Liste *liste, int nvAge, char *nvNom[], char *nvPrenom[], char *nvVille[]);
void suppression(Liste *liste);
void afficherListe(Liste *liste);
void Saisie(Liste *liste);


#endif // LISTCHAIN_H_INCLUDED
