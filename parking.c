#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>
#include <math.h>

#include "engin_deux_roues.h"
#include "camion.h"
#include "vehicule-classic.h"

/**
* \author FANE Brahima
* \version 20.03
* \date 14 Avril 2021
* \brief Ce fichier permet la gestion des camions(insertion, affichage, modification, sortie)
*/

/** Appel du fichier parking.c
* \file parking.c
* \fn void affiche_nbr_engin ()
*/


static char host[255] = "localhost";
static char user[255] = "root";
static char pass[255] = "";
static char dbname[255] = "parking3";

static unsigned int port = 3306;


MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;



/**AFFICHE NOMBRE DE PLACE DES DIFFERENTS ENGINS*/
void affiche_nbr_engin(){
    mysql_query(conn, "SELECT nbr_moto, nbr_vehicule, nbr_camion FROM nbr_engin");
    res = mysql_store_result(conn);

    while (row = mysql_fetch_row(res))
    {
        printf("====>Nombre de place pour les engins a deux roues: %s \n", row[0]);
        printf("====>Nombre de place pour les engins vehicules: %s \n", row[1]);
        printf("====>Nombre de place pour les engins camions: %s \n", row[2]);
    }
    mysql_free_result(res);
    mysql_close(conn);
}



int main()

{
     

    conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, host, user, pass, dbname, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    


    int choix;
    int choix2;
    int choix3;
    int choix4;

    do
    {
        printf("==>NOMBRE DE PLACE DANS PARKING \n");
        affiche_nbr_engin();
        printf("\n");
        printf("********************************************** \n");
        printf("1 LES ENGINS ENTRANT \n"); /** ajouter l'élément et trier la liste*/
        printf("2 LES ENGINS SORTANT\n");
        printf("3 AFFICHAGE DU NOMBRE DE PLACE DANS PARKING \n");
        printf("4 RECHERCHE DES ENGINS \n");
        printf("5 AFFICHAGE DES ENGINS \n");

        printf("CHOISISSEZ UN NUMERO DANS LE MENU: ");
        scanf("%i", &choix);

        switch(choix)
        {
        case 1:
            do
            {
               printf("1 LES ENGINS A 2 ROUES \n");
               printf("2 LES VEHICULE \n");
               printf("3 LES CAMIONS \n");
               printf("CHOISISSEZ UN ENGIN : \n");
               scanf("%i", &choix2);

               switch (choix2)
               {
               case 1:
                    printf("BINVENUE ENGIN DE ROUES\n");
                    insertion();
                    //affiche();
                break;

                case 2:
                    printf("BIENVENUE VEHICULE \n");
                    insertion_vehicule();
                    //affiche_vehicule();
                break;

                case 3:
                    printf("BIENVENUE CAMION \n");
                    insertion_camion();
                    //affiche_camion();
                break;
               
               default:
                    system("cls");
                    printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 3 \n");
                break;
               }

            } while (choix2 != 3);
            getchar();
     
        break;

        case 2:
            do
            {
               printf("LES ENGINS SORTANT \n");
               printf("1 LES ENGINS A 2 ROUES \n");
               printf("2 LES VEHICULE \n");
               printf("3 LES CAMIONS \n");
               printf("CHOISISSEZ UN ENGIN : \n");
               scanf("%i", &choix3);

               switch (choix3)
               {
               case 1:
                    printf("BONNE ROUTE ENGIN A ROUES\n");
                    sortie_engin_deux_roues();
                    
                    //affiche();
                break;

                case 2:
                    printf("BONNE ROUTE ENGIN VEHICULE \n");
                    sortie_engin_vehicule();
                    //update_sortie_engin_deux_roues();
                    //affiche_vehicule();
                break;

                case 3:
                    printf("BONNE ROUTE ENGIN CAMION \n");
                    sortie_engin_camion();
                    //affiche_camion();
                break;
               
               default:
                    system("cls");
                    printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 3 \n");
                break;
               }

            } while (choix2 != 3);
            getchar();   
        break; 

        case 3:
            //system("cls");
            printf("==>NOMBRE DE PLACE DANS PARKING \n");
            affiche_nbr_engin();
        break;
        
        case 4:
            printf("==>RECHERHER UN ENGIN DANS LE PARKING \n");

           
               printf("====>1 LES ENGINS A 2 ROUES \n");
               printf("====>2 LES VEHICULE \n");
               printf("====>3 LES CAMIONS \n");
               printf("====>CHOISISSEZ UN ENGIN : \n");
               scanf("%i", &choix4);

               switch (choix4)
               {
               case 1:
                    printf("AFFICHAGE DE ENGIN DE ROUES\n");
                    rechercher();
                break;

                case 2:
                    printf("AFFICHAGE DE VEHICULE \n");
                    rechercher_vehicule();
                break;

                case 3:
                    printf("AFFICHAGE DE CAMION \n");
                    rechercher_camion();
                break;
               
               default:
                    system("cls");
                    printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 3 \n");
                break;
               }
        break;

        case 5:
            printf("==>AFFICHAGE DES ENGINS DANS LE PARKING \n");

            do
            {
               printf("====>1 AFFICHE LES ENGINS A 2 ROUES \n");
               printf("====>2 AFFICHE LES VEHICULE \n");
               printf("====>3 AFFICHE LES CAMIONS \n");
               printf("====>CHOISISSEZ UN ENGIN : \n");
               scanf("%i", &choix4);

               switch (choix4)
               {
               case 1:
                    printf("AFFICHAGE DE ENGIN DE ROUES\n");
                     affiche();
                break;

                case 2:
                    printf("AFFICHAGE DE VEHICULE \n");
                    affiche_vehicule();
                break;

                case 3:
                    printf("AFFICHAGE DE CAMION \n");
                    affiche_camion();
                break;
               
               default:
                    system("cls");
                    printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 3 \n");
                break;
               }
               

            } while (choix4 != 3);
            getchar();
            
        break;
        
        default :
            system("cls");
            printf("ERREUR :-(, VEUILLEZ SAISIR UN CHIFFRE DE 1 À 2 \n");
        break;
        }
        
    }while(choix != 4);
    getchar(); /**LA FONCTION getchar PERMET DE RENVOYER VALEUR SAISIR*/

    return 0;


}
