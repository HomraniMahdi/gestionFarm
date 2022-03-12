#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include <string.h>
#include <stdlib.h>
#include "support.h"
#include "ouvrier.h"
#include "calendrier.h"
#include "capteur.h"
#include "equipement.h"
#include "verification.h"
#include "verificationA.h"
#include "troupeaux.h"
#include "client.h"
#include "fonction.h"
#include"absenteisme.h"
#include "capteurtache2.h"


int t[]={0,0,0,0};
int t1[]={0,0,0,0};
int x,y;
int tab_an[100];
float tab_temp[100]={0};

void
on_button_acceuil_clicked              (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *acceuil;
	GtkWidget *gestion;
	GtkWidget *treeview1;
	GtkWidget *treeview2;
	acceuil=lookup_widget(objet,"acceuil");
	gtk_widget_hide (acceuil);
	gestion=lookup_widget(objet,"gestion");
	gestion=create_gestion();
	gtk_widget_show (gestion);
	treeview1=lookup_widget(gestion,"treeview1");
	afficher_ouvrier(treeview1,"ouvrier.txt");
	treeview2=lookup_widget(gestion,"treeview2");
	afficher_ouvrier(treeview2,"ouvrier.txt");
}


void
on_button_retour_clicked               (GtkWidget        *objet,
                                        gpointer         user_data)
{
		GtkWidget *acceuil;
		GtkWidget *gestion;
		acceuil=lookup_widget(objet,"acceuil");
		gestion=lookup_widget(objet,"gestion");
		acceuil=create_acceuil();
		gtk_widget_hide (gestion);
		gtk_widget_show (acceuil);
}


void
on_button_confirmer_ajouter_ouvrier_clicked
                                       (GtkWidget        *objet,
                                        gpointer         user_data)
{
		ouvrier ov;

		GtkWidget *entrynom;
		GtkWidget *entryprenom;
		GtkWidget *entryadresse;
		GtkWidget *entrycin;
		GtkWidget *entrysalaire_actuel;
		GtkWidget *entrynum_tel;
		GtkWidget *gestion;
		GtkWidget *success;
		GtkWidget *existe;
		GtkWidget *entry_jour_emb;
		GtkWidget *entry_mois_emb;
		GtkWidget *entry_annee_emb;
		GtkWidget *entry_jour_naiss;
		GtkWidget *entry_mois_naiss;
		GtkWidget *entry_annee_naiss;
		GtkWidget *entry_situation_sociale;
		GtkWidget *entry_nationalite;
		GtkWidget *entry_homme;
		GtkWidget *entry_femme;
		int b=1;

		gestion=create_gestion();

		entrynom=lookup_widget(objet,"entry_nom_ajouter_ouvrier");
		entryprenom=lookup_widget(objet,"entry_prenom_ajouter_ouvrier");
		entrycin=lookup_widget(objet,"entry_cin_ajouter_ouvrier");
		entryadresse=lookup_widget(objet,"entry_adresse_ajouter_ouvrier");
		entrysalaire_actuel=lookup_widget(objet,"entry_salaire_actuel_ajouter_ouvrier");
		entrynum_tel=lookup_widget(objet,"entry_n_tel_ajouter_ouvrier");
		success=lookup_widget(objet,"label_ouvrier_succes_ajout"); 
		existe=lookup_widget(objet,"label_ouvrier_existe_ajout"); 

		entry_jour_emb=lookup_widget(objet,"spinbutton_jour_date_embauche_ajouter_ouvrier");
		entry_mois_emb=lookup_widget(objet,"spinbutton_mois_date_embauche_ajouter_ouvrier");
		entry_annee_emb=lookup_widget(objet,"spinbutton_annee_date_embauche_ajouter_ouvrier");

		entry_jour_naiss=lookup_widget(objet,"spinbutton_jour_date_naissance_ajouter_ouvrier");
		entry_mois_naiss=lookup_widget(objet,"spinbutton_mois_date_naissance_ajouter_ouvrier");
		entry_annee_naiss=lookup_widget(objet,"spinbutton_annee_date_naissance_ajouter_ouvrier");

		entry_situation_sociale=lookup_widget(objet,"comboboxentry_situation_sociale_ajouter_ouvrier");
		entry_nationalite=lookup_widget(objet,"comboboxentry_nationalite_ajouter_ouvrier");

		entry_homme=lookup_widget(objet,"radiobutton_homme_sexe_ajouter_ouvrier");
		entry_femme=lookup_widget(objet,"radiobutton_femme_sexe_ajouter_ouvrier");

		strcpy(ov.nom,gtk_entry_get_text(GTK_ENTRY(entrynom) ) );
		strcpy(ov.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom) ) );
		strcpy(ov.cin,gtk_entry_get_text(GTK_ENTRY(entrycin) ) );
		strcpy(ov.adresse,gtk_entry_get_text(GTK_ENTRY(entryadresse) ) );
		strcpy(ov.salaire_actuel,gtk_entry_get_text(GTK_ENTRY(entrysalaire_actuel) ) );
		strcpy(ov.num_tel,gtk_entry_get_text(GTK_ENTRY(entrynum_tel) ) );

		ov.dt_emb.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour_emb));
		ov.dt_emb.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois_emb));
		ov.dt_emb.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee_emb));

		ov.dt_naiss.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour_naiss));
		ov.dt_naiss.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois_naiss));
		ov.dt_naiss.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee_naiss));

		strcpy(ov.situation_sociale,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_situation_sociale)));
		strcpy(ov.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_nationalite)));
		
		
		if(s==1)
		strcpy(ov.sexe,"homme");
		else 
		strcpy(ov.sexe,"femme");
		
		gtk_widget_hide (success);
		//condition_ajout
		if(strcmp(ov.nom,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_nom_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_nom_ajout"));
		}

		if(strcmp(ov.prenom,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_prenom_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_prenom_ajout"));
		}

		if(strcmp(ov.cin,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_cin_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_cin_ajout"));
		}

		if(strcmp(ov.adresse,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_cin_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_adresse_ajout"));
		}

		if(strcmp(ov.salaire_actuel,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_salaire_actuel_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_salaire_actuel_ajout"));
		}

		if(strcmp(ov.num_tel,"")==0){
				  gtk_widget_show (lookup_widget(objet,"label_echec_num_tel_ajout"));
		b=0;
		}
		else {
				  gtk_widget_hide(lookup_widget(objet,"label_echec_num_tel_ajout"));
		}

		if(b==1){

		if(exist_ouvier(ov.cin)==1)
		{

					  gtk_widget_show (existe);
		}
		else {
							  gtk_widget_hide (existe);
		        ajouter_ouvrier(ov);

							  gtk_widget_show (success);
		}

		
		}
}


void
on_radiobutton_homme_sexe_ajouter_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=1;
}


void
on_radiobutton_femme_sexe_ajouter_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=2;
}


void
on_button_mise_a_jour_ouvrier_clicked  (GtkWidget        *objet,
                                        gpointer         user_data)
{
	FILE *f;
	GtkWidget *entrynom;
	GtkWidget *entryprenom;
	GtkWidget *entryadresse;
	GtkWidget *entrysalaire_actuel;
	GtkWidget *entrynum_tel;
	GtkWidget *gestion;
	GtkWidget *sortie;
	GtkWidget *entry_jour_emb;
	GtkWidget *entry_mois_emb;
	GtkWidget *entry_annee_emb;
	GtkWidget *entry_jour_naiss;
	GtkWidget *entry_mois_naiss;
	GtkWidget *entry_annee_naiss;
	GtkWidget *entry_situation_sociale;
	GtkWidget *entry_nationalite;
	GtkWidget *entry_homme;
	GtkWidget *entry_femme;
	int b=1;

	f=fopen("modifier.txt","r");
	ouvrier ov;
	fscanf(f,"%s",ov.cin);
	entrynom=lookup_widget(objet,"entry_nom_modifier_ouvrier");
	entryprenom=lookup_widget(objet,"entry_prenom_modifier_ouvrier");
	entryadresse=lookup_widget(objet,"entry_adresse_modifier_ouvrier");
	entrysalaire_actuel=lookup_widget(objet,"entry_salaire_actuel_modifier_ouvrier");
	entrynum_tel=lookup_widget(objet,"entry_n_tel_modifier_ouvrier");
	sortie=lookup_widget(objet,"label_succes_modifier"); 

	entry_jour_emb=lookup_widget(objet,"spinbutton_jour_date_embauche_modifier_ouvrier");
	entry_mois_emb=lookup_widget(objet,"spinbutton_mois_date_embauche_modifier_ouvrier");
	entry_annee_emb=lookup_widget(objet,"spinbutton_annee_date_embauche_modifier_ouvrier");

	entry_jour_naiss=lookup_widget(objet,"spinbutton_jour_date_naissance_modifier_ouvrier");
	entry_mois_naiss=lookup_widget(objet,"spinbutton_mois_date_naissance_modifier_ouvrier");
	entry_annee_naiss=lookup_widget(objet,"spinbutton_annee_date_naissance_modifier_ouvrier");

	entry_situation_sociale=lookup_widget(objet,"comboboxentry_situation_sociale_modifier_ouvrier");
	entry_nationalite=lookup_widget(objet,"comboboxentry_nationalite_modifier_ouvrier");

	entry_homme=lookup_widget(objet,"radiobutton_homme_sexe_modifier_ouvrier");
	entry_femme=lookup_widget(objet,"radiobutton_femme_sexe_modifier_ouvrier");

	strcpy(ov.nom,gtk_entry_get_text(GTK_ENTRY(entrynom) ) );
	strcpy(ov.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom) ) );
	strcpy(ov.adresse,gtk_entry_get_text(GTK_ENTRY(entryadresse) ) );
	strcpy(ov.salaire_actuel,gtk_entry_get_text(GTK_ENTRY(entrysalaire_actuel) ) );
	strcpy(ov.num_tel,gtk_entry_get_text(GTK_ENTRY(entrynum_tel) ) );

	ov.dt_emb.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour_emb));
	ov.dt_emb.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois_emb));
	ov.dt_emb.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee_emb));

	ov.dt_naiss.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour_naiss));
	ov.dt_naiss.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois_naiss));
	ov.dt_naiss.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee_naiss));

	strcpy(ov.situation_sociale,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_situation_sociale)));
	strcpy(ov.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_nationalite)));

	if(s==1)
	strcpy(ov.sexe,"homme");
	else 
	strcpy(ov.sexe,"femme");
	
	//condition_ajout

	if(strcmp(ov.nom,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_nom_modifier"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_nom_modifier"));
	}

	if(strcmp(ov.prenom,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_prenom_modifier"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_prenom_modifier"));
	}


	if(strcmp(ov.adresse,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_adresse_modifier"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_adresse_modifier"));
	}

	if(strcmp(ov.salaire_actuel,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_salaire_actuel_modifier"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_salaire_actuel_modifier"));
	}

	if(strcmp(ov.num_tel,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_num_tel_modifier"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_num_tel_modifier"));
	}
        if(b==1) {
	
                ajouter_ouvrier(ov);

						  gtk_widget_show (sortie);
        }
}


