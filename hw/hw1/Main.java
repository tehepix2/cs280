import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        int[][] wArray5 = { // 5 x 5 board
            {2, 3, 4, 3, 2},
            {3, 6, 6, 6, 3},
            {4, 6, 8, 6, 4},
            {3, 6, 6, 6, 3},
            {2, 3, 4, 3, 2}
        };

        int[][] wArray8 = { // 8 x 8 board; SUPER IMPORTANT DO NOT CHANGE THIS
            {2, 3, 4, 4, 4, 4, 3, 2},
            {3, 4, 0, 6, 6, 6, 4, 3},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {4, 6, 8, 8, 8, 8, 6, 4},
            {3, 4, 6, 6, 6, 6, 4, 3},
            {2, 3, 4, 4, 4, 4, 3, 2}
        };


        int[][] tourMap = { // the tour displayed at the end will be shown by this array
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}
        };
        printArray(wArray8);

        wArray8 = updateBoard(wArray8);
        System.out.println();

        printArray(wArray8);
     
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
}

