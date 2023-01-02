/*
 * Projet IAP : Les fondamentaux de la programmation impérative
 *
 * Sprint 3
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
enum { JoueusesTournoi = 64 };  //Nombre de joueuses dans un tournoi//
enum { lgMot = 30 }; //Longueur d'un texte//
enum { Matchs = 127 }; //Nombre de matchs//
enum { Tournois = 5 }; //Nombre max de Tournois//
enum { Joueurs = 2 }; //Nombre de joueurs par match//
enum { Carac = 2 }; //Caractéristiques d'un tournoi//
enum { Alphabet = 26 }; //Nombre de lettres dans l'alphabet//

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

/*Affichage des joueuses d'un Tournoi avec ses caractéristiques
 * [in] Tournoi* t qui permet de manipuler les caractéristiques du tournoi
 * [in] Match* m qui comporte l'index de la gagnante et l'index de la perdante
 * [in] Joueuse* j qui permet de définir une joueuse du match par son nom et ses points
 */
void affichage_joueuses_tournoi(Tournoi* t, Match* m, Joueuse* j, TournoisWTA* w) {
	char datetournoi[lgMot], nomtournoi[lgMot];
	scanf("%s %s", nomtournoi, datetournoi);
	if (w->EnrTournois == 0 || strcmp(nomtournoi, t->NomTournoi)!=0 || strcmp(datetournoi, t->Date)!=0) {
		printf("tournoi inconnu\n");
	}
	else {
		char apparues[Joueuses][lgMot]; //liste des joueuses déjà traitées//
		unsigned int points[Joueuses], compteur = 0; //liste des points associés au nom des joueuses dans apparues, compteur d'apparition//
		for (int n = 0; n < 2; ++n) {// index gagnant ou index perdant// 
			for (int i = 0; i < Joueuses - 1; ++i) {// index du match//
				strcpy(j->nom, t->ListeMatchs[i][n]);
				int test = 0;
				for (int o = 0; o < Joueuses; ++o) {// on parcourt la liste apparues//
					if (strcmp(apparues[o], j->nom) == 0) {
						test = 1; //si la joueuse est apparue alors le test est négatif//
					}
				}
				if (test == 0) {
					unsigned int apparitions = 1;
					for (int k = 0; k < Matchs; ++k) { //on parcourt la liste des matchs//
						if (strcmp(t->ListeMatchs[k][m->idxGagnante], j->nom) == 0) {
							++apparitions; //si le nom de la joueuse réapparaît alors on rajoute une apparition//
						}
					}
					switch (apparitions) {
					case 1:
						j->points = 10; //a perdu lors des 64emes de finale//
						break;
					case 2:
						j->points = 45; //A gagné lors des 64emes de finale//
						break;
					case 3:
						j->points = 90; //A gagné lors des 32emes de finale//
						break;
					case 4:
						j->points = 180; //A gagné lors des 16emes de finale//
						break;
					case 5:
						j->points = 360; //A gagné lors des 8emes de finale//
						break;
					case 6:
						j->points = 720; //A gagné lors des quarts de finale//
						break;
					case 7:
						j->points = 1200; //A gagné lors des demi-finales//
						break;
					case 8:
						j->points = 2000; //A gagné le tournoi//
						break;
					}
					strcpy(apparues[compteur], j->nom); //on ajoute dans la lsite apparues le nom//
					points[compteur] = j->points; //on ajoute dans la lsite points au même indice//
					++compteur; //on ajoute 1 au compteur//
				}
			}
		}
		printf("%s %s\n", t->NomTournoi, t->Date); //on affiche le nom et la date du tounoi//
		char Rangees[Joueuses][lgMot], PlusPetit[lgMot]; //Liste des joueuses triées par ordre alphabétiques, le plus petit//
		unsigned int Prangees[Joueuses], position; //Liste des points rangés suivant l'ordre des noms//
		for (int i = 0; i < Joueuses; ++i) { //on parcourt la liste des joueuses//
			strcpy(PlusPetit, apparues[0]); //on admet le premier comme le plus petit//
			int l = 0; //index de position dans la liste//
			for (l; l < Joueuses - 1; ++l) {
				int y = 0; //index de la lettre//
				while (apparues[l + 1][y] == PlusPetit[y]) {
					++y;// si la lettre est identique alors on passe à la lettre suivante//
				}
				if (apparues[l + 1][y] < PlusPetit[y]) {
					strcpy(PlusPetit, apparues[l + 1]); //si le nom est inférieur alors il devient le plus petit//
				}
			}
			for (int n = 0; n < Joueuses; ++n) {
				if (strcmp(PlusPetit, apparues[n]) == 0) {
					position = n;//on récupère la position du plus petit que l'on a trouvé//
				}
			}
			strcpy(Rangees[i], PlusPetit); //on met le plus dans la liste rangé//
			strcpy(apparues[position], "{"); //on remplace alors le plus petit dans la table apparue par { car nous sommes en langages ASCII, qui est plus grand que toute les lettres de l'alphabet//
			Prangees[i] = points[position]; //on attribut les points//
			printf("%s %u\n", Rangees[i], Prangees[i]); //on affiche la liste trié par ordre alphabétique//
		}
	}
}

int main() {
	char mot[lgMot];
	Tournoi t;
	Match m;
	Joueuse j;
	TournoisWTA w;
	while (1) {//S'éxécute jusqu'à ce qu'une fonction l'arrête//
		scanf("%s", &mot);  //Lit tout le texte et s'arrête lorsqu'il rencontre une fonction//
		//Exécute la fonction definir_nombre_tournois s'il la rencontre dans le texte//
		if (strcmp(mot, "definir_nombre_tournois") == 0) {
			int nombre_tournois = definir_nombre_tournois(&w);
		}
		//Exécute la fonction enregistrement_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "enregistrement_tournoi") == 0) {
			enregistrement_tournoi(&t, &m, &w);
		}
		//Exécute la fonction affichage_joueuses_tournoi s'il la rencontre dans le texte//
		else if (strcmp(mot, "affichage_joueuses_tournoi") == 0) {
			affichage_joueuses_tournoi(&t, &m, &j, &w);
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