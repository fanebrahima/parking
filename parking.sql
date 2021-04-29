-- MySQL dump 10.13  Distrib 8.0.23, for Linux (x86_64)
--
-- Host: localhost    Database: parking
-- ------------------------------------------------------
-- Server version	8.0.23-0ubuntu0.20.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `camion`
--

DROP TABLE IF EXISTS `camion`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `camion` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `camion`
--

LOCK TABLES `camion` WRITE;
/*!40000 ALTER TABLE `camion` DISABLE KEYS */;
INSERT INTO `camion` VALUES (2,'7898KI01',1618759865,1614903463,1614903463);
/*!40000 ALTER TABLE `camion` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `engin_deux_roues`
--

DROP TABLE IF EXISTS `engin_deux_roues`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `engin_deux_roues` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `engin_deux_roues`
--

LOCK TABLES `engin_deux_roues` WRITE;
/*!40000 ALTER TABLE `engin_deux_roues` DISABLE KEYS */;
INSERT INTO `engin_deux_roues` VALUES (2,'7575KH01',1618096238,1614903463,1614903463);
/*!40000 ALTER TABLE `engin_deux_roues` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `engin_vehicule`
--

DROP TABLE IF EXISTS `engin_vehicule`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `engin_vehicule` (
  `id` int NOT NULL AUTO_INCREMENT,
  `matricule` varchar(10) DEFAULT NULL,
  `date_entre` int DEFAULT NULL,
  `date_sortie` int DEFAULT NULL,
  `temps_passe_parking` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `engin_vehicule`
--

LOCK TABLES `engin_vehicule` WRITE;
/*!40000 ALTER TABLE `engin_vehicule` DISABLE KEYS */;
INSERT INTO `engin_vehicule` VALUES (1,'1802TW01',1618096284,1614903463,1614903463),(3,'8978KI01',1618177062,1614903463,1614903463),(4,'2369JI01',1618179141,1614903463,1614903463);
/*!40000 ALTER TABLE `engin_vehicule` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nbr_engin`
--

DROP TABLE IF EXISTS `nbr_engin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `nbr_engin` (
  `id` int NOT NULL AUTO_INCREMENT,
  `nbr_moto` int DEFAULT NULL,
  `nbr_vehicule` int DEFAULT NULL,
  `nbr_camion` int DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nbr_engin`
--

LOCK TABLES `nbr_engin` WRITE;
/*!40000 ALTER TABLE `nbr_engin` DISABLE KEYS */;
INSERT INTO `nbr_engin` VALUES (1,30,1,14);
/*!40000 ALTER TABLE `nbr_engin` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-04-29  2:34:00
