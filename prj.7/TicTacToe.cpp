#include <iomanip>
#include <iostream>

using namespace std;

// Global constants for game settings and states
const int ROWS = 3;
const int COLS = 3;
const char PLAYER1_TOKEN = 'X';
const char PLAYER2_TOKEN = 'O';
const char EMPTY = '*';

const int WINNER = 1;
const int SPACE_LEFT = 2;
const int NO_SPACE = 3;

// Function Prototypes
void initializeBoard(char board[ROWS][COLS]);
void displayBoard(char board[ROWS][COLS]);
bool placeToken(char board[ROWS][COLS], int row, int col, char token);
int checkBoard(char board[ROWS][COLS], char token);
int getBoardState(char board[ROWS][COLS], char token);

int main() {
  char board[ROWS][COLS];
  char currentToken = PLAYER1_TOKEN;
  int gameState = SPACE_LEFT;
  int row, col;

  initializeBoard(board);

  cout << "Tic-Tac-Toe Game" << endl;

  // Main game loop
  while (gameState == SPACE_LEFT) {
    displayBoard(board);

    // Turn prompt and input validation for coordinates
    cout << "Player " << (currentToken == PLAYER1_TOKEN ? "1 (X)" : "2 (O)")
         << " turn." << endl;
    cout << "Enter row (1-3) and column (1-3) separated by a space: ";
    cin >> row >> col;

    // placeToken handles validation for range and occupied cells
    if (placeToken(board, row - 1, col - 1, currentToken)) {
      gameState = getBoardState(board, currentToken);

      if (gameState == SPACE_LEFT) {
        // Switch players if game continues
        currentToken =
            (currentToken == PLAYER1_TOKEN ? PLAYER2_TOKEN : PLAYER1_TOKEN);
      }
    } else {
      cout << "Invalid move. Try again." << endl;
    }
  }

  // Final display and result
  displayBoard(board);
  if (gameState == WINNER) {
    cout << "Player " << (currentToken == PLAYER1_TOKEN ? "1 (X)" : "2 (O)")
         << " wins!" << endl;
  } else {
    cout << "It's a tie! No more spaces left." << endl;
  }

  return 0;
}

/**
 * Fills the 3x3 array with the '*' character
 */
void initializeBoard(char board[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = EMPTY;
    }
  }
}

/**
 * Displays row/column headers and the current board state
 */
void displayBoard(char board[ROWS][COLS]) {
  cout << "\n    1 2 3" << endl;
  for (int r = 0; r < ROWS; r++) {
    cout << (r + 1) << " | ";
    for (int c = 0; c < COLS; c++) {
      cout << board[r][c] << " ";
    }
    cout << "|" << endl;
  }
  cout << endl;
}

/**
 * Validates the move and places the token if the cell is empty
 */
bool placeToken(char board[ROWS][COLS], int row, int col, char token) {
  if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
    if (board[row][col] == EMPTY) {
      board[row][col] = token;
      return true;
    }
  }
  return false;
}

/**
 * Checks for wins in rows, columns, and diagonals, or identifies ties
 */
int checkBoard(char board[ROWS][COLS], char token) {
  // Check rows and columns
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == token && board[i][1] == token &&
         board[i][2] == token) ||
        (board[0][i] == token && board[1][i] == token &&
         board[2][i] == token)) {
      return WINNER;
    }
  }

  // Check diagonals
  if ((board[0][0] == token && board[1][1] == token && board[2][2] == token) ||
      (board[0][2] == token && board[1][1] == token && board[2][0] == token)) {
    return WINNER;
  }

  // Check for any remaining empty spaces
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (board[r][c] == EMPTY) return SPACE_LEFT;
    }
  }

  return NO_SPACE;
}

/**
 * Simple wrapper to determine the state based on checkBoard
 */
int getBoardState(char board[ROWS][COLS], char token) {
  return checkBoard(board, token);
}