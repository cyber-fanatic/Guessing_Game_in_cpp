//==============================My Fruit guessing Game=============
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

//proto-types and function declerations below
void playGame();
int randNum(int size);
string userInput(string my_fruit);
void Loss(string user_in, string my_fruit);
//=================================================================

//=============================main()==============================
int main() {
    playGame();
    int index = 0;
    int const size = 5;
    index = randNum(size);//return random integer b/w 0-4   

    string fruits[size] = { "APPLE", "MANGO", "BANANA", "ORANGE", "KIVI" };
    string my_fruit;
    my_fruit = fruits[index];

    // return user guessed fruit
    string user_in = userInput(my_fruit);

    //check and call winLoss if the user not guess correctly
    if (user_in != my_fruit) {
        Loss(user_in, my_fruit);
    }
    return 0;
}

//==============================My Functions========================
//generate random num function
int randNum(int size) {
    srand((int)time(nullptr));
    int my_num = 0;
    my_num = (rand() % size);  // save any num b/w (0-4) in my_num
    return my_num;
}

//userInput function
string userInput(string my_fruit) {
    string user_in = " ";
    int attempts = 2; // Total attempts allowed

    for (int i = 1; i <= attempts; i++) {
        cout << "====================================\n";
        cout << "(#)\tGuess The Fruit Name: ";
        getline(cin, user_in);
        cout << "====================================\n";
        cout << '\n';

        //convert user input into uppercase latters
        string* ptr = &user_in;
        for (char& ch : *ptr) {
            ch = toupper(ch);
        }

        //check to compare user input with any random fruit in array
        if (user_in == my_fruit) {
            cout << "#################################|***AMAZING!! YOU WON THE GAME***|#################################\n\n";

            //if true then simply return user input tha we use latter 
            return user_in;
        }

        if (i < attempts) {
            cout << "Oops Wrong Guess Try Again!!!\n-->You have " << (attempts - i) << " attempt left.\n\n";
        }
    }
    return "wrong_guess";  // when user used both attempts
}

//winLoss function that take two arguments user input and random fruit name from array
void Loss(string user_in, string my_fruit) {
    if (user_in != my_fruit) {       // 
        cout << "========================***Oops! YOU LOSS THE GAME***=============================\n\n";
        cout << "========================### BETTER LUCK NEXT TIME ###=============================\n";
    }
}

//Game intructions
void playGame() {
    cout << "\t\t######################### \"WELCOME TO GUESS THE FRUIT GAME\" #########################\n\n";
    cout << "\t\t========================**How To Play The Game**========================\n\n";
    cout << "(+)You Need to Guess the Correct Fruit Name.\n\n";
    cout << "(+)Incase of Wrong Guess You Have One More Chance.\n\n";
    cout << "(+)Guessing  Hints::\t'Orange','Kivi','Mango','Apple','Banana'\n\n";
    cout << "\t\t<================================**Good Luck**========================>\n\n";
}