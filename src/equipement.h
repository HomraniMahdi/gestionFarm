#include <gtk/gtk.h>




typedef struct
{
int jour;
int mois ;
int annee;
}date1;

typedef struct
{
char type[30];
char id[50];
char pv[250];
date1 dm;
char etat[30];
}equip;



void  ajouter_equipement(equip ne);
void coder(char ch[]);
void supprimer_equipement(char id[50]);
int rech1(char id[50]);
void modifier_equipement(equip ne, char id[50]);
void chercher_equipement(GtkWidget *liste,char id[50]);
void afficher_equipement(GtkWidget *liste,char file[50]);



