// Library
#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

// type definition

/* cette structure permet de stocker l'element qu'on veut
mais aussi elle connait l'adresse de l'element suivant */
typedef struct Element Element;
struct Element
{
    //Données
    int nombre;


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
void insertion(Liste *liste, int nvNombre);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

#endif // TP3_H_INCLUDED
