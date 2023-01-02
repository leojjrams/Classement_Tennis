/*
 * Projet IAP : Les fondamentaux de la programmation impérative
 *
 * Sprint 1
 *
 * Auteurs : Rams Léo, Esteves Gabriel, Lenouvel Louis
 *
 * Groupe : 104
 * 
 * Dernière date de modification : 13/11/2021
 *
 * Syntaxe :
 * [in] : Entre dans la fonction
 * [out] : Sort de la fonction
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)


enum { Joueuses = 128 }; //Nombre de joueuses//
enum { lgMot = 30 }; //Longueur d'un texte//
enum { Matchs = 127 }; //Nombre de matchs//
enum { Tournois = 5 }; //Nombre max de Tournois//
enum { Joueurs = 2 }; //Nombre de joueurs par match//

//Caractéristiques d'une joueuse : Son nom et ses points//
typedef struct {
	char nom[lgMot + 1];
	unsigned int points;
} Joueuse;

//Caractéristiques d'un match : L'index de la gagnante et l'index de la perdante//
typedef struct {
	unsigned int idxGagnante;
	unsigned int idxPerdante;
} Match;

//Caractéristiques d'un Tournoi : Son nom, la date à laquelle il s'est déroulé et la liste de ses matchs//
typedef struct {
	char NomTournoi[lgMot];
	char Date[lgMot];
	char ListeMatchs[Matchs][Joueurs][lgMot];
}Tournoi;

//Stockage des Tournois : Liste des tournois, avec toutes les caractéristiques qui lui ont été associées//
typedef struct {
	char ListeTournois[Tournois];
	unsigned int EnrTournois;
}TournoisWTA;

/*Fonction qui définit le nombre de tournois, celui - ci étant indiqué sur le fichier texte
 * [out] nombre
 */
int definir_nombre_tournois(TournoisWTA *w) {
	int nombre;
	scanf("%d", &nombre);
	w->EnrTournois = 0; //Nombre de tournois enregistrés//
	return nombre;
}

/*Enregistrement d'un Tournoi avec ses caractéristiques
 * [in] Tournoi* t qui permet d'enregistrer un tournoi avec ses caractéristiques
 * [in] Match* m qui permet de séparer dans l'enregistrement les gagnantes et les perdantes
 */
void enregistrement_tournoi(Tournoi* t, Match* m, TournoisWTA* w) {
	scanf("%s", t->NomTournoi);
	scanf("%s", t->Date);
	int i;
	m->idxGagnante = 0;
	m->idxPerdante = 1;
	for (i = 0; i < 127; ++i) {
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
	}
	++w->EnrTournois;//Ajout de 1 au nombre de tournois enregistrés//
}

/*Affichage d'un Tournoi avec ses caractéristiques
 * [in] Tournoi* t qui permet de manipuler un tournoi avec ses caractéristiques
 * [in] Match* m qui comporte l'index de la gagnante et celui de la perdante
 */
char affichage_matchs_tournoi(Tournoi* t, Match* m, TournoisWTA* w) {
	char datetournoi[lgMot], nomtournoi[lgMot];
	scanf("%s %s", nomtournoi, datetournoi);
	if (w->EnrTournois == 0 || strcmp(nomtournoi, t->NomTournoi) != 0 || strcmp(datetournoi, t->Date) != 0) {
		printf("tournoi inconnu\n");
	}
	else {
		printf("%s %s\n", t->NomTournoi, t->Date); //Imprime le nom et la date du tournoi//
		int i = 0;
		m->idxGagnante = 0; //Définition de l'index de la gagnante//
		m->idxPerdante = 1; //Définition de l'index de la perdante//
		printf("64emes de finale\n");
		//Les matchs sont affichés sous la forme du nom de la gagnante puis du nom de la perdante//
		while (i < 64) { //Affiche tous les matchs des 64emes de finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("32emes de finale\n");
		while (i < 96) { //Affiche tous les matchs des 32emes de finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("16emes de finale\n");
		while (i < 112) { //Affiche tous les matchs des 16emes de finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("8emes de finale\n");
		while (i < 120) { //Affiche tous les matchs des 8emes de finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("quarts de finale\n");
		while (i < 124) { //Affiche tous les matchs des quarts de finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("demi-finales\n");
		while (i < 126) { //Affiche les demi-finales//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
		printf("finale\n");
		while (i < 127) { //Affiche la finale//
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++i;
		}
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	TournoisWTA w;
	while (1) { //S'éxécute jusqu'à ce qu'une fonction l'arrête//
		scanf("%s", &mot); //Lit tout le texte et s'arrête lorsqu'il rencontre une fonction//
		//Exécute la fonction definir_nombre_tournois s'il la rencontre dans le texte//
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			int nombre_tournois = definir_nombre_tournois(&w);
		}
		//Exécute la fonction enregistrement_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m, &w);
		}
		//Exécute la fonction affichage_matchs_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
			affichage_matchs_tournoi(&t, &m, &w);
		}
		//Arrête le programme s'il rencontre "exit" dans le texte//
		if (strcmp(mot, "exit") == 0) {
			exit(0); //Le programme s'arrête//
		}
	}
	system("pause");
	return 0;
	//Fin du programme//
}