#include <iostream>
#include <string>
#include <cstring>
#include <ctime>

#define MAX_BAD_GUESSES 10

using namespace std;

string words[] = {"AngLE", "ant", "apple", "arch", "arm", "army",
"baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
"bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
"brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
"cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
"chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
"cow", "cup", "curtain", "cushion",
"dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
"face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
"foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
"hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
"hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
"leaf", "leg", "library", "line", "lip", "lock",
"map", "match", "monkey", "moon", "mouth", "muscle",
"nail", "neck", "needle", "nerve", "net", "nose", "nut",
"office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
"pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
"rail", "rat", "receipt", "ring", "rod", "roof", "root",
"sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
"shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
"square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
"store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
"toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
"wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};

void tolower(string& word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
}

void initGame(string& secretWord, string& guessWord, int& badGuessCount) {
    badGuessCount = 0;
    int index  = rand() % (sizeof(words) / sizeof(string));
    secretWord = words[index];
    tolower(secretWord);
    guessWord = string(secretWord.length(), '-');
}

void display(const string& secretWord, const string& guessWord, int badGuessCount) 
{
    cout << guessWord << " " << endl;
    cout << "Wrong guess remains: " << MAX_BAD_GUESSES - badGuessCount << endl;
    cout << "Please enter your guess: " << endl;

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
        cout << "You lost!" << endl;
    else
        cout << "You won!" << endl;
}

char getInput() {
    string input;
    cin >> input;
    return tolower(input[0]);
}

int main()
{
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