void
on_radiobutton_homme_sexe_modifier_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=1;
}


void
on_radiobutton_femme_sexe_modifier_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=2;
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
		GtkWidget *gestion;
		GtkTreeIter iter;
			gchar *NOM;
			gchar *PRENOM;
			gchar *CIN;
			gchar *ADRESSE;
			gchar *SALAIRE_ACTUEL;
			gchar *NUM_TEL;
			gint  JOUR_EMB;
			gint  MOIS_EMB;
			gint  ANNEE_EMB;
			gint  JOUR_NAISS;
			gint  MOIS_NAISS;
			gint  ANNEE_NAISS;
			gchar *SITUATION_SOCIALE;
			gchar *NATIONALITE;
			gchar *SEXE;
			
		ouvrier ov;
		GtkTreeModel *model=gtk_tree_view_get_model(treeview);
		if (gtk_tree_model_get_iter(model,&iter,path))
		{
		//obtention des valeurs de le ligne selectionne
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&CIN,3,&ADRESSE,4,&SALAIRE_ACTUEL,5,&NUM_TEL,6,&JOUR_EMB,7,&MOIS_EMB,8,&ANNEE_EMB,9,&JOUR_NAISS,10,&MOIS_NAISS,11,&ANNEE_NAISS,12,&SITUATION_SOCIALE,13,&NATIONALITE,14,&SEXE,-1);
		
		//copie des valeurs  pour le passer a la fonction supprimer  
		strcpy(ov.cin,CIN);
		supprimer_ouvrier(ov.cin);
		afficher_ouvrier(treeview,"ouvrier.txt"); 
	}
}


void
on_buttonrefresh_clicked               (GtkWidget        *objet,
                                        gpointer         user_data)
{
		GtkWidget *gestion;
		GtkWidget *treeview1;
		gestion=lookup_widget(objet,"gestion");
		treeview1=lookup_widget(gestion,"treeview1");
		afficher_ouvrier(treeview1,"ouvrier.txt"); 
}


void
on_button_modifier_ouvrier_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
		FILE *f;
		f=fopen("modifier.txt","w");
		GtkWidget* gestion;

		GtkTreeModel     *model;
		GtkTreeSelection *selection;
		GtkTreeIter iter;
		GtkWidget* p;
		ouvrier ov;
		gchar* nom;
		gchar* prenom;
		gchar* cin;
		gchar* adresse;
		gchar* salaire_actuel;
		gchar* num_tel;
		gchar* jour_emb;
		gint* mois_emb;
		gint* annee_emb;
		p=lookup_widget(objet,"treeview1");
		selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
		if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
		{  gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&cin,3,&adresse,4,&salaire_actuel,5,&num_tel,-1);

			gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_nom_modifier_ouvrier")),nom);
		        gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_prenom_modifier_ouvrier")),prenom);
		        gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_adresse_modifier_ouvrier")),adresse);
		  	gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_salaire_actuel_modifier_ouvrier")),salaire_actuel);
			gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_n_tel_modifier_ouvrier")),num_tel);
	 
			

		   gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView
		   gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook2")));
		   fprintf(f,"%s",cin);
		   supprimer_ouvrier(cin);
		   
		
		}// modifier la ligne du fichier
		fclose(f);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
		GtkWidget *treeview2;
		GtkWidget *gestion;
		GtkTreeIter iter;
			gchar *NOM;
			gchar *PRENOM;
			gchar *CIN;
			gchar *ADRESSE;
			gchar *SALAIRE_ACTUEL;
			gchar *NUM_TEL;
			gint  JOUR_EMB;
			gint  MOIS_EMB;
			gint  ANNEE_EMB;
			gint  JOUR_NAISS;
			gint  MOIS_NAISS;
			gint  ANNEE_NAISS;
			gchar *SITUATION_SOCIALE;
			gchar *NATIONALITE;
			gchar *SEXE;
			
		ouvrier ov;
		GtkTreeModel *model=gtk_tree_view_get_model(treeview);
		if (gtk_tree_model_get_iter(model,&iter,path))
		{
		//obtention des valeurs de le ligne selectionne
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&CIN,3,&ADRESSE,4,&SALAIRE_ACTUEL,5,&NUM_TEL,6,&JOUR_EMB,7,&MOIS_EMB,8,&ANNEE_EMB,9,&JOUR_NAISS,10,&MOIS_NAISS,11,&ANNEE_NAISS,12,&SITUATION_SOCIALE,13,&NATIONALITE,14,&SEXE,-1);
		
		//copie des valeurs  pour le passer a la fonction supprimer  
		strcpy(ov.nom,NOM);
		afficher_ouvrier(treeview,"ouvrier.txt"); 
	}
}


void
on_button_rechercher_ouvrier_clicked   (GtkWidget        *objet,
                                        gpointer         user_data)
{
		GtkWidget *NOM;
		GtkWidget *gestion;
		GtkWidget *treeview2;
		char nom[100];
		NOM=lookup_widget (objet,"entry_rechercher_ouvrier");
		gestion=lookup_widget(objet,"gestion");
		strcpy(nom, gtk_entry_get_text(GTK_ENTRY(NOM)));
		treeview2=lookup_widget(gestion,"treeview2");
		chercher_ouvrier(treeview2,nom);
}


void
on_gest_calendrier_clicked             (GtkWidget        *objet,
                                       gpointer         user_data)
{
GtkWidget *p;

gestion_calendrier = create_gestion_calendrier ();
i=0;

p=lookup_widget(gestion_calendrier,"treeview4");

treeView_calendrier(p,"calendrier.txt");
gtk_widget_show (gestion_calendrier);
menu=lookup_widget(objet,"menu");
gtk_widget_hide (menu);
}




void
on_button_menu_ouvrier_clicked        (GtkWidget        *objet,
                                       gpointer         user_data)
{
	GtkWidget *acceuil;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	acceuil=lookup_widget(objet,"acceuil");
	acceuil=create_acceuil();
	gtk_widget_show (acceuil);
}


void
on_button_menu_plantation_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *menu;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	menu=lookup_widget(objet,"menu");
	menu=create_menu();
	gtk_widget_show (menu);
}


void
on_ajouter_calendrier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	calendrier c;
	int b=1;
	GtkWidget *entryID;
	GtkWidget *comboType;
	GtkWidget *radiobutt1;
	GtkWidget *radiobutt2;
	GtkWidget *p;

	p=lookup_widget(gestion_calendrier,"treeview4");

	entryID=lookup_widget(gestion_calendrier,"entry4");
	radiobutt1=lookup_widget(gestion_calendrier,"radiobutton5");
	radiobutt2=lookup_widget(gestion_calendrier,"radiobutton2");
	comboType=lookup_widget(gestion_calendrier,"combobox3");
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
	c.jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton7")));
	c.mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton8")));
	c.aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton9")));

	

	


	//hide label success
	gtk_widget_hide (lookup_widget(gestion_calendrier,"label30"));

	/*controle de saisie*/

	if(strcmp(c.id,"")==0){
			  gtk_widget_show (lookup_widget(gestion_calendrier,"label31"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(gestion_calendrier,"label31"));
	}



	if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboType))==-1){
		        gtk_widget_show (lookup_widget(gestion_calendrier,"label20"));
	b=0;
	}
	else{

		   gtk_widget_hide (lookup_widget(gestion_calendrier,"label20"));
	}





	if(b==1){



	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboType)));


	if(exist_calendrier(c.id)==1)
		{

					  gtk_widget_show (lookup_widget(gestion_calendrier,"label32"));
		}
		else {
							  gtk_widget_hide (lookup_widget(gestion_calendrier,"label32"));
		        ajouter_Nouv_calendrier(c);

							  gtk_widget_show (lookup_widget(gestion_calendrier,"label30"));
			/*Mise a jour treeView*/

			treeView_calendrier(p,"calendrier.txt");
        }


	}
}


