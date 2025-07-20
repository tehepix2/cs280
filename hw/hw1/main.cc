#include <iostream>
#include <array>
#include <vector>

using namespace std;

void printArray(array<array<int, 8>, 8> board) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << board[i][j] << "  ";
            }
            cout << "\n\n";
        }
    }

int checkWeight(array<array<int, 8>, 8> board, int x, int y) { // done
        int weight = 0;
        // check both top-left corners
        if (!((x - 1 < 0) || (y - 2 < 0))) {
            if (board[x - 1][y - 2] != -1) {
                weight++;
            }
        }

        if (!((x - 2 < 0) || (y - 1 < 0))) {
            if (board[x - 2][y - 1] != -1) {
                weight++;
            }
        }

        // check both top-right corners
        if (!((x - 2 < 0) || (y + 1 > 7))) {
            if (board[x - 2][y + 1] != -1) {
                weight++;
            }
        }

        if (!((x - 1 < 0) || (y + 2 > 7))) {
            if (board[x - 1][y + 2] != -1) {
                weight++;
            }
        }

        // check both bottom-right corners
        if (!((x + 1 > 7) || (y + 2 > 7))) {
            if (board[x + 1][y + 2] != -1) {
                weight++;
            }
        }

        if (!((x + 2 > 7) || (y + 1 > 7))) {
            if (board[x + 2][y + 1] != -1) {
                weight++;
            }
        }

        // check both bottom-left corners
        if (!((x + 2 > 7) || (y - 1 < 0))) {
            if (board[x + 2][y - 1] != -1) {
                weight++;
            }
        }

        if (!((x + 1 > 7) || (y - 2 < 0))) {
            if (board[x + 1][y - 2] != -1) {
                weight++;
            }
        }

        return weight;
    }

