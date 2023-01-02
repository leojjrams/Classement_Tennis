/*
Projet IAP : Les fondamentaux de la programmation imp�rative

Sprint 1

Auteurs : Rams L�o, Esteves Gabriel, Lenouvel Louis

Groupe : 104
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
enum { Tournois = 4 }; //Nombre max de Tournois//
enum { Joueurs = 2 }; //Nombre de joueurs par match//
enum { Carac = 2 }; //Caract�ristiques d'un tournoi//

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
	char ListeTournois[Tournois][Carac][lgMot];
	unsigned int EnrTournois;
}TournoisWTA;

//Fonction qui d�finit le nombre de tournois, celui-ci �tant indiqu� sur le fichier texte//
int definir_nombre_tournois(TournoisWTA* w) {
	int nombre;
	scanf("%d", &nombre);
	w->EnrTournois = 0; //Nombre de tournois enregistr�s//
	return nombre;
}

//Enregistrement d'un Tournoi avec ses caract�ristiques//
void enregistrement_tournoi(Tournoi* t, Match* m, TournoisWTA* w) {
	scanf("%s", t->NomTournoi); //Stockage du nom du Tournoi//
	scanf("%s", t->Date); //Stockage de la date � laquelle se d�roule le Tournoi//
	int i;
	m->idxGagnante = 0; //D�finition de l'index de la gagnante//
	m->idxPerdante = 1; //D�finition de l'index de la perdante//
	for (i = 0; i < 127; ++i) {
		//Stockage des noms des gagnantes et perdantes du Tournoi dans ListeMatchs//
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
	}
}

//Affiche le nom du Tournoi, sa date et tous les matchs de ListeMatchs//
void afficher_matchs_joueuse(Tournoi* t, Match* m, Joueuse* j, TournoisWTA* w) {
	char datetournoi[lgMot], nomtournoi[lgMot];
	scanf("%s %s %s", nomtournoi, datetournoi, j->nom); //[in] 
	int compteur = 0;
	for (int i = 0; i < 127; ++i) {
		if (strcmp(t->ListeMatchs[i][m->idxGagnante], j->nom) == 0 || strcmp(t->ListeMatchs[i][m->idxPerdante], j->nom) == 0) {
			printf("%s %s\n", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
			++compteur;
		}
	}
	if (compteur == 0) {
		printf("Nom inconnu");
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	Joueuse j;
	TournoisWTA w;
	while (1) {
		scanf("%s", &mot);
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			int nombre_tournois = definir_nombre_tournois(&w);
		}
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m, &w);
		}
		else if (strcmp(mot, "afficher_matchs_joueuse") == 0) {
			afficher_matchs_joueuse(&t, &m, &j, &w);
		}
		if (strcmp(mot, "exit") == 0) {
			exit(0);
		}
	}
	system("pause");
	return 0;
}