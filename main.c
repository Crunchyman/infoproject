#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DimL 9
#define DimC 7
#define DIM_CHAR 50
#define NUMOFPIECES 8

typedef enum { BLUE, RED } colorType;
typedef enum { EMPTY, WATER, RTRAP, BTRAP, FLAGRED, FLAGBLUE } state;
/*  initialiser le tableau 9x7 donc display
 * definir les positions initialement //done
 * definir la place des pieges et tout ca.
 * creer structure rouge et bleu.
 * definir quand le jeu termine
 * definir eau
 * definir qui mange qui
 * definir les regles
 * definir les pieges
 * definir le drapeau.
 * */
/*
USE STR COPY !!!
//done
*/
// add switch case for STATE
// everytime you want to change cases always remember to change the value of,
// taken to 0 in the old case
/*					DONT FORGET TO USE BLUE AND RED AS PLAYERS
 * 					INSTEAD OF PLAYER 1 AND 2
 * 																			*/
struct pieces {
    colorType color;
    int order;
    int inWater;
    int canWater;
    int canLeep;
    char name[DIM_CHAR];
    char character;
    char subcharacter;
};
typedef struct pieces playerPieces;

struct tableHolder {
    playerPieces Player;
    state State;
    int taken;
};
typedef struct tableHolder table;

//***************************SUB PROGRAMS **********************************
void playerRandomizer(int* player);                                                          // DONE, ralph
void gameinit(playerPieces B[], playerPieces R[], playerPieces* nothing, table tab[][DimC]); // DONE, ralph
void playerChooser(int* player);                                                             // DONE, ralph
void pieceInit(playerPieces Blue[], playerPieces Red[]);                                     // DONE, ralph
//**************************END OF SUBPROGRAMS******************************
int main()
{
    int player;
    playerPieces Blue[NUMOFPIECES];
    playerPieces Red[NUMOFPIECES];
    playerPieces nothing;
    table tab[DimL][DimC];
    playerRandomizer(&player);
    gameinit(Blue, Red, &nothing, tab);
}

void gameinit(playerPieces Blue[], playerPieces Red[], playerPieces* nothing, table tab[][DimC])
{
    int i, j;

    // initialisation of a case where there is nothing
    nothing->canLeep = 0;
    nothing->canWater = 0;
    nothing->character = ' ';
    nothing->subcharacter = ' ';
    nothing->color = 0;
    nothing->order = -1;
    nothing->inWater = 0;

    pieceInit(Blue, Red);
    for(i = 0; i < DimL; i++) {
	for(j = 0; j < DimC; j++) {

	    // initialisation of BLUE PIECES
	    if(i == 0) {
		if(j == 0) {
		    tab[i][j].Player = Blue[6];
		    tab[i][j].State = EMPTY;
		}

		if((j == 2) || (j == 4) || (j == 3)) {
		    tab[i][j].State = BTRAP; // define place for trap
		    tab[i][j].Player.order = -1;
		}

		if(j == 3) {
		    tab[i][j].State = FLAGBLUE; // define place for flag
		    tab[i][j].Player.order = -1;
		}
		if(j == 6) {
		    tab[i][j].Player = Blue[5];
		    tab[i][j].State = EMPTY;
		}
	    }

	    if(i == 1) {

		if(j == 1) {
		    tab[i][j].Player = Blue[3];
		    tab[i][j].State = EMPTY;
		}
		if(j == 3) {
		    tab[i][j].Player.order = -1;
		}
		if(j == 5) {
		    tab[i][j].Player = Blue[1];
		    tab[i][j].State = EMPTY;
		}
	    }

	    if(i == 2) {
		if(j == 0) {
		    tab[i][j].Player = Blue[0];
		    tab[i][j].State = EMPTY;
		}
		if(j == 2) {
		    tab[i][j].Player = Blue[4];
		    tab[i][j].State = EMPTY;
		}
		if(j == 4) {
		    tab[i][j].Player = Blue[2];
		    tab[i][j].State = EMPTY;
		}
		if(j == 6) {
		    tab[i][j].Player = Blue[7];
		    tab[i][j].State = EMPTY;
		}
	    }

	    // intialisation of water
	    if(i == 3 || i == 4 || i == 5) {

		if(j == 1 || j == 2 || j == 4 || j == 5) {
		    tab[i][j].Player = *nothing;
		    tab[i][j].State = WATER;
		}
	    }

	    //************** INITIALISATION OF RED PIECES**************
	    if(i == 6) {

		if(j == 0) {
		    tab[i][j].Player = Red[7];
		    tab[i][j].State = EMPTY;
		}
		if(j == 2) {
		    tab[i][j].Player = Red[2];
		    tab[i][j].State = EMPTY
		}
		if(j == 4) {
		    tab[i][j].Player = Red[4];
		    tab[i][j].State = EMPTY;
		}
		if(j == 6) {
		    tab[i][j].Player = Red[0];
		    tab[i][j].State = EMPTY;
		}
	    }
	    if(i == 7) {
		if(j == 1) {
		    tab[i][j].Player = Red[1];
		    tab[i][j].State = EMPTY;
		}
		if(j == 3) {
		    tab[i][j].Player.order = -1;
		    tab[i][j].State = RTRAP;
		}
		if(j == 5) {
		    tab[i][j].Player = Red[3];
		    tab[i][j].State = EMPTY;
		}
	    }
	    if(i == 8) {
		if(j == 0) {
		    tab[i][j].Player = Red[5];
		    tab[i][j].State = EMPTY;
		}
		if(j == 2 || j == 4) {
		    tab[i][j].Player.order = -1;
		    tab[i][j].State = RTRAP;
		}
		if(j == 6) {
		    tab[i][j].Player = Red[6];
		    tab[i][j].State = EMPTY;
		}
	    } else {
		tab[i][j].State = EMPTY;
		tab[i][j].Player = *nothing;
	    }
	}
    }
}

