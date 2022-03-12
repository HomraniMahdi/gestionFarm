#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "calendrier.h"
#include <gtk/gtk.h>
#include "interface.h"
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
/*
char id[20];
char type[30];
char genre[30];
int jj;
int mm;
int aa;
*/


void ajouter_Nouv_calendrier(calendrier c){
FILE*f=NULL;
f=fopen("calendrier.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,c.jj,c.mm,c.aa);
fclose(f);
}

int exist_calendrier(char*id){
FILE*f=NULL;
 calendrier c;
f=fopen("calendrier.txt","r");
while(fscanf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,&c.jj,&c.mm,&c.aa)!=EOF){
if(strcmp(c.id,id)==0)return 1;
}
fclose(f);
return 0;
}


void supprimer_calendrier(char*id){
FILE*f=NULL;
FILE*f1=NULL;
calendrier c ;
f=fopen("calendrier.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,&c.jj,&c.mm,&c.aa)!=EOF){
if(strcmp(id,c.id)!=0)fprintf(f1,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,c.jj,c.mm,c.aa);
}
fclose(f);
fclose(f1);
remove("calendrier.txt");
rename("ancien.txt","calendrier.txt");

}


calendrier retourner_calendrier(char*id){
FILE*f=NULL;
calendrier c ;
calendrier c1 ;
int b=0;
f=fopen("calendrier.txt","r");
while(fscanf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,&c.jj,&c.mm,&c.aa)!=EOF){
if (strcmp(c.id,id)==0)
{
c1=c;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(c1.id,"***");
}
return  c1;
}
void modifier_calendrier(calendrier c1){

FILE*f=NULL;
FILE*f1=NULL;
calendrier c ;
f=fopen("calendrier.txt","r");
f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,&c.jj,&c.mm,&c.aa)!=EOF){
if(strcmp(c1.id,c.id)!=0){fprintf(f1,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,c.jj,c.mm,c.aa);
}else{
fprintf(f1,"%s %s %s %d %d %d\n",c.id,c1.type,c1.genre,c1.jj,c1.mm,c1.aa);
}
}
fclose(f);
fclose(f1);
remove("calendrier.txt");
rename("ancien.txt","calendrier.txt");


}






void treeView_calendrier(GtkWidget* treeview1,char*l)
{

calendrier c;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %d %d %d\n",c.id,c.type,c.genre,&c.jj,&c.mm,&c.aa)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.id,
                            1,c.type,
                            2,c.genre,
                            3,c.jj,
                            4,c.mm,
                            5,c.aa,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("GENRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MOIS",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ANNEE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}







