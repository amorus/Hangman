#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu{
private:
public:
    //method to display the main menu
    void displayMenu();

    //method to add a word to the Words.dat word database
    void addWord();

    //displays all categories available(from Categories.dat)
    int displayCategories();
};

#endif // MENU_H_INCLUDED
