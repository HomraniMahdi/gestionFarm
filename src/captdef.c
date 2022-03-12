#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <config.h>
#include "captdef.h"
#include "support.h"






void capteurTH()
{
	FILE *f,*f1,*f2;
	f=fopen("capteur.txt","r");
	f1=fopen("capteurT.txt","w");
	f2=fopen("capteurH.txt","w");
	capteur c1;
	if(f==NULL)
		return;
	else
	{
		while(fscanf(f,"%s %s %s %s %s %d %d %d %d %d %d \n",c1.id_capteur,c1.marque,c1.type,c1.etat,c1.valeur,&c1.datef.jour,&c1.datef.mois,&c1.datef.annee,&c1.datep.jour,&c1.datep.mois,&c1.datep.annee)!=EOF)
		{
			if(strcmp(c1.type,"temperature")==0)
				fprintf(f1,"%s %s\n",c1.marque,c1.etat);
			else
				fprintf(f2,"%s %s\n",c1.marque,c1.etat);
				
		}
	}
	fclose(f);
	fclose(f1);
	fclose(f2);
}


void chercher_marque(char file[100],char ch[20])
{
    FILE *f3;
    int i=1,n=0,j,k,c1,max1=0,pos;
    char mot[100][100];
    int max[100]={0};
    char marque[20];
    char etat[20];
    FILE *f,*ftmp,*f2;
    f=fopen(file,"r");
    ftmp=fopen("tmp6.txt","w");
   
    while(!feof(f))
    {
        fscanf(f,"%s %s\n",marque,etat);
        if(strcmp(etat,"défectueux")==0)
   	{
            fprintf(ftmp,"%10s\n",marque);
                n++;

   	}
       
    }
    fclose(ftmp);
    f2=fopen("tmp6.txt","r");
    fgets(mot[0],11,f2);
    while ((c1 = getc(f2)) != EOF)
    {
        if(c1=='\n')
        {
            fgets(mot[i],11,f2);
            i++;
        }
    }
    fclose(f2);
    fclose(f);
    for(j=0;j<n;j++)
    {
        for(k=0;k<n;k++)
        {
    	    if(strcmp(mot[j],mot[k])==0)
        	max[j]++;
        }
    }
    for(j=0;j<n;j++)
    {
        if(max[j]>max1)
        {
            max1=max[j];
            pos=j;
        }
    }
    strcpy(ch,mot[pos]);


}

