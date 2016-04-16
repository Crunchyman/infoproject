#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
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
void playerRandomizer(colorType* player);                                                    // DONE, ralph
void gameinit(playerPieces B[], playerPieces R[], playerPieces* nothing, table tab[][DimC]); // DONE, ralph
void playerChooser(colorType* player);                                                       // DONE, ralph
void pieceInit(playerPieces Blue[], playerPieces Red[]);                                     // DONE, ralph
void movePiece();
//**************************END OF SUBPROGRAMS******************************
int main()
{
    srand(time(NULL));
    colorType player;
    playerPieces Blue[NUMOFPIECES];
    playerPieces Red[NUMOFPIECES];
    playerPieces nothing;
    table tab[DimL][DimC];
    playerRandomizer(&player);
    gameinit(Blue, Red, &nothing, tab);
}

void playerChooser(colorType* player) // done adapt to blue and red
{
    // blue = 1 red =2
    int p;
    if(*player == BLUE)
	p = 1;
    if(*player == RED)
	p = 2;
    p = p % 2 + 1;
    if(p == 1)
	*player = BLUE;
    if(p == 2)
	*player = RED;
}

void playerRandomizer(colorType* player) // done but adapt to blue and red
{

    int p;
    p = (rand() % 2) + 1;
    if(p == 1)
	*player = BLUE;
    if(p == 2)
	*player = RED;
}

void checkMoves(table tab[][DimC], int lign, int col)
{
    int answer;
    table currentPiece = tab[lign - 1][col - 1];
    table nextPiece;
    do {
	printf("Where would you like to move ?\n 1: front \n 2:left\n 3:right");
	scanf("%d", &answer);
    } while(answer < 1 || answer > 3);

    if(currentPiece.Player.color == BLUE) {
	// need to check if water and if he can get into the water
	// same thing for the red so just copy paste
	// BLUE
	// 1 : front  tab[lign][col]
	// 2: left tab[lign-1][col-2]
	// 3: right tab[lign-1][col]
	if(answer == 1) {
	    nextPiece = tab[lign][col - 1];
	    if(nextPiece.State != EMPTY) {
		if(nextPiece.State == WATER && currentPiece.Player.canWater == 1) {
		    movePiece();
		} else if(nextPiece.State == WATER && currentPiece.Player.canLeep == 1) {

		} else if(nextPiece.State == BTRAP) {

		} else if(nextPiece.State == RTRAP) {

		} else if(nextPiece.State == FLAGBLUE) {

		} else if(nextPiece.State == FLAGRED) {
		}
		// check for case of flag, trap, and water
	    } else if(nextPiece.State == EMPTY) {
		movePiece(); // add parameters current piece and next piece and table of course
	    }
	} else if(answer == 2) {
	    if(tab[lign][col - 1])
	} else if(answer == 3) {
	}
    } else if(currentPiece.color == RED) {
	// RED
	// 1: front tab[lign-2][
	// 2:
	// 3:
	if(answer == 1) {
	}
	if(answer == 2) {
	}
	if(answer == 3) {
	}
    } else {
	printf("Error occured while analysing the answer");
	exit(EXIT_FAILURE);
    }
}
void answer(playerPieces Blue[], playerPieces Red[], table tab[][DimC])
{
    int lign, col, sure;
    do {
	sure = 1;
	printf("Which piece would you like to move ? (X,Y)");
	scanf(" %d %d", &lign, &col);
	printf("\n Is this is the piece you would like to move?");
	getinfo();
	// add sure =1 continue sure = 0 redo !!
    } while((lign < 1 || lign > 9) || (col < 1 || col > 7) || (tab[lign][col].Player.order == -1));
    // get piece info
    getinfo();
    // analyse his moves
    checkMoves();
    // move his piece
    movePiece();
}

void gameChecker()
{
}

void Display()
{
}

void movePiece(table currentPiece, table nextPiece)
{ // add table parameter, currentpiece parameter, nextpiece parameter
    // check order in this one
	if(nextPiece.State != EMPTY) {
		if(nextPiece.State == WATER && currentPiece.Player.canWater == 1) {
		    movePiece;
		} else if(nextPiece.State == WATER && currentPiece.Player.canLeep == 1) {

		} else if(nextPiece.State == BTRAP) {

		} else if(nextPiece.State == RTRAP) {

		} else if(nextPiece.State == FLAGBLUE) {

		} else if(nextPiece.State == FLAGRED) {
		}
		// check for case of flag, trap, and water
	    } else if(nextPiece.State == EMPTY) {
		movePiece; // add parameters current piece and next piece and table of course
	    }
}
void movePlace(table currentPiece,table nextPiece,playerPieces nothing){
	nextPiece = currentPiece;
	currentPiece = nothing;
}
void getGameInfo(table tab[][DimC], int lign, int col)
{ // NOT DONE
    char color[DIM_CHAR];
    if(tab[lign][col].Player.order == -1)
	printf("this place is empty");
    else {
	(tab[lign][col].Player.color == BLUE) ? strcpy(color, "Blue") : strcpy(color, "Red");
	printf("\t Order: %d\n", tab[lign][col].Player.order);
	printf("\t inwater: %d\n", tab[lign][col].Player.inWater);
	printf("\t canwater: %d\n", tab[lign][col].Player.canWater);
	printf("\t canleep: %d\n", tab[lign][col].Player.canLeep);
	printf("\t name: %s\n", tab[lign][col].Player.name);
	printf("\t Character: %c\n", tab[lign][col].Player.character);
	printf("\t subCharacter: %c\n\n", tab[lign][col].Player.subcharacter);
    }
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

char* getColor(colorType player)
{
    switch(player) {
    case BLUE:
	return "BLUE";
    case RED:
	return "RED";
    }
    return 0;
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
		    tab[i][j].State = EMPTY;
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

void color(int couleurDuTexte, int couleurDuFond)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond * 16 + couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc�
// 2.Vert fonc�
// 3.Turquoise
// 4.Rouge fonc�
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc�
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc