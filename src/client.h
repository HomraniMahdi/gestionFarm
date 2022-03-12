#include <gtk/gtk.h>


//structure des clients
int s;
int i;
typedef struct 
{ 
int jour;
int mois;
int annee;
}DateC;
typedef struct
{
char nom[100];
char prenom[100];
char cin[20];
char adresse[100];
char num_tel[10];
DateC dt_naiss;
char situation_sociale[50];
char nationalite[50];
char sexe[15];
}client;

//ajouter des clients
void ajouter_client(client c);

//existence des clients
int exist_client (char cin[50]);

//supprimer des clients
void supprimer_client(char cin[50]);

//modifier des clients
void modifier_client(char cin[50]);

//chercher des clients
void chercher_client(GtkWidget *liste,char nom[50]);

//afficher des clients
void afficher_client(GtkWidget *liste,char file[50]);


