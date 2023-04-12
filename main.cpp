#include<iostream>

using namespace std;

char board[3][3];

void init() {
    for(int row=0;row<3;row++) {
        for(int col=0;col<3;col++) {
            board[row][col] = ' ';
        }
    }
}

bool checkWinner(char player) {
    // for row
    for(int row=0;row<3;row++) {
        if(board[row][0]==player && board[row][1]==player && board[row][2]==player) {
            return true;
        }
    }

    // for column
    for(int col=0;col<3;col++) {
        if(board[0][col]==player && board[1][col]==player && board[2][col]==player) {
            return true;
        }
    }

    // for diagonals
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) {
        return true;
    }

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) {
        return true;
    }

    return false;
}

bool isBoardFilled() {
    for(int row=0;row<3;row++) {
        for(int col=0;col<3;col++) {
            if(board[row][col] == ' ') {
                return false;
            }
        }
    }

    return true;
}

void display() {
    for(int row=0;row<3;row++) {
        cout<<"|";
        for(int col=0;col<3;col++) {
            cout<<board[row][col]<<"|";
        }
        cout<<endl;
    }
}


int main() {

    init();
    int row , col;
    bool gameOver = false;
    char current_player = 'X';

    while(!gameOver) {
        display();
        cout<<"Player "<<current_player<<" enter : ";
        cin>>row>>col;

        if(board[row][col]==' ') {
            board[row][col]=current_player;
            gameOver = checkWinner(current_player);

            if(gameOver) {
                display();
                cout<<"\nPlayer "<<current_player<<" has won"<<endl;
            }
            else {
                current_player = (current_player=='X') ? 'O' : 'X';
            }

            if(isBoardFilled()) {
                cout<<"\nThis match is a draw"<<endl;
                gameOver = true;
            }
        }
        else {
            cout<<"Invalid move . Try again"<<endl;
        }
    }

    return 0;
}