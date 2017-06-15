#include <ctime>
#include <algorithm>
#include <fstream>

#include "Game.h"


void Game::Play(){
    char ch;
    std::string temp;
    int guessed;
    randomize();

    while(getLives() > 0 && (correctlyGuessed != getWords()->at(getRandomizedWord()).getCharsToGuess())) {

        getWords()->at(getRandomizedWord()).writeGuessed();
        std::getline(std::cin, temp);

        if(temp == getWords()->at(getRandomizedWord()).getWord()){
            guessed = getWords()->at(getRandomizedWord()).getCharsToGuess();
            break;
        }

        ch = temp.at(0);

        guessed = getWords()->at(getRandomizedWord()).checkWord(ch);

        if(guessed == 0){
            setLives(getLives()-1);
            std::cout << "You have " << getLives() << " tries left!" << std::endl;
            }

        else if(guessed > 0){
                correctlyGuessed += guessed;
            }
        }
        if(getLives() == 0){
            std::cout << "You lose! The word was " << getWords()->at(getRandomizedWord()).getWord() << std::endl;
        }
        else{
            std::cout << "You win!" << std::endl;
        }
    }

void Game::randomize(){
    srand(time(0));

    randomizedWord = rand()%(hangmanWords.size());
}

int Game::chooseCategory(std::string desiredCategory){

    std::ifstream readFile("Words.dat");
    std::string word, category;
    std::string loweredCategory = desiredCategory;
    std::transform(loweredCategory.begin(), loweredCategory.end(), loweredCategory.begin(), ::tolower);


    bool isPresent = false;

    if(!readFile){
        std::cout << "Error! Could not open file or file does not exist. Try to add a word to create file." << std::endl;
        return -1;
    }

    if(readFile.peek() == std::ifstream::traits_type::eof()){
        std::cout << "There are no words in the database! Add a word to play." << std::endl;
        readFile.close();
        return 0;
    }

    while(readFile >> category) {
        std::transform(category.begin(), category.end(), category.begin(), ::tolower);
        readFile.ignore(1);
        std::getline(readFile, word);

        if(category == loweredCategory){
            isPresent = true;
            HangmanWord newWord(word, category);
            hangmanWords.push_back(newWord);
        }
    }
    readFile.close();
    if(isPresent == false){
        std::cout << "There is no such category." << std::endl;
        return -1;
    }
    return 1;
}
