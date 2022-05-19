#ifndef HIGHSCORES
#define HIGHSCORES

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct player
{
    string name;
    double score;
};

void inputNew(int n);

void loadScore(string path, string n, double s);

#endif