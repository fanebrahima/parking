#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include <time.h>
#include <math.h>

#include "vehicule-classic.h"

/**
* \author FANE Brahima
* \version 20.03
* \date 14 Avril 2021
* \brief Ce fichier permet la gestion des véhicules classics(insertion, affichage, modification, sortie)
*/

/** Appel du fichier vehicule-classic.c
* \file vehicule-classic.c
* \fn void insertion_vehicule ()
* \fn void affiche_vehicule ()
* \fn void sortie_engin_vehicule ()
*/

static char host[255] = "localhost";
static char user[255] = "root";
static char pass[255] = "";
static char dbname[255] = "parking3";

static unsigned int port = 3306;


MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

/**INSERTION VEHICULE*/
void insertion_vehicule(){


  int h, min, s, day, mois, an;
  time_t now;
    
  time(&now);
  struct tm *local = localtime(&now);
  h = local->tm_hour;        
  min = local->tm_min;            
  day = local->tm_mday;          
  mois = local->tm_mon + 1;     
  an = local->tm_year + 1900;  
  printf("L'heure d'ENTREE: %02d:%02d\n", h, min);
  /**Afficher la date courante*/
  printf("La date d'ENTREE: %02d/%02d/%d\n", day, mois, an);

    char matricule1[25];
    char marque[25];
    char couleur[25];
    char query[255];
    char autre[255];
    
    printf("Veuillez saisir le matricule de votre VEHICULE :\n");
    scanf("%s", matricule1);
    printf("Veuillez saisir la marque de votre VEHICULE :\n");
    scanf("%s", marque);
    printf("Veuillez saisir la couleur de votre VEHICULE :\n");
    scanf("%s", couleur);
    conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, host, user, pass, dbname, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    sprintf(query, "INSERT INTO engin_vehicule (matricule, marque, couleur, date_entre, date_sortie, temps_passe_parking) VALUES('%s' , '%s' , '%s' , '%ld', '%d', '%d');", matricule1, marque, couleur, time(&now), 0, 0);

    if (mysql_query(conn, query))
    {
        printf(":-(");
    }

    sprintf(autre, "SELECT * FROM nbr_engin;");
     if (mysql_query(conn, autre))
    {
        printf(":-(");
    }
    res = mysql_store_result(conn);

    while (row = mysql_fetch_row(res))
    {
        
//<math.h>

    if (atoi(row[2]) > 0)
    {
        sprintf(autre, "UPDATE nbr_engin SET nbr_vehicule = nbr_vehicule - 1");
        if (mysql_query(conn, autre))
        {
            printf(":-(");
        }
    }
    
    else if (atoi(row[3])-1 > 0){
        printf("===> LE PARKING POUR LES VEHICULES EST REMPLI VOUS DEVRIEZ PLACER VOTRE VEHICULE DANS LE PARKING DES CAMIONS. MERCI \n");
        sprintf(autre, "UPDATE nbr_engin SET nbr_camion = nbr_camion - 1");
        if (mysql_query(conn, autre))
        {
            printf(":-(");
        }
    }

    else{
        printf("===> DESOLER, IL N' Y A PLUS DE PLACE DANS LE PARKING POUR DES VEHICULES ET AUSSI DANS CELUI DES CAMIONS. BYE!!! \n");
    }

    
    exit(EXIT_SUCCESS);
    
    }
}

/**AFFICHE LES VEHICULE*/
void affiche_vehicule(){

    conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, host, user, pass, dbname, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

     char aut[200]=" ";
     //printf("ok");
     sprintf(aut, "SELECT * FROM engin_vehicule");
     if (mysql_query(conn, aut))
        {
            printf(":-(");
        }
        res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res))
    {
         printf("matricule \t marque \t couleur \n\n");
         printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(conn);
}

