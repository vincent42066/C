#include <stdio.h>
#include <stdlib.h>
#include"tp3.h"





int main()
{
    //création de la structure de contrôle
    Liste *maListe = initialisation();
    //insertion d'un element
    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    suppression(maListe);

    afficherListe(maListe);

    return 0;
}
