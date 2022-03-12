typedef struct {
char nom [20];
char prenom [20];
char password [20];
char numero [20];
char pays [20];
char cin [20];
int  dtjour;	
int  dtmois;
int  dtannee;
char sexe[20];
char role[50];

}admin;
int verifier1(char login[20], char password[20]);
void ajouter_c(admin c);


