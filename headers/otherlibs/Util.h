/* Util Library */
#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"
using namespace std;

class Util {
public:
  enum enCharType { SamallLetter = 1, CapitalLetter = 2,
    SpecialCharacter = 3, Digit = 4, Mixed = 5 };
  static void _srand() { srand(time(0)); }
  static int random_number(int from, int to) { return rand() % (to - from + 1) + from; }
  static char random_charachter(enCharType);
  static string generate_word(enCharType, short);
  static string generate_key(enCharType);
  static void generate_keys(enCharType, unsigned short);
  static void swap(short &, short &);
  static void swap(int &, int &);
  static void swap(float &, float &);
  static void swap(double &, double &);
  static void swap(string &, string &);
  static void swap(clsDate &, clsDate &);
  static void ShuffleArray(int *, int);
  static void ShuffleArray(string *, int);
  static void fillArrayWithRandomNumbers(int *, unsigned short, int, int);
  static void fillArrayWithRandomWords(string *, unsigned short, enCharType, unsigned short);
  static void fillArrayWithRandomKeys(string *, unsigned short, enCharType);
  static string tabs(unsigned short);
  static string EncryptText(string, short);
  static string DecryptText(string, short);
  static string NumToTxt(int);
  static void printContentOfFile(const string);
  static void back_to_X_menu(const string);
  static void PauseWithMsg(const string);
  static bool stringToBool(string str) { return stoi(str); }
};

char Util::random_charachter(enCharType charType) {
  if(charType == enCharType::Mixed)
    charType = (enCharType) random_number(1, 4);
  switch (charType) {
    case enCharType::SamallLetter: {
      return char(random_number(97, 122));
      break;
    }
    case enCharType::CapitalLetter: {
      return char(random_number(65, 90));
      break;
    }
    case enCharType::SpecialCharacter: {
      return char(random_number(33, 47));
      break;
    }
    case enCharType::Digit: {
      return char(random_number(48, 57));
      break;
    }
  }
  return 0;
}

string Util::generate_word(enCharType charType, short length) {
string Word;
  for (int i = 1; i <= length; i++) 
    Word = Word + random_charachter(charType);
  return Word;
}

string Util::generate_key(enCharType charType) {
string key = "";
  for (int i = 0; i < 4; i++) {
    key += generate_word(enCharType::Mixed, 4);
    if (i != 3) key += "-";
  }
  return key;
}

void Util::generate_keys(enCharType charType, unsigned short howmany_keys) {
  for (int i = 0; i < howmany_keys; i++) 
    cout << "Key[" << i+1 << "]: " << generate_key(charType) << endl;
}

void Util::swap(short & x, short & y) {
int tmp = x;
  x = y;
  y = tmp;
}

void Util::swap(int & x, int & y) {
int tmp = x;
  x = y;
  y = tmp;
}

void Util::swap(float & x, float & y) {
int tmp = x;
  x = y;
  y = tmp;
}

void Util::swap(double & x, double & y) {
double tmp = x;
  x = y;
  y = tmp;
}

void Util::swap(string & x, string & y) {
string tmp = x;
  x = y;
  y = tmp;
}

void Util::swap(clsDate & x, clsDate & y) {
clsDate tmp = x;
  x = y;
  y = tmp;
}

void Util::ShuffleArray(int * arr, int arrLength) {
  for (int i = 0; i < arrLength; i++) 
    swap(arr[random_number(1, arrLength) - 1],
      arr[random_number(1, arrLength) - 1]);
}

void Util::ShuffleArray(string * arr, int arrLength) {
  for (int i = 0; i < arrLength; i++) 
    swap(arr[random_number(1, arrLength) - 1],
      arr[random_number(1, arrLength) - 1]);
}

void Util::fillArrayWithRandomNumbers(int * arr, unsigned short length, int from, int to) {
  for (int i = 0; i < length; i++) 
    arr[i] = random_number(from, to);
}

void Util::fillArrayWithRandomWords(string * arr, unsigned short length, enCharType charType, unsigned short lengthOfWord) {
  for (int i = 0; i < length; i++)
    arr[i] = generate_word(charType, lengthOfWord);
}

void Util::fillArrayWithRandomKeys(string * arr, unsigned short length, enCharType charType) {
  for (int i = 0; i < length; i++)
    arr[i] = generate_key(charType);
}

string Util::tabs(unsigned short length) {
string tabs = "";
  for (int i = 0; i < length; i++)
    tabs += "\t";
  return tabs;
}

string Util::EncryptText(string Text, short EncryptionKey) {
  for (int i = 0; i <= Text.length(); i++)
    Text[i] = char((int)Text[i] + EncryptionKey);
  return Text;
}

string Util::DecryptText(string Text, short EncryptionKey) {
  for (int i = 0; i <= Text.length(); i++)
    Text[i] = char((int)Text[i] - EncryptionKey);
  return Text;
}

string Util::NumToTxt(int n) {
  if (n == 0)
    return "";

  if (n > 0 && n <= 19) {
    string arr[] {"", "One", "TWo", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
      "Ten", "Eleven", "Twilve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    return arr[n];
  } 

  if (n >= 20 && n <= 99) {
    string arr[] {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sexty", "Seventy", "Eighty", "Ninety"};
    return arr[n / 10] + " " + NumToTxt(n % 10);
  } 

  if (n >= 100 && n <= 999) 
    return NumToTxt(n / 100) + " Houndred " + NumToTxt(n % 100);

  if (n >= 1000 && n <= 999999) 
    return NumToTxt(n / 1000) + " Thouthand " + NumToTxt(n % 1000);

  if (n >= 1000000 && n <= 999999999) 
    return NumToTxt(n / 1000000) + " Milion " + NumToTxt(n % 1000000);

  if (n >= 1000000000 && n <= 9999999999) 
    return NumToTxt(n / 1000000000) + " Milion " + NumToTxt(n % 1000000000);

  return "";
}

void Util::printContentOfFile(const string filepath) {
    ifstream file("filepath");
    if (!file) {
        cerr << "Error: Cannot open file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
    return;
}

void Util::back_to_X_menu(const string X) {
    cout << "Press Any Key To Go To " << X << " Menu...";
    system("pause>0");
}

void Util::PauseWithMsg(const string msg) {
    cout << msg;
    system("pause>0");
}