void
on_supprimer_calendrier_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	int b=1;
	char id[30];
	GtkWidget *entryID;
	GtkWidget *p;
	p=lookup_widget(gestion_calendrier,"treeview4");
	entryID=lookup_widget(gestion_calendrier,"entry5");
	/*controle de saisie*/
	 strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
	//hide label success
	gtk_widget_hide (lookup_widget(gestion_calendrier,"label33"));

	if(strcmp(id,"")==0){
			  gtk_widget_show (lookup_widget(gestion_calendrier,"label18"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(gestion_calendrier,"label18"));
	}


	if(b==1){

	if(exist_calendrier(id)==0){
			  gtk_widget_show (lookup_widget(gestion_calendrier,"label34"));
	}else{

			  gtk_widget_hide (lookup_widget(gestion_calendrier,"label34"));
	supprimer_calendrier(id);
	//show label success
			  gtk_widget_show (lookup_widget(gestion_calendrier,"label33"));
	/*Mise a jour treeView*/

			treeView_calendrier(p,"calendrier.txt");

	}




	}

}


void
on_modifier_calendrier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entryID;

	GtkWidget *p;
	GtkWidget *radiobutt1;
	GtkWidget *radiobutt2;
	calendrier c;


	radiobutt1=lookup_widget(gestion_calendrier,"radiobutton7");
	radiobutt2=lookup_widget(gestion_calendrier,"radiobutton4");
	p=lookup_widget(gestion_calendrier,"treeview4");
	entryID=lookup_widget(gestion_calendrier,"entry6");
	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(entryID)));


	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_calendrier,"combobox4"))));
	c.jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton10")));
	c.mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton11")));
	c.aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_calendrier,"spinbutton12")));

	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
	strcpy(c.genre,"arbre");
	}

	if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
	strcpy(c.genre,"plante");
	}

	modifier_calendrier(c);

	//show success label
	gtk_widget_show(lookup_widget(gestion_calendrier,"label29"));
	/*mise a jour treeView*/
			treeView_calendrier(p,"calendrier.txt");
}


void
on_verifier_calendrier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *entryID;
	GtkWidget *radiobutt1;
	GtkWidget *radiobutt2;
	calendrier c;
	int n,b=1;
	char id[30];



	entryID=lookup_widget(gestion_calendrier,"entry6");

	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));

	if(strcmp(id,"")==0){
			  gtk_widget_show (lookup_widget(gestion_calendrier,"label23"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(gestion_calendrier,"label23"));
	}

	if(b==1){


	c=retourner_calendrier(id);
	if(strcmp(c.id,"***")==0){
	//show label inexistant
	gtk_widget_show (lookup_widget(gestion_calendrier,"label35"));

	}
	else
	{

	gtk_widget_hide (lookup_widget(gestion_calendrier,"label35"));






	radiobutt1=lookup_widget(gestion_calendrier,"radiobutton3");
	radiobutt2=lookup_widget(gestion_calendrier,"radiobutton4");



	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_calendrier,"spinbutton4")),c.jj);  
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_calendrier,"spinbutton5")),c.mm);  
	gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_calendrier,"spinbutton6")),c.aa); 




	if(strcmp(c.type,"Aubergine")==0)n=0;		
	if(strcmp(c.type,"Betterave")==0)n=1;                
	if(strcmp(c.type,"Arbre_épinnete")==0)n=2 ;  
	if(strcmp(c.type,"Sapin_baumier")==0)n=3 ;  

	gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_calendrier,"combobox2")),n);


	if(strcmp(c.genre,"arbre")==0){
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt1),TRUE );
	}

	if(strcmp(c.genre,"plante")==0){
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt2),TRUE );
	}


	}

	}
}


void
on_retour_gest_calendrier_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  gtk_widget_destroy (gestion_calendrier);
  gtk_widget_show (menu);
}



void
on_radio_temperature_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
	x=1;
	}
}


void
on_button_ajouter_capteur_clicked      (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur c;
	GtkWidget *fenetre_capteur;
	GtkWidget *id_capteur;
	GtkWidget *valeur;
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *label;


	/*entry text*/
	fenetre_capteur=lookup_widget(objet,"gestionDesCapteur");
	id_capteur=lookup_widget(objet,"entry_id_ajouter_capteur");
	strcpy(c.id_capteur,gtk_entry_get_text(GTK_ENTRY(id_capteur)));
	valeur=lookup_widget(objet,"entry_valeur_ajouter_capteur");
	strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(valeur)));
	/*entry spin button*/

	jour=lookup_widget(objet,"spinbutton1_datef_ajouter_capteur");
	c.datef.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));


	mois=lookup_widget(objet,"spinbutton2_datef_ajouter_capteur");
	c.datef.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));

	annee=lookup_widget(objet,"spinbutton3_datef_ajouter_capteur");
	c.datef.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));


	/*entry radio button*/
	if(x==1)
	{
	strcpy(c.type,"temperature");
	}
	else
	{
	strcpy(c.type,"humidite");
	}
	/*entry checkbutton*/
	if(t[0]==1)
	{strcpy(c.marque,"testo610");}
	else if(t[1]==1)
	{strcpy(c.marque,"css014");}
	else if(t[2]==1)

	{strcpy(c.marque,"hs-ascon");}
	else if(t[3]==1)
	{strcpy(c.marque,"pt100");}

	/* valeur par defaut*/
	strcpy(c.etat,"non_defectueux");
	c.datep.jour=0;
	c.datep.mois=0;
	c.datep.annee=0;


	ajouter_capteur(c);
	label=lookup_widget(objet,"label_resultat_ajouter_capteur");
	gtk_label_set_text(GTK_LABEL(label),"capteur ajouté aves succés");
}



void
on_checkbutton4_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t[3]=1;}
}


void
on_checkbutton3_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t[2]=1;}
}


void
on_checkbutton2_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t[1]=1;}
}


void
on_checkbutton1_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t[0]=1;}
}


void
on_button_supprimer_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget  *input_supprimer;
	char id_capteur[50];
	capteur c;


	input_supprimer=lookup_widget(objet,"entry_id_supprimer_capteur");


	strcpy(id_capteur,gtk_entry_get_text(GTK_ENTRY(input_supprimer)));
	supprimer_capteur(id_capteur);
}


void
on_button_afficherm_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char str1[50];
	char str2[50];
	char str3[50];
	char str4[50];
	char str5[50];
	char str6[50];
	capteur c;
	capteur c1;
	GtkWidget *label;
	GtkWidget *id_capteur;
	GtkWidget *labelmarque;
	GtkWidget *labeltype;
	GtkWidget *labeletat;
	GtkWidget *labelvaleur;
	GtkWidget *labeldatef;
	GtkWidget *labeldatep;
	id_capteur=lookup_widget(objet,"entry_id_modifier_capteur");
	strcpy(c.id_capteur,gtk_entry_get_text(GTK_ENTRY(id_capteur)));
	label=lookup_widget(objet,"label_id1_modifier_capteur");
	labelmarque=lookup_widget(objet,"label_marque_ma_capteur");
	labeltype=lookup_widget(objet,"label_type_ma_capteur");
	labeletat=lookup_widget(objet,"label_etat_ma_capteur");
	labelvaleur=lookup_widget(objet,"label_valeur_ma_capteur");
	labeldatef=lookup_widget(objet,"label_datef_ma_capteur");
	labeldatep=lookup_widget(objet,"label_datep_ma_capteur");
	/*
	int z;
	z=rech(c.id_capteur);
	if (z==1)
	{
	*/
	gtk_label_set_text(GTK_LABEL(label),"identifiant de capteur existe");
	FILE *f;
	f=fopen("capteur.txt","r");
	if(f==NULL)
		return;
	else
	{
			while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,&c1.datef.jour,&c1.datef.mois,&c1.datef.annee,&c1.datep.jour,&c1.datep.mois,&c1.datep.annee)!=EOF)	
			{ 
				if(strcmp(c1.id_capteur,c.id_capteur)==0)
			{ 
				gtk_label_set_text(GTK_LABEL(labelmarque),c1.marque);
				gtk_label_set_text(GTK_LABEL(labeltype),c1.type);
				gtk_label_set_text(GTK_LABEL(labeletat),c1.etat);
				gtk_label_set_text(GTK_LABEL(labelvaleur),c1.valeur);
				sprintf(str1,"%d",c1.datef.jour);
				sprintf(str2,"%d",c1.datef.mois);
				sprintf(str3,"%d",c1.datef.annee);
				sprintf(str4,"%d",c1.datep.jour);
				sprintf(str5,"%d",c1.datep.mois);
				sprintf(str6,"%d",c1.datep.annee);
				strcat(str1,"/");
				strcat(str2,"/");
				strcat(str1,str2);
				strcat(str1,str3);
				strcat(str4,"/");
				strcat(str5,"/");
				strcat(str4,str5);
				strcat(str4,str6);


				gtk_label_set_text(GTK_LABEL(labeldatef),str1);
				gtk_label_set_text(GTK_LABEL(labeldatep),str4);
					
			}}
	}
	fclose(f);
}


void
on_checkbutton1_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t1[0]=1;}
}


void
on_checkbutton2_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t1[1]=1;}
}


void
on_checkbutton3_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t1[2]=1;}
}


void
on_checkbutton4_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{t1[3]=1;}
}



void
on_radio_temperature_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
	y=1;
	}
}


