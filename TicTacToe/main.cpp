#include <iostream>
using namespace std;

char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';

void Draw() {
    system("cls");
    cout << "Tic Tac Toe v1.0" << endl;
    cout << "Player 1 [X] vs Player 2 [O]" << endl;
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Input() {
    int a;
    cout << "It's " << player << "'s turn. Enter a number: ";
    cin >> a;

    if (a == 1) {
        if (matrix[0][0] == '1') {
            matrix[0][0] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 2) {
        if (matrix[0][1] == '2') {
            matrix[0][1] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 3) {
        if (matrix[0][2] == '3') {
            matrix[0][2] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 4) {
        if (matrix[1][0] == '4') {
            matrix[1][0] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 5) {
        if (matrix[1][1] == '5') {
            matrix[1][1] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 6) {
        if (matrix[1][2] == '6') {
            matrix[1][2] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 7) {
        if (matrix[2][0] == '7') {
            matrix[2][0] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 8) {
        if (matrix[2][1] == '8') {
            matrix[2][1] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else if (a == 9) {
        if (matrix[2][2] == '9') {
            matrix[2][2] = player;
        }
        else {
            cout << "Invalid move! Try again." << endl;
            Input();
        }
    }
    else {
        cout << "Invalid move! Try again." << endl;
        Input();
    }
}

void TogglePlayer() {
    if (player == 'X') {
    player = 'O';
    }
    else {
    player = 'X';
    }
}

char CheckWin() {
// Check rows
    for (int i = 0; i < 3; i++) {
    if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) {
    return matrix[i][0];
    }
    }
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) {
            return matrix[0][i];
        }
    }

    // Check diagonals
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) {
        return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
        return matrix[0][2];
    }

    return '/';
}

int main() {
    Draw();
    while (1) {
        Input();
        Draw();
        if (CheckWin() == 'X') {
            cout << "Player 1 [X] wins! Congratulations." << endl;
            break;
        }
        else if (CheckWin() == 'O') {
            cout << "Player 2 [O] wins! Congratulations." << endl;
            break;
        }
        else if (CheckWin() == '/' && matrix[0][0] != '1' && matrix[0][1] != '2' && matrix[0][2] != '3' && matrix[1][0] != '4' && matrix[1][1] != '5' && matrix[1][2] != '6' && matrix[2][0] != '7' && matrix[2][1] != '8' && matrix[2][2] != '9') {
            cout << "It's a draw! No one wins." << endl;
            break;
        }
        TogglePlayer();
}
    system("pause");
    return 0;
}
