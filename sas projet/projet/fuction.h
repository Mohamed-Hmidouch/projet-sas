#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <string.h>
#include "struct.h"
struct informations etudiant[300];
int nbr_eleve=0;
char numero_unique[100];
char recherche[100];
//////////fonction d'ajoute//////
void ajoute()
{
    int i=0;
    struct informations etudiant[100];
    int sortie;
    do{
        printf("--------------------------------\n");
        printf("ajouter les informations d'etudiant:\n");
        printf("ajouter le id ,exemple(D12345) :");
        scanf(" %[^\n]",etudiant[i].numero_unique);
        printf("ajouter le nom  :");
        scanf(" %[^\n]",etudiant[i].nom);
        printf("ajouter le prenom  : ");
        scanf(" %[^\n]",etudiant[i].prenom);
        printf("ajouter la date de naissance d'etudiant exemple(1/1/2000): ");
        scanf(" %[^\n]",etudiant[i].date_naissance);
        printf("ajouter le departement : ");
        scanf(" %[^\n]",etudiant[i].departement);
        printf("ajouter la note generale d'etudiant : ");
        scanf("%f",&etudiant[i].note_generale);
        nbr_eleve++;
        printf("voulez vous continue encore?\n");
        printf("1-oui\n");
        printf("2-non\n");
        scanf("%d",&sortie);
        printf("--------------------------------\n");
    }while(sortie != 2);

};
//////////////fonction d'modifier/////////
void modifier()
{
    int i;
    struct informations etudiant[100];
    printf("entrer le numero unique que vous voulez modifer :");
    scanf(" %[^\n]",recherche);
    for(i=0; i<nbr_eleve; i++)
    {
        if(strcmp(recherche,etudiant[i].numero_unique)==0)
        {
            printf("entre le nouveaux nom :");
            scanf("%s[\n]",etudiant[i].nom);
            printf("entre le nouveaux prenom ");
            scanf("%s[\n]",etudiant[i].prenom);
            printf("entre le nouveaux date de naissance exemple(1/1/2000): ");
            scanf("%s[\n]",etudiant[i].date_naissance);
            printf("entre le nouveaux departemment :");
            scanf("%s[\n]",etudiant[i].departement);
            printf("entre le nouvelle moyenne :");
            scanf("%f[\n]",&etudiant[i].note_generale);

        }
        else
        {
            printf("ce numero est invalide.");
        }
    }



}
//////////fonction de suprimer//////
void suprimer()
{

    int i;
    struct informations etudiant[100];
    printf("entrer l'id que vous voulez le suprimer :");
    scanf(" %[^\n]",recherche);
    for(i=0; i<nbr_eleve; i++)
    {
                if(strcmp(etudiant[i].numero_unique,recherche)==0){
                        int j;
                       for(j=i;j<nbr_eleve-1;j++){
                        numero_unique[j]=numero_unique[ j + 1];
                       }
                    nbr_eleve--;
                    printf("l'eleve est suprimer.\n");
                }

    }
}
void afichage(){
   int i;
   struct informations etudiant[100];
   printf("quel etudiant afficher[id]");
   scanf(" %[^\n]",recherche);
   for(i=0; i<nbr_eleve; i++)
            {
                if(strcmp(etudiant[i].numero_unique,recherche)==0){
                printf("id d'eleve est : \n",etudiant[i].numero_unique);
                printf("le nom d'eleve est : %s \n",etudiant[i].nom);
                printf("le prenom d'eleve est : %s \n",etudiant[i].prenom);
                printf("la date de naissance est : %s \n",etudiant[i].date_naissance);
                printf("la moyenne general est : %.2f \n",etudiant[i].note_generale);
                }

            };
}
void calcul(){
  struct informations etudiant[100];
  char departement_1[50];
  float somme_general=0;
  float m_eleve= 0;
  int N=0;
  printf("entre le departemment :");
  scanf(" %[^\n]s",departement_1);
  for(int i=0;i<nbr_eleve;i++){
    somme_general = etudiant[i].note_generale;
    m_eleve = m_eleve + somme_general;
    N++;
  }
  m_eleve = m_eleve/N;
  printf("la moyenne general de departemment %s est :%.2f \n",departement_1,m_eleve);
}
void Statistiques(){
int cotinue;
    do{
        printf("1-Afficher le nombre total d'étudiants inscrits.\n");
        printf("2-Afficher le nombre d'etudiants dans chaque departement.\n");
        printf("3-Afficher les etudiants ayant une moyenne generale superieure à un certain seuil.\n");
        printf("4-Afficher les 3 etudiants ayant les meilleures notes.\n");
        printf("5-Afficher le nombre d'etudiants ayant reussi dans chaque departement (ceux ayant une note superieure ou egale à 10/20).\n");
        printf("voulez vous continue encore?\n");
        printf("1-oui\n");
        printf("2-non\n");
        scanf("%d",&cotinue);
        ///////////switch///////////
    switch(cotinue){
    case 1:
    printf("le nombre d'etudients inscrits est : %d\n",nbr_eleve);
    break ;
    case 2:
    break ;
    case 3:
    break ;
    case 4:
    break ;
    case 5:
    break ;
    default:
    printf("entrer un autre choix valable");
    break;
    }
    }while(cotinue !=2);
}
#endif // FONCTION_H_INCLUDED
