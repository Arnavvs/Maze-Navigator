#include "classes.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// Maze2D constructor
Maze2D::Maze2D(const std::string& filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Maze file not found.");

    std::string line;
    int rowLength = -1;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            if (cell != "0" && cell != "1")
                throw std::runtime_error("Maze contains invalid entries.");
            row.push_back(std::stoi(cell));
        }

        if (rowLength == -1)
            rowLength = row.size();
        else if (row.size() != rowLength)
            throw std::runtime_error("Maze rows have unequal lengths.");

        maze.push_back(row);
    }

    size = maze.size();

    if (maze.empty() || maze[0].empty() || maze[0][0] != 1)
        throw std::runtime_error("Maze must start with 1.");
}

bool Maze2D::isValidCell(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size && maze[x][y] == 1;
}

int Maze2D::getSize() const {
    return size;
}

const std::vector<std::vector<int>>& Maze2D::getMaze() const {
    return maze;
}

// Path1D constructor
Path1D::Path1D(const std::string& filename) {
    std::ifstream file(filename);
    if (!file)
        throw std::runtime_error("Path file not found.");

    std::string line;
    bool dataRead = false;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        if (dataRead)
            throw std::runtime_error("Multiple path data lines found.");

        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            try {
                int val = std::stoi(token);
                if (val < 0 || val > 4)
                    throw std::runtime_error("Path file contains invalid entry.");
                path.push_back(val);
            } catch (...) {
                throw std::runtime_error("Path file contains non-integer entries.");
            }
        }

        dataRead = true;
    }

    bool zeroFound = false;
    for (int p : path) {
        if (p == 0) zeroFound = true;
        if (zeroFound && p != 0)
            throw std::runtime_error("Non-zero found after zero in path.");
    }
}

const std::vector<int>& Path1D::getPath() const {
    return path;
}

// PathTraversal constructor
PathTraversal::PathTraversal(const Maze2D& m, const Path1D& p) : maze(m), path(p) {}

void PathTraversal::traverse() {
    int x = 0, y = 0;
    int size = maze.getSize();

    std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));

    if (!maze.isValidCell(x, y))
        throw std::runtime_error("Start cell is invalid.");

    visited[x][y] = true;

    for (int move : path.getPath()) {
        if (x == size - 1 && y == size - 1) {
            if (move != 0)
                throw std::runtime_error("Path continues after reaching destination.");
            else
                continue;
        }
    

        switch (move) {
            case 1: x -= 1; break; // up
            case 2: y += 1; break; // right
            case 3: x += 1; break; // down
            case 4: y -= 1; break; // left
            case 0: continue;      // no move
            default:
                throw std::runtime_error("Invalid move in path.");
        }

        if (x < 0 || x >= size || y < 0 || y >= size)
            throw std::runtime_error("Path moves out of maze boundaries.");

        if (!maze.isValidCell(x, y))
            throw std::runtime_error("Path visits invalid (0) maze cell.");

        if (visited[x][y])
            throw std::runtime_error("Revisiting cell.");

        visited[x][y] = true;
    }

    if (x != size - 1 || y != size - 1)
        throw std::runtime_error("Path ends before reaching destination.");
}
