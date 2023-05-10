#include <iostream>

class TicTacToe {
	
private:
    char board[3][3];  
    int currentPlayer; 

public:
    TicTacToe() {
        currentPlayer = 1; 
        initializeBoard();
        std::cout << "-- Tic Tac Toe --CSIE&CGU" << std::endl;
        std::cout << "Player 1 (X) - Player 2 (O)" << std::endl;
    }

    void initializeBoard() {
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        std::cout << "■■■■■■■■■■■■■" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "█ ";
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j] << " █ ";
            }
            std::cout << std::endl << "■■■■■■■■■■■■■" << std::endl;
        }
    }

    bool isBoardFull() {
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidMove(int position) {
        
        if (position < 1 || position > 9) {
            return false;
        }
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        if (board[row][col] != ' ') {
            return false;
        }
        return true;
    }

    void makeMove(int position) {
        
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;
        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
    }

    bool hasWon() {
        
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
                return true;
            }
        }
      
        for (int j = 0; j < 3; j++) {
            if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
                return true;
            }
        }
        
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return true;
        }
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    void run() {
        int position;
        while (true) {
            printBoard();
            std::cout << "Player " << currentPlayer << ", 請輸入『1-9』的數字: ";
            std::cin >> position;

            if (isValidMove(position)) {
                makeMove(position);
                if (hasWon()) {
                    printBoard();
                    std::cout << "==>Player " << currentPlayer << " wins" << std::endl;
                    break;
                } else if (isBoardFull()) {
                    printBoard();
                    std::cout << "==>Game draw " << std::endl;
                    break;
                } else {
                    switchPlayer();
                }
            } else {
                std::cout << "輸入重複" << std::endl;
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
