/*
 * Projet IAP : Les fondamentaux de la programmation impérative
 *
 * Sprint 2
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
enum { Carac = 2 }; //Caractéristiques d'un tournoi//

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
	char ListeTournois[Tournois][Carac][lgMot];
	unsigned int EnrTournois;
}TournoisWTA;

/*Fonction qui définit le nombre de tournois, celui - ci étant indiqué sur le fichier texte
 * [out] nombre
 */
int definir_nombre_tournois(TournoisWTA* w) {
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
	scanf("%s", t->NomTournoi); //Stockage du nom du Tournoi//
	scanf("%s", t->Date); //Stockage de la date à laquelle se déroule le Tournoi//
	int i;
	m->idxGagnante = 0; //Définition de l'index de la gagnante//
	m->idxPerdante = 1; //Définition de l'index de la perdante//
	for (i = 0; i < 127; ++i) {
		//Stockage des noms des gagnantes et perdantes du Tournoi dans ListeMatchs//
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
	}
	++w->EnrTournois;//Ajout de 1 au nombre de tournois enregistrés//
}

/*Affichage des matchs d'une joueuse lors d'un tournoi
 * [in] Tournoi* t qui permet de manipuler un tournoi ainsi que ses caractéristiques
 * [in] Match* m qui comporte l'index de la gagnante et de la perdante
 * [in] Joueuse* j qui permet de définir une joueuse du tournoi avec son nom et ses points
 */
void afficher_matchs_joueuse(Tournoi* t, Match* m, Joueuse* j, TournoisWTA* w) {
	char datetournoi[lgMot], nomtournoi[lgMot];
	scanf("%s %s %s", nomtournoi, datetournoi, j->nom);
	if (w->EnrTournois==0 || strcmp(nomtournoi, t->NomTournoi) != 0 || strcmp(datetournoi, t->Date) != 0) {
		printf("tournoi inconnu\n");
	}
	else {
		int compteur = 0;
		for (int i = 0; i < 127; ++i) {
			if (strcmp(t->ListeMatchs[i][m->idxGagnante], j->nom) == 0 || strcmp(t->ListeMatchs[i][m->idxPerdante], j->nom) == 0) {//si le nom de la joueuse apparaît lors d'un match (victoire ou défaite) alors nous affichons ce match//
				printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
				++compteur;
			}
		}
		if (compteur == 0) {
			printf("joueuse inconnue");
		}
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	Joueuse j;
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
		//Exécute la fonction affichage_matchs_joueuse s'il la rencontre dans le texte//
		else if (strcmp(mot, "afficher_matchs_joueuse") == 0) {
			afficher_matchs_joueuse(&t, &m, &j, &w);
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
