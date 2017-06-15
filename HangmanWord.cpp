#include <algorithm>

#include "HangmanWord.h"

HangmanWord::HangmanWord(std::string inputWord, std::string inputCat){
    word = inputWord;
    category = inputCat;
    int neededToGuess = 0;
    int len = word.length();

    guessedWord = word;
    for(int i = 0; i < len; i++){
        if(word.at(i) == ' ')
            guessedWord.at(i) = ' ';

        else{
            guessedWord.at(i) = '_';
            neededToGuess++;
        }
    }
    charsToGuess = neededToGuess;
}

int HangmanWord::checkWord(char guessedChar){
    int len = word.length();
    int match = 0;
    if(std::find(guessedChars.begin(), guessedChars.end(), guessedChar) != guessedChars.end()
        || std::find(guessedChars.begin(), guessedChars.end(), guessedChar-32) != guessedChars.end()
        || std::find(guessedChars.begin(), guessedChars.end(), guessedChar+32) != guessedChars.end()){

        std::cout << "You already tried that" << std::endl;
        return -1;
    }
    for(int i = 0; i < len; i++){
        if((word.at(i) == guessedChar) || ((word.at(i))-32 == guessedChar) || ((word.at(i))+32 == guessedChar)){
            guessedWord.at(i) = word.at(i);
            match++;
        }
        guessedChars.push_back(guessedChar);
    }

    return match;
}

void HangmanWord::resetGuessed(){
    int neededToGuess = 0;
    int len = word.length();

    guessedWord = word;
    for(int i = 0; i < len; i++){
        if(word.at(i) == ' ')
            guessedWord.at(i) = ' ';

        else{
            guessedWord.at(i) = '_';
            neededToGuess++;
        }
    }
    charsToGuess = neededToGuess;
}
