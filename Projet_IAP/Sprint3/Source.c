/*
 * Projet IAP : Les fondamentaux de la programmation imp�rative
 *
 * Sprint 3
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
enum { JoueusesTournoi = 64 };  //Nombre de joueuses dans un tournoi//
enum { lgMot = 30 }; //Longueur d'un texte//
enum { Matchs = 127 }; //Nombre de matchs//
enum { Tournois = 5 }; //Nombre max de Tournois//
enum { Joueurs = 2 }; //Nombre de joueurs par match//
enum { Carac = 2 }; //Caract�ristiques d'un tournoi//
enum { Alphabet = 26 }; //Nombre de lettres dans l'alphabet//

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

/*Fonction qui d�finit le nombre de tournois, celui - ci �tant indiqu� sur le fichier texte
 * [out] nombre
 */
int definir_nombre_tournois(TournoisWTA* w) {
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
	scanf("%s", t->NomTournoi); //Stockage du nom du Tournoi//
	scanf("%s", t->Date); //Stockage de la date � laquelle se d�roule le Tournoi//
	int i;
	m->idxGagnante = 0; //D�finition de l'index de la gagnante//
	m->idxPerdante = 1; //D�finition de l'index de la perdante//
	for (i = 0; i < 127; ++i) {
		//Stockage des noms des gagnantes et perdantes du Tournoi dans ListeMatchs//
		scanf("%s %s", t->ListeMatchs[i][m->idxGagnante], t->ListeMatchs[i][m->idxPerdante]);
	}
	++w->EnrTournois;//Ajout de 1 au nombre de tournois enregistr�s//
}

/*Affichage des joueuses d'un Tournoi avec ses caract�ristiques
 * [in] Tournoi* t qui permet de manipuler les caract�ristiques du tournoi
 * [in] Match* m qui comporte l'index de la gagnante et l'index de la perdante
 * [in] Joueuse* j qui permet de d�finir une joueuse du match par son nom et ses points
 */
void affichage_joueuses_tournoi(Tournoi* t, Match* m, Joueuse* j, TournoisWTA* w) {
	char datetournoi[lgMot], nomtournoi[lgMot];
	scanf("%s %s", nomtournoi, datetournoi);
	if (w->EnrTournois == 0 || strcmp(nomtournoi, t->NomTournoi)!=0 || strcmp(datetournoi, t->Date)!=0) {
		printf("tournoi inconnu\n");
	}
	else {
		char apparues[Joueuses][lgMot]; //liste des joueuses d�j� trait�es//
		unsigned int points[Joueuses], compteur = 0; //liste des points associ�s au nom des joueuses dans apparues, compteur d'apparition//
		for (int n = 0; n < 2; ++n) {// index gagnant ou index perdant// 
			for (int i = 0; i < Joueuses - 1; ++i) {// index du match//
				strcpy(j->nom, t->ListeMatchs[i][n]);
				int test = 0;
				for (int o = 0; o < Joueuses; ++o) {// on parcourt la liste apparues//
					if (strcmp(apparues[o], j->nom) == 0) {
						test = 1; //si la joueuse est apparue alors le test est n�gatif//
					}
				}
				if (test == 0) {
					unsigned int apparitions = 1;
					for (int k = 0; k < Matchs; ++k) { //on parcourt la liste des matchs//
						if (strcmp(t->ListeMatchs[k][m->idxGagnante], j->nom) == 0) {
							++apparitions; //si le nom de la joueuse r�appara�t alors on rajoute une apparition//
						}
					}
					switch (apparitions) {
					case 1:
						j->points = 10; //a perdu lors des 64emes de finale//
						break;
					case 2:
						j->points = 45; //A gagn� lors des 64emes de finale//
						break;
					case 3:
						j->points = 90; //A gagn� lors des 32emes de finale//
						break;
					case 4:
						j->points = 180; //A gagn� lors des 16emes de finale//
						break;
					case 5:
						j->points = 360; //A gagn� lors des 8emes de finale//
						break;
					case 6:
						j->points = 720; //A gagn� lors des quarts de finale//
						break;
					case 7:
						j->points = 1200; //A gagn� lors des demi-finales//
						break;
					case 8:
						j->points = 2000; //A gagn� le tournoi//
						break;
					}
					strcpy(apparues[compteur], j->nom); //on ajoute dans la lsite apparues le nom//
					points[compteur] = j->points; //on ajoute dans la lsite points au m�me indice//
					++compteur; //on ajoute 1 au compteur//
				}
			}
		}
		printf("%s %s\n", t->NomTournoi, t->Date); //on affiche le nom et la date du tounoi//
		char Rangees[Joueuses][lgMot], PlusPetit[lgMot]; //Liste des joueuses tri�es par ordre alphab�tiques, le plus petit//
		unsigned int Prangees[Joueuses], position; //Liste des points rang�s suivant l'ordre des noms//
		for (int i = 0; i < Joueuses; ++i) { //on parcourt la liste des joueuses//
			strcpy(PlusPetit, apparues[0]); //on admet le premier comme le plus petit//
			int l = 0; //index de position dans la liste//
			for (l; l < Joueuses - 1; ++l) {
				int y = 0; //index de la lettre//
				while (apparues[l + 1][y] == PlusPetit[y]) {
					++y;// si la lettre est identique alors on passe � la lettre suivante//
				}
				if (apparues[l + 1][y] < PlusPetit[y]) {
					strcpy(PlusPetit, apparues[l + 1]); //si le nom est inf�rieur alors il devient le plus petit//
				}
			}
			for (int n = 0; n < Joueuses; ++n) {
				if (strcmp(PlusPetit, apparues[n]) == 0) {
					position = n;//on r�cup�re la position du plus petit que l'on a trouv�//
				}
			}
			strcpy(Rangees[i], PlusPetit); //on met le plus dans la liste rang�//
			strcpy(apparues[position], "{"); //on remplace alors le plus petit dans la table apparue par { car nous sommes en langages ASCII, qui est plus grand que toute les lettres de l'alphabet//
			Prangees[i] = points[position]; //on attribut les points//
			printf("%s %u\n", Rangees[i], Prangees[i]); //on affiche la liste tri� par ordre alphab�tique//
		}
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	Joueuse j;
	TournoisWTA w;
	while (1) {//S'�x�cute jusqu'� ce qu'une fonction l'arr�te//
		scanf("%s", &mot);  //Lit tout le texte et s'arr�te lorsqu'il rencontre une fonction//
		//Ex�cute la fonction definir_nombre_tournois s'il la rencontre dans le texte//
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			int nombre_tournois = definir_nombre_tournois(&w);
		}
		//Ex�cute la fonction enregistrement_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m, &w);
		}
		//Ex�cute la fonction affichage_joueuses_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
			affichage_joueuses_tournoi(&t, &m, &j, &w);
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