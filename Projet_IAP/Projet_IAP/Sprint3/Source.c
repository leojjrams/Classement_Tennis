#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)

enum { Joueuses = 128 };
enum {JoueusesTournoi = 64};
enum { lgMot = 30 };
enum { Matchs = 127 };
enum { Tournois = 4 };
enum { Joueurs = 2 };
enum { Carac = 2 };
enum {Alphabet=26};

typedef struct {
	char nom[lgMot + 1];
	unsigned int points;
} Joueuse;

typedef struct {
	unsigned int idxGagnante;
	unsigned int idxPerdante;
} Match;

typedef struct {
	char NomTournoi[lgMot];
	char Date[lgMot];
	char ListeMatchs[Matchs][Joueurs][lgMot];
}Tournoi;

typedef struct {
	char ListeTournois[Tournois][Carac][lgMot];
	unsigned int EnrTournois;
}TournoisWTA;

int definir_nombre_tournois(TournoisWTA* w) {
	int nombre;
	scanf("%d", &nombre);
	w->EnrTournois = 0;
	return nombre;
}

void enregistrement_tournoi(Tournoi* t, Match* m, TournoisWTA* w) {
	scanf("%s", t->NomTournoi);
	scanf("%s", t->Date);
	int i;
	m->idxGagnante = 0;
	m->idxPerdante = 1;
	for (i = 0; i < Matchs; ++i) {
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
	}
}

void affichage_joueuses_tournoi(Tournoi* t, Match* m, Joueuse* j) {
	char apparues[Joueuses][lgMot];
	unsigned int points[Joueuses], compteur = 0;
	for (int n = 0; n < 2; ++n) {
		for (int i = 0; i < Joueuses-1; ++i) {
			strcpy(j->nom, t->ListeMatchs[i][n]);
			int test = 0;
			for (int o = 0; o < Joueuses; ++o) {
				if (strcmp(apparues[o], j->nom) == 0) {
					test = 1;
				}
			}
			if (test == 0) {
				unsigned int apparitions = 1;
				for (int k = 0; k < Matchs; ++k) {
					if (strcmp(t->ListeMatchs[k][m->idxGagnante], j->nom) == 0) {
						++apparitions;
					}
				}
				switch (apparitions) {
				case 1:
					j->points = 10;
					break;
				case 2:
					j->points = 45;
					break;
				case 3:
					j->points = 90;
					break;
				case 4:
					j->points = 180;
					break;
				case 5:
					j->points = 360;
					break;
				case 6:
					j->points = 720;
					break;
				case 7:
					j->points = 1200;
					break;
				case 8:
					j->points = 2000;
					break;
				}
				strcpy(apparues[compteur], j->nom);
				points[compteur] = j->points;
				++compteur;
			}
		}
	}
	printf("%s %s\n", t->NomTournoi, t->Date);
	char Rangees[Joueuses][lgMot], PlusPetit[lgMot];
	unsigned int Prangees[Joueuses], position;
	for (int i = 0; i < Joueuses; ++i) {
		strcpy(PlusPetit, apparues[0]);
		int l = 0;
		for (l; l < Joueuses-1; ++l) {
			int k = 0;
			int y = 0;
			while (apparues[l + 1][y] == PlusPetit[y]) {
				++y;
			}
			if (apparues[l + 1][y] < PlusPetit[y]) {
				strcpy(PlusPetit, apparues[l + 1]);
			}
		}
		for (int n = 0; n < Joueuses; ++n) {
			if (strcmp(PlusPetit, apparues[n]) == 0) {
				position = n;
			}
		}
		strcpy(Rangees[i], PlusPetit);
		strcpy(apparues[position], "{");
		Prangees[i] = points[position];
		printf("%s %u\n", Rangees[i], Prangees[i]);
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
		else if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
			affichage_joueuses_tournoi(&t, &m, &j);
		}
		if (strcmp(mot, "exit") == 0) {
			exit(0);
		}
	}
	system("pause");
	return 0;
}