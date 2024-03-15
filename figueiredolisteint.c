#include "figueiredolisteint.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

maillon_int* init_elt() // maillon_int est une structure, maillon_int* pointe sur un "maillon_int"
{
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int)); //on alloue de l'espace pour un pointeur "p_nv_elt" de type "maillon_int"
    p_nv_elt->val = rand() % 21; //attribue à "val" un nb entre 0 et 20
    p_nv_elt->p_suiv = NULL; //"p_suiv" est un pointeur sur un maillon 
    return p_nv_elt;
}


maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt) // prend deux pointeur sur des "maillon_int" en paramètre
{
    p_nv_elt->p_suiv = p_tete; // affecte à "p_suiv" de la structure pointée par "p_nv_elt" : "p_tete"
    p_tete = p_nv_elt; // ensuite "p_tete" est remplacer par "p_nv_elt"
    return p_tete;
}


void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt) // prend un pointeur sur un pointeur et un pointeur sur un "maillon_int" en paramètre
{
    p_nv_elt->p_suiv = *p_p_tete; // affecte à "p_suiv" de la structure pointée par "p_nv_elt" : l'élément pointé par "*p_p_tete"
    *p_p_tete = p_nv_elt; // la valeur que pointe "*p_p_tete" est remplacé par "p_nv_elt"
}


void parcourir(maillon_int* p_tete) // prend un pointeur sur un "maillon_int" en paramètre
{
    if (p_tete == NULL) // si le pointeur est null, la liste est vide
        printf("liste vide");
    else
        while (p_tete != NULL) { // sinon, parcours de la liste tant que le pointeur n'est pas null
            printf("%d--", p_tete->val); // affiche la valeur du maillon actuel
            p_tete = p_tete->p_suiv; // passe au maillon suivant
        }
    putchar('\n'); // affiche un saut de ligne à la fin de l'affichage de la liste
}



maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt) // prend deux pointeurs sur des "maillon_int" en paramètre
{
    maillon_int* n, * prec; // déclaration des pointeurs locaux
    
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {  // si la liste est vide ou si la valeur du nouvel élément est <= à celle du premier élément
        p_nv_elt->p_suiv = p_tete; // le pointeur suivant du nouvel élément pointe sur le premier élément actuel
        p_tete = p_nv_elt; // le premier élément devient le nouvel élément
    }
    else {  
        n = prec = p_tete; // initialisation des pointeurs de parcours
        while (n != NULL && p_nv_elt->val > n->val) { // tant que le maillon actuel n'est pas null et que la valeur du nvl elemt est supérieure à celle du maillon actuel
            prec = n; // sauvegarde du maillon précédent
            n = n->p_suiv; 
        }
        p_nv_elt->p_suiv = n; // le pointeur suivant du nouvel élément pointe sur le maillon actuel
        prec->p_suiv = p_nv_elt; // le pointeur suivant du maillon précédent pointe sur le nouvel élément
    }
    return p_tete;
}


void inserer2(maillon_int** prem, maillon_int* e) // prend un pointeur sur un pointeur et un pointeur sur un "maillon_int" en paramètre
{
    maillon_int* n, * prec; // déclaration des pointeurs locaux
    
    if (*prem == NULL || e->val <= (*prem)->val){ // si liste vide ou si la valeur du nouvel élément est <= à celle du premier élément
        e->p_suiv = *prem; // le pointeur suivant du nouvel élément pointe sur la tête de la liste actuelle
        *prem = e; // la tête de la liste devient le nouvel élément
    }
    else { 
        n = prec = *prem; // initialisation des pointeurs de parcours
        while (n != NULL && e->val > n->val) { // tant que le maillon actuel n'est pas NULL et que la valeur du nouvel élément est supérieure à celle du maillon actuel
            prec = n; // sauvegarde du maillon précédent
            n = n->p_suiv; // avancement dans la liste
        }
        e->p_suiv = n; // le pointeur suivant du nouvel élément pointe sur le maillon actuel
        prec->p_suiv = e; // le pointeur suivant du maillon précédent pointe sur le nouvel élément
    }
}


