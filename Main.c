#include "fonctions.h"
#include "fonctions.c"
#include "stdlib.h"
#include "stdio.h"

int main(){
    int en_marche = 1;
    int ref;
    f_commandes = init_com();
    f_degustation = init_deg();

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                       Bienvenue dans notre patisserie!\n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    while (en_marche==1){
    {
        printf("Veuillez saisir une valeur\n");
        printf("|--------------------------|      |---------------------------------------|        |-------------------------------|\n");
        printf("|1->Initialiser les gouts  |      |2- Saisir 2 pour passer votre commande |        |3- Traiter votre commande      |\n");
        printf("|                          |      |                                       |        |     et faire votre gateau     |\n");
        printf("|                          |      |                                       |        |                               |\n");
        printf("|--------------------------|      |---------------------------------------|        |-------------------------------|\n");
        printf("|------------------------------------|                                 |-------------------------------------------|\n");
        printf("|4-Mangez votre gateau               |                                 |5-Vous nous quittez deja au revoir !!      |\n");
        printf("|                                    |                                 |                                           |\n");
        printf("|                                    |                                 |                                           |\n");
        printf("|                                    |                                 |                                           |\n");
        printf("|------------------------------------|                                 |-------------------------------------------|\n");
        printf("valeur : ");
        scanf("%d", &ref);
        switch (ref) {
            case 1:{
                l_gouts = initialiser_gouts();
                display_list(l_gouts);
                break;
            }
            case 2:{
                char commande_str[50];
                printf("Vous voulez plus commander, entrez 1\n");
                printf("Veuillez saisir votre commande afin de lancer la preparation en cuisine :\n");
                scanf("%s", &commande_str);
                if (commande_str[0] == '1'){
                    break;
                }
                passer_commande(commande_str, f_commandes);
                printf("MArci de votre commande, voici le recapitulatif de votre commande : ");
                display_list(f_commandes->data);
                break;

            }
            case 3:{
                Element_str* commande_traitee = traiter_commande(f_commandes);
                Gateau* gat = creer_gateau(commande_traitee);
                construire_gateau(gat, l_gouts);
                display_list(gat->p_gouts->data);
                livrer(gat, f_degustation);

                break;
            }
            case 4:{
                int nb_parts;
                printf("Combien de parts souhaitez vous ? ?");
                scanf("%d", &nb_parts);
                degustation(f_degustation, nb_parts);
                break;
            }
            case 5:{
                printf("Merci de votre comfiance a bientot !!!");
                en_marche = 0;
                break;
            }
        }
    }
}}
