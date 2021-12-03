#include "fonctions.h"
#include "stdlib.h"
#include "stdio.h"

Element_str* creer_list(char chaine[50]){
    Element_str* list;
    list = (Element_str*) malloc(sizeof (Element_str));
    for (int i = 0; i<= 50; i++)
        list -> texte[i] = chaine[i];
    list -> next = NULL;
    return list;
}

void ajout_fin(Element_str** ad_liste, char txt[50]){
    if (*ad_liste == NULL){
        *ad_liste = creer_list(txt);
    }
    else{
        ajout_fin( &((*ad_liste)->next) , txt);
    }
}

void display_list(Element_str* liste){
    if (liste != NULL){
        if (liste -> next != NULL)
            printf("%s-> ", liste-> texte);
        else
            printf("%s", liste-> texte);
        display_list(liste->next);
    }
    else{
        printf("\n");
    }
}

Element_str* initialiser_gouts(){
    Element_str* l_gout=NULL;
    char gout[]="chocolat";
    l_gout=creer_list(gout);
    Element_str* temp;
    temp=l_gout;
    char gout2[]="Vanille";
    temp->next=creer_list(gout2);
    char gout3[]="fraise";
    temp->next->next = creer_list(gout3);
    char gout4[]="Abricot";
    temp->next->next->next = creer_list(gout4);
    char gout5[]="Pomme";
    temp->next->next->next->next = creer_list(gout5);
    char gout6[]="Banane";
    temp->next->next->next->next->next = creer_list(gout6);
    char gout7[]="Myrtille";
    temp->next->next->next->next->next->next = creer_list(gout7);
    return l_gout;
};

int nb_com(Element_str* list){
    int cpt = 0;
    while (list != NULL){
        cpt++;
        list = list -> next;
    }
    return cpt;
}


File_Commandes * init_com(){
    File_Commandes * nouv_file = (File_Commandes *)malloc(sizeof(File_Commandes));
    nouv_file->data = NULL;
    return nouv_file;
}

void passer_commande(char commande[50], File_Commandes * f_commandes)
{
    if (nb_com(f_commandes->data) <10)
    {
        Element_str *nouv_el = NULL;
        ajout_fin(&nouv_el, commande);
        nouv_el->next = NULL;
        //Ajout à la fin

        if (f_commandes->data == NULL) {
            f_commandes->data = nouv_el;
        }
        else {
            Element_str *temp = f_commandes ->data;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nouv_el;
        }
    }
    else{
        printf("Il y a trop de commande, veuillez repasser !\n");
    }
}

Element_gtx* init_gat(Gateau* g){
    Element_gtx * nouv_file = (Element_gtx *)malloc(sizeof(Element_gtx));
    nouv_file->gateau = g;
    nouv_file->next = NULL;
    return nouv_file;
}

File_Degustation* init_deg(){
    File_Degustation* nouv_file = (File_Degustation*)malloc(sizeof(File_Degustation));
    nouv_file ->data = NULL;
    return nouv_file;
}

void ajouter_fin(Element_gtx** list, Gateau* gateau){
    Element_gtx** temp = list;
    while ((*temp) != NULL)
    {
        *temp = (*temp) ->next;
    }
    *temp = init_gat(gateau);
}

void livrer(Gateau* gateau, File_Degustation* f_degustation)
{
    if (gateau != NULL)
        ajouter_fin(&(f_degustation->data), gateau);
}

Element_str* conv_list(char commande[50]){
    Element_str* list = NULL;
    for (int i =0; i <= 50; i++){
        if (commande[i] == 'C'){
            ajout_fin(&list, "C");
        }
        if (commande[i] == 'V'){
            ajout_fin(&list, "V");
        }
        if (commande[i] == 'F'){
            ajout_fin(&list, "F");
        }
        if (commande[i] == 'A'){
            ajout_fin(&list, "A");
        }
        if (commande[i] == 'P'){
            ajout_fin(&list, "P");
        }
        if (commande[i] == 'B'){
            ajout_fin(&list, "B");
        }
        if (commande[i] == 'M'){
            ajout_fin(&list, "M");
        }
        if (commande[i] == '\0'){
            break;
        }
        display_list(list);
    }
    return list;
}

Element_str* traiter_commande(File_Commandes* f_commandes){
    if (f_commandes != NULL){
        Element_str* cpt = conv_list(f_commandes -> data -> texte);
        Element_str* temp = f_commandes -> data -> next;
        free(f_commandes -> data);
        f_commandes ->data =NULL;
        f_commandes -> data = temp;
        return cpt;
    }
    return NULL;
}


Pile_Gouts * init_pile(){
    Pile_Gouts * nouv_pile = (Pile_Gouts*) malloc(sizeof(Pile_Gouts));
    nouv_pile->data = NULL;
    return nouv_pile;
}

void empilement(Pile_Gouts * p, char a[50]){
    Element_str * nouv_el = creer_list(a);
    Element_str* temp = p -> data;
    nouv_el-> next = p-> data;
    p->data = nouv_el;
}

Gateau* creer_gateau(Element_str* commande){
    Gateau* manger = (Gateau*) malloc(sizeof (Gateau));
    manger ->commande = commande;
    manger -> p_gouts = init_pile();
    return manger;
}

void construire_gateau(Gateau* gateau, Element_str* l_gouts){
    Element_str* temp = gateau -> commande;
    while (temp != NULL){
        Element_str* cpt = l_gouts;
        while (cpt != NULL){
            if (temp -> texte[0] == cpt ->texte[0]){
                empilement(gateau->p_gouts, cpt-> texte);

            }
            cpt = cpt ->next;
        }
        temp = temp->next;
    }
}

void degustation(File_Degustation* f_degustation, int nb_parts)
{
    Element_gtx* gtx = f_degustation -> data;
    Element_gtx* gtx_suiv;
    if (gtx != NULL){
        Element_str* temp =  gtx -> gateau -> p_gouts -> data;
        Element_str* cpt_next;

        for(int i = 0; i < nb_parts; i++){

            if (temp != NULL){
                if (temp ->next != NULL){
                    cpt_next = temp ->next;
                    free(temp);
                    temp = cpt_next;
                    display_list(temp);

                }
                else if (temp ->next == NULL) {
                    free(temp);
                    if (gtx->next != NULL) {
                        gtx_suiv = gtx->next;
                        free(gtx);
                        gtx = NULL;
                        gtx = gtx_suiv;
                        temp = gtx -> gateau -> p_gouts -> data;
                    }
                    else {
                        free(gtx);
                        gtx = NULL;
                        printf("Il faut recommander si vous voulez des gateaux !");
                        break;
                    }
                }
            }
        }
    }
}