void
on_button_modifier_capteur_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur c;
	GtkWidget *fenetre_capteur;
	GtkWidget *id_capteur;
	GtkWidget *valeur;
	GtkWidget *etat;
	GtkWidget *jourf;
	GtkWidget *moisf;
	GtkWidget *anneef;
	GtkWidget *jourp;
	GtkWidget *moisp;
	GtkWidget *anneep;
	GtkWidget *label;


	/*entry text*/
	fenetre_capteur=lookup_widget(objet,"gestionDesCapteur");
	id_capteur=lookup_widget(objet,"entry_id_modifier_capteur");
	strcpy(c.id_capteur,gtk_entry_get_text(GTK_ENTRY(id_capteur)));
	valeur=lookup_widget(objet,"entry_valeur_modifier_capteur");
	strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(valeur)));
	/*entry spin button*/

	jourf=lookup_widget(objet,"spinbutton1_datef_modifier_capteur");
	c.datef.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jourf));


	moisf=lookup_widget(objet,"spinbutton2_datef_modifier_capteur");
	c.datef.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moisf));

	anneef=lookup_widget(objet,"spinbutton3_datef_modifier_capteur");
	c.datef.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (anneef));




	jourp=lookup_widget(objet,"spinbutton1_datep_modifier_capteur");
	c.datep.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jourp));


	moisp=lookup_widget(objet,"spinbutton2_datep_modifier_capteur");
	c.datep.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (moisp));

	anneep=lookup_widget(objet,"spinbutton3_datep_modifier_capteur");
	c.datep.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (anneep));
	/*entry combobox*/
	etat=lookup_widget(objet,"combobox_etat_modifier_capteur");
	strcpy(c.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(etat)));


	/*entry radio button*/
	if(y==1)
	{
	strcpy(c.type,"temperature");
	}
	else
	{
	strcpy(c.type,"humidite");
	}
	/*entry checkbutton*/
	if(t1[0]==1)
	{strcpy(c.marque,"testo610");}
	else if(t1[1]==1)
	{strcpy(c.marque,"css014");}
	else if(t1[2]==1)

	{strcpy(c.marque,"hs-ascon");}
	else if(t1[3]==1)
	{strcpy(c.marque,"pt100");}

	/* output*/
	label=lookup_widget(objet,"label_resultat_modifier_capteur");
	supprimer_capteur(c.id_capteur);
	ajouter_capteur(c);
}


void
on_treeview_capteur_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id_capteur;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id_capteur,-1);  
/*copie des valeur dans un variable c de type capteur pour qu on puisse utiliser la fonction supprimer*/


 
supprimer_capteur(id_capteur);
afficher_capteur(treeview);


}
}


void
on_button_menu_capteur_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestionDesCapteurs;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	gestionDesCapteurs=lookup_widget(objet,"gestionDesCapteurs");
	gestionDesCapteurs=create_gestionDesCapteurs();
	gtk_widget_show (gestionDesCapteurs);
}


void
on_button_gestion_equipement_clicked  (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *acceuil_gestion_equipement;
	GtkWidget *gestion_equipement;
	GtkWidget *treeview1;
	GtkWidget *treeview2;
	acceuil_gestion_equipement=lookup_widget(objet,"acceuil_gestion_equipement");
	gtk_widget_hide (acceuil_gestion_equipement);
	gestion_equipement=lookup_widget(objet,"gestion_equipement");
	gestion_equipement=create_gestion_equipement();
	gtk_widget_show (gestion_equipement);
	treeview1=lookup_widget(gestion_equipement,"treeview_equipement");
	afficher_equipement(treeview1,"equipement.txt");
	treeview2=lookup_widget(gestion_equipement,"treeview_rech_equipement");
	afficher_equipement(treeview2,"equipement.txt");
}


void
on_button_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	equip ne;	
	char id[50];
	GtkWidget *entrytype;
	GtkWidget *entryid;
	GtkWidget *entrymp;
	GtkWidget *entry_jour;
	GtkWidget *entry_mois;
	GtkWidget *entry_annee;
	GtkWidget *entry_etat;
	GtkWidget *gestion_equipement;
	GtkWidget *success;
	GtkWidget *existe;
	int b=1;

	gestion_equipement=create_gestion_equipement();

	entrytype=lookup_widget(objet,"comboboxentry_type_ajout");
	entryid=lookup_widget(objet,"entry_id_ajout");
	entrymp=lookup_widget(objet,"entry_mp_ajout");
	
	
	entry_jour=lookup_widget(objet,"spinbutton_date_jour_ajout");
	entry_mois=lookup_widget(objet,"spinbutton_date_mois_ajout");
	entry_annee=lookup_widget(objet,"spinbutton_date_annee_ajout");


	entry_etat=lookup_widget(objet,"comboboxentry_etat_ajout");
	
	success=lookup_widget(objet,"label_bien_ajout"); 
	existe=lookup_widget(objet,"label_id_test_ajout"); 

	strcpy(ne.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytype)));
	strcpy(ne.id,gtk_entry_get_text(GTK_ENTRY(entryid) ) );
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryid) ) );
	strcpy(ne.pv,gtk_entry_get_text(GTK_ENTRY(entrymp) ) );

	ne.dm.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour));
	ne.dm.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois));
	ne.dm.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee));

	strcpy(ne.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_etat)));



	if ((strcmp(ne.type,"")==0)||(strcmp(ne.id,"")==0)||strcmp(ne.pv,"")==0||(ne.dm.jour==0)||(ne.dm.mois==0)||(ne.dm.annee==0)||(strcmp(ne.etat,"")==0))
	{
		gtk_widget_show (lookup_widget(objet,"label_test_ajout"));
		b=0;
	}
	else 
	{	
		gtk_widget_hide(lookup_widget(objet,"label_test_ajout"));	
	}

	
	if(b==1){

        if(rech1(id)==1)
        {

				  gtk_widget_show (existe);
        }
        else 
	{
						  gtk_widget_hide (existe);
                ajouter_equipement(ne);
						  gtk_widget_show (success);
        }

	}

}


void
on_treeview_equipement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
		GtkWidget *window1;
	GtkTreeIter iter;
		gchar* type;
		gchar* id;
		gchar* maintenance_preventive;
		gchar* date_de_maintenance;
		gchar* etat;
		
		equip ne;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	//obtention des valeurs de le ligne selectionne
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&type,1,&id,2,&maintenance_preventive,3,&date_de_maintenance,4,&etat,-1);
	
	//copie des valeurs  pour le passer a la fonction supprimer  
	strcpy(ne.id,id);
	supprimer_equipement(ne.id);
	afficher_equipement(treeview,"equipement.txt"); 
	}

}


void
on_button_a_modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	FILE *f;
	f=fopen("modifier.txt","w");
	GtkWidget* gestion;

	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        //GtkWidget *label;
	equip ne;
        gchar* type;
	gchar* id;
	gchar* maintenance_preventive;
	gchar* date_de_maintenance;
	gchar* etat;
	
	//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        //label=lookup_widget(gestion,"label23");
        p=lookup_widget(objet,"treeview_equipement");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&type,1,&id,2,&maintenance_preventive,3,&date_de_maintenance,4,&etat,-1);

	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"comboboxentry_type_modifier")),type);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_id_modifier")),id);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_mp_modifier")),maintenance_preventive);
          	gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"comboboxentry_etat_modifier")),etat);
 
		

           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView
	   gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook9")));
	   fprintf(f,"%s",id);
	   supprimer_equipement(id);
	   
	
	}// modifier la ligne du fichier
	fclose(f);

}


void
on_treeview_rech_equipement_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *treeview2;
	GtkWidget *window1;
	GtkTreeIter iter;
		equip ne;
        gchar* type;
	gchar* ID;
	gchar* maintenance_preventive;
	gchar* date_de_maintenance;
	gchar* etat;
	char id[50];
		
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	//obtention des valeurs de le ligne selectionne
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&type,1,&id,2,&maintenance_preventive,3,&date_de_maintenance,4,&etat,-1);
	
	//copie des valeurs  pour le passer a la fonction supprimer  
	strcpy(id,ID);
	supprimer_equipement(id);
	//gestion_equipement=create_gestion_equipement();
	gtk_widget_show (window1);
	treeview2=lookup_widget(window1,"treeview_rech_equipement");
	afficher_equipement(treeview2,"equipement.txt"); 
}
}




void
on_button_afficher_clicked             (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_equipement;
	GtkWidget *treeview1;
	gestion_equipement=lookup_widget(objet,"gestion_equipement");
	treeview1=lookup_widget(gestion_equipement,"treeview_equipement");
	afficher_equipement(treeview1,"equipement.txt"); 

}


void
on_button_recherche_clicked            (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *ID;
	GtkWidget *gestion;
	GtkWidget *treeview2;
	char id[100];
	ID=lookup_widget (objet,"entry_id_recherche");
	gestion=lookup_widget(objet,"gestion_equipement");
	strcpy(id, gtk_entry_get_text(GTK_ENTRY(ID)));
	treeview2=lookup_widget(gestion,"treeview_rech_equipement");
	chercher_equipement(treeview2,id);
}





