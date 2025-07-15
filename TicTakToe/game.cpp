#include "vector"

using namespace std;

class player{
    string name;
    char symbol;

    player(const string& pname, const char& psymbol) : name(pname), symbol(psymbol){}

    char getSymbol() const{
        return symbol;
    }
    string getName() const{
        return name;
    }
};

class cell{
    int x;
    int y;
    char value;

    public:
        cell(int px, int py) : x(px), y(py), value(' '){}

        void setValue(char pvalue){
            value = pvalue;
        }
        char getValue(){
            return value;
        }

        bool isEmpty(){
            return value == ' ';
        }
}

class Board{

    int size;
    vector<vector<cell>> grid;

    public:
        Board(int psize) : size(psize){
            for(int i=0; i<psize; i++){
                for(int j=0; j<psize; j++){
                    grid[i][j] = cell(i,j);
                }
            }
        }

        MarkCell(int row, int col, char symbol){
            if(grid[i][j].isEmpty()){
                grid[row][col].setValue(symbol);
                return true;
            }
            return false;
        }

        bool isFull() const{
            for(auto& row : grid){
                for(auto& cell : row)
                    if(cell.isEmpty()){
                        return false;
                    }
                return true;
            }
        }

        const vector<vector<cell>& getGrid() const{
            return grid;
        }
};

class GameRules{
    isWinningMove(Board& objm, char symbol){

        const auto& grid = objm.getGrid();

        int size = grid.size();

        for(int i=0; i<size; i++){
            int colWin = true, int rowWin = true;
            for(int j=0; j<size; j++){

                if(grid[i][j].getValue() != symbol){
                    rowWin = false;
                }
                if(grid[j][i].getValue() != symbol){
                    rowWin = false;
                }
                if(rowWin || colWin) return true;
            }
        }

        bool mainDiag = true, antiDiag = true; 
        for (int i = 0; i < size; ++i) { 
            if (grid[i][i].getValue() != symbol) 
                mainDiag = false; 
            if (grid[i][size - 1 - i].getValue() != symbol) 
                ntiDiag = false; 
        } 
        return mainDiag || antiDiag;
    }
}

class Game{
    Player p1, p2;
    Player* currentPlayer;

    Board board;
    GameRules rules;

    public:
        Game(const Player& a, const Player& b, int boardSize) : p1(a), p2(b), board(boardSize)
        {
            currentPlayer(&p1);
        }

        void switchTurn(){
            currentPlayer = (currentPlayer == &p1) ? &p2 : &p1;
        }

        void play()
        {
            int row, col;

            while(true){
                std::cout << currentPlayer->getName() << " (" <<
                currentPlayer->getSymbol() << "), enter row and col: "; 
                std::cin >> row >> col;

                if (!board.markCell(row, col, currentPlayer->getSymbol())) { 
                    std::cout << "Invalid move. Try again.\n"; 
                    continue; 
                }

                if (rules.isWinningMove(board, currentPlayer->getSymbol())) {
                    std::cout << currentPlayer->getName() << " 
                    wins!\n"; 
                    break; 
                }

                if (board.isFull()) { 
                    std::cout << "It's a draw!\n"; 
                    break; 
                } 
                switchTurn(); 
            }
        }
}

int main()
{
    Game obj;
    obj.play();
}