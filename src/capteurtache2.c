#ifdef HAVE_CONFIG_H
# include<config.h>
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<capteurtache2.h>
#include<gtk/gtk.h>
enum
{
EID_CAPTEUR,
EMARQUE,
ETYPE,    
EETAT,
EVALEUR,
EJOURP,
EMOISP,
EANNEEP,
EJOURF,
EMOISF,
EANNEEF,
COLUMNS,
};
//////////////////////////////////////////////////////
void ajouter_capteur1(capteur1 c)
{
	FILE *f;
	f=fopen("capteur.txt","a+");
	if (f!=NULL)
	{
		fprintf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c.id_capteur,c.marque,c.type,c.etat,c.valeur,c.datef.jour,c.datef.mois,c.datef.annee,c.datep.jour,c.datep.mois,c.datep.annee);
		
	}
	fclose(f);
}
///////////////////////////////////////////////////////


void afficher_capteur1(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id_capteur[30];
	char marque[20];
	char type[20];
	char etat[20];
	char valeur[20];
	int jour_de_mise_en_fonction;
	int mois_de_mise_en_fonction;
	int annee_de_mise_en_fonction;
	int jour_de_mise_en_panne;
	int mois_de_mise_en_panne;
	int annee_de_mise_en_panne;
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id_capteur",renderer,"text",EID_CAPTEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("marque",renderer,"text",EMARQUE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("etat",renderer,"text",EETAT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",EVALEUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour_de_mise_en_fonction",renderer,"text",EJOURF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois_de_mise_en_fonction",renderer,"text",EMOISF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee_de_mise_en_fonction",renderer,"text",EANNEEF,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour_de_mise_en_panne",renderer,"text",EJOURP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois_de_mise_en_panne",renderer,"text",EMOISP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee_de_mise_en_panne",renderer,"text",EANNEEP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
f=fopen("capteuralarmante.txt","r");
if (f==NULL)
{
return;
}
else
{
f=fopen("capteuralarmante.txt","a+");
while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",id_capteur,marque,type,etat,valeur,&jour_de_mise_en_fonction,&mois_de_mise_en_fonction,&annee_de_mise_en_fonction,&jour_de_mise_en_panne,&mois_de_mise_en_panne,&annee_de_mise_en_panne)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID_CAPTEUR,id_capteur,EMARQUE,marque,ETYPE,type,EETAT,etat,EVALEUR,valeur,EJOURF,jour_de_mise_en_fonction,EMOISF,mois_de_mise_en_fonction,EANNEEF,annee_de_mise_en_fonction,EJOURP,jour_de_mise_en_panne,EMOISP,mois_de_mise_en_panne,EANNEEP,annee_de_mise_en_panne,-1);

}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (GTK_TREE_VIEW (liste)),GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
////////////////////////////////////////////////////////////
void supprimer_capteur1(char id_capteur[70])
{
	capteur1 c1;
	FILE *f,*g;
	f=fopen("capteur.txt","r");
	g=fopen("capteur1.txt","w");
	if(f==NULL||g==NULL)
		return;
	else
	{
			while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,&c1.datef.jour,&c1.datef.mois,&c1.datef.annee,&c1.datep.jour,&c1.datep.mois,&c1.datep.annee)!=EOF)	
			{ 
				if(strcmp(c1.id_capteur,id_capteur)!=0)
					fprintf(g,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,c1.datef.jour,c1.datef.mois,c1.datef.annee,c1.datep.jour,c1.datep.mois,c1.datep.annee);
			}
	}
	fclose(f);
	fclose(g);
	remove("capteur.txt");
	rename("capteur1.txt","capteur.txt");
}