void
on_button_modifier_clicked             (GtkWidget        *objet,
                                        gpointer         user_data)
{
	FILE *f;
	equip ne;	
	char id[50];
	GtkWidget *entrytype;
	GtkWidget *entryid;
	GtkWidget *entrymp;
	GtkWidget *entry_jour;
	GtkWidget *entry_mois;
	GtkWidget *entry_annee;
	GtkWidget *success;
	GtkWidget *entry_etat;
	GtkWidget *gestion_equipement;
	GtkWidget *existe;

	int b=1;

	/*f=fopen("modifier.txt","r");
	fscanf(f,"%s",ne.id);*/

	entrytype=lookup_widget(objet,"comboboxentry_typee_modifier");
	entryid=lookup_widget(objet,"entry_id_modifier");
	entrymp=lookup_widget(objet,"entry_mp_modifier");
	
	
	entry_jour=lookup_widget(objet,"spinbutton_date_jour_modifier");
	entry_mois=lookup_widget(objet,"spinbutton_date_mois_modifier");
	entry_annee=lookup_widget(objet,"spinbutton_date_anee_modifier");


	entry_etat=lookup_widget(objet,"comboboxentry_etat_modifier");
	
	success=lookup_widget(objet,"label_bien_modifier");

	strcpy(ne.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entrytype)));
	strcpy(ne.id,gtk_entry_get_text(GTK_ENTRY(entryid) ) );
	strcpy(ne.pv,gtk_entry_get_text(GTK_ENTRY(entrymp) ) );

	ne.dm.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour));
	ne.dm.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois));
	ne.dm.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee));

	strcpy(ne.etat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_etat)));
	

                ajouter_equipement(ne);
						  gtk_widget_show (success);
}




void
on_button_menu_equipement_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *acceuil_gestion_equipement;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	acceuil_gestion_equipement=lookup_widget(objet,"acceuil_gestion_equipement");
	acceuil_gestion_equipement=create_acceuil_gestion_equipement();
	gtk_widget_show (acceuil_gestion_equipement);
}


void
on_button2_login_clicked               (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *window2,*input1,*input2, *output;
	  GtkWidget *window5,*test,*authentification,*surface_admin;
	FILE *f;
	FILE *f1;
	f=fopen("employer.txt","r");
	f1=fopen("users.txt","r");
	char nom[20];
	char password[20];
	employer e;
	admin c;
	authentification = create_authentification();
	input1=lookup_widget(objet,"entry6_login");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1))); 
	input2=lookup_widget(objet,"entry7_login");
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2))); 
	output=lookup_widget(objet,"label_afficha");
	if (f!=NULL)
	{
	while (fscanf(f,"%s %s %s \n",e.nom,e.prenom,e.password)!=EOF)
	{
	if ((strcmp(nom,e.nom)==0)&&(strcmp(password,e.password)==0))
	{
	
	authentification=lookup_widget(objet,"authentification");
	gtk_widget_destroy(authentification);
	test=lookup_widget(objet,"test");
	test = create_test ();
	  gtk_widget_show (test);
	test=lookup_widget(authentification,"test");

	}
	else if (f1!=NULL)
	{
		while (fscanf(f1,"%s %s %s \n",c.nom,c.prenom,c.password)!=EOF)
	{
	if ((strcmp(nom,c.nom)==0)&&(strcmp(password,c.password)==0))
	{
	authentification=lookup_widget(objet,"authentification");
	gtk_widget_destroy(authentification);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin = create_surface_admin ();
	gtk_widget_show (surface_admin);
	surface_admin=lookup_widget(authentification,"surface_admin");
	}
	else
	gtk_label_set_text(GTK_LABEL(output),"Not Found!");
	}
	}
	}
	}

}



void
on_button_afficher_troupeaux_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_troupeaux,*treeview_affichage_troupeaux;
	gestion_troupeaux=lookup_widget(objet_graphique,"gestion_troupeaux");
	treeview_affichage_troupeaux=lookup_widget(gestion_troupeaux,"treeview_affichage_troupeaux");
	afficher_troupeaux(treeview_affichage_troupeaux);	
}


void
on_button_ajouter_troupeaux_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	troupeaux t;
	GtkWidget *combobox_type;
	GtkWidget *combobox_genre;
	GtkWidget *id;
	GtkWidget *jour;
	GtkWidget *success;
	GtkWidget *existe;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *combobox_etat;
	GtkWidget *gestion_troupeaux;
	int b=1;
	id = lookup_widget(objet_graphique,"entry_id_ajouter_troupeaux");
	success=lookup_widget(objet_graphique,"label_troupeaux_succes_ajout"); 
	existe=lookup_widget(objet_graphique,"label_troupeaux_existe_ajout"); 
	combobox_type = lookup_widget(objet_graphique,"combobox_type_ajouter_troupeaux");
	combobox_genre = lookup_widget(objet_graphique,"combobox_genre_ajouter_troupeaux");
	jour = lookup_widget(objet_graphique,"spinbutton_datedenaissance_ajouter_troupeaux_jour");
	mois = lookup_widget(objet_graphique,"spinbutton_datedenaissance_ajouter_troupeaux_mois");
	annee = lookup_widget(objet_graphique,"spinbutton_datedenaissance_ajouter_troupeaux_annee");
	combobox_etat = lookup_widget(objet_graphique,"combobox_etat_ajouter_troupeaux");
	t.date_de_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	t.date_de_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	t.date_de_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(id)));
	if(strcmp("Vache",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_type)))==0)
		strcpy(t.type,"Vache");
	else if(strcmp("Chevaux",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_type)))==0)
		strcpy(t.type,"Chevaux");
	else if(strcmp("Poulet",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_type)))==0)
		strcpy(t.type,"Poulet");
	else if(strcmp("Mouton",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_type)))==0)
		strcpy(t.type,"Mouton");
	else 
		strcpy(t.type,"Berbis");
	if(strcmp("male",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_genre)))==0)
		strcpy(t.genre,"male");
	else
		strcpy(t.genre,"femelle");
	if(strcmp("Malade",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_etat)))==0)	
		strcpy(t.etat,"Malade");
	else
		strcpy(t.etat,"EnBonneEtat");
	
	if(strcmp(t.id,"")==0){
			  gtk_widget_show (lookup_widget(objet_graphique,"label_echec_id_ajout_troupeaux"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet_graphique,"label_echec_id_ajout_troupeaux"));
	}


	if(b==1){

        if(exist_troupeaux(t.id)==1)
        {

				  gtk_widget_show (existe);
        }
        else {
						  gtk_widget_hide (success);
                ajout_troupeaux(t);

						  gtk_widget_show (success);
        }

	
	}
}


void
on_button_afficher_troupeaux1_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)

{
	GtkWidget *gestion_troupeaux,*treeview_affichage_troupeaux;
	gestion_troupeaux=lookup_widget(objet_graphique,"gestion_troupeaux");
	treeview_affichage_troupeaux=lookup_widget(gestion_troupeaux,"treeview_affichage_troupeaux");
	afficher_troupeaux(treeview_affichage_troupeaux);
}


void
on_button_supprimer_troupeaux_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
		char id1[100];
		GtkWidget *Id,*gestion_troupeaux;
		gestion_troupeaux=lookup_widget(objet_graphique,"gestion_troupeaux");
		Id=lookup_widget(objet_graphique,"entry_id_supprimer_troupeaux");
		strcpy(id1,gtk_entry_get_text(GTK_ENTRY(Id)));
		supprimer_troupeaux(id1);

}


void
on_button_modifier_troupeaux_clicked   (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
	troupeaux t;
	GtkWidget *type;
	GtkWidget *genre;
	GtkWidget *jour;
	GtkWidget *id;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *etat;
	GtkWidget *gestion_troupeaux;
	char j[50];
	char m[50];
	char a[50];
	gestion_troupeaux=lookup_widget(objet_graphique,"gestion_troupeaux");	
	type=lookup_widget(objet_graphique,"entry_type_modifier_troupeaux");
	genre=lookup_widget(objet_graphique,"entry_genre_modifier_troupeaux");
	id=lookup_widget(objet_graphique,"entry_id_modifier_troupeaux");
	jour=lookup_widget(objet_graphique,"entry_date_modifier_troupeaux_jour");
	mois=lookup_widget(objet_graphique,"entry_date_modifier_troupeaux_mois");
	annee=lookup_widget(objet_graphique,"entry_date_modifier_troupeaux_annee");
	etat=lookup_widget(objet_graphique,"entry_etat_modifier_troupeaux");


	strcpy(t.type,gtk_entry_get_text(GTK_ENTRY(type)));
	strcpy(t.genre,gtk_entry_get_text(GTK_ENTRY(genre)));
	strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(j,gtk_entry_get_text(GTK_ENTRY(jour)));
	strcpy(m,gtk_entry_get_text(GTK_ENTRY(mois)));
	strcpy(a,gtk_entry_get_text(GTK_ENTRY(annee)));
	strcpy(t.etat,gtk_entry_get_text(GTK_ENTRY(etat)));
	
	modifier_troupeaux(t,j,m,a);

}


void
on_button_afficher_troupeaux2_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *gestion_troupeaux,*treeview_affichage_troupeaux;
	gestion_troupeaux=lookup_widget(objet_graphique,"gestion_troupeaux");
	treeview_affichage_troupeaux=lookup_widget(gestion_troupeaux,"treeview_affichage_troupeaux");
	afficher_troupeaux(treeview_affichage_troupeaux);	

}



void
on_button_gestion_troupeaux_clicked    (GtkButton       *objet,
                                        gpointer         user_data)
{
	GtkWidget *espace_troupeaux;
	GtkWidget *gestion_troupeaux;
	GtkWidget *treeview_affichage_troupeaux;
	espace_troupeaux=lookup_widget(objet,"espace_troupeaux");
	gtk_widget_hide (espace_troupeaux);
	gestion_troupeaux=lookup_widget(objet,"gestion_troupeaux");
	gestion_troupeaux=create_gestion_troupeaux();
	gtk_widget_show (gestion_troupeaux);
	treeview_affichage_troupeaux=lookup_widget(gestion_troupeaux,"treeview_affichage_troupeaux");
	afficher_troupeaux(treeview_affichage_troupeaux);
}


