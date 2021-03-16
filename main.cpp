#include <string.h> 
#include <iostream> 
#include <fstream>
using namespace std;

int main() {
  string action;
  int actionSelected = 0;
  string confirmSelection;
  string fileName;
  while (actionSelected == 0) {
    cout << "Select file compressing (1) or file decompressing (2): ";
    getline(cin, action);
    if (action == "1") {
      cout << "You selected 'file compressing (1)', are you sure (y/n)? ";
        getline(cin, confirmSelection);
    }
    else if (action == "2") {
      cout << "You selected 'file decompressing (2)', are you sure (y/n)? ";
        getline(cin, confirmSelection);
    }
    else {
      cout << "Selection not understood, try again" << endl;
      confirmSelection = "n";
    }
    if (confirmSelection == "Y" || confirmSelection == "y") {
      actionSelected = 1;
    }
    else if (confirmSelection == "N" || confirmSelection == "n") {
      actionSelected = 0;
    }
    else {
      cout << "Not understood, try again" << endl;
    }
  }
  if (action == "1") {
    cout << "Type name of the file that will be compressed: ";
    getline(cin, fileName);
    cout << fileName;
  }
  else if (action == "2") {
    cout << "Type name of the file that will be decompressed: ";
    getline(cin, fileName);
    cout << fileName;
  }
  else {
    return 0;
  }
  return 0;
}