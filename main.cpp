#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

long GAME_CT = 0; //Total number of games played so far
long USER_SCORE = 0; //Score of User
long COMP_SCORE = 0; //Score of Computer

string playerName;

int getUserChoice() {
    string userInput;
    int userChoice;
    cout << "Please type-in your choice: Rock[1], Paper[2], Scissors[3] - ";
    cin >> userInput;
    cout << endl;

    while (userInput.length() != 1 || (userInput[0]-'1') < 0 || (userInput[0]-'1') > 2) {
        cout << "Input not in the correct format. Please select an integral value from range - [1,3]" << endl;
        cout << "Please type-in your choice: Rock[1], Paper[2], Scissors[3] - ";
        cin >> userInput;
        cout << endl;
    }
    userChoice = userInput[0]-'1';
    return userChoice;
}

int getCompChoice() {

    int compChoice = rand()%3; //Selecting a random value and the mod3 operation returns a value in correct range
    return compChoice;
}

int showResult(int userChoice, int compChoice) { //return value of 1 implies error in result execution
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
            cerr << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
            return 1;
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
            cerr << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
            return 1;
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
            cerr << "Computer Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
            return 1;
        }
    }
    else {
        cerr << "User Choice Error. Please force exit using Ctrl/Cmd+C, and restart the game" << endl;
        return 1;
    }
    return 0;

}

void beforeExit() {
    cout << endl << "SESSION SUMMARY:" << endl;
    cout << "Total games played - " << GAME_CT << endl;
    cout << "Your Score (" << playerName << ") - " << USER_SCORE << endl;
    cout << "Computer's Score - " << COMP_SCORE << endl;
    cout << "Games Tied - " << GAME_CT-(USER_SCORE+COMP_SCORE) << endl;
    cout << endl << "===============BYE!===============" << endl << endl;
}

int main (int argc, char** argv) {
    try {
        srand(time(0)); //Seeding the pseudo random generator function with the initial seed value of current time
        cout << endl << "===============WELCOME!===============" << endl << endl;
        cout << "Ready to play Rock-Paper-Scissors?!" << endl << endl;
        cout << "Please enter your name below : ";
        cin >> playerName;
        cout << endl;

        cout << "Hello, "<<playerName << "! Let's begin the game session" << endl << endl;

        bool exit = false;
        while(!exit) {
            cout << "ROUND #"<< GAME_CT+1 << endl;

            int userChoice, compChoice;

            userChoice = getUserChoice();
            compChoice = getCompChoice();
            int ret_code = showResult (userChoice, compChoice);
            cout << endl;
            if(ret_code) {
                cout << "Unexpected error caught in this round. Force-quitting the game" << endl;
                break;
            }

            GAME_CT++;
            cout << "----SCORE----" << endl;
            cout << playerName << "(" << USER_SCORE << ") - Computer(" << COMP_SCORE << ")" << endl << endl;
            string userInput;
            cout << "Do you want to play another round? (y/n) : ";
            cin >> userInput;
            while (userInput.length()!=1 || (tolower(userInput[0]) !='y' && tolower(userInput[0]) != 'n')) {
                cout << "Did not receive a valid input. Do you want to continue? (y/n) : " << endl;
                cin >> userInput;
            }
            cout << endl;
            if (tolower(userInput[0]) == 'y') {
                exit = false;
            }
            else if (tolower(userInput[0]) == 'n') {
                exit = true;
            }
        }
    }
    catch (int x) {
        cout << "Unexpected error caught in this round. Force-quitting the game" << endl;
    }
    cout << endl << endl;
    beforeExit();
    return 0;
}