void
on_treeview_affichage_troupeaux_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

		GtkTreeIter iter;
		gchar* type;
		gchar* genre;
		gchar* id;
		gchar* jour;
		gchar* mois;
		gchar* annee;
		gchar* etat;
		troupeaux t;

		GtkTreeModel *model = gtk_tree_view_get_model(treeview);
		
		if(gtk_tree_model_get_iter(model,&iter,path))
		{
		
			//obtention de la ligne selictionneé

			gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&type,1,&genre,2,&id,3,&jour,4,&mois,5,&annee,6,&etat, -1);

			//copie des valeur vers la variable p pour le passe a  la fonction de suppression 
		
			strcpy(t.type,type); 
			strcpy(t.genre,genre); 
			strcpy(t.id,id); 
			strcpy(t.date_de_naissance.jour,jour); 
			strcpy(t.date_de_naissance.mois,mois); 
			strcpy(t.date_de_naissance.annee,annee); 
			strcpy(t.etat,etat); 
			//appel de la fonction du suppression
			supprimer_troupeaux(id);
			//mise a jour de l'affichage de la treeview
			afficher_troupeaux(treeview);
		}


}


void
on_button_menu_troupeaux_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *espace_troupeaux;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	espace_troupeaux=lookup_widget(objet,"espace_troupeaux");
	espace_troupeaux=create_espace_troupeaux();
	gtk_widget_show (espace_troupeaux);
}


void
on_button_acceuil_client_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *acceuil_client;
	GtkWidget *Gestion_client;
	GtkWidget *treeview1;
	GtkWidget *treeview2;
	acceuil_client=lookup_widget(objet,"Acceuil_client");
	gtk_widget_hide (acceuil_client);
	Gestion_client=lookup_widget(objet,"Gestion_client");
	Gestion_client=create_Gestion_client();
	gtk_widget_show (Gestion_client);
	treeview2=lookup_widget(Gestion_client,"treeview_client_aff");
	afficher_client(treeview2,"client.txt");
	treeview1=lookup_widget(Gestion_client,"treeview_reche_client");
	afficher_client(treeview1,"client.txt");
}


void
on_button_confirmer_ajouter_gestion_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;

	GtkWidget *entrynom;
	GtkWidget *entryprenom;
	GtkWidget *entryadresse;
	GtkWidget *entrycin;
	GtkWidget *entrynum_tel;
	GtkWidget *gestion;
	GtkWidget *success;
	GtkWidget *existe;
	GtkWidget *entry_jour_naiss;
	GtkWidget *entry_mois_naiss;
	GtkWidget *entry_annee_naiss;
	GtkWidget *entry_situation_sociale;
	GtkWidget *entry_nationalite;
	GtkWidget *entry_homme;
	GtkWidget *entry_femme;
	int b=1;

	

	entrynom=lookup_widget(objet,"entry_nom_ajouter_gestion_client");
	entryprenom=lookup_widget(objet,"entry_prenom_ajouter_gestion_client");
	entrycin=lookup_widget(objet,"entry_cin_ajouter_gestion_client");
	entryadresse=lookup_widget(objet,"entry_adresse_ajouter_gestion_client");
	entrynum_tel=lookup_widget(objet,"entry_tel_ajouter_gestion_client");
	success=lookup_widget(objet,"label_client_succes_ajouter"); 
	existe=lookup_widget(objet,"label_client_existe_ajouter"); 

	entry_jour_naiss=lookup_widget(objet,"spinbutton_jour_ajouter_gestion_client");
	entry_mois_naiss=lookup_widget(objet,"spinbutton_mois_ajouter_gestion_client");
	entry_annee_naiss=lookup_widget(objet,"spinbutton_annee_ajouter_gestion_client");

	entry_situation_sociale=lookup_widget(objet,"comboboxentry_situation_ajouter_gestion_client");
	entry_nationalite=lookup_widget(objet,"comboboxentry_nationalite_ajouter_gestion_client");

	entry_homme=lookup_widget(objet,"radiobutton_homme_ajouter_gestion_client");
	entry_femme=lookup_widget(objet,"radiobutton_femme_ajouter_gestion_client");

	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entrynom) ) );
	strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(entryprenom) ) );
	strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entrycin) ) );
	strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(entryadresse) ) );
	strcpy(c.num_tel,gtk_entry_get_text(GTK_ENTRY(entrynum_tel) ) );

	c.dt_naiss.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour_naiss));
	c.dt_naiss.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois_naiss));
	c.dt_naiss.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee_naiss));

	strcpy(c.situation_sociale,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_situation_sociale)));
	strcpy(c.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_nationalite)));
	
	
	if(s==1)
	strcpy(c.sexe,"homme");
	else 
	strcpy(c.sexe,"femme");
	
	gtk_widget_hide (success);
	//condition_ajout
	if(strcmp(c.nom,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_nom_ajouter"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_nom_ajouter"));
	}

	if(strcmp(c.prenom,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_prenom_ajouter"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_prenom_ajouter"));
	}

	if(strcmp(c.cin,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_cin_ajouter"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_cin_ajouter"));
	}

	if(strcmp(c.adresse,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_adresse_ajouter"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_adresse_ajout"));
	}

	if(strcmp(c.num_tel,"")==0){
			  gtk_widget_show (lookup_widget(objet,"label_echec_tel_ajouter"));
	b=0;
	}
	else {
			  gtk_widget_hide(lookup_widget(objet,"label_echec_tel_ajouter"));
	}

	if(b==1){
        if(exist_client(c.cin)==1)
        {

		gtk_widget_show (existe);
        }
        else
	{
		gtk_widget_hide (existe);
                ajouter_client(c);
		gtk_widget_show (success);
        }

	
	}

}


void
on_radiobutton_homme_modifier_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
	s=1;
}


void
on_radiobutton_femme_modifier_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
	s=2;
}


void
on_button_mise_a_jour_client_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_treeview_client_aff_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *gestion;
	GtkTreeIter iter;
		gchar *NOM;
		gchar *PRENOM;
		gchar *CIN;
		gchar *ADRESSE;
		gchar *NUM_TEL;
		gint  JOUR_NAISS;
		gint  MOIS_NAISS;
		gint  ANNEE_NAISS;
		gchar *SITUATION_SOCIALE;
		gchar *NATIONALITE;
		gchar *SEXE;
		
	client c;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	//obtention des valeurs de le ligne selectionne
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&CIN,3,&ADRESSE,4,&NUM_TEL,5,&JOUR_NAISS,6,&MOIS_NAISS,7,&ANNEE_NAISS,8,&SITUATION_SOCIALE,9,&NATIONALITE,10,&SEXE,-1);
	
	//copie des valeurs  pour le passer a la fonction supprimer  
	strcpy(c.cin,CIN);
	supprimer_client(c.cin);
	afficher_client(treeview,"client.txt"); 
	}

}




void
on_button_modifier_client_clicked      (GtkWidget        *objet,
                                        gpointer         user_data)
{
FILE *f;
	f=fopen("modifierC.txt","w");
	GtkWidget* gestion;

	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        //GtkWidget *label;
	client c;
        gchar* nom;
	gchar* prenom;
	gchar* cin;
	gchar* adresse;
	gchar* num_tel;
	//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        //label=lookup_widget(gestion,"label23");
        p=lookup_widget(objet,"treeview_client_aff");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {
		gtk_tree_model_get (model,&iter,0,&nom,1,&prenom,2,&cin,3,&adresse,4,&num_tel,-1);

	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_nom_modifier_gestion_client")),nom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_prenom_modifier_gestion_client")),prenom);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_adresse_modifier_gestion_client")),adresse);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet,"entry_tel_modifier_gestion_client")),num_tel);
 
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView
	   gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet,"notebook13")));
	   fprintf(f,"%s",cin);
	   //supprimer_client(cin);
	   
	
	}// modifier la ligne du fichier
	fclose(f);
}


void
on_treeview_reche_client_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
	GtkWidget *gestion;
	GtkTreeIter iter;
		gchar *NOM;
		gchar *PRENOM;
		gchar *CIN;
		gchar *ADRESSE;
		gchar *NUM_TEL;
		gint  JOUR_NAISS;
		gint  MOIS_NAISS;
		gint  ANNEE_NAISS;
		gchar *SITUATION_SOCIALE;
		gchar *NATIONALITE;
		gchar *SEXE;
		
	client c;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
	//obtention des valeurs de le ligne selectionne
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&CIN,3,&ADRESSE,4,&NUM_TEL,5,&JOUR_NAISS,6,&MOIS_NAISS,7,&ANNEE_NAISS,8,&SITUATION_SOCIALE,9,&NATIONALITE,10,&SEXE,-1);
	
	//copie des valeurs  pour le passer a la fonction supprimer  
	strcpy(c.nom,NOM);
	afficher_client(treeview,"client.txt"); 
}
}


void
on_button_rechercher_client_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *NOM;
	GtkWidget *gestion;
	GtkWidget *treeview1;
	char nom[100];
	NOM=lookup_widget (objet,"entry_rechercher_client");
	gestion=lookup_widget(objet,"Gestion_client");
	strcpy(nom, gtk_entry_get_text(GTK_ENTRY(NOM)));
	treeview1=lookup_widget(gestion,"treeview_reche_client");
	chercher_client(treeview1,nom);
}


void
on_radiobutton_homme_ajouter_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
	s=1;
}


void
on_radiobutton_femme_ajouter_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton));
	s=2;
}


void
on_button_refresh_client_clicked       (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_client;
	GtkWidget *treeview2;
	Gestion_client=lookup_widget(objet,"Gestion_client");
	treeview2=lookup_widget(Gestion_client,"treeview_client_aff");
	afficher_client(treeview2,"client.txt");
}



