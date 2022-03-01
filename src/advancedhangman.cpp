#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

const int MAX_BAD_GUESSES = 10;

vector<string> words;

void get_words()
{
    ifstream fin("words.txt");
    if (fin.is_open()) 
    {
        string line;
        while (getline(fin, line))
        {
            words.push_back(line);
        }
        fin.close();
    }
}

void tolower(string& word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
}

void initGame(string& secretWord, string& guessWord, int& badGuessCount) {
    badGuessCount = 0;
    int index  = rand() % 100;
    cout << index << endl;
    secretWord = words[index];
    tolower(secretWord);
    guessWord = string(secretWord.length(), '_');
}

void display(const string& secretWord, const string& guessWord, int badGuessCount) 
{
    cout << guessWord << " " << endl;
    cout << "Wrong guess remains: " << MAX_BAD_GUESSES - badGuessCount << endl;
    cout << "Please enter your guess: " << endl;
    cout << endl;
    //hangman
}

bool contains(const string& word, char c)
{
    return (word.find_first_of(c) != string::npos);
}

void updateGame(char input, const string& secretWord, string& guessWord, int& badGuessCount)
{
    if (contains(secretWord, input)) {
        for (int i = 0; i < guessWord.length(); i++) {
            if (secretWord[i] == input) guessWord[i] = input;
        }
    }
    else badGuessCount++;
}

bool gameOver(const string& secretWord, const string& guessWord, int badGuessCount)
{
    return (secretWord == guessWord || badGuessCount >= MAX_BAD_GUESSES);
}

void displayResult(const string& guessWord, int badGuessCount)
{
    if (badGuessCount >= MAX_BAD_GUESSES)
        cout << "You lost!\n";
    else
        cout << "You won!\n";
}

char getInput() {
    string input;
    cin >> input;
    return tolower(input[0]);
}

int main()
{
    get_words();
    srand(time(0));

    string secretWord;
    string guessWord;
    int badGuessCount;
    initGame(secretWord, guessWord, badGuessCount);

    do {
        display(secretWord, guessWord, badGuessCount);
        char input = getInput();
        updateGame(input, secretWord, guessWord, badGuessCount);
    } while (!gameOver(secretWord, guessWord, badGuessCount)) ;
    displayResult(guessWord, badGuessCount);
    cout << "The word is " << secretWord;
    cout << endl;
    return 0;
}