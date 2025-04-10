/*
#include "classes.h"
#include <iostream>

int main() {
    try {
        // Load maze and path from the specified files
        Maze2D maze("C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test05_NonzerosInPathAfter0\\Maze2D.txt");
        Path1D path("C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test05_NonzerosInPathAfter0\\Path1D.txt");

        // Print the maze
        std::cout << "Maze:\n";
        const auto& mazeGrid = maze.getMaze();
        for (const auto& row : mazeGrid) {
            for (int cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << std::endl;
        }

        // Print the path
        std::cout << "\nPath:\n";
        const auto& pathData = path.getPath();
        for (int step : pathData) {
            std::cout << step << ' ';
        }
        std::cout << std::endl;

        // Uncomment to test traversal
         PathTraversal traversal(maze, path);
         traversal.traverse();
         std::cout << "Path is valid and successful!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
*/

//------------------------------------------------code2------------------------------------------------

#include "classes.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // List of (maze_file, path_file) test cases
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test00_FilesDontExistOrWrongFormat\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test00_FilesDontExistOrWrongFormat\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test01_NormalCase_GOOD\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test01_NormalCase_GOOD\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test02_RevisitingCell\\Maze2D.txt","C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test02_RevisitingCell\\Path1D.txt" },
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test05_NonzerosInPathAfter0\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test05_NonzerosInPathAfter0\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test06_InvalidContentsInMazeFile_OtherThan0or1\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test06_InvalidContentsInMazeFile_OtherThan0or1\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test07_InvalidContentsInMazeFile_TopLeftIs0\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test07_InvalidContentsInMazeFile_TopLeftIs0\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test08_InvalidContentsInPathFile\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test08_InvalidContentsInPathFile\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test09_InvalidPathTerminatingElsewhere\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test09_InvalidPathTerminatingElsewhere\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test10_InvalidPathHavingMoreNonZeroEntriesEvenAfterReachingEndofMaze\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test10_InvalidPathHavingMoreNonZeroEntriesEvenAfterReachingEndofMaze\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test11_InvalidPathVisitingAnInvalidCell\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test11_InvalidPathVisitingAnInvalidCell\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test12_NonsquareMaze\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test12_NonsquareMaze\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test13_NonsquareMaze\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test13_NonsquareMaze\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test14_MultiplePathsInPathFile\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test14_MultiplePathsInPathFile\\Path1D.txt"},
        {"C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test15_TraversesBeyondTheMazeBoundaries\\Maze2D.txt", "C:\\Users\\HP\\OneDrive\\Desktop\\OOPs_final_project\\Test15_TraversesBeyondTheMazeBoundaries\\Path1D.txt"}
        // Add more as needed
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        const auto& [mazeFile, pathFile] = testCases[i];
        std::cout << "Test Case " << i + 1 << ":\n";
        std::cout << "Maze: " << mazeFile << ", Path: " << pathFile << "\n";

        try {
            Maze2D maze(mazeFile);
            Path1D path(pathFile);
            PathTraversal traversal(maze, path);
            traversal.traverse();
            std::cout << "✅ Valid Path\n";
        } catch (const std::runtime_error& e) {
            std::cout << "❌ Error: " << e.what() << "\n";
        }

        std::cout << "-----------------------------\n";
    }

    return 0;
}
