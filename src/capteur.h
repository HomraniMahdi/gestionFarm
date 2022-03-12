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
void ajouter_capteur(capteur c);
void supprimer_capteur (char id_capteur[]);
void afficher_capteur(GtkWidget *liste);
void modifier_capteur(char id_capteur[]);
int rech(char id_capteur[70]);

