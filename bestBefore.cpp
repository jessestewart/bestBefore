#include <iostream>
// bestBefore.cpp by Jesse Stewart 2014
// This program takes as input three sets of numbers which must then be ordered into an actual date if possible which is output and if the set of numbers is not an actual date then the message --/--/---- is illegal.

using namespace std;
int main() {
	int month, day, year, mark1, mark2, set1, set2, set3;
	bool leapyear;
	cout << "Please enter three integers representing a date between Jan 1, 2000 and Dec 31, 2999 (inclusive)." << endl;
	cin >> set1 >> set2 >> set3;
	// Find which number is the largest:
	if (set1 > set2 && set1 > set3) {
		year = set1;
		mark1 = set2;
		mark2= set3;
	} else if (set2 > set1 && set2 > set3) {
		year = set2;
		mark1 = set1;
		mark2 = set3;
	} else if (set3 > set1 && set3 > set2) {
		year = set3;
		mark1 = set1;
		mark2 = set2;
	}
	// Check to see if the number of years is less than 2999:
	if (year > 2999 || year <= 1999) {
		cout << mark1 << "/" << mark2 << "/" << year << " is illegal." << endl;
		return 0;
	}
	// See if either of the numbers are illegal:
	if (mark1 > 31 || mark1 <= 0 || mark2 > 31 || mark2 <= 0) {
		cout << mark1 << "/" << mark2 << "/" << year << " is illegal." << endl;
		return 0;
	}
	// Check to see if it is a leapyear:
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				leapyear = true;
			} else {
				leapyear = false;
			}
		} else {
			leapyear = true;
		}
	} else {
		leapyear = false;
	}
	// Find which number is the month:
	if (mark1 > 12) {
		day = mark1;
		month = mark2;
	} else if (mark2 > 12) {
		day = mark2;
		month = mark1;
	} else {
		day = mark1;
		month = mark2;
	}
	// Check to see if Feb has a 29th day on a non-leap year:
	if ((leapyear == false) && (month == 2) && (day == 29)) {
		cout << month << "/" << day << "/" << year << " is illegal." << endl;
		return 0;
	}
	// Check to see if the day is invalid for the month:
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		if (day == 31) {
			cout << month << "/" << day << "/" << year << " is illegal." << endl;
			return 0;
		}
	} else {
		cout << month << "/" << day << "/" << year << endl;
	}
	return 0;
}
