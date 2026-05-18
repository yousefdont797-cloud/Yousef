#include <iostream>
using namespace std;
 //struct is used to groups related data together
struct TicTacToe {
    char board[3][3];
};
//we used this function to fill the board with numbers from 1 to 9
void initializeBoard(TicTacToe &game) {
//this 1 is a starting valew
    char num = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
//this function stores the starting valeu and increase it
            game.board[i][j] = num++;
        }
    }
}
//this function display the board on the screen
void displayBoard(TicTacToe game) {
    cout << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
//print each board value
            cout << " " << game.board[i][j] << " ";

            if (j < 2)
                cout << "|";
        }

        cout << endl;

        if (i < 2)
            cout << "---|---|---" << endl;
    }

    cout << endl;
}
//this function check if theres a winner
bool checkWinner(TicTacToe game, char player) {

    for (int i = 0; i < 3; i++) {

        if (game.board[i][0] == player &&
            game.board[i][1] == player &&
            game.board[i][2] == player)
            return true;

        if (game.board[0][i] == player &&
            game.board[1][i] == player &&
            game.board[2][i] == player)
            return true;
    }

    if (game.board[0][0] == player &&
        game.board[1][1] == player &&
        game.board[2][2] == player)
        return true;

    if (game.board[0][2] == player &&
        game.board[1][1] == player &&
        game.board[2][0] == player)
        return true;

    return false;
}
//Places the player's symbol on the board
void makeMove(TicTacToe &game, int choice, char player) {

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
//check if the position is free
    if (game.board[row][col] != 'X' &&
        game.board[row][col] != 'O') {

        game.board[row][col] = player;
    }
    else {
        cout << "Position already taken! Try again.\n";
    }
}

int main() {
//create the board
    TicTacToe game;
//fill the board with numbers
    initializeBoard(game);
//stores the player input
    int choice;
    char player = 'X';
//make the possible moves max
    for (int turn = 0; turn < 9; turn++) {

        displayBoard(game);

        cout << "Player " << player
             << ", enter position (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice!\n";
            turn--;
            continue;
        }
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;
//check the used position
        if (game.board[row][col] == 'X' ||
            game.board[row][col] == 'O') {

            cout << "Position already used!\n";
            turn--;
            continue;
        }

        makeMove(game, choice, player);

        if (checkWinner(game, player)) {
            displayBoard(game);
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    displayBoard(game);
    cout << "It's a draw!\n";

    return 0;
}
