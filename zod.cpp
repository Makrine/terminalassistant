#include <ncurses.h>
#include "zodiac.h"
#include <cstring>

// source https://stackoverflow.com/questions/22399406/drawing-boxes-using-ncurses/22399551 FOR THE FRAME

	ZODIAC A;
	PEOPLE B;

void menu(char* filename);
void currentUser(class ZODIAC& A);
void input(char* filename);
void PrintFile(char* filename) {
	string line;
	ifstream file(filename);
	for(int i=0;getline(file, line);i++) mvprintw(i, 0, "%s", line.c_str());
}
void removeLine(char* filename) {

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


void choice1(char* filename) {
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
	menu(filename);
}
void choice2(char* filename) {
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
	menu(filename);
}
void choice3(char* filename) {
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
	menu(filename);
}
void choice4(char* filename) {
	clear();
	noecho();
	curs_set(0);
	PrintFile(filename);
	printw("\n\nPress any key to go to menu...");
	getch();
	menu(filename);
}
void choice5(char* filename) {
	clear();
	skeleton();
	currentUser(A);
	
	A.BlankFile(filename);

	noecho();
	curs_set(0);
	mvprintw(8, 22, "User Data has been REMOVED");
	mvprintw(10, 22, "Press Any Key to go back to menu...");
	getch();
	input(filename);
}
void choice6(char* filename) {
	clear();
	skeleton();
	currentUser(A);
	
	removeLine(filename);

	noecho();
	curs_set(0);
	mvprintw(8, 22, "User: %s %s %s is REMOVED from database", A.GetName().c_str(), A.GetSurname().c_str(), A.GetBirthdate().c_str());
	mvprintw(10, 22, "Press Any Key to go back to menu...");
	getch();
	input(filename);

}
void choice7(char* filename) {
	clear();
	skeleton();
	currentUser(A);
	
	input(filename);
	menu(filename);

}

void choice8() {
/*	system("clear");
	exit(0);
*/
	endwin();
	refresh();
}
void choice(char* filename) {
	echo();
	curs_set(1);
	move(35, 1);
	int ch;
	ch = getch();
	getch();
	
	switch(ch) {
		case '1':
			choice1(filename);
			break;
		case '2':
			choice2(filename);
			break;
		case '3':
			choice3(filename);
			break;
		case '4':
			choice4(filename);
			break;
		case '5':
			choice5(filename);
			break;
		case '6':
			choice6(filename);
			break;
		case '7':
			choice7(filename);
			break;
		case '8':
			choice8();
			break;
	}

}
void menu(char* filename) {
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
	choice(filename);
}
void Check(char* filename, char* name, char* surname, char* birthdate) {
	bool flag = true;
	if(A.CheckNameSurname(name)) A.SetName(name);
	else {mvprintw(13, 16, "Invalid Name!"); flag=false;}
	if(A.CheckNameSurname(surname)) A.SetSurname(surname);
	else {mvprintw(14, 16, "Invalid Surname!"); flag=false;}
	if(A.CheckDate(birthdate)) A.SetBirthdate(birthdate);
	else {mvprintw(15, 16, "Invalid Birthdate!"); flag=false;}
	
	if(!flag) {mvprintw(20, 55, "Enter any key to input data again..."); getch(); input(filename);}
}
void input(char* filename) {
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
	Check(filename, name, surname, birthdate);
	A.PrintToFile(filename);

	//sorting starts
	B.SetSize(filename);
	B.FileToList(filename);
	B.Sort();
	B.PrintToFile(filename);
	//sorting ends
	menu(filename);

}

void currentUser(class ZODIAC& A) {
	mvprintw(6, 22, "NAME: %s\t\tSURNAME: %s\t\tBIRTHDATE: %s", A.GetName().c_str(), A.GetSurname().c_str(), A.GetBirthdate().c_str());
}

int main()
{

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

	input(filename);

	menu(filename);

	endwin();			/* End curses mode		  */

	return 0;
}
