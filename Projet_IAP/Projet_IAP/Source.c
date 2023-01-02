/*
 * Projet IAP : Les fondamentaux de la programmation imp�rative
 *
 * Sprint 1
 *
 * Auteurs : Rams L�o, Esteves Gabriel, Lenouvel Louis
 *
 * Groupe : 104
 * 
 * Derni�re date de modification : 13/11/2021
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

//Caract�ristiques d'une joueuse : Son nom et ses points//
typedef struct {
	char nom[lgMot + 1];
	unsigned int points;
} Joueuse;

//Caract�ristiques d'un match : L'index de la gagnante et l'index de la perdante//
typedef struct {
	unsigned int idxGagnante;
	unsigned int idxPerdante;
} Match;

//Caract�ristiques d'un Tournoi : Son nom, la date � laquelle il s'est d�roul� et la liste de ses matchs//
typedef struct {
	char NomTournoi[lgMot];
	char Date[lgMot];
	char ListeMatchs[Matchs][Joueurs][lgMot];
}Tournoi;

//Stockage des Tournois : Liste des tournois, avec toutes les caract�ristiques qui lui ont �t� associ�es//
typedef struct {
	char ListeTournois[Tournois];
	unsigned int EnrTournois;
}TournoisWTA;

/*Fonction qui d�finit le nombre de tournois, celui - ci �tant indiqu� sur le fichier texte
 * [out] nombre
 */
int definir_nombre_tournois(TournoisWTA *w) {
	int nombre;
	scanf("%d", &nombre);
	w->EnrTournois = 0; //Nombre de tournois enregistr�s//
	return nombre;
}

/*Enregistrement d'un Tournoi avec ses caract�ristiques
 * [in] Tournoi* t qui permet d'enregistrer un tournoi avec ses caract�ristiques
 * [in] Match* m qui permet de s�parer dans l'enregistrement les gagnantes et les perdantes
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
	++w->EnrTournois;//Ajout de 1 au nombre de tournois enregistr�s//
}

/*Affichage d'un Tournoi avec ses caract�ristiques
 * [in] Tournoi* t qui permet de manipuler un tournoi avec ses caract�ristiques
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
		m->idxGagnante = 0; //D�finition de l'index de la gagnante//
		m->idxPerdante = 1; //D�finition de l'index de la perdante//
		printf("64emes de finale\n");
		//Les matchs sont affich�s sous la forme du nom de la gagnante puis du nom de la perdante//
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
	while (1) { //S'�x�cute jusqu'� ce qu'une fonction l'arr�te//
		scanf("%s", &mot); //Lit tout le texte et s'arr�te lorsqu'il rencontre une fonction//
		//Ex�cute la fonction definir_nombre_tournois s'il la rencontre dans le texte//
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			int nombre_tournois = definir_nombre_tournois(&w);
		}
		//Ex�cute la fonction enregistrement_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m, &w);
		}
		//Ex�cute la fonction affichage_matchs_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
			affichage_matchs_tournoi(&t, &m, &w);
		}
		//Arr�te le programme s'il rencontre "exit" dans le texte//
		if (strcmp(mot, "exit") == 0) {
			exit(0); //Le programme s'arr�te//
		}
	}
	system("pause");
	return 0;
	//Fin du programme//
}