#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace std;

int main(int argc, char** argv) {
	if(argc < 2) {cout << "\nThis is TERSY!\nFor help please type \n\n./tersy -help\n\n in your terminal :)\n" << endl; return 0;}
	else {
		if(!strcmp(argv[1], "-help")) cout << "\nTERSY has a few features to have fun with.\n1)type\n./tersy -zodiac\n and TERY will be your personal Guru.\n2)Type \n./tersy -shoplist\nAnd TERSY will help you in your shopping!\n :)" << endl;
		else if(!strcmp(argv[1], "-zodiac")) {cout << "Opening zodiac..."<< endl; sleep(1); string f = "./zod"; system(f.c_str());}
		else if(!strcmp(argv[1], "-shoplist")) {cout << "Opening shoplist..."<< endl;sleep(1); string f = "./SHOPLIST"; system(f.c_str());}
		else cout << "Please type -help for help!" << endl;
	}
	return 0;
}
