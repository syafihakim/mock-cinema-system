#include <bits/stdc++.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

//SIMPLE MOVIE TICKET SYSTEM

int screenWidth = 30;

void printBanner(string);
void printCenter(string);
void print(string);
void printMenu();
void viewMoviePage();
void viewFoodPage();
void viewDrinkPage();
void viewSeatPage();
void printHorizontalLine();
void printHorizontalLineTwo();
int getInput();
void addMovie(string, string);
void addFood(string, string);
void addDrink(string, string);
void addDefaultItems();
void printTableHeader(string, string);
void printTwoColumn(string, string);
void assignRandomSeats();

struct movie {
    string title;
    string screenTime;
};

struct food {
    string name;
    string price;
};

struct drink {
    string name;
    string price;
};


vector<movie> movies;
vector<food> foodList;
vector<drink> drinkList;
vector<vector<vector<int>>> seats;

int main()
{
    addDefaultItems();
    assignRandomSeats();

    do {
        system("cls");
        printBanner("CINEMA SYSTEM");
        printMenu();
        int choice = getInput();
        if(choice == 1) {
            viewMoviePage();
        } else if(choice == 2) {
            viewFoodPage();
        } else if(choice == 3) {
            viewDrinkPage();
        } else if(choice == 4) {
            viewSeatPage();
        }
    }while(true);
    return 0;
}

void viewSeatPage() {
    int _choice;
    int movieIdx = 0;

    do {
        system("cls");
        printBanner("AVAILABLE SEATS");
        printCenter("_______Screen_______");
        for(int i=0; i<4; i++) {
            cout << string(6, ' ');
            for(int j=0; j<6; j++) {
                if(seats[movieIdx][i][j] == 0)
                    cout << "[ ]";
                else
                    cout << "[X]";
            }
            cout << endl;
        }
        printHorizontalLineTwo();
        string currMovieTitle;
        currMovieTitle = "Title: ";
        currMovieTitle += movies[movieIdx].title;
        printCenter(currMovieTitle);
        printCenter("Press A/D/Esc");
        _choice = getch();
        if((_choice == 'a' || _choice == 'A') && movieIdx != 0)
            movieIdx--;
        else if((_choice == 'd' || _choice == 'D') && movieIdx != movies.size()-1)
            movieIdx++;
    }while(_choice != 27);
}

void viewDrinkPage() {
    // Temporary
    system("cls");

    printBanner("ALL DRINK");
    printTableHeader("Name", "Price");
    for(int i=0; i<drinkList.size(); i++) {
        drink curr = drinkList[i];
        printTwoColumn(curr.name, curr.price);
    }
    printHorizontalLine();
    getch();
}

void viewFoodPage() {
    // Temporary
    system("cls");

    printBanner("ALL FOOD");
    printTableHeader("Name", "Price");
    for(int i=0; i<foodList.size(); i++) {
        food curr = foodList[i];
        printTwoColumn(curr.name, curr.price);
    }
    printHorizontalLine();
    getch();
}

void viewMoviePage() {
    // Temporary
    system("cls");

    printBanner("ALL MOVIES");
    printTableHeader("Title", "Time");
    for(int i=0; i<movies.size(); i++) {
        movie curr = movies[i];
        printTwoColumn(curr.title, curr.screenTime);
    }
    printHorizontalLine();
    getch();
}

void printTableHeader(string a, string b) {
    printTwoColumn(a, b);
    printHorizontalLine();
}

void printHorizontalLine() {
    string border = "+";
    border += string(screenWidth-2, '-');
    border += "+";
    print(border);
}

void printHorizontalLineTwo() {
    string border = string(screenWidth-8, '_');
    printCenter(border);
}

void printTwoColumn(string a, string b) {
    printf(" %-15s  %10s \n", a.c_str(), b.c_str());
}

void printMenu() {
    print("[1] View all movies");
    print("[2] View all food");
    print("[3] View all drink");
    print("[4] View seats");
    print("");
}

void printBanner(string title) {
    string border = "+";
    border += string(screenWidth-2, '=');
    border += "+";

    cout << border << endl;
    printCenter(title);
    cout << border << endl;
    cout << endl;
}

void printCenter(string text) {
    string centerText;
    int spacesCount = (screenWidth - text.size())/2;
    string spaces = string(spacesCount, ' ');
    centerText = spaces + text + spaces;
    cout << centerText << endl;
}

void print(string text) {
    cout << text << endl;
}

int getInput() {
    print("Press button ...");
    int choice = getch();
    return (choice - '0');
}

void addMovie(string title, string screenTime) {
    movie curr;
    curr.title = title;
    curr.screenTime = screenTime;

    movies.push_back(curr);
}

void addFood(string name, string price) {
    food curr;
    curr.name = name;
    curr.price = price;

    foodList.push_back(curr);
}

void addDrink(string name, string price) {
    drink curr;
    curr.name = name;
    curr.price = price;

    drinkList.push_back(curr);
}

void addDefaultItems() {
    addMovie("MECHAMATO", "12:00 PM");
    addMovie("AVATAR", "3:00 PM");
    addMovie("JOHN WICK 4", "4:00 PM");
    addMovie("EJEN ALI", "9:00 PM");
    addFood("POPCORN", "RM 12");
    addFood("NUGGET", "RM 10");
    addFood("SOSEJ", "RM 11");
    addFood("MAGGI", "RM 13");
    addDrink("PEPSI", "RM 4");
    addDrink("COKE", "RM 4");
    addDrink("FANTA", "RM 3");
    addDrink("MILO", "RM 3");
    addDrink("ICED L. TEA", "RM 3");
}

void assignRandomSeats() {
    srand(time(0));

    for(int t=0; t<movies.size(); t++) {
        for(int i=0; i<4; i++) {
            for(int j=0; j<6; j++) {
                seats.push_back(vector<vector<int>>());
                seats[t].push_back(vector<int>());
                seats[t][i].push_back(rand()%2);
            }
        }
    }
}



















