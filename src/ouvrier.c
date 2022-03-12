#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <config.h>
#include "ouvrier.h"
#include "support.h"

enum
{
	ENOM,
	EPRENOM,
	ECIN,
	EADRESSE,
	ESALAIRE_ACTUEL,
	ENUM_TEL,
	EJOUR_EMB,
	EMOIS_EMB,
	EANNEE_EMB,
	EJOUR_NAISS,
	EMOIS_NAISS,
	EANNEE_NAISS,
	ESITUATION_SOCIALE,
	ENATIONALITE,
	ESEXE,
	COLUMNS
};

//*********ajouter_ouvrier***********//
void ajouter_ouvrier(ouvrier ov)
{

  FILE *f;

	f=fopen("ouvrier.txt","a+");
	 if (f!=NULL)
		{
		fprintf(f,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,ov.dt_emb.jour,ov.dt_emb.mois,ov.dt_emb.annee,ov.dt_naiss.jour,ov.dt_naiss.mois,ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe);
	 	fclose(f);
		}
}


//*********supprimer_ouvrier***********//
void supprimer_ouvrier(char cin[50])
{
	FILE*f=NULL;
	FILE*f1=NULL;
	ouvrier ov;
	f=fopen("ouvrier.txt","r");
	f1=fopen("ancien.txt","w+");
	while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,&ov.dt_emb.jour,&ov.dt_emb.mois,&ov.dt_emb.annee,&ov.dt_naiss.jour,&ov.dt_naiss.mois,&ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe)!=EOF){
	if(strcmp(cin,ov.cin)!=0)
	fprintf(f1,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,ov.dt_emb.jour,ov.dt_emb.mois,ov.dt_emb.annee,ov.dt_naiss.jour,ov.dt_naiss.mois,ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe);
	}
	fclose(f);
	fclose(f1);
	remove("ouvrier.txt");
	rename("ancien.txt","ouvrier.txt");
}


int exist_ouvier (char cin[50]){
FILE*f=NULL;
 ouvrier ov;
f=fopen("ouvrier.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,&ov.dt_emb.jour,&ov.dt_emb.mois,&ov.dt_emb.annee,&ov.dt_naiss.jour,&ov.dt_naiss.mois,&ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe)!=EOF){
if(strcmp(ov.cin,cin)==0)return 1;
}
fclose(f);
return 0;
}


