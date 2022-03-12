#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <config.h>
#include "client.h"
#include "support.h"

enum
{
	ENOM,
	EPRENOM,
	ECIN,
	EADRESSE,
	ENUM_TEL,
	EJOUR_NAISS,
	EMOIS_NAISS,
	EANNEE_NAISS,
	ESITUATION_SOCIALE,
	ENATIONALITE,
	ESEXE,
	COLUMNS
};

//*********ajouter_client***********//
void ajouter_client(client c)
{

  FILE *f;

	f=fopen("client.txt","a+");
	 if (f!=NULL)
		{
		fprintf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,c.dt_naiss.jour,c.dt_naiss.mois,c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe);
	 	fclose(f);
		}
}


//*********supprimer_client***********//
void supprimer_client(char cin[50])
{
	FILE*f=NULL;
	FILE*f1=NULL;
	client c;
	f=fopen("client.txt","r");
	f1=fopen("ancien.txt","w");
	while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,&c.dt_naiss.jour,&c.dt_naiss.mois,&c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe)!=EOF){
	if(strcmp(cin,c.cin)!=0)
	fprintf(f1,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,c.dt_naiss.jour,c.dt_naiss.mois,c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe);
	}
	fclose(f);
	fclose(f1);
	remove("client.txt");
	rename("ancien.txt","client.txt");
	

}


int exist_client (char cin[50])
{
	FILE *f;
	int x=0;
	client c;
	f=fopen("client.txt","a+");
	if(f==NULL)
		x=1;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,&c.dt_naiss.jour,&c.dt_naiss.mois,&c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe)!=EOF)
		{
			if(strcmp(cin,c.cin)==0)
				x=1;
	
		}
	}
	fclose(f);
	return(x);

}


//*********modifier_clientr***********//
void modifier_client(char cin[50])
{
client c;
	FILE *f;
	FILE *f2;
f=fopen("client.txt","r");
f2=fopen("ancien1.txt","w+"); 
	if (f==NULL)
	return;
	else
	{
	if (f2==NULL)
	return;
	else
	{ 
	  while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,&c.dt_naiss.jour,&c.dt_naiss.mois,&c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe)!=EOF)
		{
		 if(strcmp(cin,c.cin)==0) 
			{ fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,c.dt_naiss.jour,c.dt_naiss.mois,c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe); }
		 else   { fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,c.dt_naiss.jour,c.dt_naiss.mois,c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe); }
		}
	}
fclose(f2);
fclose(f);
remove("client.txt");
rename("ancien1.txt","client.txt");
	}
}


//*********chercher_client***********//
void chercher_client(GtkWidget *liste,char nom[50])
{
	client c;
	FILE *f1,*f2;
	f1=fopen("client.txt","r");
	f2=fopen("ancien2.txt","w");
	
	while(!feof(f1))
			{
				fscanf(f1,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,&c.dt_naiss.jour,&c.dt_naiss.mois,&c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe);
			if(strcmp(c.nom,nom)==0)
				fprintf(f2,"%s %s %s %s %s %d %d %d %s %s %s\n",c.nom,c.prenom,c.cin,c.adresse,c.num_tel,c.dt_naiss.jour,c.dt_naiss.mois,c.dt_naiss.annee,c.situation_sociale,c.nationalite,c.sexe);
		}
	fclose(f1);
	fclose(f2);
	afficher_client(liste,"ancien2.txt");
	remove("ancien2.txt");	
	
}


//*********afficher_client***********//
void  afficher_client(GtkWidget *liste,char file[50])
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
	char situation_sociale[30];
	char nationalite[30];
	char sexe[30];
	int JOUR_NAISS;
	int MOIS_NAISS;
	int ANNEE_NAISS;

client c;
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
	column = gtk_tree_view_column_new_with_attributes("num_tel",renderer,"text",ENUM_TEL,NULL);
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

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING);

	
	f = fopen(file,"r");

if(f==NULL)
	{
	return;
	}
else
	{
	while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",nom,prenom,cin,adresse,num_tel,&JOUR_NAISS,&MOIS_NAISS,&ANNEE_NAISS,situation_sociale,nationalite,sexe)!=EOF)
	


		{
		gtk_list_store_append(store,&iter);

		gtk_list_store_set(store,&iter, ENOM, nom,EPRENOM, prenom, ECIN, cin,EADRESSE, adresse,ENUM_TEL,num_tel,EJOUR_NAISS,JOUR_NAISS,EMOIS_NAISS,MOIS_NAISS,EANNEE_NAISS,ANNEE_NAISS, ESITUATION_SOCIALE, situation_sociale,ENATIONALITE,nationalite,ESEXE,sexe,-1);

		}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);


}	
}



	
	


