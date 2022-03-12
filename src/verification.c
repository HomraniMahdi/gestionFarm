#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verification.h"
#include <gtk/gtk.h>

int verifier(char login[20], char password[20]){
FILE *f ;
int test=0;
f=fopen("employer.txt","r") ;
char login1[20]; char password1[20]; int role;
if (f!=NULL) {
while ((fscanf(f,"%s %s %d",login1,password1,&role)!=EOF)) {
if ((strcmp(login1,login)==0) && (strcmp(password1,password))==0){ 
test=role;
}}
fclose(f);
}
return test;
}
void ajouter_e(employer e)
{
FILE *f=NULL;
f=fopen("employer.txt","a");
if(f!=NULL){
fprintf(f,"%s %s %s %s %s %s %d %d %d %s\n",e.nom,e.prenom,e.password,e.numero,e.pays,e.cin,e.dtjour,e.dtmois,e.dtannee,e.sexe,e.role);
fclose(f);
}}

