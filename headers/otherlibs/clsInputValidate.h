#pragma once

#include <iostream>
#include <string>
#include <limits> /* for line 50 */
#include "clsDate.h"
#include "Util.h"
using namespace std;

class clsInputValidate {
private:
  static bool _ValidateInput(char);
public:
  static bool IsNumberBetween(short, short, short);
  static bool IsNumberBetween(int, int, int);
  static bool IsNumberBetween(float, float, float);
  static bool IsNumberBetween(double, double, double);
  static bool IsDateBetween(clsDate, clsDate, clsDate);
  static int  readIntNumber(string);
  static short  readShortNumber(string);
  static float  readFloatNumber(string);
  static double readDblNumber(string);
  static int  readPositiveIntNumber(string);
  static short  readPositiveShortNumber(string);
  static float  readPositiveFloatNumber(string);
  static double readPositiveDblNumber(string);
  static int  readIntNumberBetween(int, int, string);
  static short  readShortNumberBetween(short, short, string);
  static float  readFloatNumberBetween(float, float, string);
  static double readDblNumberBetween(double, double, string);
  static bool isValidDate(clsDate);
  static string readString(string);
  static bool readBool(string);
};

bool clsInputValidate::IsNumberBetween(short num, short start, short end) { 
  if(start > end)
    Util::swap(start, end);
  return !(num > end || num < start);
}
bool clsInputValidate::IsNumberBetween(int num, int start, int end) { 
  if(start > end)
    Util::swap(start, end);
  return !(num > end || num < start);
}
bool clsInputValidate::IsNumberBetween(float num, float start, float end) { 
  if(start > end)
    Util::swap(start, end);
  return !(num > end || num < start);
}
bool clsInputValidate::IsNumberBetween(double num, double start, double end) { 
  if(start > end)
    Util::swap(start, end);
  return !(num > end || num < start);
}

bool clsInputValidate::IsDateBetween(clsDate date, clsDate start, clsDate end) {
  if (clsDate::CompareDates(start, end) == clsDate::enDateCompare::After)
    Util::swap(start, end);
    /* I Applied the same logic of IsNumberBetween() function */
  return !(clsDate::CompareDates(date, end) == clsDate::enDateCompare::After || clsDate::CompareDates(date, start) == clsDate::enDateCompare::Before);
}

int clsInputValidate::readIntNumber(string errorMsg = "Invalid Input") {
int num;
  while(!(cin >> num)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg << endl;
  }
  return num;
}

short clsInputValidate::readShortNumber(string errorMsg = "Invalid Input") {
short num;
  while(!(cin >> num)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg << endl;
  }
  return num;
}

float clsInputValidate::readFloatNumber(string errorMsg = "Invalid Input") {
float num;
  while(!(cin >> num)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg << endl;
  }
  return num;
} 

double clsInputValidate::readDblNumber(string errorMsg = "Invalid Input") {
double num;
  while(!(cin >> num)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg;
  }
  return num;
}

int clsInputValidate::readPositiveIntNumber(string errorMsg = "Invalid Input") {
int num;
  while((!(cin >> num)) && (num <= 0)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg;
  }
  return num;
}

  
short clsInputValidate::readPositiveShortNumber(string errorMsg = "Invalid Input") {
short num;
  while((!(cin >> num)) && (num <= 0)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg;
  }
  return num;
}

float clsInputValidate::readPositiveFloatNumber(string errorMsg = "Invalid Input") {
float num;
  while((!(cin >> num)) && (num <= 0)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg;
  }
  return num;
}

double clsInputValidate::readPositiveDblNumber(string errorMsg = "Invalid Input") {
double num;
  while((!(cin >> num)) && (num <= 0)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << errorMsg;
  }
  return num;
}

int clsInputValidate::readIntNumberBetween(int start, int end, string errorMsg = "Invalid Input") {
int num = readIntNumber();  
  while(!(IsNumberBetween(num, start, end))) {
    cout << errorMsg;
    num = readIntNumber();
  }
  return num;
}

short clsInputValidate::readShortNumberBetween(short start, short end, string errorMsg = "Invalid Input") {
short num = readShortNumber();  
  while(!(IsNumberBetween(num, start, end))) {
    cout << errorMsg;
    num = readShortNumber();
  }
  return num;
}

float clsInputValidate::readFloatNumberBetween(float start, float end, string errorMsg = "Invalid Input") {
float num = readFloatNumber();  
  while(!(IsNumberBetween(num, start, end))) {
    cout << errorMsg;
    num = readFloatNumber();
  }
  return num; 
}

double clsInputValidate::readDblNumberBetween(double start, double end, string errorMsg = "Invalid Input") {
double num = readDblNumber();  
  while(!(IsNumberBetween(num, start, end))) {
    cout << errorMsg;
    num = readDblNumber();
  }
  return num;
}

bool clsInputValidate::isValidDate(clsDate D) {
  return clsDate::IsValidDate(D);
}

string clsInputValidate::readString(string msg) {
string S = "";
  cout << msg;
  getline(cin >> ws, S);
  return S;
}

bool clsInputValidate::readBool(string msg) {
char b;
  cout << msg;
  cin >> b;
  return _ValidateInput(b);
}
bool clsInputValidate::_ValidateInput(char b) {
  while (!(b == 'Y' || b == 'y' || b == 'N' || b == 'n')) {
    cout << "Invalid Input, Try Again\n";
    cin >> b;
  }
  return b == 'Y' || b == 'y';
}