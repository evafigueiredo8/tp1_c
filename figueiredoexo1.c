#include "figueiredolisteint.h"
#include <stdio.h>

int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
        "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
        "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
        "4 Supprimer l'élément de tête\n"
        "5 Supprimer tous les maillons d'une valeur donnee\n"
        "6 Detruire liste\n"
        "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
        "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

int main()
{
    maillon_int* premier = NULL;
    maillon_int* nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin) {
        i = menu();
        switch (i) {

        case 1: // Créer une liste de taille aléatoire
            nb = rand() % 20 + 1;
            for (int j = 0; j < nb; j++) {
                nouveau = init_elt();
                ajout_tete_v2(&premier, nouveau); // appel de la fonction ajout_tete_v2 en passant en paramètre l'adresse du pointeur premier
            }
            break;

        case 2: // Ajouter un élément en tête de liste
            nouveau = init_elt();
            ajout_tete_v2(&premier, nouveau);
            break;

        case 3: // Insérer un élément dans l'ordre croissant
            nouveau = init_elt();
            inserer2(&premier, nouveau);
            break;

        case 4: // Supprimer le premier élément de la liste
            supprimer_debut(&premier);
            break;

        case 5: // Supprimer tous les maillons d'une valeur donnée
            printf("Entrez la valeur à supprimer : ");
            scanf("%d", &nb);
            rewind(stdin);
            critere_supp_un2(&premier, nb);
            break;

        case 6: // Détruire la liste
            detruire_liste2(&premier);
            break;

        case 7: // Sauver la liste dans un fichier binaire
            sauver_liste(premier);
            break;

        case 8: // Charger la liste depuis un fichier binaire
            detruire_liste2(&premier); 
            premier = load_liste();
            break;

        default:
            fin = 1;
            break;
        }
        printf("Liste : ");
        parcourir(premier);
    }

    detruire_liste2(&premier); // à la fin destruction de la liste

    return 0;
}
