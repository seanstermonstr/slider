#include "puzzle.h"

puzzle::puzzle(){

    srand(time(NULL));  //seed for random number generation

    //prepares the grid vector
    GRID_SIZE = defaultSize;
    grid.resize(GRID_SIZE);
    for(int i = 0; i < GRID_SIZE; i++)
        grid[i].resize(GRID_SIZE);

    //prepares SOLUTION_VECTOR and 
    //sets iCoord and jCoord to the
    //location of 0
    initSolutionVector();
    setCoords();
}

//generates the solution vector
void puzzle::initSolutionVector(){

    vector<int> temp;   //to store values 1-n
    //prepares SOLUTION_VECTOR
    SOLUTION_VECTOR.resize(GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++)
        SOLUTION_VECTOR[i].resize(GRID_SIZE);

    //stores values 1-n
    temp.resize(GRID_SIZE * GRID_SIZE);
    for (int i = 0; i < temp.size(); i++)
        temp[i] = i+1;

    //stores values 1-n into SOLUTION_VECTOR
    for (int i = 0, k = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++, k++)
            SOLUTION_VECTOR[i][j] = temp[k];
    SOLUTION_VECTOR[GRID_SIZE-1][GRID_SIZE-1] = 0;
}

void puzzle::setCoords(){

    //finds the location of element 0
    //sets iCoord and jCoord to that location
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            if (grid[i][j] == 0){
                iCoord = i;
                jCoord = j;
            }
}

//Function allows user to specify n when n is GRID_SIZE
void puzzle::reInit(char input){

    cout<<"Please enter an n greater than 2.\n";
    cin>>GRID_SIZE;

    //basic input checking
    while (!(GRID_SIZE > 2)){
        cout<<"Invalid input.\n"
            <<"Please enter an n greater than 2.\n";
        cin>>GRID_SIZE;
    }
    
    //resizes the grid to what is needed
    grid.resize(GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++)
        grid[i].resize(GRID_SIZE);

    //determines what randomizing function to call.
    if (input == 'b' || input =='B')
        initGrid();
    else if (input == 'd' || input == 'D')
        initSoluble();
}

//Prints the grid
void puzzle::print(){

    for (int i = 0; i < GRID_SIZE; i++){
        for (int j = 0; j < GRID_SIZE; j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }
}

//Handles basic char input for several functions
char puzzle::getInput(){
   char input;
   cin>> input;
   return input;
}

//function that handles gameplay
bool puzzle::playGame(){
    char input;
    error = true;
    while(true){
        print(); //prints the updated grid
        input = getInput();

        switch (input){
        case 'w':
        case 'W':
            up();
            break;
        case 's':
        case 'S':
            down();
            break;
        case 'a':
        case 'A':
            left();
            break;
        case 'd':
        case 'D':
            right();
            break;
        case 'q':
        case 'Q':
            //reinits GRID_SIZE to default
            GRID_SIZE = defaultSize;
            return false;
            break;
        case 'h':
        case 'H':
            help();
            break;
        default:
            cout<<"Invalid input, please try again.\n";
        }
        if (isSolved()){
            //reinits GRID_SIZE to default
            GRID_SIZE = defaultSize;
            return true;
        }
    }
}

//The code that handles moving the zero up
void puzzle::up(){
    
    int temp;
    if (iCoord - 1 < 0){
        if(error)
            cout<<"Can't move there.\n";
        return;
    }
    else {
        temp = grid[iCoord][jCoord];
        grid[iCoord][jCoord] = grid[iCoord-1][jCoord];
        grid[iCoord-1][jCoord] = temp;
        iCoord -= 1;
    }
}

//The code that handles moving the zero down
void puzzle::down(){
    
    int temp;
    if (iCoord + 1 > GRID_SIZE -1){
        if (error)
            cout<<"Can't move there.\n";
        return;
    }
    else {
        temp = grid[iCoord][jCoord];
        grid[iCoord][jCoord] = grid[iCoord+1][jCoord];
        grid[iCoord+1][jCoord] = temp;
        iCoord += 1;
    }
}

//The code that handles moving the zero to the left
void puzzle::left(){
    
    int temp;
    if (jCoord - 1 < 0){
        if (error)
            cout<<"Can't move there.\n";
        return;
    }
    else {
        temp = grid[iCoord][jCoord];
        grid[iCoord][jCoord] = grid[iCoord][jCoord-1];
        grid[iCoord][jCoord-1] = temp;
        jCoord -= 1;
    }
}

//The code that handles moving the zero to the right
void puzzle::right(){
    
    int temp;
    if (jCoord + 1 > GRID_SIZE -1){
        if (error)
            cout<<"Can't move there.\n";
        return;
    }
    else {
        temp = grid[iCoord][jCoord];
        grid[iCoord][jCoord] = grid[iCoord][jCoord+1];
        grid[iCoord][jCoord+1] = temp;
        jCoord += 1;
    }
}

//checks if the puzzle is solved
bool puzzle::isSolved(){
    
    //if grid matches SOLUTION_VECTOR
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++) 
            if (grid[i][j] == SOLUTION_VECTOR[i][j]){}
            else return false;
    
    print();
    return true;
}

