/*
 * Projet IAP : Les fondamentaux de la programmation imp�rative
 *
 * Sprint 1
 *
 * Auteurs : Rams L�o, Esteves Gabriel, Lenouvel Louis
 *
 * Groupe : 104
 *
 * Syntaxe :
 * [in] : Entre dans le programmme
 * [out] : Sort du programme
 */


#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)


enum { Joueuses = 128 };
enum { lgMot = 30 };
enum { Matchs = 127 };
enum { Tournois = 5 };
enum { Joueurs = 2 };

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
}TournoisWTA;

/*Fonction qui d�finit le nombre de tournois, celui - ci �tant indiqu� sur le fichier texte
 * [in-out] nombre
 */
int definir_nombre_tournois() { 
	int nombre;
	scanf("%d", &nombre);
	return nombre;
}

/*Enregistrement d'un Tournoi avec ses caract�ristiques
 * [in] t->NomTournoi
 * [in] t->Date
 * [in] t->ListeMatchs[i][m->idxGagnante], Pour i allant de 0 � 127, enregistrement de la gagnante du match
 * [in] t->ListeMatchs[i][m->idxPerdante], Pour i allant de 0 � 127, enregistrement de la perdante du match
 */
void enregistrement_tournoi(Tournoi* t, Match* m) { 
	scanf("%s", t->NomTournoi);
	scanf("%s", t->Date);
	int i;
	m->idxGagnante = 0;
	m->idxPerdante = 1;
	for (i = 0; i < 127; ++i) {
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]); 
	}
}

//Affiche le nom du Tournoi, sa date et tous les matchs de ListeMatchs//
char affichage_matchs_tournoi(Tournoi* t, Match* m) { 
	printf("%s %s\n", t->NomTournoi, t->Date); //[out] Imprime le nom et la date du tournoi//
	int i = 0;
	m->idxGagnante = 0; //D�finition de l'index de la gagnante//
	m->idxPerdante = 1; //D�finition de l'index de la perdante//
	printf("64emes de finale\n");
	//Les matchs sont affich�s sous la forme du nom de la gagnante puis du nom de la perdante//
	while (i < 64) { //[out] Affiche tous les matchs des 64emes de finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("32emes de finale\n"); //[out]//
	while (i < 96) { //[out] Affiche tous les matchs des 32emes de finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("16emes de finale\n"); //[out]//
	while (i < 112) { //[out] Affiche tous les matchs des 16emes de finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("8emes de finale\n"); //[out]//
	while (i < 120) { //[out] Affiche tous les matchs des 8emes de finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("quarts de finale\n"); //[out]//
	while (i < 124) { //[out] Affiche tous les matchs des quarts de finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("demi-finales\n"); //[out]//
	while (i < 126) { //[out] Affiche les demi-finales//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
	printf("finale\n"); //[out]//
	while (i < 127) { //[out] Affiche la finale//
		printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
		++i;
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	while (1) { //S'�x�cute jusqu'� ce qu'une fonction l'arr�te//
		scanf("%s", &mot); //[in] Lit tout le texte et s'arr�te lorsqu'il rencontre une fonction//
		//Ex�cute la fonction definir_nombre_tournois s'il la rencontre dans le texte//
		if (strcmp(mot, "definir_nombre_tournois") == 0) { 
			int nombre_tournois = definir_nombre_tournois();
		}
		//Ex�cute la fonction enregistrement_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m);
		}
		//Ex�cute la fonction affichage_matchs_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "affichage_matchs_tournoi") == 0) {
			affichage_matchs_tournoi(&t, &m);
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