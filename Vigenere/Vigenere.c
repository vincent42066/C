/* Cryptage par la methode de Vigenere */
/* Fichier Vigenere.c */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define CHIFFRER 1
#define DECHIFFRER 2
#define NLIG 26
#define NCOL 26

int choix_traitement (char * msg, char * mot_cle);
void init_table_correspondance (char table_correspondance[][NCOL]);
void chiffre_msg (char * msg, char * mot_cle, char * msg_rslt,
                  char table_correspondance[][NCOL]);
void dechiffre_msg (char * msg, char * mot_cle, char * msg_rslt,
                    char table_correspondance[][NCOL]);

int choix_traitement (char * msg, char * mot_cle)
{
    char c;

    /* Saisie du message à traiter */
    do {
        puts ("Message a traiter : ");
        gets (msg);
    } while (!strcmp (msg, ""));

    /* Saisie du mot cle */
    do {
        puts ("Mot cle : ");
        gets (mot_cle);
    } while (!strcmp (mot_cle, ""));

    /* Saisie du type d'opération à effectuer */
    do {
        puts ("Operation a effectuer : ");
        puts ("Chiffrage : c\nDechiffrage : d");
        c = tolower (getchar ()); /* Conversion en minuscule */
    } while (c != 'c' && c != 'd');
    switch (c)
    {
        case 'c' : return (CHIFFRER);
                break;
        case 'd' : return (DECHIFFRER);
                break;
    }
}

void init_table_correspondance (char table_correspondance[][NCOL])
{
    int c_courant = 'a'-1;
    int i, j;

    for (i = 0; i < NLIG; i++)
        {
            for (j = 0; j < NCOL; j++)
                {
                    if (c_courant >= 'z') c_courant = (c_courant + 1)%'z' + 'a' - 1;
                        else c_courant++;
                    table_correspondance[i][j]= c_courant;
                }
            c_courant ++;
        }
}

void chiffre_msg (char * msg, char * mot_cle, char * msg_rslt,
                  char table_correspondance[][NCOL])
{
    char *c_msg, *c_mot_cle, *c_msg_rslt;
    int i, j;

    c_msg = msg;
    c_mot_cle = mot_cle;
    c_msg_rslt = msg_rslt;

    while (*c_msg != '\0')
    {
        if (*c_msg == ' ' || *c_msg == '?' || *c_msg == '\'')
            {
                *c_msg_rslt = *c_msg;
                c_msg ++;
                c_msg_rslt ++;
            } else
            {
                if (isupper (*c_msg)) i = *c_msg - 'A'; /* caractère à chiffrer est une majuscule */
                    else i = *c_msg - 'a';
                if (isupper (*c_mot_cle)) j = *c_mot_cle - 'A'; /* caractère mot cle est une majuscule */
                    else j = *c_mot_cle - 'a';
                if (isupper (*c_msg))*c_msg_rslt = toupper (table_correspondance[i][j]);
                    else *c_msg_rslt = table_correspondance[i][j];
                c_msg ++;
                c_msg_rslt ++;
                c_mot_cle ++;
                if (* c_mot_cle == '\0') c_mot_cle = mot_cle;
            }
    }
    *c_msg_rslt = '\0';
}

void dechiffre_msg (char * msg, char * mot_cle, char * msg_rslt,
                    char table_correspondance[][NCOL])
{
    char *c_msg, *c_mot_cle, *c_msg_rslt;
    char c;
    int i, j;

    c_msg = msg;
    c_mot_cle = mot_cle;
    c_msg_rslt = msg_rslt;

    c = *c_msg;
    while (c != '\0')
    {
        if (c == ' ' || c == '?' || c == '\'')
            {
                *c_msg_rslt = c;
                c_msg ++;
                c_msg_rslt ++;
                c = *c_msg;
            } else
            {
                if (isupper (*c_mot_cle)) j = *c_mot_cle - 'A'; /* caractère mot cle est une majuscule */
                else j = *c_mot_cle - 'a';
                if (isupper (c)) c = tolower (c); /* Conversion caractère c en minuscule */

                i = 0;
                while (table_correspondance[i][j]!= c) i++;

                if (isupper (*c_msg))*c_msg_rslt = 'A' + i;
                    else *c_msg_rslt = 'a' + i;
                c_msg ++;
                c_msg_rslt ++;
                c_mot_cle ++;
                c = *c_msg;
                if (* c_mot_cle == '\0') c_mot_cle = mot_cle;
            }
    }
    *c_msg_rslt = '\0';
}

int main (void)
{
    char msg[15];
    char msg_rslt [15];
    char mot_cle [10];
    char table_correspondance [NLIG][NCOL];
    int type_traitement;


    init_table_correspondance (table_correspondance);
    type_traitement = choix_traitement (msg, mot_cle);

    printf ("Message initial : %s\n", msg);
    printf ("Mot cle : %s\n",mot_cle);

    switch (type_traitement)
    {
        case CHIFFRER :
            {
            chiffre_msg (msg, mot_cle, msg_rslt,table_correspondance);
            printf ("Message chiffre : %s\n", msg_rslt);
            }
            break;
        case DECHIFFRER :
            {
                dechiffre_msg (msg, mot_cle, msg_rslt,table_correspondance);
                printf ("Message dechiffre : %s\n", msg_rslt);
            }
            break;
    }

    return (0);
}
