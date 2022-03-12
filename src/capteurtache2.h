#include<gtk/gtk.h>
typedef struct 
{
int jour;
int mois;
int annee;
}date6;
typedef struct 
{
char id_capteur[20];
char marque[20];
char type[20];
char valeur[20];
date6 datef;
date6 datep;
char etat[20];
} capteur1;
void ajouter_capteur1(capteur1 c);
void supprimer_capteur1 (char id_capteur1[]);
void afficher_capteur1(GtkWidget *liste);
void modifier_capteur1(char id_capteur1[]);
int rech1(char id_capteur1[70]);

