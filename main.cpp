#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

long GAME_CT = 0; //Total number of games played so far
long USER_SCORE = 0; //Score of User
long COMP_SCORE = 0; //Score of Computer

string playerName;
// enum RPS_Choice {ROCK, PAPER, SCISSORS};

int getUserChoice() {
    int userChoice;
    cout << "Please type-in your choice: Rock[1], Paper[2], Scissors[3] - ";
    cin >> userChoice;
    cout << endl;
    while (userChoice != 1 && userChoice != 2 && userChoice != 3) {
        cout << "Input not in the correct range - [1,3]" << endl << "Please give a valid choice - ";
        cin >> userChoice;
        cout << endl;
    }
    return --userChoice;
}

int getCompChoice() {
    cout << "Debug Line: " << RAND_MAX << " " << rand() << endl;
    int compChoice = rand()%3;
    return compChoice;
}

void showResult(int userChoice, int compChoice) {

    if (userChoice == 0) { //User Choice - Rock
        if (compChoice == 0) { //Computer Choice - Rock
            cout << "You chose Rock(1), Computer chose Rock(1)" << endl;
            cout << "It's a tie." << endl;
        }
        else if (compChoice == 1) { // Computer Choice - Paper
            cout << "You chose Rock(1), Computer chose Paper(2)" << endl;
            cout << "Paper covers Rock. You Lose ;;" << endl;
            COMP_SCORE++;
        }
        else if (compChoice == 2){ // Computer Choice - Scissors
            cout << "You chose Rock(1), Computer chose Scissors(3)" << endl;
            cout << "Rock smashes Scissors. You Win! XD" << endl;
            USER_SCORE++;
        }
        else {
            cout << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
        }
    }
    else if (userChoice == 1) { // User Choice - Paper
        if (compChoice == 0) { //Computer Choice - Rock
            cout << "You chose Paper(2), Computer chose Rock(1)" << endl;
            cout << "Paper covers Rock. You Win! XD" << endl;
            USER_SCORE++;
        }
        else if (compChoice == 1) { // Computer Choice - Paper
            cout << "You chose Paper(2), Computer chose Paper(2)" << endl;
            cout << "It's a tie." << endl;
        }
        else if (compChoice == 2){ // Computer Choice - Scissors
            cout << "You chose Paper(1), Computer chose Scissors(3)" << endl;
            cout << "Scissors cut Paper. You Lose ;;" << endl;
            COMP_SCORE++;
        }
        else {
            cout << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
        }
    }
    else if (userChoice == 2) { // User Choice - Scissors
        if (compChoice == 0) { //Computer Choice - Rock
            cout << "You chose Scissors(3), Computer chose Rock(1)" << endl;
            cout << "Rock smashes Scissors. You Lose ;;" << endl;
            COMP_SCORE++;
        }
        else if (compChoice == 1) { // Computer Choice - Paper
            cout << "You chose Scissors(3), Computer chose Paper(2)" << endl;
            cout << "Scissors cut Paper. You Win! XD" << endl;
            USER_SCORE++;
        }
        else if (compChoice == 2) { // Computer Choice - Scissors
            cout << "You chose Scissors(3), Computer chose Scissors(3)" << endl;
            cout << "It's a tie." << endl;
        }
        else {
            cout << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
        }
    }
    else {
        cout << "User Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
    }

}

void beforeExit() {
    cout << endl << "SESSION SUMMARY:" << endl;
    cout << "Total games played - " << GAME_CT << endl;
    cout << "Your Score (" << playerName << ") - " << USER_SCORE << endl;
    cout << "Computer's Score - " << COMP_SCORE << endl;
    cout << "Games Tied - " << GAME_CT-(USER_SCORE+COMP_SCORE) << endl;
}

int main (int argc, char** argv) {
    srand(time(0));

    cout << "Ready to play Rock-Paper-Scissors?!" << endl << endl;
    cout << "Please enter your name below : " << endl;
    cin >> playerName;

    cout << "Hello, "<<playerName << "! Let's begin the game session" << endl << endl;

    bool exit = false;
    while(!exit) {
        cout << "GAME #"<< GAME_CT+1 << endl;

        int userChoice, compChoice;

        userChoice = getUserChoice();
        compChoice = getCompChoice();
        showResult (userChoice, compChoice);
        cout << endl;
        GAME_CT++;
        cout << playerName << "(" << USER_SCORE << ") - Computer(" << COMP_SCORE << ")" << endl << endl;
        string userInput;
        cout << "Do you want to continue? (y/n) : ";
        cin >> userInput;
        while (userInput.length()!=1 || (tolower(userInput[0]) !='y' && tolower(userInput[0]) != 'n')) {
            cout << "Did not receive a valid input. Do you want to continue? (y/n) : " << endl;
            cin >> userInput;
        }
        if (tolower(userInput[0]) == 'y') {
            exit = false;
        }
        else if (tolower(userInput[0]) == 'n') {
            exit = true;
        }
        cout << endl << endl;
    }

    beforeExit();
    return 0;
}
