#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6054)

enum { Joueuses = 128, JoueusesTournoi = 64, lgMot = 30, Matchs = 127, Tournois = 5, Joueurs = 2, Carac = 2, TotalJoueuses = Joueuses * Tournois };

typedef struct {
	char nom[lgMot + 1];
	unsigned int points;
} Joueuse;

typedef struct {
	Joueuse ListeJoueuses[Joueuses];
	unsigned int EnrJoueuses;
}JoueusesMatchs;

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
	Tournoi ListeTournois[Tournois];
	unsigned int EnrTournois;
}TournoisWTA;

int definir_nombre_tournois(TournoisWTA* w, Match* m) {
	const int nombre;
	scanf("%d", &nombre);
	w->EnrTournois = 0;
	return nombre;
}

void enregistrement_tournoi(Match* m, TournoisWTA* w) {
	printf("%u\n", w->EnrTournois);
	scanf("%s", w->ListeTournois[w->EnrTournois].NomTournoi);
	scanf("%s", w->ListeTournois[w->EnrTournois].Date);
	m->idxGagnante = 0;
	m->idxPerdante = 1;
	int i;
	for (i = 0; i < Matchs; ++i) {
		scanf("%s %s", w->ListeTournois[w->EnrTournois].ListeMatchs[i][m->idxGagnante], w->ListeTournois[w->EnrTournois].ListeMatchs[i][m->idxPerdante]);
	}
	++w->EnrTournois;
	for (int g = 0; g < Matchs; ++g) {
		printf("Enregistrement : %s\n", w->ListeTournois[0].ListeMatchs[g][m->idxGagnante]);
	}
}

void afficher_classement(Match* m, TournoisWTA* w, Joueuse* j, JoueusesMatchs* x) {
	for (int g = 0; g < Matchs; ++g) {
		printf("afficher : %s\n", w->ListeTournois[0].ListeMatchs[g][m->idxGagnante]);
	}
	x->EnrJoueuses = 0;
	int TotalTournois = w->EnrTournois;
	char apparues[TotalJoueuses][lgMot];
	for (int y = 0; y < w->EnrTournois; ++y) {
		unsigned int compteur = 0;
		char apparuesTournoi[Joueuses][lgMot];
		for (int i = 0; i < Joueuses - 1; ++i) {
			for (int g = 0; g < Matchs; ++g) {
				printf("FOR : %s\n", w->ListeTournois[0].ListeMatchs[g][m->idxGagnante]);
			}
			for (int n = 0; n < 2; ++n) {
				int test1 = 0, test2 = 0;
				strcpy(j->nom, w->ListeTournois[y].ListeMatchs[i][n]);
				for (int o = 0; o < Joueuses; ++o) {
					if (strcmp(apparuesTournoi[o], j->nom) == 0) {
						test1 = 1;
					}
				}
				for (int l = 0; l < Joueuses*TotalTournois; ++l) {
					if (strcmp(apparues[l], j->nom) == 0) {
						test2 = 1;
					}
				}
				if (test2 == 0) {
					strcpy(x->ListeJoueuses[x->EnrJoueuses].nom, j->nom);
					x->ListeJoueuses[x->EnrJoueuses].points = 0;
					strcpy(apparues[x->EnrJoueuses], j->nom);
					++x->EnrJoueuses;
				}
				if (test1 == 0) {
					unsigned int apparitions = 1;
					unsigned int indice;
					for (int k = 0; k < Matchs; ++k) {
						if (strcmp(w->ListeTournois[y].ListeMatchs[k][m->idxGagnante], j->nom) == 0) {
							++apparitions;
						}
					}
					for (int p = 0; p < x->EnrJoueuses;++p) {
						if (strcmp(j->nom, x->ListeJoueuses[p].nom) == 0) {
							indice = p;
						}
					}
					switch (apparitions) {
						case 1:
							x->ListeJoueuses[indice].points += 10;
							break;
						case 2:
							x->ListeJoueuses[indice].points += 45;
							break;
						case 3:
							x->ListeJoueuses[indice].points += 90;
							break;
						case 4:
							x->ListeJoueuses[indice].points += 180;
							break;
						case 5:
							x->ListeJoueuses[indice].points += 360;
							break;
						case 6:
							x->ListeJoueuses[indice].points += 720;
							break;
						case 7:
							x->ListeJoueuses[indice].points += 1200;
							break;
						case 8:
							x->ListeJoueuses[indice].points += 2000;
							break;
					}
					strcpy(apparuesTournoi[compteur], j->nom);
					++compteur;
				}
			}
		}
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	Joueuse j;
	TournoisWTA w;
	JoueusesMatchs x;
	int nombre_tournois;
	while (1) {
		scanf("%s", &mot);
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			nombre_tournois = definir_nombre_tournois(&w, &m);
		}
		if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&m, &w);
		}
		if (strcmp(mot, "afficher_classement") == 0) {
			afficher_classement(&m, &w, &x, &j);
		}
		if (strcmp(mot, "exit") == 0) {
			exit(0);
		}
	}
	system("pause");
	return 0;
}