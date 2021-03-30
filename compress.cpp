#include <string.h>
#include <iostream>
#include <fstream>
#include "compress.h"
using namespace std;

void allocateCharacters(Character* &characters, int count) {
  if (characters == NULL) {
    // malloc
    characters = (Character*) malloc(count * sizeof(Character));
  }
  else if (characters != nullptr) {
    // realloc
    characters = (Character*) realloc(characters, count * sizeof(Character));
  }
  else {
    return;
  }
  return;
}

void deleteCharacters(Characters* &characters) {

}

Characters readFileToCharacters(fstream& file) {
  Characters characters;
  characters.count = 0;
  characters.character = NULL;
  char singleCharacter;
  while(file.get(singleCharacter)) {
    // cout << singleCharacter;
    int newCharacter = 1;
    for (int i = 0; i < characters.count; i++) {
      if (singleCharacter == characters.character[i].character) {
        newCharacter = 0;
        characters.character[i].frequency += 1;
        break;
      }
    }
    if (newCharacter == 1) {
      characters.count += 1;
      allocateCharacters(characters.character, characters.count);
      characters.character[characters.count - 1].character = singleCharacter;
      characters.character[characters.count - 1].frequency = 1;
    }
  }
  return characters;
}

Characters sortCharactersByFrequency(Characters characters) {
  int counter = 0;
  Characters sortedCharacters;
  sortedCharacters.count = 0;
  sortedCharacters.character = NULL;
  allocateCharacters(sortedCharacters.character, characters.count);
  while (sortedCharacters.count < characters.count) {
    int frequency = 0;
    int character;
    int isUndefinedCharacter = 1;
    for (int i = 0; i < characters.count; i++) {
      if (frequency <= characters.character[i].frequency) {
        int isNew = 1;
        for (int j = 0; j < sortedCharacters.count; j++) {
          if (characters.character[i].character == sortedCharacters.character[j].character) {
            isNew = 0;
          }
        }
        if (isNew == 1) {
          frequency = characters.character[i].frequency;
          character = i;
          isUndefinedCharacter = 0;
        }
      }
    }
    if (isUndefinedCharacter == 0) {
      sortedCharacters.count += 1;
      sortedCharacters.character[counter].character = characters.character[character].character;
      sortedCharacters.character[counter].frequency = characters.character[character].frequency;
      counter += 1;
    }
  }
  delete[] characters.character;
  return sortedCharacters;
}

void compress(string fileName) {
  cout << "Starting to compress the file" << endl;
  fstream file(fileName);
  Characters characters;
  characters = sortCharactersByFrequency(readFileToCharacters(file));
  cout << "Compressing done" << endl;
  // testing here
  for (int i = 0; i < characters.count; i++) {
    cout << characters.character[i].character << " - " << characters.character[i].frequency << endl;
  }
  return;
}