/**RECHERCHER UN VEHICULE CLASSIQUE*/
void rechercher_vehicule(){

	conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, host, user, pass, dbname, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

     char aut_r[200]=" ";
     char matri_r[25];
     printf("==> Veuillez saisir le numero d'IMMATRICULATION de votre Engin : \n");
     printf("====> ");
     scanf("%s", matri_r);
    
     sprintf(aut_r, "SELECT * FROM engin_vehicule WHERE matricule ='%s';", matri_r);
     if (mysql_query(conn, aut_r))
        {
            printf(":-(");
        }
        res = mysql_store_result(conn);
    while (row = mysql_fetch_row(res))
    {
        printf("matricule \t marque \t couleur \n\n");
        printf("%s\t%s\t%s\n", row[1], row[2], row[3]);
    }
    mysql_free_result(res);
    mysql_close(conn);
}


/**SORTI DE ENGIN VEHICULE*/
void sortie_engin_vehicule(){
	conn = mysql_init(NULL);
    
    if (! (mysql_real_connect(conn, host, user, pass, dbname, 0, NULL, 0)))
    {
        fprintf(stderr, "\n Error: %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    char matri[25];
    char autre[255];
    double total_tmp;
    int som_pay;
    float nbr_min;
    float nbr_h;
    int dif;

    int h, min, s, day, mois, an;
    time_t now;
        
    /**Renvoie l'heure actuelle*/
    time(&now);
    /**Convertir au format heure locale*/
    struct tm *local = localtime(&now);
    h = local->tm_hour;        
    min = local->tm_min;       
    s = local->tm_sec;       
    day = local->tm_mday;          
    mois = local->tm_mon + 1;     
    an = local->tm_year + 1900;  
    printf("L'heure de SORTIE: %02d:%02d:%02d\n", h, min, s);
    /**Afficher la date courante*/
    printf("La date de SORTIE: %02d/%02d/%d\n", day, mois, an);

    
    printf("==> Veuillez saisir le numero d'IMMATRICULATION de votre Engin : \n");
    printf("====> ");
    scanf("%s", matri);

    sprintf(autre, "SELECT * FROM engin_vehicule WHERE matricule ='%s';", matri);
     if (mysql_query(conn, autre))
    {
        printf(":-(");
    }
    res = mysql_store_result(conn);

    while (row = mysql_fetch_row(res))
    {
        printf("LE VEHICULE D'IMMATRICULATION %s", row[1]);
        printf(" DEMANDE A SORTIR \n");
        printf("\n");
    
    

    sprintf(autre, "UPDATE engin_vehicule SET date_sortie = '%ld' WHERE matricule = '%s';", time(&now),( matri));
    if (mysql_query(conn, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }

    dif = (time(&now)-atoi(row[4]));

    sprintf(autre, "UPDATE engin_vehicule SET temps_passe_parking = '%d' WHERE matricule = '%s';", dif,( matri));
        if (mysql_query(conn, autre))
        {
            printf(":-( ECHEC UPDATE\n");
        }

        if (dif <= 86399)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*500;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre Vehicule a passer: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre Vehicule a passer: %f ", nbr_min);
        printf("Minnutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE \n");
    }
    if (dif >= 86400)
    {
        total_tmp = dif;
        som_pay = ceil((total_tmp/3600))*20000;
        nbr_min = (total_tmp/60);
        nbr_h = floor(nbr_min/60);
        printf("Votre Vehicule a passer: %f ", nbr_h);
        printf("heures dans notre Parking \n");
        printf("Votre Vehicule a passer: %f ", nbr_min);
        printf("Minnutes dans notre Parking \n");
        printf("Vous devriez payer : %d ", som_pay);
        printf(" FCFA \n");
        printf("\n");
        printf("AUREVOIR ET MERCI DE NOUS AVOIR FAIT CONFIANCE \n");
    }

}

    sprintf(autre, "UPDATE nbr_engin SET nbr_vehicule = nbr_vehicule + 1");
    if (mysql_query(conn, autre))
    {
        printf(":-(");
    }
    
    sprintf(autre, "DELETE FROM engin_vehicule WHERE matricule = '%s';", matri);
    if (mysql_query(conn, autre))
    {
        printf(":-(");
    }

    exit(EXIT_SUCCESS);
    
}

