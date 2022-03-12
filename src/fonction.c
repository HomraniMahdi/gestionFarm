#include <stdio.h>
int annee_seche(int tab_an[],float tab_temp[])
{
    FILE *f;
    int i, n=0;
    int id,j,m,a;
    float temp;
    f=fopen("temperature.txt","r");
    if(f!=NULL)

    {
        while(fscanf(f,"%d %d %d %d %f",&id,&j,&m,&a,&temp)!=EOF)
           {i=0;
        while(a!=tab_an[i]&&i<n)
                        i++;
if (i==n)
{tab_an[i]=a;
       n++; }
   }


n=i;

for(i=0;i<n;i++)
    while(fscanf(f,"%d %d %d %d %f",&id,&j,&m,&a,&temp)!=EOF)
{
    if(tab_an[i]==a)
        tab_temp[i]+=temp/365;
}
    }
return n;
}


int valeur_max(float tab[],int n)
{
    int i,pos;
    float max;
    max=tab[0];
    for(i=1;i<n;i++)
    {
        if(tab[i]>max)
            max=tab[i];
           pos=i;
    }
    return pos;

}

