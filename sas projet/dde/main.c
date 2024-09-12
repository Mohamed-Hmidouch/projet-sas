#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 50
#define MAX_NOM 20
#define MAX_DEPARTEMENTS 4

typedef struct {
    char numero_unique[MAX_NOM];
    char nom[MAX_NOM];
    char prenom[MAX_NOM];
    int jour, mois, annee;
    char departement[MAX_NOM];
    float note;
} Etudiant;

// D�claration des tableaux pour stocker les �tudiants par d�partement
char departements[MAX_DEPARTEMENTS][MAX_ETUDIANTS][MAX_NOM];
int nb_etudiants_par_departement[MAX_DEPARTEMENTS] = {0};

// Variables globales
Etudiant etudiants[MAX_ETUDIANTS];
int nb_etudiants = 0;

// Fonctions pour g�rer les d�partements
int trouver_index_departement(const char *departement) {
    static const char *departements_disponibles[MAX_DEPARTEMENTS] = {
        "informatique", "english", "francais", "ENCG"
    };
    for (int i = 0; i < MAX_DEPARTEMENTS; i++) {
        if (strcmp(departement, departements_disponibles[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// Fonction pour ajouter un �tudiant
void ajouter_etudiant() {
    int choix;
    printf("Entrez le num�ro unique : ");
    scanf("%s", etudiants[nb_etudiants].numero_unique);
    printf("Entrez le nom de l'�tudiant : ");
    scanf("%s", etudiants[nb_etudiants].nom);
    printf("Entrez le pr�nom : ");
    scanf("%s", etudiants[nb_etudiants].prenom);
    printf("Entrez la date de naissance (JJ/MM/AAAA) : ");
    scanf("%d/%d/%d", &etudiants[nb_etudiants].jour, &etudiants[nb_etudiants].mois, &etudiants[nb_etudiants].annee);
    printf("Entrez le d�partement :\n");
    printf("1. Informatique\n");
    printf("2. English\n");
    printf("3. Fran�ais\n");
    printf("4. ENCG\n");
    scanf("%d", &choix);

    const char *departements_disponibles[MAX_DEPARTEMENTS] = {
        "informatique", "english", "francais", "ENCG"
    };

    if (choix >= 1 && choix <= MAX_DEPARTEMENTS) {
        strcpy(etudiants[nb_etudiants].departement, departements_disponibles[choix - 1]);
        int index = trouver_index_departement(departements_disponibles[choix - 1]);
        strcpy(departements[index][nb_etudiants_par_departement[index]], etudiants[nb_etudiants].nom);
        nb_etudiants_par_departement[index]++;
    } else {
        printf("D�partement non valide !\n");
    }

    printf("Entrez la note g�n�rale : ");
    scanf("%f", &etudiants[nb_etudiants].note);
    nb_etudiants++;

    printf("Voulez-vous ajouter un nouvel �tudiant ?\n");
    printf("1. Oui\n");
    printf("2. Non\n");
    scanf("%d", &choix);
    if (choix == 1) {
        ajouter_etudiant();
    }
}

// Fonction pour supprimer un �tudiant
void supprimer_etudiant() {
    char numero_unique[MAX_NOM];
    printf("Entrez le num�ro unique de l'�tudiant � supprimer : ");
    scanf("%s", numero_unique);

    int index = -1;
    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(etudiants[i].numero_unique, numero_unique) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("�tudiant non trouv� !\n");
        return;
    }

    int depart_index = trouver_index_departement(etudiants[index].departement);
    for (int i = index; i < nb_etudiants - 1; i++) {
        etudiants[i] = etudiants[i + 1];
    }

    nb_etudiants--;
    nb_etudiants_par_departement[depart_index]--;
}

// Fonction pour modifier les informations d'un �tudiant
void modifier_etudiant() {
    char numero_unique[MAX_NOM];
    printf("Entrez le num�ro unique de l'�tudiant � modifier : ");
    scanf("%s", numero_unique);

    int index = -1;
    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(etudiants[i].numero_unique, numero_unique) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("�tudiant non trouv� !\n");
        return;
    }

    int choix;
    printf("Quel aspect souhaitez-vous modifier ?\n");
    printf("1. Num�ro unique\n");
    printf("2. Nom\n");
    printf("3. Pr�nom\n");
    printf("4. Date de naissance\n");
    printf("5. D�partement\n");
    printf("6. Note g�n�rale\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Entrez le nouveau num�ro unique : ");
            scanf("%s", etudiants[index].numero_unique);
            break;
        case 2:
            printf("Entrez le nouveau nom : ");
            scanf("%s", etudiants[index].nom);
            break;
        case 3:
            printf("Entrez le nouveau pr�nom : ");
            scanf("%s", etudiants[index].prenom);
            break;
        case 4:
            printf("Entrez la nouvelle date de naissance (JJ/MM/AAAA) : ");
            scanf("%d/%d/%d", &etudiants[index].jour, &etudiants[index].mois, &etudiants[index].annee);
            break;
        case 5:
            {
                char nouveau_departement[MAX_NOM];
                printf("Entrez le nouveau d�partement : ");
                scanf("%s", nouveau_departement);
                int ancien_index = trouver_index_departement(etudiants[index].departement);
                int nouveau_index = trouver_index_departement(nouveau_departement);

                if (ancien_index != -1) {
                    nb_etudiants_par_departement[ancien_index]--;
                }
                if (nouveau_index != -1) {
                    strcpy(etudiants[index].departement, nouveau_departement);
                    strcpy(departements[nouveau_index][nb_etudiants_par_departement[nouveau_index]], etudiants[index].nom);
                    nb_etudiants_par_departement[nouveau_index]++;
                } else {
                    printf("D�partement non valide !\n");
                }
            }
            break;
        case 6:
            printf("Entrez la nouvelle note g�n�rale : ");
            scanf("%f", &etudiants[index].note);
            break;
        default:
            printf("Choix invalide !\n");
            break;
    }
}

// Fonction pour afficher les d�tails des �tudiants
void afficher_etudiants() {
    for (int i = 0; i < nb_etudiants; i++) {
        printf("**** %s *******\n", etudiants[i].nom);
        printf("Num�ro unique : %s\n", etudiants[i].numero_unique);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Pr�nom : %s\n", etudiants[i].prenom);
        printf("Date de naissance : %d/%d/%d\n", etudiants[i].jour, etudiants[i].mois, etudiants[i].annee);
        printf("D�partement : %s\n", etudiants[i].departement);
        printf("Note g�n�rale : %.2f\n", etudiants[i].note);
        printf("\n");
    }
}

// Fonction pour calculer les moyennes
void calculer_moyenne_departements() {
    float somme_note[MAX_DEPARTEMENTS] = {0};
    int total_etudiants[MAX_DEPARTEMENTS] = {0};

    for (int i = 0; i < nb_etudiants; i++) {
        int index = trouver_index_departement(etudiants[i].departement);
        if (index != -1) {
            somme_note[index] += etudiants[i].note;
            total_etudiants[index]++;
        }
    }

    int choix;
    printf("Que souhaitez-vous calculer ?\n");
    printf("1. La moyenne g�n�rale de chaque d�partement\n");
    printf("2. La moyenne g�n�rale de l'universit�\n");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Quel d�partement souhaitez-vous consulter ?\n");
        printf("1. Informatique\n");
        printf("2. English\n");
        printf("3. Fran�ais\n");
        printf("4. ENCG\n");
        scanf("%d", &choix);

        if (choix >= 1 && choix <= MAX_DEPARTEMENTS) {
            int index = choix - 1;
            if (total_etudiants[index] > 0) {


};
