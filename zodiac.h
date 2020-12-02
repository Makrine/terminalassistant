//ბევრი რამეა დასარედაქტირებელი აქაც და Zodiac.cpp-შიც
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

class ZODIAC {
private:
	string name, surname, birthdate;
	string s_dd, s_mm, s_yyyy;
	int dd, mm, yyyy;
	string sign, ChSign;
	int LPN; //life path number
public:
	void ShowFirstPage() {
		cout << "Welcome to the Zodiac page. Here you can calculate your Sun sign, Chinese zodiac sign, life path number and see information about each of them :) \n"
			"Please enter the following information. This information will be saved and you can use it for all options of this Zodiac page :)" << endl << endl;
		ReadInfo();
		cout << "Please choose and type the corresponding digit of the menu :)" << endl << endl;
		cout << "1. Your Sun sign\n2. Your Chinese zodiac sign\n3. Your Life Path Number\n4. See user data\n5. Enter new information\n6. Delete user data\n7. Exit"<< endl << endl;

		Choice();
	}
	void Choice() {
		int choice;
		cin >> choice;
		if(choice == 1) Choice1();
		else if(choice == 2) Choice2();
		else if(choice == 3) Choice3();
		else if(choice == 4) Choice4();
		else if(choice == 5) Choice5();
		else if(choice == 6) Choice6();
/*		else if(choice == 7) Choice7();

*/
	}
	void Choice1() {PrintSign(); cout << "Choose another digit from the menu..." << endl; Choice();}
	void Choice2() {PrintChSign(); cout << "Choose another digit from the menu..." << endl; Choice();}
	void Choice3() {PrintLPN(); cout << "Choose another digit from the menu..." << endl; Choice();}
	void Choice4() {PrintFileToConsole(); Choice();}
	void Choice5() {ReadInfo(); Choice();}
	void Choice6() {BlankFile(); ReadInfo(); Choice();}
	void ReadInfo() {cout << "NAME: "; cin >> name; cout << "SURNAME: "; cin >> surname; cout << "BIRTHDATE(dd/mm/yyyy): "; cin >> birthdate; cout << endl; PrintToFile();}
/*	void Print() {
		cout << " Name" << "                " << "Surname" << "                    " << "Birthdate" << "                " << "Sign " << endl;
		cout << "__________________________________________________________________________________" << endl << endl;
		cout << " " << name;
		for(int i=name.length()+2; i<=21; i++) {
			cout << " ";
		}
		cout << surname;
		for(int i=surname.length()+22; i<=48; i++) {
			cout << " ";
		}
		cout << birthdate << "               " << sign << endl;
	}
*/
	void BlankFile() {
		ofstream myfile;
		myfile.open("data.txt");
		myfile << " Name" << "                " << "Surname" << "                    " << "Birthdate" << endl;
		myfile << "_________________________________________________________________" << endl << endl;
	}