//randomizes the vector of vectors to the square of GRID_SIZE
void puzzle::initGrid(){
    
    //inits num as square of GRID_SIZE
    int num = GRID_SIZE * GRID_SIZE;

    vector<int> temp, temp1;    //temp vectors for storing randomized list
    int val;    // a temp int value.

    // resizes temp to size and saves integers 0-9
    temp.resize(num);
    for (int i = 0; i < temp.size(); i++)
        temp[i] = i;

    // pushes back a random sequence of numbers on to 
    // the second vector from the first vector
    // shrinks the first vector each iteration.
    while (temp.size() != 0){
        val = rand() % temp.size();
        temp1.push_back(temp[val]);
        temp.erase(temp.begin() + val);
    }
    
    // puts the random vector into the vector of vectors
    for (int i = 0, k = 0; i < GRID_SIZE; i++)
        for ( int j = 0; j < GRID_SIZE; j++, k++ )
            grid[i][j] = temp1[k];

    //sets the iCoord and jCoord values to 
    //where the 0 is located
    setCoords();
}

//generates a solvable soluton by calling a random
//movement function
void puzzle::initSoluble(){
   
    //prevents the printing of error
    //messages when the movement functions
    //are called
    error = false;
    //sets val to do an amount of 
    //swaps based on GRID_SIZE
    int val, swaps = GRID_SIZE * 1000;
    //inits grid to a solved solution

    initSolutionVector();
    for (int i = 0; i < GRID_SIZE; i++)
        for (int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = SOLUTION_VECTOR[i][j];
   
    setCoords();
    //does random swaps
    for(int i = 0; i < swaps; i++){
        val = rand() % 4;
        switch(val){
        case 1:
            up();
            break;
        case 2:
            down();
            break;
        case 3:
            left();
            break;
        case 0:
            right();
            break;
        }
    }
}



//Prints a basic help dialogue. 
void puzzle::help(){
    
    cout<<endl<<endl;
    cout<<"After entering a game, use keys WASD to move the '0' around the grid.\n One should attempt to reorder the numbers in sequential order, ending in 0.\n While playing, the user may enter the input 'q' to exit back to the main menu, and 'q' again to exit the game entirely.\n";
    cout<<endl<<endl;
    cout<<"When choosing a game in the main menu, one has the option of choosing a game that is randomly generated in one of two ways. The main difference is that one game has the possibility of generating an impossible puzzle, though the randomization is better. The other will always generate a solvable version, though often times the puzzles generated seem more trivial.  The choices are clearly labeled in the main menu.\n";
    cout<<endl<<endl;
}
