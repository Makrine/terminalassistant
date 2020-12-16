#include <ncurses.h>
#include "zodiac.h"
#include <cstring>

// source https://stackoverflow.com/questions/22399406/drawing-boxes-using-ncurses/22399551 FOR THE FRAME


void removeLine(char* filename, class ZODIAC& A);
void FRAME(int y1, int x1, int y2, int x2);
void skeleton();
void choice1(char* filename, class ZODIAC& A);
void choice2(char* filename, class ZODIAC& A);
void choice3(char* filename, class ZODIAC& A);
void choice4(char* filename, class ZODIAC& A);
void choice5(char* filename, class ZODIAC& A);
void choice6(char* filename, class ZODIAC& A);
void choice7(char* filename, class ZODIAC& A);
void choice8(char* filename, class ZODIAC& A);
void choice(char* filename, class ZODIAC& A);
void menu(char* filename, class ZODIAC& A);
void currentUser(class ZODIAC& A);
void input(char* filename, class ZODIAC& A);


void removeLine(char* filename, class ZODIAC& A) {

	string target = A.GetCurrent();
	string line;
	ifstream myfile;
	myfile.open(filename);
	ofstream temp;
	temp.open("temp.txt");

	while(getline(myfile,line)) {
		if(line == target) continue;
		else temp << line << endl;
	}

	temp.close();
	myfile.close();
	remove(filename);
	rename("temp.txt",filename);
}


void FRAME(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void skeleton() {
	FRAME(5, 20, 30, 120);
	FRAME(4, 18, 31, 122);
	mvprintw(2, 62, "WELCOME TO ZODIAC!");
}


void choice1(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	char sign[15];
	strcpy(sign, A.GetSunSign(A.GetBirthdate()).c_str());
	mvprintw(8, 22, "You are a %s! :)", sign);
	
	noecho();
	curs_set(0);
	mvprintw(10, 22, "Press any key to go back to menu...");
	getch();
	menu(filename, A);
}
void choice2(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	char sign[15];
	strcpy(sign, A.GetChineseSign(A.GetBirthdate()).c_str());
	mvprintw(8, 22, "You are a %s! :)", sign);
	
	noecho();
	curs_set(0);
	mvprintw(10, 22, "Press any key to go back to menu...");
	getch();
	menu(filename, A);
}
void choice3(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	int num;
	num = A.GetLifePathNumber(A.GetBirthdate());
	mvprintw(8, 22, "Your Life Path Number is %d! :)", num);
	
	noecho();
	curs_set(0);
	mvprintw(10, 22, "Press any key to go back to menu...");
	getch();
	menu(filename, A);
}
void choice4(char* filename, class ZODIAC& A) {
//TODO
}
void choice5(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	
	A.BlankFile(filename);

	noecho();
	curs_set(0);
	mvprintw(8, 22, "User Data has been REMOVED");
	mvprintw(10, 22, "Press Any Key to go back to menu...");
	getch();
	input(filename, A);
}
void choice6(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	
	removeLine(filename, A);

	noecho();
	curs_set(0);
	mvprintw(8, 22, "User: %s %s %s is REMOVED from database", A.GetName().c_str(), A.GetSurname().c_str(), A.GetBirthdate().c_str());
	mvprintw(10, 22, "Press Any Key to go back to menu...");
	getch();
	input(filename, A);

}
void choice7(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	
	input(filename, A);
	menu(filename, A);

}
void choice8(char* filename, class ZODIAC& A) {
//TODO
}
void choice(char* filename, class ZODIAC& A) {
	echo();
	curs_set(1);
	move(0, 0);
	int ch;
	ch = getch();
	getch();
	
	switch(ch) {
		case '1':
			choice1(filename, A);
			break;
		case '2':
			choice2(filename, A);
			break;
		case '3':
			choice3(filename, A);
			break;
		case '4':
			choice4(filename, A);
			break;
		case '5':
			choice5(filename, A);
			break;
		case '6':
			choice6(filename, A);
			break;
		case '7':
			choice7(filename, A);
			break;
		case '8':
			choice8(filename, A);
			break;
	}

}
void menu(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	currentUser(A);
	
	mvprintw(7.5, 22, "Choose and type the corresponding digit :)");
	mvprintw(8, 22, "1. Your Sun Sign");
	mvprintw(9, 22, "2. Your Chinese Sign");
	mvprintw(10, 22, "3. Your Life Path Number");
	mvprintw(11, 22, "4. See User Data");
	mvprintw(12, 22, "5. Delete User Data");
	mvprintw(13, 22, "6. Delete Current Data");
	mvprintw(14, 22, "7. Enter New Data");
	mvprintw(15, 22, "8. Exit");
	
	choice(filename, A);
}

void input(char* filename, class ZODIAC& A) {
	clear();
	skeleton();
	char name[20];
	char surname[30];
	char birthdate[12];
	mvprintw(6, 22, "Please, enter your name, surname and a date of birth in order to continue. Your data will be saved");
	mvprintw(7,22, "to the file you indicated above.");
	echo();
	curs_set(1);
	mvprintw(13, 55, "NAME: ");
	getstr(name);
	
	
	mvprintw(14, 55, "SURNAME: ");
	getstr(surname);

	mvprintw(15, 55, "BIRTHDATE (dd/mm/yyyy): ");
	mvprintw(16, 60, "(ex: 28/07/2000)");
	move(15, 79);
	getstr(birthdate);

	A.SetName(name);
	A.SetSurname(surname);
	A.SetBirthdate(birthdate);
	
	A.PrintToFile(filename);
	menu(filename, A);

}

void currentUser(class ZODIAC& A) {
	mvprintw(6, 22, "NAME: %s\t\tSURNAME: %s\t\tBIRTHDATE: %s", A.GetName().c_str(), A.GetSurname().c_str(), A.GetBirthdate().c_str());
}
int main()
{
	ZODIAC A;
	PEOPLE B;
	initscr();			/* Start curses mode 		  */	
	char name[20];
	char surname[30];
	char birthdate[12];		
	char filename[50];
	skeleton();
	
	mvprintw(6, 22, "Please enter a name for the database file: ");
	getstr(filename);
	char txt[5] = ".txt";
	strcat(filename, txt);
	
	
	A.BlankFile(filename);

	input(filename, A);

	menu(filename, A);

	endwin();			/* End curses mode		  */

	return 0;
}
