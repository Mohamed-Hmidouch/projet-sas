#include <stdio.h>
#include <stdlib.h>
#include "fuction.h"
#include <string.h>
int main()
{
    int options;
    do{
        printf("--------------------------------\n");
        printf("1-ajouter un etudiant.\n");
        printf("2-modifer un des  etudiant.\n");
        printf("3-Suprimer un etudiant.\n");
        printf("4-Aficher les details d'un etudiant.\n");
        printf("5-calculer la moyenne general d'etudiant.\n");
        printf("6-voir le menu de statistique.\n");
        printf("7-recherche par etudiant.\n");
        printf("8-fonction de tri des informations des etudiants.\n");
        printf("--------------------------------\n");
        printf("entrer votre choix : ");
        scanf("%d",&options);
////////////////////////MENU///////////////////////////
        switch(options){
        case 1 :
        ajoute();
        break;
        case 2 :
        modifier();
        break;
        case 3 :
        suprimer();
        break;
        case 4 :
        afichage();
        break;
        case 5 :
        Calcul();
        break;
        case 6 :
        printf("pas encore fait");
        //Statistiques();//
        break;
        case 7:
        /*pas encore fait
        recherche();
        break;
        case 8:
        Triage();
        break;*/
        default:
            printf("error");
            break;
        }

    }while(options !=9);
    return 0;

}
