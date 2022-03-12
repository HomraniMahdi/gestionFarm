#include <gtk/gtk.h>


int i;
GtkWidget *gestion_calendrier;
GtkWidget *menu;
GtkWidget *taux_absenteisme;

void
on_button_acceuil_clicked              (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_clicked              (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_confirmer_ajouter_ouvrier_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_radiobutton_homme_sexe_ajouter_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_sexe_ajouter_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_mise_a_jour_ouvrier_clicked  (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_radiobutton_homme_sexe_modifier_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_sexe_modifier_ouvrier_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_buttonrefresh_clicked               (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_modifier_ouvrier_clicked     (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_rechercher_ouvrier_clicked   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_gest_calendrier_clicked             (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_menu_ouvrier_clicked          (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_menu_plantation_clicked       (GtkWidget        *objet,
                                        gpointer         user_data);
void
on_ajouter_calendrier_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_calendrier_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_calendrier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_verifier_calendrier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_gest_calendrier_clicked      (GtkButton       *button,
                                        gpointer         user_data);


void
on_radio_temperature_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_capteur_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton4_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_supprimer_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_afficherm_capteur_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton1_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_temperature_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modifier_capteur_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_capteur_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_menu_capteur_clicked         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_gestion_equipement_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_equipement_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview_rech_equipement_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_button_afficher_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);;

void
on_button_recherche_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_a_modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_menu_equipement_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button2_login_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button_afficher_troupeaux_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_ajouter_troupeaux_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_afficher_troupeaux1_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_supprimer_troupeaux_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_troupeaux_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_afficher_troupeaux2_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_button_gestion_troupeaux_clicked    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_treeview_affichage_troupeaux_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_menu_troupeaux_clicked       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_acceuil_client_clicked       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_confirmer_ajouter_gestion_client_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_radiobutton_homme_modifier_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_modifier_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_mise_a_jour_client_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_client_aff_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_modifier_client_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_reche_client_row_activated (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_rechercher_client_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_radiobutton_homme_ajouter_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_ajouter_gestion_client_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_refresh_client_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_menu_client_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button3_e_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_button_creer_compte_admin_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_nombre_troupeaux_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_button_meilleur_ouvrier_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_taux_absenteisme_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_annee_seche_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_submit_meilleur_ouvrier_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_showbutton_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);
void
on_buttonnbtroupeau_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radio_humidite_ajouter_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_humidite_modifier_capteur_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_buttonrefresh1_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_employer_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_admin_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_on_button3_c_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Creer_un_compte_Employer_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_Creer_un_compte_admin_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_dashbord_admin_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhumidite_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_buttontemperature_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_marque_capteur_defctueux_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_capteur_valeur_alarmante_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_valider_valeur_alarmante_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_capteur_alarmante_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button_retour_admin_clicked          (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_calendrier_test_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_equipement_test_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_capteur_test_clicked   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_acceuil_test_clicked   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_gestion_acceuil_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_menu_test_clicked      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_calendrier_menu_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_troupeaux_acceuil_troupeaux_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_espace_troupeaux_test_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_gestion_client_test_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);
void
on_button_retour_compte_employer_dashbord_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_compte_employer_surface_admin_clicked
                                       (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_dashbord_surface_admin_clicked
                                      (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_nb_troupeaux_dashbord_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_taux_ab_dashbord_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_gestion_client_acceuil_client_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_compte_admin_surface_admin_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);



void
on_button_retour_capteur_alar_dashbord_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_meilleur_ouvrier_dashbord_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_anneeseche_dashbord_clicked   (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_compte_employer1_surface_admin_clicked
                                         (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_meilleur_dashb_clicked        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_button_retour_capdef_dashbord_clicked
                                        (GtkWidget        *objet,
                                        gpointer         user_data);

void
on_on_button_retour_equipement_acceuilequipement_clicked
                                     (GtkWidget        *objet,
                                        gpointer         user_data);



