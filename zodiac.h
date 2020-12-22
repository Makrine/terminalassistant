#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctype.h>
using namespace std;


bool cmp(const class ZODIAC&, const class ZODIAC&);


class ZODIAC {
private:
	string name, surname, birthdate;
	int dd, mm, yyyy;
	
public:
	friend bool cmp(const class ZODIAC&, const class ZODIAC&);
	friend class PEOPLE;
	
	string GetCurrent() {
		string current = "";
		current += " " + name;
		for(int i=name.length()+2; i<=21; i++) {
			current += " ";
		}
		current += surname;
		for(int i=surname.length()+22; i<=48; i++) {
			current += " ";
		}
		current += birthdate;
		
		return current;
	}
	void BlankFile(string filename) {
		ofstream myfile;
		myfile.open(filename);
		myfile << " Name" << "                " << "Surname" << "                    " << "Birthdate" << endl;
		myfile << "_________________________________________________________________" << endl;
	}
	void PrintToFile(string filename) {
		ofstream myfile;
		myfile.open(filename, ios_base::app);
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
	bool CheckNameSurname(string nm) {bool flag = true; int len=nm.size(); for(int i=0; i <len; i++) if(isalpha(nm[i])) flag = true; else {flag=false; break;} if(nm=="") flag=false; return flag;}
	bool CheckDate(string bd) {
		bool flag=true;
		if(bd=="") flag = false;
		if(isdigit(bd[0]) &&
		isdigit(bd[1]) && 
		isdigit(bd[3]) &&
		isdigit(bd[4]) &&
		isdigit(bd[6]) &&
		isdigit(bd[7]) &&
		isdigit(bd[8]) &&
		isdigit(bd[9]) &&
		bd[2] == '/' && bd[5] == '/'
		) flag =true;
		else flag = false;
		return flag;
	}
	void SetName(string nm) {name = nm;}
	void SetSurname(string snm) {surname = snm;}
	void SetBirthdate(string bd) {birthdate = bd;}
	string GetName() {return name;}
	string GetSurname() {return surname;}
	string GetBirthdate() {return birthdate;}
	void Birthdate(string bd) {
		string s_dd = bd.substr(0,2);
		string s_mm = bd.substr(3,2);
		string s_yyyy = bd.substr(6,4);
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
	string GetSunSign(string bd) {
		Birthdate(bd);
		if((dd >= 21 && dd <= 31 && mm == 3) || (dd >= 1 && dd <= 19 && mm == 4)) return "Aries";
		else if((dd >= 20 && dd <= 30 && mm == 4) || (dd >= 1 && dd <= 20 && mm == 5)) return "Taurus";
		else if((dd >= 21 && dd <= 31 && mm == 5) || (dd >= 1 && dd <= 20 && mm == 6)) return "Gemini";
		else if((dd >= 21 && dd <= 30 && mm == 6) || (dd >= 1 && dd <= 22 && mm == 7)) return "Cancer";
		else if((dd >= 23 && dd <= 31 && mm == 7) || (dd >= 1 && dd <= 22 && mm == 8)) return "Leo";
		else if((dd >= 23 && dd <= 30 && mm == 8) || (dd >= 1 && dd <= 22 && mm == 9)) return "Virgo";
		else if((dd >= 23 && dd <= 31 && mm == 9) || (dd >= 1 && dd <= 22 && mm == 10)) return "Libra";
		else if((dd >= 23 && dd <= 30 && mm == 10) || (dd >= 1 && dd <= 21 && mm == 11)) return "Scorpio";
		else if((dd >= 22 && dd <= 31 && mm == 11) || (dd >= 1 && dd <= 21 && mm == 12)) return "Sagittarius";
		else if((dd >= 22 && dd <= 30 && mm == 12) || (dd >= 1 && dd <= 19 && mm == 1)) return "Capricorn";
		else if((dd >= 20 && dd <= 31 && mm == 1) || (dd >= 1 && dd <= 18 && mm == 2)) return "Aquarius";
		else if((dd >= 19 && dd <= 29 && mm == 2) || (dd >= 1 && dd <= 20 && mm == 3)) return "Pisces";
		return "ERROR";
	}
	string GetChineseSign(string bd) {
		Birthdate(bd);
		string ChSign;
		switch((yyyy-1912)%12) {
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
		return ChSign;
	}
	int GetLifePathNumber(string bd) {
		Birthdate(bd);
		int num, a, b, c, e;
		num = dd+mm+yyyy;
		while(num/10 >= 1) {
			a = num/1000;
			num = num - a*1000;
			b = num/100;
			num = num - b*100;
			c = num/10;
			num = num - c*10;
			e = num;
			num = a + b + c + e;
		}
		return num;
	}



};

bool cmp(const class ZODIAC& p, const class ZODIAC& q) {
	if(p.name == q.name) return(p.surname < q.surname);
	else return (p.name < q.name);
}

class PEOPLE {
private:
	class ZODIAC* list;
	int size; //size of ZODIAC* list
public:

	void SetSize(string filename) {int n = GetNumOfUsers(filename); list = new class ZODIAC[n];}
	void FileToList(string filename) {
		ifstream file(filename);
		int c = 0, i = 0, j = 0;
		string words[3], line;
		for(;getline(file, line);) {
			c++;
			if(c<3) continue;
			else if(line[1] == ' ') continue;
			else {
				j = 0;
				stringstream iss(line);
				while(iss >> words[j++]);
				list[i].SetName(words[0]);
				list[i].SetSurname(words[1]);
				list[i].SetBirthdate(words[2]);
			}
			i++;
		}
	}
	int GetNumOfUsers(string filename) {
		string line;
		size = 0;
		ifstream file(filename);
		while(getline(file, line)) size++;
		size = size - 2;
		return size;
	}
	void Sort() {sort(list, list+size, cmp);}
	void PrintToFile(string filename) {list->BlankFile(filename); for(int i=0; i <size; i++) list[i].PrintToFile(filename);}
};