void
on_button_menu_client_clicked          (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *Acceuil_client;
	GtkWidget *test;
	test=lookup_widget(objet,"test");
	gtk_widget_hide (test);
	Acceuil_client=lookup_widget(objet,"Acceuil_client");
	Acceuil_client=create_Acceuil_client();
	gtk_widget_show (Acceuil_client);
}


void
on_button3_e_clicked                   (GtkWidget        *objet,
                                        gpointer         user_data)
{
	FILE *f=NULL;
	f=fopen("users.txt","r");
	admin c;
	GtkWidget *nom,*prenom,*password,*numero,*pays,*cin,*entry_jour,*entry_mois,*entry_annee,*entry_sexe,*enty_sexe;
	GtkWidget *creation_compte_employer,*test,*entry_role;

	//creation_compte_employer = create_creation_compte_employer();


	nom=lookup_widget(objet,"entry10_e");
	prenom=lookup_widget(objet,"entry11_e");
	password=lookup_widget(objet,"entry9_e");
	numero=lookup_widget(objet,"entry13_e");
	pays=lookup_widget(objet,"entry12_e");
	cin=lookup_widget(objet,"entry8_e");

	entry_jour=lookup_widget(objet,"spinbutton1_e");
	entry_mois=lookup_widget(objet,"spinbutton2_e");
	entry_annee=lookup_widget(objet,"spinbutton3_e");
	
	entry_sexe=lookup_widget(objet,"combobox_e");

	strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(c.password,gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(c.numero,gtk_entry_get_text(GTK_ENTRY(numero)));
	strcpy(c.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
	strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(cin)));

	c.dtjour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour));
	c.dtmois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois));
	c.dtannee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee));

	strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_sexe)));

	ajouter_c(c);
}



void
on_button_creer_compte_admin_clicked   (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *surface_admin;
	GtkWidget *creation_compte_admin;
	creation_compte_admin=lookup_widget(objet,"creation_compte_admin");
	surface_admin=lookup_widget(objet,"surface_admin");
	creation_compte_admin=create_creation_compte_admin();
	gtk_widget_hide (surface_admin);
	gtk_widget_show (creation_compte_admin);
}


void
on_button_nombre_troupeaux_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *nombre_de_troupeaux;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	nombre_de_troupeaux=lookup_widget(objet,"nombre_de_troupeaux");
	nombre_de_troupeaux=create_nombre_de_troupeaux();
	gtk_widget_show (nombre_de_troupeaux);
}	


void
on_button_meilleur_ouvrier_clicked     (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *meilleur_ouvrier;
	meilleur_ouvrier=lookup_widget(objet,"meilleur_ouvrier");
	dashbord=lookup_widget(objet,"dashbord");
	meilleur_ouvrier=create_meilleur_ouvrier();
	gtk_widget_hide (dashbord);
	gtk_widget_show (meilleur_ouvrier);
}


void
on_button_taux_absenteisme_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashbord;
float taux=0;
char ch1[20];

char ch2[20];
 float tab[12];
    int i;
taux_absenteisme = create_taux_absenteisme ();


for(i=0;i<12;i++){
    tab[i] =  calculer_taux_absenteisme(i+1)*100;
    printf("%f\n", tab[i]);
    sprintf(ch1,"label%d",i+1); 
    sprintf(ch2,"%.3f",tab[i]);
    strcat(ch2," %");
    gtk_label_set_text(GTK_LABEL( lookup_widget(taux_absenteisme,ch1) ),ch2);
    }






  gtk_widget_show (taux_absenteisme);
  dashbord=lookup_widget(button,"dashbord");
  gtk_widget_hide (dashbord);
}


void
on_button_annee_seche_clicked          (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *anneeseche;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	anneeseche=lookup_widget(objet,"anneeseche");
	anneeseche=create_anneeseche();
	gtk_widget_show (anneeseche);
}


void
on_button_submit_meilleur_ouvrier_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data)
{
int y,x;
char ch[50];
	GtkWidget *output;
	GtkWidget *meilleur_ouvrier;
	GtkWidget *entry_meilleur_ouvrier;
	output=lookup_widget(objet,"label_meilleur_ouvrier"); 
	entry_meilleur_ouvrier=lookup_widget(objet,"spinbutton_meilleur_ouvrier");
	x=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_meilleur_ouvrier));
	y=meilleur_ouvrier1(x);
	sprintf(ch,"%d",y);
	gtk_label_set_text(GTK_LABEL(output),ch);
}


void
on_showbutton_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
int i;
int pos;
int n;
char ch1[100]="";
char ch2[100]="";
char aff[1000];
n=annee_seche(tab_an,tab_temp);
pos=valeur_max(tab_temp,n);
output=lookup_widget(button,"label_seche");
for(i=0;i<=n;i++)
{sprintf(ch2,"%d\n",tab_an[i]);
strcat(ch1,ch2);}
sprintf(aff,"Les annees de plantations sont:\n%s \n L'annee la plus seche est %d ",ch1,tab_an[pos]);
gtk_label_set_text(GTK_LABEL(output),aff);

}


void
on_buttonnbtroupeau_clicked            (GtkWidget        *objet,
                                        gpointer         user_data)
{
int x;
	char ch[5],ch1[20];
	GtkWidget *labelnbtroupeau;
	GtkWidget *nombre_de_troupeaux;
	GtkWidget *entrytype5;
	nombre_de_troupeaux=lookup_widget(objet,"nombre_de_troupeaux");
	labelnbtroupeau=lookup_widget(objet,"labelnbtroupeau");
	entrytype5=lookup_widget(objet,"entrytype5");
	strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(entrytype5) ) );
	x=nombre_troupeau(ch1);
	sprintf(ch,"%d",x);
	gtk_label_set_text(GTK_LABEL(labelnbtroupeau),ch);
}


void
on_radio_humidite_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
	x=2;
	}
}


void
on_radio_humidite_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
	y=0;
	}
}


void
on_buttonrefresh1_clicked              (GtkWidget        *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestionDesCapteurs;
	GtkWidget *treeview_capteur;
	gestionDesCapteurs=lookup_widget(objet,"gestionDesCapteurs");
	treeview_capteur=lookup_widget(gestionDesCapteurs,"treeview_capteur");
	afficher_capteur(treeview_capteur);
}


void
on_radiobutton_employer_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=1;
}


void
on_radiobutton_admin_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
		if (gtk_toggle_button_get_active(togglebutton));
		s=2;
}

void
on_on_button3_c_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	FILE *f=NULL;
	f=fopen("employer.txt","r");
	employer e;
	GtkWidget *nom,*prenom,*password,*numero,*pays,*cin,*entry_jour,*entry_mois,*entry_annee,*entry_sexe,*enty_sexe;
	GtkWidget *creation_compte_employer,*test,*entry_role;

	//creation_compte_employer = create_creation_compte_employer();


	nom=lookup_widget(objet,"entry10_c");
	prenom=lookup_widget(objet,"entry11_c");
	password=lookup_widget(objet,"entry9_c");
	numero=lookup_widget(objet,"entry13_c");
	pays=lookup_widget(objet,"entry12_c");
	cin=lookup_widget(objet,"entry8_c");

	entry_jour=lookup_widget(objet,"spinbutton1_c");
	entry_mois=lookup_widget(objet,"spinbutton2_c");
	entry_annee=lookup_widget(objet,"spinbutton3_c");
	
	entry_sexe=lookup_widget(objet,"combobox_c");

	strcpy(e.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(e.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(e.password,gtk_entry_get_text(GTK_ENTRY(password)));
	strcpy(e.numero,gtk_entry_get_text(GTK_ENTRY(numero)));
	strcpy(e.pays,gtk_entry_get_text(GTK_ENTRY(pays)));
	strcpy(e.cin,gtk_entry_get_text(GTK_ENTRY(cin)));

	e.dtjour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_jour));
	e.dtmois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_mois));
	e.dtannee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(entry_annee));

	strcpy(e.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(entry_sexe)));

	ajouter_e(e);
}




void
on_button_dashbord_admin_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *surface_admin;
	surface_admin=lookup_widget(objet,"surface_admin");
	gtk_widget_hide (surface_admin);
	dashbord=lookup_widget(objet,"dashbordr");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_Creer_un_compte_Employer_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_employer;
	GtkWidget *surface_admin;
	surface_admin=lookup_widget(objet,"surface_admin");
	gtk_widget_hide (surface_admin);
	creation_compte_employer=lookup_widget(objet,"creation_compte_employer");
	creation_compte_employer=create_creation_compte_employer();
	gtk_widget_show (creation_compte_employer);
}


void
on_Creer_un_compte_admin_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_admin;
	GtkWidget *surface_admin;
	surface_admin=lookup_widget(objet,"surface_admin");
	gtk_widget_hide (surface_admin);
	creation_compte_admin=lookup_widget(objet,"creation_compte_admin");
	creation_compte_admin=create_creation_compte_admin();
	gtk_widget_show (creation_compte_admin);
}




void
on_buttonhumidite_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char ch[20],ch1[100];
GtkWidget *capdef;
GtkWidget *labelresultat;
capdef=lookup_widget(objet_graphique,"capdef");
labelresultat=lookup_widget(objet_graphique,"labelhumidite");
capteurTH();
chercher_marque("capteurH.txt",ch);
gtk_label_set_text(GTK_LABEL(labelresultat),ch);
}


void
on_buttontemperature_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char ch[20],ch1[100];
GtkWidget *capdef;
GtkWidget *labelresultat;
capdef=lookup_widget(objet_graphique,"capdef");
labelresultat=lookup_widget(objet_graphique,"labeltemperature");
capteurTH();
chercher_marque("capteurT.txt",ch);
gtk_label_set_text(GTK_LABEL(labelresultat),ch);
}


