#include "Game.h"
#include "HangmanWord.h"
#include "Menu.h"
#include <iomanip>

int main()
{
    std::string l = "Welcome to Hangman. What would you like to do?";
    int pos = 45 + int(l.length()/2);
    std::cout << std::setw(pos) << l << std::endl;

    //create menu object for file i/o and starting game
    Menu hangmanMenu;

    int choice;
    std::string category;

    //enters options menu
    while(choice != 4){
        hangmanMenu.displayMenu();

        //prevents entering of non-int value
        while(!(std::cin >> choice)){
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cout << "Invalid input. Try again: " << std::endl;
        }

        switch(choice){
        case 1:{
            //creates game logic object
            Game *hangmanGame = new Game();
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "Enter category: ";
            std::cin >> category;
            std::cin.ignore();

            if(hangmanGame->chooseCategory(category) == 1){
                hangmanGame->Play();
            }
            delete hangmanGame;

            std::cout << "-----------------------------------" << std::endl;
            break;}
        case 2:
            hangmanMenu.displayCategories();
            break;
        case 3:
            hangmanMenu.addWord();
            break;
        case 4:
            break;
        default:
            std::cout << "Choose 1-4 only." << std::endl;
            break;
        }
    }
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
