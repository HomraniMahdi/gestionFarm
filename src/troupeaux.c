#include <stdio.h>
#include <stdlib.h>
#include "troupeaux.h"
#include <gtk/gtk.h>
#include <string.h>

enum
{
	ETYPE,
	EGENRE,
	EID,
	EJOUR,
	EMOIS,
	EANNEE,
	EETAT,
	COLUMNS
};

void ajout_troupeaux(troupeaux t)
{

FILE *f;
f=fopen("troupeaux.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %d %d %d %s\n",t.type,t.genre,t.id,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee,t.etat); 
fclose(f);
}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void supprimer_troupeaux(char Ident[100])
{
 	    troupeaux t;
	    FILE *f;
	    FILE *f1;
	    f=fopen("troupeaux.txt","r");
	    f1=fopen("tmp.txt","w");
	    if((f!=NULL)&&(f1!=NULL))
		{
	        while(fscanf(f,"%s %s %s %d %d %d %s\n",t.type,t.genre,t.id,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee,t.etat)!=EOF)
		{
 
          	  if(strcmp(t.id,Ident)!=0)
 
               		 fprintf(f1,"%s %s %s %d %d %d %s\n",t.type,t.genre,t.id,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee,t.etat);
		}
		
		fclose(f);
		fclose(f1);
		remove ("troupeaux.txt");
		rename ("tmp.txt","troupeaux.txt");

		}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
void modifier_troupeaux(troupeaux t2, char j[],char m[],char a[])
{
    troupeaux t;
    FILE *f;
    FILE *f1;
    f=fopen("troupeaux.txt","r");
    f1=fopen("tmp.txt","w");
    if((f!=NULL) && (f1!=NULL)){ 
        while(fscanf(f,"%s %s %s %d %d %d %s \n",t.type,t.genre,t.id,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee,t.etat)!=EOF){
            if(strcmp(t.id,t2.id)!=0){

                fprintf(f1,"%s %s %s %d %d %d %s \n",t.type,t.id,t.genre,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee,t.etat);
            }
else
{
fprintf(f1,"%s %s %s %s %s %s %s \n",t2.type,t2.id,t2.genre,j,m,a,t2.etat);
            }
                

            }
        fclose(f);
        fclose(f1);

        
	remove ("troupeaux.txt");
	rename ("tmp.txt","troupeaux.txt");
	}
}
//////////////////////////////////////////////////////////////////////////////
/*void recherche_troupeaux(troupeaux t);
{
   FILE *f;
   int i=0;
   char ident;
   f=fopen("toupeaux.txt","r");
   if (f!=NULL)
   {
       scanf("%s",ident);
       while (fscanf(f,%s %s %s %d %d %d %s",t.type,t.genre,t.id,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee,t.etat)!=EOF )
       {
          if (t.id==ident)
          {

           printf("le type de l'animal : %s \n",t.type);
           printf("le genre de l'animal:%s \n,",t.genre);
           printf("la date de naissance de l'animal : %d %d %d \n",t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee);
           printf("le num de l'identifion de l'animal : %s \n",t.id);

           fclose(f);
          }
       }
   }

}*/
////////////////////////////////////////////////////////////////
void afficher_troupeaux(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char type[100];
    char genre[100];
    char id[100];
    char jour[100];
    char mois[100];
    char annee[100];
    char etat[100];
    
    store==NULL;
    FILE *f;
    store=gtk_tree_view_get_model(liste);
    if(store==NULL)
    {
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type" , renderer, "text",ETYPE ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre" , renderer, "text",EGENRE ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id" , renderer, "text",EID ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour" , renderer, "text",EJOUR ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois" , renderer, "text",EMOIS ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee" , renderer, "text",EANNEE ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
	

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("etat" , renderer, "text",EETAT ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

       

	}
			store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen("troupeaux.txt","r");
	if(f==NULL)
	{
		return;
	}	
	else
	{
		
	 	while (fscanf(f,"%s %s %s %s %s %s %s \n", type,genre,id,jour,mois,annee,etat)!=EOF )
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store, &iter, ETYPE, type, EGENRE, genre,EID, id,EJOUR ,jour,EMOIS ,mois ,EANNEE, annee, EETAT ,etat);
		}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

////////////////////////////////////////////////////////////////////////////////
int nombre_troupeau(char type[100])
{
	FILE *f;
	int n=0;
	troupeaux t;
	f=fopen("troupeaux.txt","r");
	while(fscanf(f,"%s %s %s %d %d %d %s\n",t.type,t.genre,t.id,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee,t.etat)!=EOF )
	{
		if(strcmp(t.type,type)==0)
			n++;
	}
	return n;
}
/////////////////////////////////////////////////////////////////////////////////
/*int controlsaisie()
{
int trouve=-1;
FILE f*=NULL;
F=fopen("troupeaux.txt","r");
char ident[100]
troupeaux t;
if (f!=NULL)
    {

       while (fscanf(f,"%s %s %s %d %d %d %s",t.type,t.genre,t.id,t.date_de_naissance.jour,t.date_de_naissance.mois,t.date_de_naissance.annee,t.etat)!=EOF )
       {
		if(strcmp(t.id,id)==0)
		{
			trouve=1;
		}
		fclose(f);
	}	
	return trouve;
}*/
///////////////////////////////////////////////////


int exist_troupeaux (char id[50]){
FILE*f=NULL;
troupeaux t;
f=fopen("troupeaux.txt","r");
while(fscanf(f,"%s %s %s %d %d %d %s",t.type,t.genre,t.id,&t.date_de_naissance.jour,&t.date_de_naissance.mois,&t.date_de_naissance.annee,t.etat)!=EOF){
if(strcmp(t.id,id)==0)return 1;
}
fclose(f);
return 0;
}
