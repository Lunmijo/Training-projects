#pragma once
#include <iostream>
#include <string>
using namespace std;
const int with_dot = 1;
const int with_hyphen = 2;
const int with_slash = 3;

class Date {
private:
	unsigned int day, year, month;
	string date;
	bool isTrueDate(unsigned int days, unsigned int monthes, unsigned int years) {
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
	string NeedZero(unsigned int m) {
		if (m < 10) {
			return "0";
		}
		else {
			return "";
		}
	}
public:
	bool isLeapYear() const {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {//OR (division by 4 return remainder 0 and division by 100 do not return remainder 0) OR (division by 400 return remainder 0
			return true;
		}
		else {
			return false;
		}
	}
	Date() {
		day = 1;
		month = 1;
		year = 1974;
	}
	Date(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
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
	string getDate(int i) {
		string hyphen = "-", dot = ".", slash = "/";
		if (isTrueDate(day, month, year) == 1) {
			if ((isLeapYear() != 0 && day <= 29 && month == 2) || (isLeapYear() == 0 && day < 29 && month == 2) || month != 2) {
				if (i == with_dot) {
					string isZero = NeedZero(day);
					date = isZero;
					date += to_string(day);
					date += dot;

					isZero = NeedZero(month);
					date += isZero;
					date += to_string(month);
					date += dot;
					date += to_string(year);
					return date;
				}
				else if (i == with_hyphen) {
					string isZero = NeedZero(day);
					
					date = isZero;
					date += to_string(day);
					date += dot;

					isZero = NeedZero(month);
					date += isZero;
					date += to_string(month);
					date += dot;
					date += to_string(year);
					return date;
				}
				else if (i == with_slash) {
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
					date = to_string(day);
					date += slash;
					date += lettmonth;
					date += slash;
					date += to_string(year);
					return date;
				}
			}
			else {
				return "Wrong way";
			}
		}
		else {
			return "Wrong date";
		}
	}
	~Date() { }
};
