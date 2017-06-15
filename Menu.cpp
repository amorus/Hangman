#include <algorithm>
#include <fstream>
#include <iostream>

#include "Menu.h"

void Menu::displayMenu(){
    std::cout << "1. Play" << std::endl;
    std::cout << "2. Show categories" << std::endl;
    std::cout << "3. Add word" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

int Menu::displayCategories()
{
    std::ifstream readFile("Categories.dat");
    std::string category;
    system("cls||clear");
    std::cout << "All available categories are: " << std::endl << "-----------------------------------" << std::endl;

    if(!readFile){
        std::cout << "Error! Could not open file or file does not exist. Try to add a word to create file." << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        return -1;
    }

    if(readFile.peek() == std::ifstream::traits_type::eof()){
        std::cout << "There are no categories!" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        return 0;
    }

    while(readFile >> category) {
        std::cout << category << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    return 1;
}

void Menu::addWord(){
    std::string category, word;
    std::string tempCategory;
    bool isPresent = false;

    std::ofstream writeWord("Words.dat", std::ios::app);
    std::ifstream readCategory("Categories.dat");
    system("cls||clear");
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Enter category of word to add(can't be space seperated): ";
    std::cin >> category;
    std::transform(category.begin(), category.end(), category.begin(), ::tolower);
    std::cin.ignore();

    std::cout << "Enter word to add(CAN be space seperated): ";
    std::getline(std::cin, word);
    std::cout << std::endl << "Word" << word << "has been added in category " << category << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    while(readCategory >> tempCategory){
        std::transform(tempCategory.begin(), tempCategory.end(), tempCategory.begin(), ::tolower);
        if(tempCategory == category)
            isPresent = true;
    }
    readCategory.close();
    if(isPresent == false){
        std::ofstream writeCategory("Categories.dat", std::ios::app);
        writeCategory << category << std::endl;
        writeCategory.close();
    }
    writeWord << category << " " << word << std::endl;
    writeWord.close();
}
