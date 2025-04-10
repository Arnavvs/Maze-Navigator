#ifndef CLASSES_H
#define CLASSES_H

#include <vector>
#include <string>

/**
 * @class Maze2D
 * @brief Handles loading and validation of a square maze from a file.
 * 
 * Maze is represented as a 2D grid of 0s and 1s:
 *  - 1: Open path
 *  - 0: Wall or invalid path
 * 
 * It performs checks for file existence, valid entries, and proper structure.
 */
class Maze2D {
private:
    std::vector<std::vector<int>> maze; // 2D representation of maze
    int size; // Dimension of the square maze
public:
    Maze2D(const std::string& filename); // Loads and validates maze from file
    bool isValidCell(int x, int y) const; // Checks if a given cell is traversable
    int getSize() const; // Returns maze size
    const std::vector<std::vector<int>>& getMaze() const; // Returns the full maze grid

};

/**
 * @class Path1D
 * @brief Handles loading and validation of a 1D path from a file.
 * 
 * Path is a sequence of movement directions:
 *  - 1: Up
 *  - 2: Down
 *  - 3: Left
 *  - 4: Right
 *  - 0: No move
 */
class Path1D {
private:
    std::vector<int> path; // Sequence of moves
public:
    Path1D(const std::string& filename); // Loads and validates path from file
    const std::vector<int>& getPath() const; // Returns the path vector
};

/**
 * @class PathTraversal
 * @brief Validates and simulates movement through the maze using the path.
 * 
 * Performs logical checks such as:
 *  - Staying within bounds
 *  - Not revisiting a cell
 *  - Only stepping on '1' cells
 *  - Proper start and end locations
 */
class PathTraversal {
private:
    const Maze2D& maze; // Reference to Maze2D object
    const Path1D& path; // Reference to Path1D object
public:
    PathTraversal(const Maze2D& maze, const Path1D& path); // Constructor
    void traverse(); // Performs the simulation and throws errors if path is invalid
};

#endif