void supprimer_debut(maillon_int** prem) // prend un pointeur sur un pointeur en paramètre
{
    maillon_int* n; // déclaration d'un pointeur local
    
    if (*prem != NULL) { // si la liste n'est pas vide
        n = *prem; // sauvegarde du premier maillon
        *prem = (*prem)->p_suiv; // la tête de la liste pointe sur le maillon suivant
        free(n); // libération de la mémoire occupée par le premier maillon
    }
}



maillon_int* critere_supp_un1(maillon_int* prem, int val) // prend un pointeur sur un maillon et un entier en paramètres
{
    maillon_int* e = prem, * prec = NULL, * n; // déclaration des pointeurs locaux

    while (e != NULL) { // tant que le maillon actuel n'est pas null
        n = NULL;
        if (e->val == val) { // si la valeur du maillon actuel correspond à la valeur à supprimer
            n = e; // sauvegarde du maillon à supprimer
            if (prec == NULL)
                prem = e->p_suiv; // si le maillon à supprimer est en tête de liste, mise à jour de la tête de liste
            else
                prec->p_suiv = e->p_suiv; // sinon, réorganisation des pointeurs pour contourner le maillon à supprimer
        }
        else
            prec = e; // remplace prec par e
        e = e->p_suiv; // avancement dans la liste
        if (n != NULL)
            free(n); // libération de la mémoire occupée par le maillon à supprimer
    }
    return prem; // retourne la tête de liste mise à jour
}


void critere_supp_un2(maillon_int** prem, int val) // prend un pointeur sur un pointeur et un entier en paramètres
{
    maillon_int* e = *prem, * prec = NULL, * n; // déclaration des pointeurs locaux

    while (e != NULL) { // tant que le maillon actuel n'est pas null
        n = NULL; // initialisation du maillon à supprimer à NULL
        if (e->val == val) { // si la valeur du maillon actuel correspond à la valeur à supprimer
            n = e; // sauvegarde du maillon à supprimer
            if (prec == NULL)
                *prem = e->p_suiv; // si le maillon à supprimer est en tête de liste, mise à jour de la tête de liste
            else
                prec->p_suiv = e->p_suiv; // sinon, réorganisation des pointeurs pour contourner le maillon à supprimer
        }
        else
            prec = e; // remplace prec par e
        e = e->p_suiv; // avancement dans la liste
        if (n != NULL)
            free(n); // libération de la mémoire occupée par le maillon à supprimer
    }
}



void detruire_liste(maillon_int** prem) // prend un pointeur sur un pointeur en paramètre
{
    maillon_int* n; // déclaration d'un pointeur local

    while (*prem != NULL) { // tant que la tête de liste n'est pas null
        n = *prem; // sauvegarde du maillon en tête de liste
        *prem = (*prem)->p_suiv; // mise à jour de la tête de liste
        free(n); // libération de la mémoire occupée par le maillon sauvegardé
    }
}


void detruire_liste2(maillon_int** prem) // prend un pointeur sur un pointeur en paramètre
{
    while (*prem != NULL) // tant que la tête de liste n'est pas null
        supprimer_debut(prem); // appel de la fonction supprimer_debut pour supprimer le premier élément de la liste
}


void sauver_liste(maillon_int* prem)
{
    //ouvrir un fichier binaire en écriture : suffixe b
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    // si liste non vide
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else // parcourir la liste jusque fin
            while (prem != NULL) {
                // écrire chaque maillon en binaire
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else 
                // passer au maillon suivant
                prem = prem->p_suiv;
            }
            fclose(f);	// fermer le fichier
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}

maillon_int* load_liste() // retourne un pointeur sur un maillon
{
    FILE* f; // déclaration du fichier
    maillon_int* prem = NULL, * p, e;

    // ouverture du fichier en mode lecture binaire
    if ((f = fopen("saveliste.bin", "rb")) != NULL) { 
        prem = malloc(sizeof(maillon_int)); 
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem; 

        // lecture des maillons suivants jusqu'à la fin du fichier
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv; 
            *p = e; 
            p->p_suiv = NULL; // mise à jour du pointeur suivant du dernier maillon
        }
        fclose(f); // fermeture du fichier
    }
    else
        printf("erreur ou fichier inexistant"); // affichage d'un message d'erreur si le fichier n'est pas accessible

    return prem; // retourne la tête de liste
}

