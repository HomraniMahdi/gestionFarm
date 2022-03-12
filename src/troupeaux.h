#ifndef TROUPEAUX_H_INCLUDED
#define TROUPEAUX_H_INCLUDED
#include <gtk/gtk.h>

typedef struct date
{
    int jour;
    int mois;
    int annee;
}date3;
 struct troupeaux
{
    char type[100];
    char genre[100];
    char etat[100];
    date3 date_de_naissance;
    char id[100];
};
typedef struct troupeaux troupeaux;
void ajout_troupeaux(troupeaux t);
void supprimer_troupeaux(char Ident[100]);
void modifier_troupeaux(troupeaux t, char j[],char m[],char a[]);
/*void recherche_troupeaux(troupeaux t);*/
void afficher_troupeaux(GtkWidget *liste);
int nombre_troupeau(char type[100]);
int exist_troupeaux (char id[50]);/*
int controlesaisie(troupeaux t);*/


#endif // TROUPEAUX_H_INCLUDED

