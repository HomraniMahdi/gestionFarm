#include<gtk/gtk.h>
typedef struct 
{
int jour;
int mois;
int annee;
}date;
typedef struct 
{
char id_capteur[20];
char marque[20];
char type[20];
char valeur[20];
date datef;
date datep;
char etat[20];
} capteur;
void chercher_marque(char file[100],char ch[20]);
void capteurTH();
