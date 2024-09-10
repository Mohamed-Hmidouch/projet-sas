#include <stdio.h>
#include <stdlib.h>
#include "fuction.h"

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
        printf("6-sortier de programme.\n");
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
        /*case 3 :
        suprimer();
        break;
        case 4 :
        afichage();
        break;
        case 5 :
        recherhche();
        break;
        */
        default:
            printf("error");
            break;
        }

    }while(options !=6);
    return 0;

}
