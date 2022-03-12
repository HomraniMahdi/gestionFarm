#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificationA.h"
#include <gtk/gtk.h>

int verifier1(char login[20], char password[20]){
FILE *f ;
FILE *f1 ;
int test=0;
f=fopen("users.txt","r") ;
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
void ajouter_c(admin c)
{
FILE *f=NULL;
f=fopen("users.txt","a");
if(f!=NULL){
fprintf(f,"%s %s %s %s %s %s %d %d %d %s %s\n",c.nom,c.prenom,c.password,c.numero,c.pays,c.cin,c.dtjour,c.dtmois,c.dtannee,c.sexe,c.role);
fclose(f);
}}

