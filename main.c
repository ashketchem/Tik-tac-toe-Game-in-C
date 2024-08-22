#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int row, int col, char player);

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char player = 'X';
    int gameOver = 0;

    initializeBoard(board);

    while (!gameOver) {
        
        printBoard(board);
        printf("Player %c, enter your move row and column ( 0-2 and use space to separate): ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            printf("Invalid input!, please try again \n");
            continue;
        }

        makeMove(board, row, col, player);
        if (checkWin(board)) {
            printf("Player %c wins!\n", player);
            gameOver = 1;
        } else if (checkDraw(board)) {
            printf("It's a draw!\n");
            gameOver = 1;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    int i, j;
    printf("\n");

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
            printf("\n");
            if (i < SIZE - 1) {
                printf("---|---|---\n");
            }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE]) {
    int i;

    for(i = 0; i < SIZE; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')) {
            return 1;
        }
    }
    
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1; 
    }
    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    board[row][col] = player;
}