#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <config.h>
#include "equipement.h"
#include "support.h"


enum
{
	TYPE,
	ID,
	PV,
	DATEM,
	ETAT,
	COLUMNS
};

				// espace
void coder(char ch[])
{
int i,n;
n=strlen(ch);
for(i=0;i<n;i++)
{
if (ch[i]==' ')
{ch[i]='.';}
}
}


				//ajouter equipement

void  ajouter_equipement(equip ne)
{
FILE *f=NULL;
f=fopen("equipement.txt","a+");

coder(ne.id);
coder(ne.pv);

	if(f==NULL)
		return;
	else
		{
		fprintf(f,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, ne.dm.jour, ne.dm.mois, ne.dm.annee, ne.etat);
		fclose(f);
		}
}



				//supprimer equipement

void supprimer_equipement(char id[50])
{
FILE *f=NULL;
FILE *f1=NULL;
equip ne;
f=fopen("equipement.txt","r");
f1=fopen("ancien.txt","w+");

	if(f==NULL)
		return;
	else
		{
	while(fscanf(f,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, &ne.dm.jour, &ne.dm.mois, &ne.dm.annee, ne.etat)!=EOF)
		{
		if(strcmp(id,ne.id)!=0)
			fprintf(f1,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, ne.dm.jour, ne.dm.mois, ne.dm.annee, ne.etat);
		}
		}
fclose(f);
fclose(f1);
remove("equipement.txt");
rename("ancien.txt","equipement.txt");
}


				//  FONCTION RECH  elle rendre soit 1 soit 0 
int rech1(char id[50])
{
  	FILE *f;
  	equip ne ;
  	f=fopen("equipement.txt","r");
    if (f!=NULL)
{
  while (fscanf(f,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, &ne.dm.jour, &ne.dm.mois, &ne.dm.annee, ne.etat)!=EOF)
	{
            if (strcmp(id,ne.id)==0) return 1; 
	}
}
fclose(f);
return 0;
}

				//modifier equipement

void modifier_equipement(equip ne, char id[50])
{
equip ns;
FILE *f;
FILE *f2;
f=fopen("equipement.txt","r");
f2=fopen("equipement_tmp.txt","a+"); 
	if (f==NULL)
	return;
	else
	{
	if (f2==NULL)
	return;
	else
	{ 
	  while (fscanf(f,"%s %s %s %d %d %d %s\n", ns.type, ns.id, ns.pv, &ns.dm.jour, &ns.dm.mois, &ns.dm.annee, ns.etat)!=EOF)
		{
		 if(strcmp(ns.id,id)==0) 
			{ fprintf(f2,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, ne.dm.jour, ne.dm.mois, ne.dm.annee, ne.etat); }
		 else   { fprintf(f2,"%s %s %s %d %d %d %s\n", ns.type, ns.id, ns.pv, ns.dm.jour, ns.dm.mois, ns.dm.annee, ns.etat); }
		}
	}
fclose(f2);
fclose(f);
remove("equipement.txt");
rename("equipement_tmp.txt","equipement.txt");
	}
}



				//chercher equipement
void chercher_equipement(GtkWidget *liste,char id[50])
{
	equip ne;
	FILE *f1,*f2;
	f1=fopen("equipement.txt","r");
	f2=fopen("ancien.txt","w");
	
	while(fscanf(f1,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, &ne.dm.jour, &ne.dm.mois, &ne.dm.annee, ne.etat)!=EOF)
			{				
				if(strcmp(ne.id,id)==0)
				fprintf(f2,"%s %s %s %d %d %d %s\n", ne.type, ne.id, ne.pv, ne.dm.jour, ne.dm.mois, ne.dm.annee, ne.etat);
			}
	fclose(f1);
	fclose(f2);
	afficher_equipement(liste,"ancien.txt");
	remove("ancien.txt");	
	
}





				//afficher equipement

void afficher_equipement(GtkWidget *liste,char file[50])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	FILE *f;
	
	char Type[30];
	char Id[50];
	char Maintenance_preventive[200];
	char Date_de_maintenance[50]="";
	char Etat[30];
	char j[2];
	char m[3];
	char a[5];
	int j1;
	int m1;
	int a1;
	
	equip ne;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
	{
	renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Id",renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Maintenance_preventive",renderer, "text",PV,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date_de_maintenance",renderer, "text",DATEM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",ETAT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	}
	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f = fopen(file,"r");

if(f==NULL)
	{
	return;
	}
else
	{
	while (fscanf(f,"%s %s %s %d %d %d %s\n", Type, Id, Maintenance_preventive, &j1, &m1, &a1, Etat)!=EOF)
		{
		
		snprintf(j, 2, "%d", j1); 
		snprintf(m, 3, "%d", m1); 
		snprintf(a, 5, "%d", a1); 
		if(j1<10 ){
		        strcpy(Date_de_maintenance,"0");
 		        strcat(Date_de_maintenance,j);
  		        strcat(Date_de_maintenance,"/");
			  }
    		else{
        		strcpy(Date_de_maintenance,j);
        		strcat(Date_de_maintenance,"/");
    		    }

    		if(m1<10){
        		strcat(Date_de_maintenance,"0");
        		strcat(Date_de_maintenance,m);
        		strcat(Date_de_maintenance,"/");
    			}
    		else{
        		strcat(Date_de_maintenance,m);
        		strcat(Date_de_maintenance,"/");
    		    }
    		strcat(Date_de_maintenance,a);


		
		

		gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter, TYPE, Type, ID, Id, PV, Maintenance_preventive, DATEM, Date_de_maintenance, ETAT, Etat, -1);
		}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);


	

}
}



































