#ifndef HANGMANWORD_H_INCLUDED
#define HANGMANWORD_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>

class HangmanWord {
private:
    //how many chars must the player guess to win
    int charsToGuess;

    //all guessed chars so far
    std::vector<char> guessedChars;

    //the word to guess
    std::string word;

    //the category of the word to guess
    std::string category;

    //the word guessed so far
    std::string guessedWord;

public:
    static int nextId;

    int getCharsToGuess() { return charsToGuess; }
    std::string getWord() { return word; }
    std::string getCategory() { return category; }

    void setWord(std::string inputWord);
    void setCategory(std::string inputCat);

    //checks if the char the player guess is in the word. Takes a live or fills guessedWord accordingly
    int checkWord(char guessedChar);

    //display the guessed word so far
    void writeGuessed() { std::cout << guessedWord << std::endl << std::endl; }

    void resetGuessed();

    HangmanWord(std::string inputWord, std::string inputCat);
};


#endif // HANGMANWORD_H_INCLUDED
