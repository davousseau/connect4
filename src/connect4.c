/**
 * @file connect4.c
 * @brief Source code and game logic.
 * @author David Brousseau
 * @version 0.1
 * @date Janvier 2021
 */
#include <stdio.h>
#include <stdlib.h>

// Globals variables
int full;        /**< Column is full indicator */
char grid[6][7]; /**< Game board */
char player;     /**< Player indicator */
int turn;        /**< Turn count */

// Function declarations
void checkColumns();
void checkDiagonals();
void checkLines();
int requestColumn();
int validateColumn(int ascii);

/** @brief Alternate players and increase the number of turns. */
void alternatePlayers() {
    turn++;
    switch (player) {
    case 'X': player = 'O'; break;
    case 'O': player = 'X'; break;
    }
}

/** @brief Analyse the game. */
void analyzeGame() {
    if (turn == 41) {
        printf("It's a draw...\n");
        exit(0);
    }
    checkColumns();
    checkDiagonals();
    checkLines();
}

/**
 * @brief Check column for a winning streak.
 * @param i Initial row
 * @param j Fixed column
 */
void checkColumn(int i, int j) {
    if (grid[i][j] == player) {
        if (grid[i + 1][j] == player) {
            if (grid[i + 2][j] == player) {
                if (grid[i + 3][j] == player) {
                    printf("Player %c wins!\n", player);
                    exit(0);
                }
            }
        }
    }
}

/** @brief Check all columns for a winning streak. */
void checkColumns() {
    int i, j;
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 3; i++) { checkColumn(i, j); }
    }
}

/**
 * @brief Check diagonal left to right for a winning streak.
 * @param i Initial row
 * @param j Initial column
 */
void checkDiagonalLeftRight(int i, int j) {
    if (grid[i][j] == player) {
        if (grid[i + 1][j + 1] == player) {
            if (grid[i + 2][j + 2] == player) {
                if (grid[i + 3][j + 3] == player) {
                    printf("Player %c wins!\n", player);
                    exit(0);
                }
            }
        }
    }
}

/**
 * @brief Check diagonal right to left for a winning streak.
 * @param i Initial row
 * @param j Initial column
 */
void checkDiagonalRightLeft(int i, int j) {
    if (grid[i][j] == player) {
        if (grid[i + 1][j - 1] == player) {
            if (grid[i + 2][j - 2] == player) {
                if (grid[i + 3][j - 3] == player) {
                    printf("Player %c wins!\n", player);
                    exit(0);
                }
            }
        }
    }
}

/** @brief Check all diagonals for a winning streak. */
void checkDiagonals() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) checkDiagonalLeftRight(i, j);
        for (j = 3; j < 7; j++) checkDiagonalRightLeft(i, j);
    }
}

/**
 * @brief Check line for a winning streak.
 * @param i Fixed row
 * @param j Initial column
 */
void checkLine(int i, int j) {
    if (grid[i][j] == player) {
        if (grid[i][j + 1] == player) {
            if (grid[i][j + 2] == player) {
                if (grid[i][j + 3] == player) {
                    printf("Player %c wins!\n", player);
                    exit(0);
                }
            }
        }
    }
}

/** @brief Check all lines for a winning streak. */
void checkLines() {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 4; j++) { checkLine(i, j); }
    }
}

/**
 * @brief Clear the buffer and invalidate multiple entry.
 * @param ascii Character ASCII code
 */
void clearBuffer(int *ascii) {
    if (getchar() != '\n') {
        while (getchar() != '\n') {}
        *ascii = 56;
    }
}

/** @brief Display the grid. */
void displayGrid() {
    int i, j;
    printf("\n  1 2 3 4 5 6 7 \n");
    for (i = 0; i < 6; i++) {
        printf("|");
        for (j = 0; j < 7; j++) { printf(" %c", grid[i][j]); }
        printf(" |\n");
    }
    printf("-----------------\n\n");
}

/** @brief Initialize an empty grid. */
void initializeEmptyGrid() {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) { grid[i][j] = ' '; }
    }
}

/** @brief Initialize the game. */
void initializeGame() {
    initializeEmptyGrid();
    displayGrid();
    player = 'X';
    turn = 0;
}

/**
 * @brief Insert into column j.
 * @param j Column to insert
 */
void insertColumn(int j) {
    full = 0;
    if (grid[5][j] == ' ') {
        grid[5][j] = player;
    } else if (grid[4][j] == ' ') {
        grid[4][j] = player;
    } else if (grid[3][j] == ' ') {
        grid[3][j] = player;
    } else if (grid[2][j] == ' ') {
        grid[2][j] = player;
    } else if (grid[1][j] == ' ') {
        grid[1][j] = player;
    } else if (grid[0][j] == ' ') {
        grid[0][j] = player;
    } else {
        fprintf(stderr, "Error: the column %d is full.\n", j + 1);
        full = 1;
    }
}

/** @brief Pick the column to insert. */
void pickColumnToInsert() {
    int ascii = requestColumn();
    if (ascii == 50) { insertColumn(1); }
    if (ascii == 51) { insertColumn(2); }
    if (ascii == 49) { insertColumn(0); }
    if (ascii == 52) { insertColumn(3); }
    if (ascii == 53) { insertColumn(4); }
    if (ascii == 54) { insertColumn(5); }
    if (ascii == 55) { insertColumn(6); }
}

/** @brief Request the user for the column to insert. */
int requestColumn() {
    int ascii;
    int isValide = 0;
    while (isValide != 1) {
        printf("Player %c action: ", player);
        ascii = getchar();
        clearBuffer(&ascii);
        isValide = validateColumn(ascii);
    }
    printf("\n");
    return ascii;
}

/**
 * @brief Validate the requested column.
 * @param ascii Column ASCII code
 * @return 1 for true, 0 for false
 */
int validateColumn(int ascii) {
    int isValide = 1;
    if (ascii == 48) {
        printf("exit\n");
        exit(0);
    }
    if (ascii < 49 || ascii > 55) {
        fprintf(stderr, "Error: action should be an integer between `1` and `7`.\n");
        isValide = 0;
    }
    return isValide;
}

/** @brief Launch the game. */
int main() {
    initializeGame();
    while (1) {
        pickColumnToInsert();
        displayGrid();
        if (full != 1) {
            analyzeGame();
            alternatePlayers();
        }
    }
}
