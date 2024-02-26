#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits> 
#include <algorithm> 


using namespace std;

void provideFeedback(const string& targetWord, const string& guess) {
    string feedback;
    for (size_t i = 0; i < guess.size(); ++i) {
        if (targetWord.find(guess[i]) != string::npos) {
            if (guess[i] == targetWord[i]) {
                feedback += "*";
            } else {
                feedback += "+";
            }
        } else {
            feedback += "-";
        }
    }
    cout << "Feedback: " << feedback << endl;
}

int main() {
    while (true) {
        cout << "Welcome to Wordle!" << endl;
        cout << "Guess the hidden word. You have 6 attempts." << endl;
        cout << "Game Rule :" << endl;
        cout << "Rule 1 : Letters at correct position are represented with '*'" << endl;
        cout << "Rule 2 : Letters present in the word are represented with '+'" << endl;

        vector<string> wordList = {"apple", "banana", "orange", "grape", "melon"};

        srand(time(nullptr));
        string targetWord = wordList[rand() % wordList.size()];

        cout << "The word you need to guess has " << targetWord.length() << " letters." << endl;

        int attempts = 6;
        while (attempts > 0) {
            cout << "Enter your guess: ";
            string guess;
            cin >> guess;

            provideFeedback(targetWord, guess);

            if (guess == targetWord) {
                cout << "Congratulations! You guessed the word!" << endl;
                break;
            } else {
                attempts--;
                cout << "Attempts remaining: " << attempts << endl;
            }
        }

        if (attempts == 0) {
            cout << "Sorry, you've run out of attempts. The word was: " << targetWord << endl;
        }

        cout << "Do you want to play again? (yes/no): ";
        string playAgain;
        cin >> playAgain;

        if (playAgain != "yes") {
            cout << "Thank you for playing Wordle!" << endl;
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
