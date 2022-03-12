
typedef struct calendrier calendrier;
struct calendrier{
char id[20];
char type[30];
char genre[30];
int jj;
int mm;
int aa;
};



void ajouter_Nouv_calendrier(calendrier c);
int exist_calendrier(char*id);
void supprimer_calendrier(char*id);
calendrier retourner_calendrier(char*id);
void modifier_calendrier(calendrier c);
void treeView_calendrier(GtkWidget* treeview1,char*l);
