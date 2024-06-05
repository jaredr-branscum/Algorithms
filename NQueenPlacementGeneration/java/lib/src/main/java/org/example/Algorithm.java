/*
 * Source file for Algorithms
 * Author: Jared Branscum
 */
package org.example;

import java.util.ArrayList;
import java.util.List;

import org.apache.commons.math3.util.CombinatoricsUtils;

public class Algorithm {

    /**
     * Gradle default library method
     * @return - true
     */
    public boolean returnTrue() {
        return true;
    }

    /**
     * Returns number of all possible placements of N objects in NxN board
     * Objects cannot be placed in same cell on the board
     * @param n - size of N x N board and N objects to be uniquely placed
     * @return - number of unique placements of N objects on N x N board
     */
    public static long countPlacements(int n) {

        int[][] board = new int[n][n];
        return generatePlacements(board, 0, 0, n, n);
    }

    /**
     * Returns number of all possible placements of N objects in NxN board
     * Objects cannot be placed in same cell on the board
     * Efficiently returns combinatoric answer of all possible placements
     * @param n - size of N x N board and N objects to be uniquely placed
     * @return - number of unique placements of N objects on N x N board
     */
    public static long fastCountPlacements(int n) {
        return CombinatoricsUtils.binomialCoefficient(n*n, n);
    }

    /**
     * Returns array of all possible placements of N objects on N x N board
     * @param n - size of N x N board and N objects to be uniquely placed
     * @return - array of all possible unique placements of N objects on N x N board
     */
    public static List<int[][]> generatePlacements(int n) {
        List<int[][]> result = new ArrayList<>();
        int[][] board = new int[n][n];
        generatePlacements(board, 0, 0, n, n, result);
        return result;
    }

    private static long generatePlacements(int[][] board, int row, int col, int n, int objectsToPlace) {
        if (objectsToPlace == 0) {
            return 1;
        }
        if (row >= n) {
            return 0;
        }

        long count = 0;

        // Place an object at the current cell
        board[row][col] = 1;
        if (col == n - 1) {
            count += generatePlacements(board, row + 1, 0, n, objectsToPlace - 1);
        } else {
            count += generatePlacements(board, row, col + 1, n, objectsToPlace - 1);
        }
        board[row][col] = 0; // Backtrack

        // Try not placing an object at the current cell
        if (col == n - 1) {
            count += generatePlacements(board, row + 1, 0, n, objectsToPlace);
        } else {
            count += generatePlacements(board, row, col + 1, n, objectsToPlace);
        }
        return count;
    }

    private static void generatePlacements(int[][] board, int row, int col, int n, int objectsToPlace, List<int[][]> result) {
        if (objectsToPlace == 0) {
            result.add(copyBoard(board));
            return;
        }
        if (row >= n) {
            return;
        }

        // Place an object at the current cell
        board[row][col] = 1;
        if (col == n - 1) {
            generatePlacements(board, row + 1, 0, n, objectsToPlace - 1, result);
        } else {
            generatePlacements(board, row, col + 1, n, objectsToPlace - 1, result);
        }
        board[row][col] = 0; // Backtrack

        // Try not placing an object at the current cell
        if (col == n - 1) {
            generatePlacements(board, row + 1, 0, n, objectsToPlace, result);
        } else {
            generatePlacements(board, row, col + 1, n, objectsToPlace, result);
        }
    }

    private static int[][] copyBoard(int[][] board) {
        int[][] copy = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            System.arraycopy(board[i], 0, copy[i], 0, board[0].length);
        }
        return copy;
    }
}
