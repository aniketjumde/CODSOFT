#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
protected:
    string symbol;

public:
    Player(const string& sym) : symbol(sym) {}

    const string& getSymbol() const {
        return symbol;
    }

    virtual void makeMove(vector<vector<string>>& board) = 0;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const string& sym) : Player(sym) {}

    void makeMove(vector<vector<string>>& board) override {
        int row, col;
        cout << "Enter row and column for symbol " << symbol << " (e.g., 1 2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != " ") {
            cout << "Invalid move! Try again." << endl;
            makeMove(board); // Recursive call to retry move
            return;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = symbol;
    }
};

class Game {
private:
    vector<vector<string>> board;
    Player* currentPlayer;
    HumanPlayer player1;
    HumanPlayer player2;
    bool gameOver;

public:
    Game() : board(3, vector<string>(3, " ")), player1("X"), player2("O"), gameOver(false) {
        currentPlayer = &player1; // Player 1 starts first
    }

    void displayBoard() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    bool checkWin(const string& playerSymbol) const {
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
                return true;
            if (board[0][i] == playerSymbol && board[1][i] == playerSymbol && board[2][i] == playerSymbol)
                return true;
        }
        // Check diagonals
        if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
            return true;
        if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
            return true;
        return false;
    }

    bool checkDraw() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell != "X" && cell != "O")
                    return false; // If any cell is empty, game is not a draw
            }
        }
        return true; // All cells are filled, game is a draw
    }

    void play() {
        while (!gameOver) {
            cout << "Current Board:" << endl;
            displayBoard();

            currentPlayer->makeMove(board);

            // Check for win or draw
            if (checkWin(currentPlayer->getSymbol())) {
                cout << "Player " << currentPlayer->getSymbol() << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                cout << "It's a draw!" << endl;
                gameOver = true;
            }

            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }

        cout << "Final Board:" << endl;
        displayBoard();
        cout << "Game over." << endl;
    }
};

int main() {
    Game game;
    game.play();

    return 0;
}
