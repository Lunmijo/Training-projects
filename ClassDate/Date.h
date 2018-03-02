#pragma once
#include <iostream>
#include <string>

using namespace std;

class Date {
private:
	unsigned int day, year, month;
	bool isLeapYear() {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {//OR (division by 4 return remainder 0 and division by 100 do not return remainder 0) OR (division by 400 return remainder 0
			return true;
		}
		else {
			return false;
		}
	}
	bool isTrue(unsigned int days, unsigned int monthes, unsigned int years) {
		if (years >= 1 && years <= 2050) {
			if (isLeapYear() == 0 && (monthes == 2 && days >= 1 && days < 29)) {
				return 1;
			}
			else if (isLeapYear() != 0 && monthes == 2 && days >= 1 && days <= 29) {
				return 1;
			}
			else if ((monthes == 1 || monthes == 3 || monthes == 5 || monthes == 7 || monthes == 8 || monthes == 10 || monthes == 12) && (days >= 1 && days <= 31)) {
				return 1;
			}
			else if ((monthes == 2 || monthes == 4 || monthes == 6 || monthes == 9 || monthes == 11) && (days >= 1 && days <= 30)) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	void NeedZeroD(unsigned int d) {
		if (d < 10) {
			cout << "0";
		}
	}
	void NeedZeroM(unsigned int m) {
		if (m < 10) {
			cout << "0";
		}
	}
public:
	Date() {
		day = 1;
		month = 1;
		year = 1974;
	}
	void setDay(unsigned int d) {
		day = d;
	}
	void setMonth(unsigned int m) {
		month = m;
	}
	void setYear(unsigned int y) {
		year = y;
	}
	void coutDate() {
		if (isTrue(day, month, year) == 1) {
			short int i;
			cout << "In what format do you want to see the date?\ndd/mm/y - 1\ndd.mm.y - 2\nmm-dd-y - 3\n";
			cin >> i;
			cout << "Leap-year: " << isLeapYear() << endl;
			if ((isLeapYear() != 0 && day <= 29 && month == 2) || (isLeapYear() == 0 && day < 29 && month == 2) || month != 2) {
				if (i == 1) {
					NeedZeroD(day);
					cout << day << ".";

					NeedZeroM(month);
					cout << month << "." << year << endl;
				}
				else if (i == 2) {
					NeedZeroD(day);
					cout << day << "/";
					NeedZeroM(month);
					cout << month << "/" << year << endl;
				}
				else if (i == 3) {
					string lettmonth = "";
					switch (month) {
					case 1: lettmonth = "Jan"; break;
					case 2: lettmonth = "Feb"; break;
					case 3: lettmonth = "Mar"; break;
					case 4: lettmonth = "Apr"; break;
					case 5: lettmonth = "May"; break;
					case 6: lettmonth = "Jun"; break;
					case 7: lettmonth = "Jul"; break;
					case 8: lettmonth = "Aug"; break;
					case 9: lettmonth = "Sep"; break;
					case 10: lettmonth = "Oct"; break;
					case 11: lettmonth = "Nov"; break;
					case 12: lettmonth = "Dec"; break;
					}
					cout << day << "-" << lettmonth << "-" << year;
				}
			}
			else {
				cout << "Wrong way";
			}
		}
		else {
			cout << "Wrong date";
		}
	}
	~Date() { }
};