//*********modifier_ouvrier***********//
void modifier_ouvrier(char cin[50])
{
ouvrier ov;
	FILE *f;
	FILE *f2;
f=fopen("ouvrier.txt","r");
f2=fopen("ancien.txt","w+"); 
	if (f==NULL)
	return;
	else
	{
	if (f2==NULL)
	return;
	else
	{ 
	  while (fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n", ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,&ov.dt_emb.jour,&ov.dt_emb.mois,&ov.dt_emb.annee,&ov.dt_naiss.jour,&ov.dt_naiss.mois,&ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe)!=EOF)
		{
		 if(strcmp(cin,ov.cin)==0) 
			{ fprintf(f2,"%s %s %s %s %s %d %d %d %d %d %d %s %s %s\n", ov.nom,ov.prenom,ov.adresse,ov.salaire_actuel,ov.num_tel,ov.dt_emb.jour,ov.dt_emb.mois,ov.dt_emb.annee,ov.dt_naiss.jour,ov.dt_naiss.mois,ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe); }
		 else   { fprintf(f2,"%s %s %s %s %s %d %d %d %d %d %d %s %s %s\n", ov.nom,ov.prenom,ov.adresse,ov.salaire_actuel,ov.num_tel,ov.dt_emb.jour,ov.dt_emb.mois,ov.dt_emb.annee,ov.dt_naiss.jour,ov.dt_naiss.mois,ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe); }
		}
	}
fclose(f2);
fclose(f);
remove("ouvrier.txt");
rename("ancien.txt","ouvrier.txt");
	}
}


//*********chercher_ouvrier***********//
void chercher_ouvrier(GtkWidget *liste,char nom[50])
{
	ouvrier ov;
	FILE *f1,*f2;
	f1=fopen("ouvrier.txt","r");
	f2=fopen("ancien.txt","w");
	
	while(!feof(f1))
			{
				fscanf(f1,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,&ov.dt_emb.jour,&ov.dt_emb.mois,&ov.dt_emb.annee,&ov.dt_naiss.jour,&ov.dt_naiss.mois,&ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe);
			if(strcmp(ov.nom,nom)==0)
				fprintf(f2,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n",ov.nom,ov.prenom,ov.cin,ov.adresse,ov.salaire_actuel,ov.num_tel,ov.dt_emb.jour,ov.dt_emb.mois,ov.dt_emb.annee,ov.dt_naiss.jour,ov.dt_naiss.mois,ov.dt_naiss.annee,ov.situation_sociale,ov.nationalite,ov.sexe);
		}
	fclose(f1);
	fclose(f2);
	afficher_ouvrier(liste,"ancien.txt");
	remove("ancien.txt");	
	
}


//*********afficher_ouvrier***********//
void  afficher_ouvrier(GtkWidget *liste,char file[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	FILE *f;
	
	char nom[30];
	char prenom[50];
	char cin[50];
	char adresse[50];
	char num_tel[50];
	char salaire_actuel[50];
	char situation_sociale[30];
	char nationalite[30];
	char sexe[30];
	int JOUR_EMB;
	int MOIS_EMB;
	int ANNEE_EMB;
	int JOUR_NAISS;
	int MOIS_NAISS;
	int ANNEE_NAISS;

ouvrier ov;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("adresse",renderer, "text",EADRESSE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("salaire_actuel",renderer,"text",ESALAIRE_ACTUEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("num_tel",renderer,"text",ENUM_TEL,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("JOUR_EMB",renderer,"text",EJOUR_EMB,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MOIS_EMB",renderer,"text",EMOIS_EMB,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ANNEE_EMB",renderer,"text",EANNEE_EMB,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("JOUR_NAISS",renderer,"text",EJOUR_NAISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("MOIS_NAISS",renderer,"text",EMOIS_NAISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ANNEE_NAISS",renderer,"text",EANNEE_NAISS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("situation_sociale",renderer,"text",ESITUATION_SOCIALE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite",renderer,"text",ENATIONALITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	}

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	
	f = fopen(file,"r");

if(f==NULL)
	{
	return;
	}
else
	{
	while (fscanf(f,"%s %s %s %s %s %s %d %d %d %d %d %d %s %s %s\n", nom, prenom, cin, adresse, salaire_actuel, num_tel, &JOUR_EMB, &MOIS_EMB, &ANNEE_EMB, &JOUR_NAISS, &MOIS_NAISS,&ANNEE_NAISS, situation_sociale, nationalite,sexe)!=EOF)
	


		{
		gtk_list_store_append(store,&iter);

		gtk_list_store_set(store,&iter, ENOM, nom,EPRENOM, prenom, ECIN, cin,EADRESSE, adresse, ESALAIRE_ACTUEL,salaire_actuel,ENUM_TEL,num_tel,EJOUR_EMB,JOUR_EMB,EMOIS_EMB,MOIS_EMB,EANNEE_EMB,ANNEE_EMB,EJOUR_NAISS,JOUR_NAISS,EMOIS_NAISS,MOIS_NAISS,EANNEE_NAISS,ANNEE_NAISS, ESITUATION_SOCIALE, situation_sociale,ENATIONALITE,nationalite,ESEXE,sexe,-1);

		}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);


}	
}

int meilleur_ouvrier1(int x)
{
    FILE* f;
    f=fopen("absenteisme.txt","r");
    int i,tab[10];
    int id,j,m,a,ab,mo,mx=0;
    //printf("donner l'annnee\t");
    //scanf ("%d",&x);
    for (i=0; i<10; i++)
        tab[i]=0;
        if (f!=NULL)
        {
           while (fscanf(f,"%d %d %d %d %d",&id,&j,&m,&a,&ab)!=EOF)
            {
                if ((a==x)&&(ab==0))
                    {
                        tab[id]++;
                    }
            }
        }
    for (i=1 ; i<10;i++)
    {
        if (tab[i]>mx)
        {
            mx=tab[i];
            mo=i;
        }
    }
return (mo);
}





	
	