void
on_marque_capteur_defctueux_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *capdef;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	capdef=lookup_widget(objet,"dashbord");
	capdef=create_capdef();
	gtk_widget_show (capdef);
}


void
on_treeview_capteur_valeur_alarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id_capteur;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model,&iter,path))
{

gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id_capteur,-1);  
/*copie des valeur dans un variable c de type capteur pour qu on puisse utiliser la fonction supprimer*/


 
supprimer_capteur1(id_capteur);
afficher_capteur1(treeview);
}
}


void
on_valider_valeur_alarmante_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char valeurmin[10];
char valeurmax[10];
capteur c1;
GtkWidget *seuil_min;
GtkWidget *seuil_max,*treeview_capteur_valeur_alarmante;
seuil_min=lookup_widget(objet,"entry_seuil_min");
strcpy(valeurmin,gtk_entry_get_text(GTK_ENTRY(seuil_min)));
seuil_max=lookup_widget(objet,"entry_seuil_max");
strcpy(valeurmax,gtk_entry_get_text(GTK_ENTRY(seuil_max)));
FILE *f;
FILE *g;
f=fopen("capteur.txt","r");
g=fopen("capteuralarmante.txt","w");
	if(f==NULL)
		return;
	else
	{
			while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,&c1.datef.jour,&c1.datef.mois,&c1.datef.annee,&c1.datep.jour,&c1.datep.mois,&c1.datep.annee)!=EOF)
			{

					if((strcmp(c1.valeur,valeurmin)==-1)||(strcmp(valeurmax,c1.valeur)==1))
						fprintf(g,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,c1.datef.jour,c1.datef.mois,c1.datef.annee,c1.datep.jour,c1.datep.mois,c1.datep.annee);


			}
	}
fclose(f);
fclose(g);
treeview_capteur_valeur_alarmante=lookup_widget(objet,"treeview_capteur_valeur_alarmante");
afficher_capteur1(treeview_capteur_valeur_alarmante);
}


void
on_capteur_alarmante_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *window_capteur_valeur_alarmante;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	window_capteur_valeur_alarmante=lookup_widget(objet,"window_capteur_valeur_alarmante");
	window_capteur_valeur_alarmante=create_window_capteur_valeur_alarmante();
	gtk_widget_show (window_capteur_valeur_alarmante);
}




void
on_button_retour_admin_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *capdef;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	capdef=lookup_widget(objet,"dashbord");
	capdef=create_capdef();
	gtk_widget_show (capdef);
}


void
on_button_retour_calendrier_test_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *capdef;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	capdef=lookup_widget(objet,"dashbord");
	capdef=create_capdef();
	gtk_widget_show (capdef);
}


void
on_button_retour_equipement_test_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *test;
	GtkWidget *acceuil_gestion_equipement;
	acceuil_gestion_equipement=lookup_widget(objet,"acceuil_gestion_equipement");
	gtk_widget_hide (acceuil_gestion_equipement);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_capteur_test_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *test;
	GtkWidget *gestionDesCapteurs;
	gestionDesCapteurs=lookup_widget(objet,"gestionDesCapteurs");
	gtk_widget_hide (gestionDesCapteurs);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_acceuil_test_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *test;
	GtkWidget *acceuil;
	acceuil=lookup_widget(objet,"acceuil");
	gtk_widget_hide (acceuil);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_gestion_acceuil_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion;
	GtkWidget *acceuil;
	gestion=lookup_widget(objet,"gestion");
	gtk_widget_hide (gestion);
	acceuil=lookup_widget(objet,"acceuil");
	acceuil=create_acceuil();
	gtk_widget_show (acceuil);
}


void
on_button_retour_menu_test_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menu;
	GtkWidget *test;
	menu=lookup_widget(objet,"menu");
	gtk_widget_hide (menu);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_calendrier_menu_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *menu;
	GtkWidget *gestion_calendrier;
	gestion_calendrier=lookup_widget(objet,"gestion_calendrier");
	gtk_widget_hide (gestion_calendrier);
	menu=lookup_widget(objet,"menu");
	menu=create_menu();
	gtk_widget_show (menu);
}


void
on_button_retour_troupeaux_acceuil_troupeaux_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_troupeaux;
	GtkWidget *espace_troupeaux;
	gestion_troupeaux=lookup_widget(objet,"gestion_troupeaux");
	gtk_widget_hide (gestion_troupeaux);
	espace_troupeaux=lookup_widget(objet,"espace_troupeaux");
	espace_troupeaux=create_espace_troupeaux();
	gtk_widget_show (espace_troupeaux);
}


void
on_button_retour_espace_troupeaux_test_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *test;
	GtkWidget *espace_troupeaux;
	espace_troupeaux=lookup_widget(objet,"espace_troupeaux");
	gtk_widget_hide (espace_troupeaux);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_gestion_client_test_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *test;
	GtkWidget *Acceuil_client;
	Acceuil_client=lookup_widget(objet,"Acceuil_client");
	gtk_widget_hide (Acceuil_client);
	test=lookup_widget(objet,"test");
	test=create_test();
	gtk_widget_show (test);
}


void
on_button_retour_compte_employer_dashbord_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_employer;
	GtkWidget *dashbord;
	creation_compte_employer=lookup_widget(objet,"creation_compte_employer");
	gtk_widget_hide (creation_compte_employer);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_button_retour_compte_employer_surface_admin_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_employer;
	GtkWidget *surface_admin;
	creation_compte_employer=lookup_widget(objet,"creation_compte_employer");
	gtk_widget_hide (creation_compte_employer);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin=create_surface_admin();
	gtk_widget_show (surface_admin);
}


void
on_button_retour_dashbord_surface_admin_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *dashbord;
	GtkWidget *surface_admin;
	dashbord=lookup_widget(objet,"dashbord");
	gtk_widget_hide (dashbord);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin=create_surface_admin();
	gtk_widget_show (surface_admin);
}


void
on_button_retour_nb_troupeaux_dashbord_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *nombre_de_troupeaux;
	GtkWidget *dashbord;
	nombre_de_troupeaux=lookup_widget(objet,"nombre_de_troupeaux");
	gtk_widget_hide (nombre_de_troupeaux);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_button_retour_taux_ab_dashbord_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *taux_absenteisme;
	GtkWidget *dashbord;
	taux_absenteisme=lookup_widget(objet,"taux_absenteisme");
	gtk_widget_hide (taux_absenteisme);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_button_retour_gestion_client_acceuil_client_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Gestion_client;
	GtkWidget *Acceuil_client;
	Gestion_client=lookup_widget(objet,"Gestion_client");
	gtk_widget_hide (Gestion_client);
	Acceuil_client=lookup_widget(objet,"Acceuil_client");
	Acceuil_client=create_Acceuil_client();
	gtk_widget_show (Acceuil_client);
}


void
on_button_retour_compte_admin_surface_admin_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_admin;
	GtkWidget *surface_admin;
	creation_compte_admin=lookup_widget(objet,"creation_compte_admin");
	gtk_widget_hide (creation_compte_admin);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin=create_surface_admin();
	gtk_widget_show (surface_admin);
}





void
on_button_retour_capteur_alar_dashbord_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window_capteur_valeur_alarmante;
	GtkWidget *dashbord;
	window_capteur_valeur_alarmante=lookup_widget(objet,"window_capteur_valeur_alarmante");
	gtk_widget_hide (window_capteur_valeur_alarmante);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_button_retour_meilleur_ouvrier_dashbord_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window_capteur_valeur_alarmante;
	GtkWidget *surface_admin;
	window_capteur_valeur_alarmante=lookup_widget(objet,"window_capteur_valeur_alarmante");
	gtk_widget_hide (window_capteur_valeur_alarmante);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin=create_surface_admin();
	gtk_widget_show (surface_admin);
}


void
on_button_anneeseche_dashbord_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *anneeseche;
	GtkWidget *dashbord;
	anneeseche=lookup_widget(objet,"anneeseche");
	gtk_widget_hide (anneeseche);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);

}


void
on_button_retour_compte_employer1_surface_admin_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *creation_compte_employer;
	GtkWidget *surface_admin;
	creation_compte_employer=lookup_widget(objet,"creation_compte_employer");
	gtk_widget_hide (creation_compte_employer);
	surface_admin=lookup_widget(objet,"surface_admin");
	surface_admin=create_surface_admin();
	gtk_widget_show (surface_admin);
}


void
on_button_meilleur_dashb_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *meilleur_ouvrier;
	GtkWidget *dashbord;
	meilleur_ouvrier=lookup_widget(objet,"meilleur_ouvrier");
	gtk_widget_hide (meilleur_ouvrier);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_button_retour_capdef_dashbord_clicked
                                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *capdef;
	GtkWidget *dashbord;
	capdef=lookup_widget(objet,"capdef");
	gtk_widget_hide (capdef);
	dashbord=lookup_widget(objet,"dashbord");
	dashbord=create_dashbord();
	gtk_widget_show (dashbord);
}


void
on_on_button_retour_equipement_acceuilequipement_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *gestion_equipement;
	GtkWidget *acceuil_gestion_equipement;
	gestion_equipement=lookup_widget(objet,"gestion_equipement");
	gtk_widget_hide (gestion_equipement);
	acceuil_gestion_equipement=lookup_widget(objet,"dashbord");
	acceuil_gestion_equipement=create_acceuil_gestion_equipement();
	gtk_widget_show (acceuil_gestion_equipement);
}




