#include "puzzle.h"


int main(){
    
    char input;
    puzzle game;

    cout<<"Move the '0' around to arrange the numbers from 1-n!\n";
    cout<<"The '0' goes in the last place in the grid.\n";

    while(true){
       
        cout<<"Menu\n";
        cout<<"OPTION A: Play 3x3 game (may produce impossible puzzle)\n";
        cout<<"OPTION B: Play nxn game (may produce impossible puzzle)\n";
        cout<<"OPTION C: Play 3x3 game (A solution exists)\n";
        cout<<"OPTION D: Play nxn game (a solution exists)\n";
        cout<<"OPTION H: Help playing. May be pressed at any time.\n";
        cout<<"OPTION Q: Quit the game.\n";
        cin>> input;

        switch (input){
        case 'a':
        case 'A':
            //Inits the random grid
            game.initGrid();

            if (game.playGame())
                cout<<"Congrats, you won!\n";
            else cout<<"Sorry, you lose.\n";

            break;

        case 'b':
        case 'B':
            //inits the nxn grid
            game.reInit(input);

            if (game.playGame())
                cout<<"Congrats, you won!\n";
            else cout<<"Sorry, you lose.\n";

            break;

        case 'c':
        case 'C':
            
            game.initSoluble();

            if (game.playGame())
                cout<<"Congrats, you won!\n";
            else cout<<"Sorry, you lose.\n";

            break;
        case 'd':
        case 'D':
                
            game.reInit(input); 
            
            if (game.playGame())
                cout<<"Congrats, you won!\n";
            else cout<<"Sorry, you lose.\n";

            break;

        case 'h':
        case 'H':
            game.help();
            break;

        case 'q':
        case 'Q':
            cout<<"Thanks for playing!\n";
            return 0;
        
        default:
            cout<<"Invalid option, please try again.\n";
        }
    }
    return 0;
}
