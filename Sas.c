#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int id_dep;
    char nom_dep[100];
} departement;
typedef struct
{
    int num_uniq;
    char nom[100];
    char prenom[100];
    float noteGenerale;
    char date_naissance[50];
    departement depart;

} etudiant;

etudiant etud[100];
int Id = 0;
int dem = 0;

void ajouter_etudiant(etudiant etud[]){
    int chx;
    etud[dem].num_uniq = Id + 1;
    printf("nom : ");
    scanf(" %[^\n]", etud[dem].nom);
    printf("prenom :");
    scanf(" %[^\n]", etud[dem].prenom);
    printf("date de naissance (jj - mm - yy) :");
    scanf(" %[^\n]", etud[dem].date_naissance);
    do
    {
        printf("\t\tchoiser un departement :\n A- 1.SMI | 2.SMA | 3.SPC | 4.SVT :");
        scanf("%d",&chx); 
    } while (chx<=0 || chx>4 );
    switch(chx){
        case 1: 
             strcpy(etud[dem].depart.nom_dep,"SMI");
             break;
         case 2: 
             strcpy(etud[dem].depart.nom_dep,"SMA");
             break;
        case 3: 
             strcpy(etud[dem].depart.nom_dep,"SPC");
             break;  
        case 4: 
             strcpy(etud[dem].depart.nom_dep,"SVT");
             break; 
        default:
              printf("valeur invalide.\n");                 
    }
    
   
    do
    {
        printf("note general:");
        scanf(" %f", &etud[dem].noteGenerale);
    } while (etud[dem].noteGenerale < 0 || etud[dem].noteGenerale > 20);
    printf("\n\n");

    Id++;
    dem++;
}
void ajoutePlus(etudiant etud[])
{
    int nbr, plus;
    printf("\t\t combien vous voulez ajouter : ");
    scanf("%d", &nbr);
    plus = nbr + dem;
    for (int i = dem; i < plus; i++)
    {
        ajouter_etudiant(etud);
    }
}
void Affichage(etudiant etud[])
{
    printf("**** Affichage D'etudiants ******\n\n");

    for (int i = 0; i < dem; i++)
    {
        printf("\t\t etudiant numero  %d :\n", etud[i].num_uniq);
        printf("\t\t nom : %s \n", etud[i].nom);
        printf("\t\t prenom : %s \n", etud[i].prenom);
        printf("\t\t date de naissance (jj - mm - yy) : %s \n", etud[i].date_naissance);
        printf("\t\t Departement : %s \n", etud[i].depart.nom_dep);
        printf("\t\t Note Generale  : %.2f \n\n", etud[i].noteGenerale);
    }
}

void modifier_etud(etudiant etud[])
{

    int id;

    printf("entre id de etudiant a modifier  :");
    scanf(" %d", &id);
    if (id <= 0 || id > dem)
    {
        printf("etudiant non trouve ");
        return;
    }

    int index = id - 1;
    printf("nouvelle nom : ");
    scanf(" %[^\n]", etud[index].nom);
    printf("nouvelle prenom :");
    scanf(" %[^\n]", etud[index].prenom);
    printf("nouveau date de naissance (jj - mm - yy) :");
    scanf(" %[^\n]", etud[index].date_naissance);
    printf("nouveau nom de departement :");
    scanf(" %[^\n]", etud[index].depart.nom_dep);
    do
    {
        printf("nouveau note general:");
        scanf(" %f", &etud[index].noteGenerale);
    } while (etud[index].noteGenerale < 0 || etud[index].noteGenerale > 20);

    printf("## etudiant est modifier succes ##");
}

void supprimer_etud(etudiant etud[])
{

    int id;

    printf("entre id de etudiant a supprimer :");
    scanf(" %d", &id);
    if (id <= 0 || id > dem)
    {
        printf("etudiant non trouve ");
        return;
    }
    for (int i = id - 1; i < dem - 1; i++)
    {
        etud[i] = etud[i + 1];
    }
    dem--;
    printf("supprimer est bien succes");
};

void moyenne_general(etudiant etud[])
{
    char nomdep[50];
    printf("entre le nom de departement pour calculer la moyenne : ");
    scanf(" %[^\n]", nomdep);
    float s = 0, moyennG;
    int cmp = 0;
    for (int i = 0; i < dem; i++)
    {
        if (strcmp(etud[i].depart.nom_dep, nomdep) == 0)
        {
            s += etud[i].noteGenerale;
            cmp++;
        }
    }
    moyennG = s / cmp;
    printf("la moyenne generale de departement est : %.2f", moyennG);
}

