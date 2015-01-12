#include "debug.h"

void printBoard(long *board) {
	char i;
	char j;

	for ( i = 0; i < 25 - TETRIS_BOARD_HEIGHT + HEAD; i++ ) {
		printf("\n");
	}

	for ( i = TETRIS_BOARD_HEIGHT - HEAD; i > 0 ; i-- ) {

		for ( j = TETRIS_BOARD_WIDTH; j > 0 ; j-- ) {
			short level = ( board[i - 1] & 1<<(j-1) ) != 0 ? 1 : 0;
			printf("%d ", level);
		}
		printf("\n");
	}
}

int main() {
	long board[TETRIS_BOARD_HEIGHT];
	long boardDisplay[TETRIS_BOARD_HEIGHT];
	tetermino_t tetermino;

	memset(board, 0, sizeof(long) * TETRIS_BOARD_HEIGHT);

	createTetermino(&tetermino, z ); //rand() % 7);
	tetermino.pos=up;
	createTeterminoData(&tetermino);

	while(1) {
		calculateDisplayBoard(boardDisplay, board, &tetermino);
		printBoard(boardDisplay);
		
		
		if ( isCollision (board, &tetermino) ) {
			memcpy ( board, boardDisplay, sizeof(long) * TETRIS_BOARD_HEIGHT);
			createTetermino(&tetermino, j); // rand() % 7);
			if ( isCollision(board, &tetermino) ) {
				break;
			}
		} else {
			moveTetermino(&tetermino);
		}	
		usleep(500 * 1000);
	} 
	return 0;
}