#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include "struct.h"
struct informations etudients[300];
int nbr_etudiant = 0;
//////////fonction d'ajoute//////
void ajoute()
{
    int i=0;
    int  choix;
    struct informations etudiant[100];

        do{
        printf("--------------------------------\n");
        printf("ajouter les informations de  [%d] etudiant:\n",i+1);
        printf("ajouter le numero unique d'eleve  :");
        scanf(" %[^\n]",etudiant[i].numero_unique);
        printf("ajouter le nom de  :");
        scanf(" %[^\n]",etudiant[i].nom);
        printf("ajouter le prenom  : ");
        scanf(" %[^\n]",etudiant[i].prenom);
        printf("ajouter la date de naissance d'etudiant: ");
        scanf(" %[^\n]",etudiant[i].date_naissance);
        printf("ajouter le departement : ");
        scanf(" %[^\n]",etudiant[i].departement);
        printf("ajouter la note generale d'etudiant : ");
        scanf("%f",&etudiant[i].note_generale);
        nbr_etudiant++;
        printf("voulez vous ajouter un autre choix 1-yes ; 2-no :");
        scanf("%d",&choix);
        printf("--------------------------------\n");
         }while(choix!=2);

};
//////////////fonction d'modifier/////////
 void modifier()
{
    int i;
    char modifier_info[20];
    struct informations etudiant[100];
    printf("entrer le nom de contact que vous voulez modifer :");
    scanf(" %[^\n]",modifier_info);
    for(i=0; i<nbr_etudiant; i++)
    {
        if(strcmp(etudiant[i].nom,modifier_info)==0)
        {
       printf("entre le nouveaux numero unique");
       scanf(" %[\n]",etudiant[i].numero_unique);
       printf("entre le nouveaux nom");
       scanf(" %[\n]",etudiant[i].nom);
       printf("entre le nouveaux prenom");
       scanf(" %[\n]",etudiant[i].prenom);
       printf("entre le nouveaux date de naissance");
       scanf(" %[\n]",etudiant[i].date_naissance);
       printf("entre le nouveaux departemment");
       scanf(" %[\n]",etudiant[i].departement);
       printf("entre le nouvelle moyenne :");
       scanf(" %[\n]f",etudiant[i].note_generale);

        }
    }



}
#endif // FONCTION_H_INCLUDED
