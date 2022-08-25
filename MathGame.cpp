#include <iostream>//libary for input and output / cout|cin
#include <ctime>//libery to pull computers current time 

void PrintIntroduction()//this is a function to print the intro message
{
    std::cout<<"You are in a powerplant thats overheating\n";
    std::cout<<"The supervisor has passed out\n";
    std::cout<<"You find a note with the shutdown code\n";
    std::cout<<"But its a math problem! can you solve it??\n";
    std::cout<<"There are three numbers in each code\n";
    std::cout<<"You approach the main Terminal and read\n\n";
    std::cout<<"[Powerplant shutdown] please enter 1st code\n";
}

bool PlayGame(int Level)//this is a function to start the game
{
    const int Code1 = rand() % Level + Level, Code2 = rand() % Level + Level, Code3 = rand() % Level + Level;//declaring constant variables

    int CodeAdd = Code1 + Code2 + Code3;
    int CodeMultiply = Code1 * Code2 * Code3;//making the answer to the game

    std::cout<<"\nYou are on level: " << Level;
    std::cout<<"\nThe code adds up to: " << CodeAdd;
    std::cout<<"\nThe code multiplies to: " << CodeMultiply;
    std::cout<<"\nWhat is the code?: ";// explaining the game


    int Guess1, Guess2, Guess3;
    std::cin >> Guess1 >> Guess2 >> Guess3;// getting users answer

    int GuessAdd = Guess1 + Guess2 + Guess3;
    int GuessMultiply = Guess1 * Guess2 * Guess3;

    if (GuessAdd == CodeAdd)//if else statement to print win or loose message if users amswer = or ! to realanswer
    {
        std::cout << "\n[Correct!] ";
        return true;
    }
    else
    {
        std::cout << "\n[INCORRECT!] ";
        return false;
    }
}

int main ()// this is where the compiler starts and finishes
{
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    srand(time(NULL));// creates random sequence based on time of day
    PrintIntroduction();
    while (LevelDifficulty <= MaxDifficulty)// loop game untill all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();//clears any errors
        std::cin.ignore();//Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;//adds a level if completed previous level
        }
        
    }
    std::cout << "\n[Successful shutdown!] You Win!";
    return 0;
}
