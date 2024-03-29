// question 1 :

typedef struct Horaire {
    char villeDepart;
    char villeArrivee;
    char heureDepart;
    char heureArrivee;
    int distance;
    int valeur;
} Horaire;

void ajouter_horaire(Horaire **liste, char *ville_depart, char *ville_arrivee, char *heure_depart, char *heure_arrivee, int distance) {
    Horaire *nouveau_horaire = malloc(sizeof(Horaire));
    if (nouveau_horaire == NULL) {
        fprintf(stderr, "Impossible d'allouer de la mémoire\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nouveau_horaire->ville_depart, ville_depart);
    strcpy(nouveau_horaire->ville_arrivee, ville_arrivee);
    strcpy(nouveau_horaire->heure_depart, heure_depart);
    strcpy(nouveau_horaire->heure_arrivee, heure_arrivee);
    nouveau_horaire->distance = distance;
    nouveau_horaire->suivant = NULL;

    if (*liste == NULL) {
        *liste = nouveau_horaire;
    } else {
        Horaire *temp = *liste;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouveau_horaire;
    }
}