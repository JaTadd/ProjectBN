#ifndef FONCTIONS_H
#define FONCTIONS_H



typedef struct Element_str{
    char texte[50];
    struct Element_str* next;
}Element_str;

Element_str* l_gouts;


typedef struct File_Commandes{
    Element_str* data;
}File_Commandes;

typedef struct Pile_Gouts{
    Element_str* data;
}Pile_Gouts;


typedef struct Gateau{
    struct Element_str* commande;
    struct Pile_Gouts* p_gouts;
}Gateau;


typedef struct Element_gtx{
    struct Gateau* gateau;
    struct Element_gtx* next;
}Element_gtx;


typedef struct File_Degustation{
    Element_gtx* data;
}File_Degustation;

File_Commandes* f_commandes;
File_Degustation* f_degustation;


//allocation dynamique de la memoire et creation d'une liste chainée.
Element_str* creer_list(char chaine[50]);

//-------------------------//

//fonction de base qui permet d'ajouter recursivement un element a la fin d'une liste
void ajout_fin(Element_str** ad_liste, char txt[50]);

//-------------------------//

// fonction de base qui permet d'afficher une liste chainée
void display_list(Element_str* liste);

//-------------------------//

// initialisation de la liste des goûts a dispostion du pâtissier
Element_str* initialiser_gouts();

//-------------------------//

//cette focntion permet de gerer le nombre de commande, qui est limité a 10 dans le projet
int nb_com(Element_str* list);

//-------------------------//

//cette fonction permet dans d'autre fonction de creer notre liste de commande en allocation dynamique de la memoire
File_Commandes * init_com();

//-------------------------//

/* Cette fonction prend en paramêtre la commande du client et notre file de commande.
 * la première etape est de verifeier si notre liste contient bien moins de 10 commandes.
 * si la liste est null alors on appelle directement notre fonction ajout_fin qui remplit a la premiere place la liste vide
 * si elle n'est pas vide alors on la parcours jusuqu'a avoir un element null au quel on ajoutera la nouvelle commande*/
void passer_commande(char commande[50], File_Commandes * f_commandes);

//-------------------------//

//initialisation de notre file de gateaux
Element_gtx* init_gat(Gateau* g);

//-------------------------//

// initialisation de la fine de degustatiuon
File_Degustation* init_deg();

//-------------------------//

//ajouter a la fin de notre file de gateau un nouvel emplacement de gateau
void ajouter_fin(Element_gtx** list, Gateau* gateau);

//-------------------------//

// apres la creation de nos gateaux, ils sont mis dans la list de livraison
void livrer(Gateau* gateau, File_Degustation* f_degustation);

//-------------------------//

// ici, on convertit une chaine de caractère en liste afin de pouvoir traiter la commande
Element_str* conv_list(char commande[50]);

//-------------------------//

// ici on traite les commande dans l'odre puis on libere l'espace pour eviter l'encombrement de la memoire
Element_str* traiter_commande(File_Commandes* f_commandes);

//-------------------------//

//initialisation d'une pile
Pile_Gouts * init_pile();

//-------------------------//

// focntion de base qui permet d'empiler
void empilement(Pile_Gouts * p, char a[50]);

//-------------------------//

// Dans cette fonctio, on créer notre gateau avce une pile de gout vide
Gateau* creer_gateau(Element_str* commande);

//-------------------------//

/* dasn Cette fonction nous allons creer etage par etage notre gateau.
    Ici pour chaque lettre contenue dans la structure gateau->commande, on creer et on empile des etage avec le gout associé a la commande
*/
void construire_gateau(Gateau* gateau, Element_str* l_gouts);

//-------------------------//

/* hmmmm
 ici, on deguste les gateaux dans l'odre, c'est a dire qu'a chaquoi fois qu'il est mangé, on le supprime et on libére son espace memoire associé.
 on pernd en paramétre le nombre de parts qu'il souhaite manger, si il finit pas un gateau on ne le supprime pas, on supprime juste les etages qu'il a mangé
 lors de la prochiane degustation vu que l'odre importe, le client finara le gateau deja entamé
 Dès que le geteau est fini, on libere la memoire qu'il occupe dans les liste comme on fait avec chaque goût
*/
void degustation(File_Degustation* f_degustation, int nb_parts);
#endif
