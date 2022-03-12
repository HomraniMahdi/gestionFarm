#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "absenteisme.h"




float calculer_taux_absenteisme(int m){
FILE*f=NULL;
int a=0,nbTot=0;
absenteisme ab;
f=fopen("absenteisme.txt","r");//(+) creation du fichier sil nexsite pas
while(fscanf(f,"%s %d %d %d %d\n",ab.id,&ab.jj,&ab.mm,&ab.aa,&ab.present)!=EOF){
if(ab.mm==m){
if(ab.present==0)
{a++;}

nbTot++;
}
}

fclose(f);
printf("nb Absence = %d\nnbTotale = %d\n",a,nbTot);
return (float)a/nbTot ;
}