	void PrintToFile() {
		ofstream myfile;
		myfile.open("data.txt", ios_base::app);
		myfile << " " << name;
		for(int i=name.length()+2; i<=21; i++) {
			myfile << " ";
		}
		myfile << surname;
		for(int i=surname.length()+22; i<=48; i++) {
			myfile << " ";
		}
		myfile << birthdate << endl;
		myfile.close();
	}
	string GetBirthdate() {return birthdate;}
	void Birthdate(string birthdate) {
			s_dd = birthdate.substr(0,2);
			s_mm = birthdate.substr(3,2);
			s_yyyy = birthdate.substr(6,4);

			int a, b, c, d;
			a = s_dd[0] - '0';
			b = s_dd[1] - '0';
			dd = a*10 + b;

			a = s_mm[0] - '0';
			b = s_mm[1] - '0';
			mm = a*10 + b;

			a = s_yyyy[0] - '0';
			b = s_yyyy[1] - '0';
			c = s_yyyy[2] - '0';
			d = s_yyyy[3] - '0';
			yyyy = a*1000 + b*100 + c*10 + d;
	}
	void GetSign() {
		Birthdate(birthdate);
//		CheckInput(name, surname, birthdate);
		if((dd >= 21 && dd <= 31 && mm == 3) || (dd >= 1 && dd <= 19 && mm == 4)) sign = "Aries";
		else if((dd >= 20 && dd <= 30 && mm == 4) || (dd >= 1 && dd <= 20 && mm == 5)) sign = "Taurus";
		else if((dd >= 21 && dd <= 31 && mm == 5) || (dd >= 1 && dd <= 20 && mm == 6)) sign = "Gemini";
		else if((dd >= 21 && dd <= 30 && mm == 6) || (dd >= 1 && dd <= 22 && mm == 7)) sign = "Cancer";
		else if((dd >= 23 && dd <= 31 && mm == 7) || (dd >= 1 && dd <= 22 && mm == 8)) sign = "Leo";
		else if((dd >= 23 && dd <= 30 && mm == 8) || (dd >= 1 && dd <= 22 && mm == 9)) sign = "Virgo";
		else if((dd >= 23 && dd <= 31 && mm == 9) || (dd >= 1 && dd <= 22 && mm == 10)) sign = "Libra";
		else if((dd >= 23 && dd <= 30 && mm == 10) || (dd >= 1 && dd <= 21 && mm == 11)) sign = "Scorpio";
		else if((dd >= 22 && dd <= 31 && mm == 11) || (dd >= 1 && dd <= 21 && mm == 12)) sign = "Sagittarius";
		else if((dd >= 22 && dd <= 30 && mm == 12) || (dd >= 1 && dd <= 19 && mm == 1)) sign = "Capricorn";
		else if((dd >= 20 && dd <= 31 && mm == 1) || (dd >= 1 && dd <= 18 && mm == 2)) sign = "Aquarius";
		else if((dd >= 19 && dd <= 29 && mm == 2) || (dd >= 1 && dd <= 20 && mm == 3)) sign = "Pisces";
	}
	void GetChSign() {
		Birthdate(birthdate);
		switch((yyyy-1936)%12) {
			case 0:
				ChSign = "Rat";
				break;
			case 1:
				ChSign = "Ox";
				break;
			case 2:
				ChSign = "Tiger";
				break;
			case 3:
				ChSign = "Rabbit";
				break;
			case 4:
				ChSign = "Dragon";
				break;
			case 5:
				ChSign = "Snake";
				break;
			case 6:
				ChSign = "Horse";
				break;
			case 7:
				ChSign = "Goat";
				break;
			case 8:
				ChSign = "Monkey";
				break;
			case 9:
				ChSign = "Rooster";
				break;
			case 10:
				ChSign = "Dog";
				break;
			case 11:
				ChSign = "Pig";
				break;
		}
	}
	void GetLPN() {
		Birthdate(birthdate);
		int num, a, b, c, d;
		num = dd+mm+yyyy;
		while(num/10 >= 1) {
			a = num/1000;
			num = num - a*1000;
			b = num/100;
			num = num - b*100;
			c = num/10;
			num = num - c*10;
			d = num;
			num = a + b + c + d;
		}
		LPN = num;
	}
	void Pr() {cout << dd << " " << mm << " " << yyyy << endl;}
	void PrintSign() {GetSign(); cout << "You are " << sign << "! :)" << endl;}
	void PrintLPN() {GetLPN(); cout << "Your Life Path Number is " << LPN << "! :)" << endl;}
	void PrintChSign() {GetChSign(); cout << "You are " << ChSign << "! :)" << endl;}
	void PrintFileToConsole() {
		ifstream myfile("data.txt");
		string str;
		while(!myfile.eof()) {
			getline(myfile, str);
			cout << str << endl;
		}
	}
/*
	void CheckInput(string name, string surname, string birthdate) {
		int len_name = name.length();
		int len_surname = surname.length();
		for(int i=0; i < len_name; i++) {if(!isalpha(toupper(name[i]))) {cout << "Please enter a valid name.." << endl;ReadName();}}
		for(int i=0; i < len_surname; i++) {if(!isalpha(toupper(surname[i]))) {cout << "Please enter a valid surname.." << endl;ReadSurname();}}
	}
*/
};