array<int, 2> findLowestWeight(array<array<int, 8>, 8> board, int x, int y) {

        // if this tracker is 0 after checking, that means no other moves are available
        int smallestTracker = 0;
        bool foundLowest = false;
        array<int, 2> smallestCoordinates;
        // check both top-left corners
        if (!((x - 1 < 0) || (y - 2 < 0))) {
            if (smallestTracker == 0) {
                if (board[x - 1][y - 2] != -1) {
                    smallestTracker = board[x - 1][y - 2];
                    smallestCoordinates[0] = x - 1; 
                    smallestCoordinates[1] = y - 2; 
                    foundLowest = true;
                }
                
            }
            else if (board[x - 1][y - 2] < smallestTracker) {
                if (board[x - 1][y - 2] != -1) {
                    smallestTracker = board[x - 1][y - 2];
                    smallestCoordinates[0] = x - 1; 
                    smallestCoordinates[1] = y - 2; 
                    foundLowest = true;
                }
                
            }
        }

        if (!((x - 2 < 0) || (y - 1 < 0))) {
            if (smallestTracker == 0) {
                if (board[x - 2][y - 1] != -1) {
                    smallestTracker = board[x - 2][y - 1];
                    smallestCoordinates[0] = x - 2; 
                    smallestCoordinates[1] = y - 1; 
                    foundLowest = true;
                }
                
            }
            else if (board[x - 2][y - 1] < smallestTracker) {
                if (board[x - 2][y - 1] != -1) {
                    smallestTracker = board[x - 2][y - 1];
                    smallestCoordinates[0] = x - 2; 
                    smallestCoordinates[1] = y - 1; 
                    foundLowest = true;
                }
                
            }
        }

        // check both top-right corners
        if (!((x - 2 < 0) || (y + 1 > 7))) {
            if (smallestTracker == 0) {
                if (board[x - 2][y + 1] != -1) {
                    smallestTracker = board[x - 2][y + 1];
                    smallestCoordinates[0] = x - 2; 
                    smallestCoordinates[1] = y + 1; 
                    foundLowest = true;
                }
                
            }
            else if (board[x - 2][y + 1] < smallestTracker) {
                if (board[x - 2][y + 1] != -1) {
                    smallestTracker = board[x - 2][y + 1];
                    smallestCoordinates[0] = x - 2; 
                    smallestCoordinates[1] = y + 1; 
                    foundLowest = true;
                }
                
            }
        }

        if (!((x - 1 < 0) || (y + 2 > 7))) {
            if (smallestTracker == 0) {
                if (board[x - 1][y + 2] != -1) {
                    smallestTracker = board[x - 1][y + 2];
                    smallestCoordinates[0] = x - 1; 
                    smallestCoordinates[1] = y + 2; 
                    foundLowest = true;
                }
                
            }
            else if (board[x - 1][y + 2] < smallestTracker) {
                if (board[x - 1][y + 2] != -1) {
                    smallestTracker = board[x - 1][y + 2];
                    smallestCoordinates[0] = x - 1; 
                    smallestCoordinates[1] = y + 2; 
                    foundLowest = true;
                }
                
            }
        }

        // check both bottom-right corners
        if (!((x + 1 > 7) || (y + 2 > 7))) {
            if (smallestTracker == 0) {
                if (board[x + 1][y + 2] != -1) {
                    smallestTracker = board[x + 1][y + 2];
                    smallestCoordinates[0] = x + 1; 
                    smallestCoordinates[1] = y + 2; 
                    foundLowest = true;
                }
                
            }
            else if (board[x + 1][y + 2] < smallestTracker) {
                if (board[x + 1][y + 2] != -1) {
                    smallestTracker = board[x + 1][y + 2];
                    smallestCoordinates[0] = x + 1; 
                    smallestCoordinates[1] = y + 2; 
                    foundLowest = true;
                }
                
            }
        }

        if (!((x + 2 > 7) || (y + 1 > 7))) {
            if (smallestTracker == 0) {
                if (board[x + 2][y + 1] != -1) {
                    smallestTracker = board[x + 2][y + 1];
                    smallestCoordinates[0] = x + 2; 
                    smallestCoordinates[1] = y + 1; 
                    foundLowest = true;
                }
                
            }
            else if (board[x + 2][y + 1] < smallestTracker) {
                if (board[x + 2][y + 1] != -1) {
                    smallestTracker = board[x + 2][y + 1];
                    smallestCoordinates[0] = x + 2; 
                    smallestCoordinates[1] = y + 1; 
                    foundLowest = true;                
                }

            }
        }

        // check both bottom-left corners
        if (!((x + 2 > 7) || (y - 1 < 0))) {
            if (smallestTracker == 0) {
                if (board[x + 2][y - 1] != -1) {
                    smallestTracker = board[x + 2][y - 1];
                    smallestCoordinates[0] = x + 2; 
                    smallestCoordinates[1] = y - 1; 
                    foundLowest = true;                  
                }

            }
            else if (board[x + 2][y - 1] < smallestTracker) {
                if (board[x + 2][y - 1] != -1) {
                    smallestTracker = board[x + 2][y - 1];
                    smallestCoordinates[0] = x + 2; 
                    smallestCoordinates[1] = y - 1;
                    foundLowest = true;                    
                }
                
            }
        }

        if (!((x + 1 > 7) || (y - 2 < 0))) {
            if (smallestTracker == 0) {
                if (board[x + 1][y - 2] != -1) {
                    smallestTracker = board[x + 1][y - 2];
                    smallestCoordinates[0] = x + 1; 
                    smallestCoordinates[1] = y - 2; 
                    foundLowest = true;
                }

            }
            else if (board[x + 1][y - 2] < smallestTracker) {
                if (board[x + 1][y - 2] != -1) {
                    smallestTracker = board[x + 1][y - 2];
                    smallestCoordinates[0] = x + 1; 
                    smallestCoordinates[1] = y - 2; 
                    foundLowest = true;
                }
                
            }
        }
        if (foundLowest) {
            return smallestCoordinates;
        }
        else {
            return array<int,2> {x, y};
        }
        
    }
array<array <int, 8>, 8> updateBoard(array<array <int, 8>, 8> board) {
        array<array <int, 8>, 8> newBoard = board;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != -1) {
                    newBoard[i][j] = checkWeight(board, i, j);
                }
            }
        }
        return newBoard;
    }

    array<array <int, 8>, 8> findTour(array<array <int, 8>, 8> board, int x, int y, int tourStep, array<array <int, 8>, 8> tourBoard) {
        board[x][y] = -1;
        board = updateBoard(board);
        tourBoard[x][y] = tourStep;

        if (tourStep != 64) {
            return findTour(board, findLowestWeight(board, x, y)[0], findLowestWeight(board, x, y)[1], tourStep + 1, tourBoard);
        }
        else {
            return tourBoard;
        }
    }
int main() {

    array<array<int, 8>, 8> gameBoard {{  
        {2, 3, 4, 4, 4, 4, 3, 2},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {4, 6, 8, 8, 8, 8, 6, 4},
        {3, 4, 6, 6, 6, 6, 4, 3},
        {2, 3, 4, 4, 4, 4, 3, 2}
    }};

    array<array<int, 8>, 8> moveBoard {{  
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    }};
    // ---------------------
    
    cout << "Knight's tour starting from the top-left corner of the board: " << "\n";
    
    printArray(findTour(gameBoard, 0, 0, 1, moveBoard));
    return 0;
}


