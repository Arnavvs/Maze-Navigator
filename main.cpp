#include <iostream>
#include <algorithm> 
#include<string>
#include<fstream> //for file operations;
#include <vector>
#include <sstream> //extract numbers or words from a string(treat a string like a stream);
using namespace std;
int main() {   
    string filePath1;//Maze2D fle path
    vector<vector<int>> maze; //2d vector to store maze content
    string filePath2;//Path1D file path
    vector<int> path;//Store path1D content
    
    cout << "Enter the path for Maze2D file";
    cin >> ws;//skip leading whitespaces;
    getline(cin,filePath1);//read the file path     
    //filePath1.erase(remove(filePath1.begin(), filePath1.end(), '"'), filePath1.end());
   
    cout << "Enter the path for Path1D file";
    cin >> ws;
    getline(cin,filePath2);
    //filePath2.erase(remove(filePath2.begin(), filePath2.end(), '"'), filePath2.end());
   
    cout << filePath1;

    if(filePath1==filePath2){
        cout << "File Path cant be the same";
        return 1;
    }

    //Reading Maze2D file
    try {
        ifstream file(filePath1);
        if (!file) {
            throw runtime_error("Wrong Path or format for Maze2D file");
        }// open filePath1 and check if the path is valid

        string line;
        while (getline(file, line)) { //Read file line by line
            replace(line.begin(), line.end(), ',', ' ');
            vector<int> row;// Temporary vector to store each row of the maze
            stringstream ss(line);// Convert line into a stream for extracting numbers
            int value;
            while (ss >> value) {//extract integers from the line
                row.push_back(value);//store them in the row vector
            }
            maze.push_back(row);//Add the row to the 2D maze vector
        }
        file.close();
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }//catch any runtime errors

    //Reading Path1D file
    try {
        ifstream file(filePath2);
        if (!file) {
            throw runtime_error("Wrong Path or format for Path1D file");
        }//open filePath2 and check if the path is valid

        string line;
    if (getline(file, line)) { //Read the entire line (only one line in Path1D file)
        replace(line.begin(), line.end(), ',', ' ');
        stringstream ss(line); //Convert line into a stream
        int value;
        while (ss >> value) { //Extract numbers
            path.push_back(value); //Store in the path vector
        }
    }
    file.close();
} 
catch (const exception& e) {
    cerr << e.what() << endl;
    return 1;
}
    

cout << "\nMaze Data:\n";
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
   
 // Displaying Path1D
 cout << "\nPath Data:\n";
 for (int step : path) {
     cout << step << " ";
 }
 cout << endl;    
   

    return 0;
}
