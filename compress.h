#ifndef COMPRESS_H
#define COMPRESS_H

#include <string.h>
#include <iostream>
using namespace std;

void compress(string fileName);

class Character {
  public:
    char character;
    int frequency;
};

class Characters {
  public:
    Character* character;
    int count;
};

#endif