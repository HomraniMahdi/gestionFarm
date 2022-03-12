#include <gtk/gtk.h>


//structure des ouvrier
int s;
int i;
typedef struct 
{ 
int jour;
int mois;
int annee;
}Date;
typedef struct
{
char nom[100];
char prenom[100];
char cin[20];
char adresse[100];
char salaire_actuel[100];
char num_tel[10];
Date dt_emb;
Date dt_naiss;
char situation_sociale[50];
char nationalite[50];
char sexe[15];
}ouvrier;

//ajouter des ouvrier
void ajouter_ouvrier(ouvrier ov);

//existence des ouvrier
int exist_ouvier (char cin[50]);

//supprimer des ouvrier
void supprimer_ouvrier(char cin[50]);

//modifier des ouvrier
void modifier_ouvrier(char cin[50]);

//chercher des ouvrier
void chercher_ouvrier(GtkWidget *liste,char nom[50]);

//afficher des ouvrier
void afficher_ouvrier(GtkWidget *liste,char file[50]);

//meilleur ouvrier

int meilleur_ouvrier1(int x);

