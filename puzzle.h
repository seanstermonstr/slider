#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class puzzle {
public:
    puzzle();
    void reInit(char input);    //reinits the object
    void print();               //Prints the grid
    void help();                //some basic help instructions
    void initGrid();            //generates a random grid
    void initSoluble();         //generates a solved puzzle and shuffles it
    void initSolutionVector();  //prepares the solution vector
    char getInput();            //gets char input for playing the game
    bool playGame();            //game loop
    bool isSolved();            //checks if the game is solved against solution vector

private:
    void up();                  //moves the 0 slot up one
    void down();                //moves the 0 slot down one
    void left();                //moves the 0 slot left one
    void right();               //moves the 0 slot right one
    void setCoords();           //sets the iCoord and jCoord values

    std::vector< std::vector<int> > grid;             //grid for the game
    std::vector< std::vector<int> > SOLUTION_VECTOR;  //contains the solution
    int GRID_SIZE;                          //size of the grid
    int iCoord, jCoord;                     //store where 0 is on the grid
    const static int defaultSize = 3;       //default used by constructor etc
    bool error;                             //used to avoid error messages when initSoluble is called
};
