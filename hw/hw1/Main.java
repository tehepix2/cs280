import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        // initializing game boards

        int[][] wArray8 = { // 8 x 8 board; SUPER IMPORTANT DO NOT CHANGE THIS
            {2, 3, 4, 4, 4, 4, 3, 2},
            {3, 4, 6, 6, 6, 6, 4, 3},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {3, 4, 6, 6, 6, 6, 4, 3},
            {2, 3, 4, 4, 4, 4, 3, 2}
        };

        int[][] tourArray = new int[8][8];

        //---------------------------------------------------------

        printArray(findTour(wArray8, 0, 0, 1, tourArray));
        
    }

    // finds a knight's tour for a selected coordinate
    // the hard part
    public static int[][] findTour(int[][] board, int x, int y, int tourStep, int[][] tourBoard) {
        board[x][y] = 0;
        board = updateBoard(board);
        if (checkLowestWeight(board, x, y)[2] != 0) {
            tourBoard[x][y] = tourStep;
            
        }
        return tourBoard;

    }

    // returns false if non-zero square is detected, returns true otherwise
    public static boolean isTour(int[][] board) {
        for (int[] i : board) {
            for (int j : i) {
                if (j != 0) {
                    return false;
                }
            }
        }
        return true;
    }
    // updates the weight of each square on the board
    public static int[][] updateBoard(int[][] board) {
        int[][] newBoard = board;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] != 0) {
                    newBoard[i][j] = checkWeight(board, i, j);
                }
            }
        }
        return newBoard;
    }

    // prints a 2D array
    public static void printArray(int[][] array) {
        for (int[] i: array) {
            for (int j:i) {
                System.out.print(j + " ");
            }
            System.out.println();
        } 
    }
    /*
     * Checking order:
     *  O-----------y 
     *  |  2 3
     *  | 1   4
     *  |   X
     *  | 8   5
     *  |  7 6
     *  |
     *  x 
     * 
     * 
     */
    public static int checkWeight(int[][] board, int x, int y) { // done
        int weight = 0;
        // check both top-left corners
        if (!((x - 1 < 0) || (y - 2 < 0))) {
            if (board[x - 1][y - 2] != 0) {
                weight++;
            }
        }

        if (!((x - 2 < 0) || (y - 1 < 0))) {
            if (board[x - 2][y - 1] != 0) {
                weight++;
            }
        }

        // check both top-right corners
        if (!((x - 2 < 0) || (y + 1 > 7))) {
            if (board[x - 2][y + 1] != 0) {
                weight++;
            }
        }

        if (!((x - 1 < 0) || (y + 2 > 7))) {
            if (board[x - 1][y + 2] != 0) {
                weight++;
            }
        }

        // check both bottom-right corners
        if (!((x + 1 > 7) || (y + 2 > 7))) {
            if (board[x + 1][y + 2] != 0) {
                weight++;
            }
        }

        if (!((x + 2 > 7) || (y + 1 > 7))) {
            if (board[x + 2][y + 1] != 0) {
                weight++;
            }
        }

        // check both bottom-left corners
        if (!((x + 2 > 7) || (y - 1 < 0))) {
            if (board[x + 2][y - 1] != 0) {
                weight++;
            }
        }

        if (!((x + 1 > 7) || (y - 2 < 0))) {
            if (board[x + 1][y - 2] != 0) {
                weight++;
            }
        }

        return weight;
    }

    // returns a sorted list (ascending) of coordinates of the lowest weighted squares near the selected coordinates
    public static int[] checkLowestWeight(int[][] board, int x, int y) {

        // if this tracker is 0 after checking, that means no other moves are available
        int smallestTracker = 0;

        int[] smallestCoordinates = new int[3];
        // check both top-left corners
        if (!((x - 1 < 0) || (y - 2 < 0))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x - 1][y - 2];
                smallestCoordinates[0] = x - 1; 
                smallestCoordinates[1] = y - 2; 
            }
            else if (board[x - 1][y - 2] < smallestTracker) {
                smallestTracker = board[x - 1][y - 2];
                smallestCoordinates[0] = x - 1; 
                smallestCoordinates[1] = y - 2; 
            }
        }

        if (!((x - 2 < 0) || (y - 1 < 0))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x - 2][y - 1];
                smallestCoordinates[0] = x - 2; 
                smallestCoordinates[1] = y - 1; 
            }
            else if (board[x - 2][y - 1] < smallestTracker) {
                smallestTracker = board[x - 2][y - 1];
                smallestCoordinates[0] = x - 2; 
                smallestCoordinates[1] = y - 1; 
            }
        }

        // check both top-right corners
        if (!((x - 2 < 0) || (y + 1 > 7))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x - 2][y + 1];
                smallestCoordinates[0] = x - 2; 
                smallestCoordinates[1] = y + 1; 
            }
            else if (board[x - 2][y + 1] < smallestTracker) {
                smallestTracker = board[x - 2][y + 1];
                smallestCoordinates[0] = x - 2; 
                smallestCoordinates[1] = y + 1; 
            }
        }

        if (!((x - 1 < 0) || (y + 2 > 7))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x - 1][y + 2];
                smallestCoordinates[0] = x - 1; 
                smallestCoordinates[1] = y + 2; 
            }
            else if (board[x - 1][y + 2] < smallestTracker) {
                smallestTracker = board[x - 1][y + 2];
                smallestCoordinates[0] = x - 1; 
                smallestCoordinates[1] = y + 2; 
            }
        }

        // check both bottom-right corners
        if (!((x + 1 > 7) || (y + 2 > 7))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x + 1][y + 2];
                smallestCoordinates[0] = x + 1; 
                smallestCoordinates[1] = y + 2; 
            }
            else if (board[x + 1][y + 2] < smallestTracker) {
                smallestTracker = board[x + 1][y + 2];
                smallestCoordinates[0] = x + 1; 
                smallestCoordinates[1] = y + 2; 
            }
        }

        if (!((x + 2 > 7) || (y + 1 > 7))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x + 2][y + 1];
                smallestCoordinates[0] = x + 2; 
                smallestCoordinates[1] = y + 1; 
            }
            else if (board[x + 2][y + 1] < smallestTracker) {
                smallestTracker = board[x + 2][y + 1];
                smallestCoordinates[0] = x + 2; 
                smallestCoordinates[1] = y + 1; 
            }
        }

        // check both bottom-left corners
        if (!((x + 2 > 7) || (y - 1 < 0))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x + 2][y - 1];
                smallestCoordinates[0] = x + 2; 
                smallestCoordinates[1] = y - 1; 
            }
            else if (board[x + 2][y - 1] < smallestTracker) {
                smallestTracker = board[x + 2][y - 1];
                smallestCoordinates[0] = x + 2; 
                smallestCoordinates[1] = y - 1; 
            }
        }

        if (!((x + 1 > 7) || (y - 2 < 0))) {
            if (smallestTracker == 0) {
                smallestTracker = board[x + 1][y - 2];
                smallestCoordinates[0] = x + 1; 
                smallestCoordinates[1] = y - 2; 
            }
            else if (board[x + 1][y - 2] < smallestTracker) {
                smallestTracker = board[x + 1][y - 2];
                smallestCoordinates[0] = x + 1; 
                smallestCoordinates[1] = y - 2; 
            }
        }
        // if index 8 of smallestCoordinates is 0, that means no move is available
        smallestCoordinates[2] = smallestTracker;
        return smallestCoordinates;
    }
}

