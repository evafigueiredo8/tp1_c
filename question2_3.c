#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Maillon {
    int valeur;
    struct Maillon *suivant;
} Maillon;

typedef struct Pile{
    Maillon *sommet;
} Pile;

void initialiser_pile(Pile *pile) {
    pile->sommet = NULL; // pile->sommet c'est pour acceder à un elmt d'une structure
}

bool est_vide(Pile *pile) {
    bool vide = false;
    if (pile->sommet == NULL){
        vide = true;
    }
    return vide;
}

void empiler(Pile *pile, int valeur) {
    Maillon *nouveau_maillon = (Maillon*)malloc(sizeof(Maillon));
    if (nouveau_maillon == NULL) {
        fprintf(stderr, "Le nouveau maillon est nul\n");
        exit(EXIT_FAILURE);
    }
    nouveau_maillon->valeur = valeur;
    nouveau_maillon->suivant = pile->sommet;
    pile->sommet = nouveau_maillon;
}

int sommet(Pile *pile) {
    if (est_vide(pile)) {
        fprintf(stderr, "La pile est vide\n");
        exit(EXIT_FAILURE);
    }
    return pile->sommet->valeur;
}

int depiler(Pile *pile) {
    if (est_vide(pile)) {
        fprintf(stderr, "La pile est vide\n");
        exit(EXIT_FAILURE);
    }
    int valeur = pile->sommet->valeur;
    Maillon *temp = pile->sommet;
    pile->sommet = pile->sommet->suivant;
    free(temp);
    return valeur;
}


// question 3

int renverser(int *liste){
    Pile pile;
    int listeRenverse = [];
    initialiser_pile(pile);
    for (int i = 0; i < length(liste); i++) {
        empiler(&pile, liste[i]);
    }
    while (!est_vide(&pile)) {
        listeRenverse = &pile[-1];
        depiler(&pile);
    }
    printf(listeRenverse);

}