void playerChooser(int* player) // done adapt to blue and red
{
    *player = *player % 2 + 1;
}

void playerRandomizer(int* player) // done but adapt to blue and red
{
    *player = (rand() % 2) + 1;
}
void checkMoves()
{
}
void answer()
{
}
void gameChecker()
{
}
void pieceInit(playerPieces Blue[], playerPieces Red[]) // ralph
{
    int i;
    // initialisation of players pieces. rat = 0
    for(i = 0; i < NUMOFPIECES; i++) {
	Blue[i].color = BLUE;
	Red[i].color = RED;
	switch(i) {
	case 0:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 1;
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Rat");
	    Blue[i].character = 'R';
	    Blue[i].subcharacter = ' ';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 1;
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Rat");
	    Red[i].character = 'R';
	    Red[i].subcharacter = ' ';
	    break;
	case 1:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Chat");
	    Blue[i].character = 'C';
	    Blue[i].subcharacter = 't';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0;
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Chat");
	    Red[i].character = 'C';
	    Red[i].subcharacter = 't';
	    break;
	case 2:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Loup");
	    Blue[i].character = 'L';
	    Blue[i].subcharacter = 'p';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0;
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Loup");
	    Red[i].character = 'L';
	    Red[i].subcharacter = 'p';
	    break;
	case 3:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0; // cannot water here ! adapt to rules, NOT DONE
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Chien");
	    Blue[i].character = 'C';
	    Blue[i].subcharacter = 'n';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0; // cannot water here ! adapt to rules, NOT DONE
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Chien");
	    Red[i].character = 'C';
	    Red[i].subcharacter = 'n';
	    break;
	case 4:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Panther");
	    Blue[i].character = 'P';
	    Blue[i].subcharacter = ' ';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0;
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Panther");
	    Red[i].character = 'P';
	    Red[i].subcharacter = ' ';
	    break;
	case 5:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 1;
	    strcpy(Blue[i].name, "Tigre");
	    Blue[i].character = 'T';
	    Blue[i].subcharacter = ' ';
	    break;
	case 6:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 1;
	    strcpy(Blue[i].name, "Lion");
	    Blue[i].character = 'L';
	    Blue[i].subcharacter = 'n';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0;
	    Red[i].canLeep = 1;
	    strcpy(Red[i].name, "Lion");
	    Red[i].character = 'L';
	    Red[i].subcharacter = 'n';
	    break;
	case 7:
	    Blue[i].order = i;
	    Blue[i].inWater = 0;
	    Blue[i].canWater = 0;
	    Blue[i].canLeep = 0;
	    strcpy(Blue[i].name, "Elephant");
	    Blue[i].character = 'E';
	    Blue[i].subcharacter = ' ';

	    Red[i].order = i;
	    Red[i].inWater = 0;
	    Red[i].canWater = 0;
	    Red[i].canLeep = 0;
	    strcpy(Red[i].name, "Elephant");
	    Red[i].character = 'E';
	    Red[i].subcharacter = ' ';
	    break;

	default:
	    printf("error occured in the initialisation of the player pieces");
	    exit(EXIT_FAILURE);
	}
    }
}
void Display()
{
}
void pieceChooser()
{
}
void movePiece()
{
}
void getGameInfo()
{ // NOT DONE
    printf("Blue:\n");
    (Blue[i].color == BLUE) ? printf("blue") : printf("error blue");
    printf("\t Order: %d\n", Blue[i].order);
    printf("\t inwater: %d\n", Blue[i].inWater);
    printf("\t canwater: %d\n", Blue[i].canWater);
    printf("\t canleep: %d\n", Blue[i].canLeep);
    printf("\t name: %s\n", Blue[i].name);
    printf("\t Character: %c\n", Blue[i].character);
    printf("\t subCharacter: %c\n\n", Blue[i].subcharacter);
    printf("Red:\n");
    (Red[i].color == RED) ? printf("red") : printf("error red");
    printf("\t Order: %d\n", Red[i].order);
    printf("\t inwater: %d\n", Red[i].inWater);
    printf("\t canwater: %d\n", Red[i].canWater);
    printf("\t canleep: %d\n", Red[i].canLeep);
    printf("\t name: %s\n", Red[i].name);
    printf("\t Character: %c\n", Red[i].character);
    printf("\t subCharacter: %c\n\n", Red[i].subcharacter);
}