#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "HangmanWord.h"

class Game{
private:
    //player lives
    int lives = 6;

    //how many chars has the player guessed
    int correctlyGuessed = 0;

    //random int to use for randomizing words
    int randomizedWord;

    //all words read from file Words.dat
    std::vector<HangmanWord> hangmanWords;
public:
    int getLives() { return lives; }

    std::vector<HangmanWord> *getWords() { return &hangmanWords; }
    void setLives(int l) { lives = l; }
    int getRandomizedWord() { return randomizedWord; }
    int chooseCategory(std::string desiredCategory);
    int getCorrectlyGuessed() {return correctlyGuessed;}
    void setCorrectlyGuessed(int c) { correctlyGuessed = c;}

    //assigns a random number to randomizedWord for use in the vector iterator later. For randomizing the words
    void randomize();

    //main game logic method
    void Play();

};

#endif // GAME_H_INCLUDED