void moyenne_university(etudiant etud[])
{

    float s = 0, moyennT;
    int cmp = 0;
    for (int i = 0; i < dem; i++)
    {
        s += etud[i].noteGenerale;
        cmp++;
    }
    moyennT = s / cmp;
    printf("la moyenne generale de departement est : %.2f", moyennT);
}
/*void statistique(etudiant etud[])
{
    etudiant h[50];
    int cmpl=0;
    printf("\t\t le nombre total d'étudiants inscrits : %d\n",dem);
    for (int  i = 0; i < dem; i++)
    {
        strcpy(h[i],etud[i]);
    }
    for (int i = 0; i < dem; i++){
     for(int j = i;j=dem;j++) {
        if(strcmp(h[j].depart.nom_dep,etud[j].depart.nom_dep)==0){
           cmpl++; 
        }
    }
    printf("\t\t le nombre d'étudiants de département %s : %d",h[i],cmpl);   
    }  

}*/
void RecherchNom(etudiant etud[]){
   char nrchr[100];
   printf("\tentrer le nom d'etudiant a rechercher :");
   scanf(" %[^\n]", nrchr);
   for (int i = 0; i < dem; i++)
   {
    if(strcmp(etud[i].nom , nrchr)==0){
        printf("\t etudiant trouve : \n");
        printf("\t\t etudiant numero  %d :\n", etud[i].num_uniq);
        printf("\t\t nom : %s \n", etud[i].nom);
        printf("\t\t prenom : %s \n", etud[i].prenom);
        printf("\t\t date de naissance (jj - mm - yy) : %s \n", etud[i].date_naissance);
        printf("\t\t Departement : %s \n", etud[i].depart.nom_dep);
        printf("\t\t Note Generale  : %.2f \n\n", etud[i].noteGenerale);
        return;
    }
   }
        printf("\t etudiant non trouve . \n");
}
void triAlph(){
   etudiant h[100],tmp;
    for (int  i = 0; i < dem; i++)
    {
       h[i] = etud[i];
    }
    for (int i = 0; i < dem-1; i++){
     for(int j = i+1;j<dem;j++) {
        if(strcmp(h[i].nom,etud[i].nom)>0){
            tmp = h[i];
            h[i] = h[j];
            h[j] = tmp;
        }
    }   
    }  
    printf("***** Tri alphabétique des étudiants en fonction de leur nom *****\n\n");
       Affichage(h);
}
void triMilieur(){
    etudiant tmp;
    for(int i=0;i<dem-1;i++){
        for (int j = i+1; j < dem; j++)
        {
            if(etud[i].noteGenerale < etud[j].noteGenerale){
                tmp = etud[i];
                etud[i]=etud[j];
                etud[j]=tmp;

            }
        }
        
    }
    printf("***** Tri des étudiants par moyenne générale *****\n\n");
       Affichage(etud);
}
void note_description(float note, char description[])
{
    if (note >= 18)
    {
        strcpy(description, "Excellent");
    }
    else if (note >= 16)
    {
        strcpy(description, "Tres Bien");
    }
    else if (note >= 14)
    {
        strcpy(description, "Bien");
    }
    else if (note >= 12)
    {
        strcpy(description, "Passable");
    }
    else if (note >= 10)
    {
        strcpy(description, "Passable");
    }
    else
    {
        strcpy(description, "echou");
    }
}
void triRuss(etudiant etud[]){
    
}
int main()
{

    int choix;
    do
    {
        printf("\n");
        printf("===========================================================\n");
        printf("|                     MENU PRINCIPAL                      |\n");
        printf("===========================================================\n");
        printf("|  1.  Ajouter un étudiant                                |\n");
        printf("|  2.  Modifier un étudiant                               |\n");
        printf("|  3.  Supprimer un étudiant                              |\n");
        printf("|  4.  Afficher un étudiant                               |\n");
        printf("|  5.  Calculer la moyenne générale                       |\n");
        printf("|  6.  Afficher les statistiques                          |\n");
        printf("|  7.  Trier les étudiants par nom                        |\n");
        printf("|  8.  Trier les étudiants par note                       |\n");
        printf("|  9.  Rechercher un étudiant par nom                     |\n");
        printf("| 10.  Afficher le nombre total d'étudiants               |\n");
        printf("| 11.  Afficher le nombre d'étudiants par département      |\n");
        printf("| 12.  Afficher les étudiants ayant une note > à un seuil  |\n");
        printf("| 13.  Afficher les 3 étudiants ayant les meilleures notes |\n");
        printf("| 14.  Afficher les étudiants ayant réussi par département |\n");
        printf("|  0.  Quitter                                            |\n");
        printf("===========================================================\n");
        printf("Votre choix >>>  ");

        scanf("%d", &choix);
        switch (choix)
        {
        case 1:

            ajouter_etudiant(etud);
            break;
        case 2:

            modifier_etud(etud);
            break;

        case 3:

            supprimer_etud(etud);
            break;
        case 4:

            Affichage(etud);
            break;

        case 5:
            moyenne_general(etud);
            break;
        case 6:
            moyenne_university(etud);
            break;
        case 7:
            ajoutePlus(etud);
            break; 
        case 8:
             triAlph();
             break;  
        case 9:
             triMilieur();
             break; 
        case 10:
             RecherchNom(etud);
             break;             
        }

    } while (choix != 0);

    return 0;
}
