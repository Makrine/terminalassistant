#include<string>
#include<iomanip>
#include<algorithm>
#include <ncurses.h>
#include <ctype.h>
using namespace std;
int i,size=1000,l; //q moved to string
string p,t,q,s;
char c,n='0',productChar[20],typeChar[20],quantityChar[20];
class shoplist
{
	private:
		string name,quantity,type;
	public:
		// to show information
		void printdata(int i)
		{
			mvaddstr(i,5,name.c_str());
			mvaddstr(i,15,"|"); //addch() changed to mvaddstr because addch() takes only 2 arguments, 3 was provided
			mvaddstr(i,16,quantity.c_str());
			mvaddstr(i,26,"|");//addch() changed to mvaddstr
			mvaddstr(i,27,type.c_str());
			mvaddstr(i,37,"|");//addch() changed to mvaddstr
		}
		// to add two quantity
		void add(string x)
		{
			int addstr;
			addstr=stoi(x)+stoi(quantity);
			quantity=to_string(addstr);
		}
		//read information
		void Read(string x,string y,string z)
		{
			name=x;
            quantity=y;
			type=z;
		}
		string checkn()
		{
			return name;
		}
		string checkq() //changed to string. it was int
		{
			return quantity;
		}
		string checkt()
		{
			return type;
		}
		//for sortig
		friend bool cmp1(shoplist const &a, shoplist const &b);
		friend bool cmp2(shoplist const &a, shoplist const &b);
		friend bool cmp3(shoplist const &a, shoplist const &b);
		friend void DeleteElement(int &sz, shoplist* arr, string n, string t);
};
bool cmp1(shoplist const &a, shoplist const &b)
{
	return (a.name < b.name);
}
bool cmp2(shoplist const &a, shoplist const &b)
{
	int qA = stoi(a.quantity);
	int qB = stoi(b.quantity);
	return (qA < qB);
}
bool cmp3(shoplist const &a, shoplist const &b)
{
	return (a.type < b.type);
}
void convert(string &x)
{
	int a=x.length();
    while(a--)
    {
    	if(x[a]>64 && x[a]<91)
    	x[a]+=32;
	}
}
void DeleteElement(int &sz, shoplist* arr, string n, string t) //function to delete an element.
{
	if(t=="0") 						//if type is 0 then it will take care of the name
	{
		int i;
		for(i=0;i<sz;i++)
		if(arr[i].name==n)
		break;
		if(i<sz)
		{
			sz--;
			for(int j=i;j<sz;j++)
			arr[j]=arr[j+1];
		}
	}
	if(n=="0")					//if name is 0 then it will take care of the name
	{
		int i;
		for(i=0;i<sz;i++)
		if(arr[i].type==t)
		break;
		if(i<sz)
		{
			sz--;
			for(int j=i;j<sz;j++)
			arr[j]=arr[j+1];
		}
	}
}
bool check(string x)
{
	int len=x.length();
	for(int i=0;i<len;i++)
	if(!isdigit(x[i]))
	return false;
	return true;
}
int main()
{
	shoplist a[size];
	initscr();
	printw("Hi this application helps you to manage your shopping list\nIn order to use this application you need to enter three things:\n\nName, Quantity and Type of that product\n\n");
	printw("Press any key to continue...");
	getch();
	int k=0;
	while(n!='6')
	{
		clear();
		printw("In order to add item on the list - press 1\nPrint data - press 2,\nSort and print - press 3\nRemove element on list - press 4,\nFind element on list - press 5\nIn order to exit - press 6\n\n");
		n = getch(); //getch(n) - wrong, getch() takes no arguments
		//for adding item in the list
		if(n=='1')
		{
			printw("\nEnter the product name: ");
			getstr(productChar);
			string str3(productChar); //convert char array to string
			p = productChar; //assign to product
			convert(p);
			for(i=0;i<k;i++)
			if(p==a[i].checkn())
			break;
			if(p!=a[i].checkn())
			{
				//create char array for quantity
				//create char array for type
				printw("Enter the Quantity: ");
				getstr(quantityChar);
				string str1(quantityChar);
				q=quantityChar;
				if(check(q))
				{
					printw("Enter the type: ");
					getstr(typeChar);
					//convert char array to string and assign them to string quantity and string type
					string str2(typeChar);
					t=typeChar;
					convert(t);
					a[k].Read(p,q,t);
					k++;
					printw("\n\nItem added to the list!\n\nPress any key to continue...");
					getch();
				}
				else
				{
					printw("\n\nyou must to add number to the Quantity!\n\nPress any key to continue..."); getch();
				}//Item added to the list!
			}
			else
			{
				printw("\nEnter the Quantity: ");
				getstr(quantityChar);
				string str4(quantityChar);//convert char array to string
				q=quantityChar;
				if(check(q))
				{
					a[i].add(q);
					printw("\n\nItem added to the list!\n\nPress any key to continue...");
                    getch(); //Item added to the list!
                }
                else
                {
					printw("\n\nyou must to add number to the Quantity!\n\nPress any key to continue..."); getch();
				}
			}
		}
		// for showing date
		else if(n=='2')
		{
			refresh();
			if(k==0) {printw("\n\nNo items in the list..."); printw("\n\nPress any key to continue..."); getch();} //in case of no items
			else {
			clear();
			for(i=0;i<k;i++)
			{
				printw("%d|", i+1);
   				a[i].printdata(i);
				printw("\n");
			}
   			printw("\n\nPress any key to continue...");
   			getch();}
		}
		// for sorting and showing data
		else if(n=='3')
		{
			if(k==0) {printw("\n\nNo items in the list..."); printw("\n\nPress any key to continue..."); getch();} //in case of no items
			else {
   			printw("\nIn order to sort by name on list click 1");
   			printw("\nIn order to sort by amount list click 2");
   			printw("\nIn order to sort by type list click 3\n\n");
      		c = getch();  //getch(c) - wrong, getch() takes no arguments
      		refresh();
   			if(c=='1')
   			sort(a,a+k,cmp1);
			else if(c=='2')
			sort(a,a+k,cmp2);
			else if(c=='3')
			sort(a,a+k,cmp3);
			else
			{
				printw("\nIncorrect charecter try again\n");
		   		printw("\n\nPress any key to continue...");
   				getch();
			}
			clear();
			for(i=0;i<k;i++)
			{
				printw("%d|", i+1);
   				a[i].printdata(i);
				printw("\n");
			}
   			printw("\n\nPress any key to continue...");
   			getch();
			}
		}
		//for removing elemnt
		else if(n=='4')
		{
			if(k==0)
			{
				printw("\n\nNo items in the list...");
				printw("\n\nPress any key to continue...");
				getch();
			} //in case of no items
			printw("\nIn order to remove element by name click 1");
			printw("\nIn order to remove elements by type click 2\n\n");
   			c = getch();  //getch(c) - wrong, getch() takes no arguments
			if(c=='1')
			{
				printw("\nEnter the product name: ");
    			char sChar[20]; //create char array for s
				getstr(sChar);
				string str5(sChar); //convert char array to string
				s = sChar; //assign to s
				DeleteElement(k, a, s, "0");
			}
			else if(c=='2')
			{
				printw("\nEnter the product type: ");
				char sChar[20]; //create char array for s
				getstr(sChar);
				string str6(sChar); //convert char array to string
				s = sChar; //assign to s
				DeleteElement(k, a, "0", s);

			}
			else
			{
				printw("\nIncorrect charecter try again\n\n");
	   			printw("\n\nPress any key to continue...");
   				getch();
			}
		}
		//for finding elemet
		else if(n=='5')
		{
			bool flag = true;
			printw("\nEnter the product name: ");
			char sChar[20]; //create char array for s
			getstr(sChar);
			string str7(sChar); //convert char array to string
			s = sChar; //assign to s
			clear();
			for(i=0;i<k;i++)
			{
				if(s==a[i].checkn())
				break;
			}
			if(k == 0 || i == k) {
				flag = false;
				printw("Item was not found :(");
				printw("\n\nPress any key to continue...");
				getch();
			}
			if(flag) {
   				a[i].printdata(i);
   				printw("\n\nPress any key to continue...");
   				getch();
   			}
		}
		else if(n == '6')
		{
			delwin(stdscr);
			endwin();
			refresh();
		}
		else
		{
			printw("\nIncorrect charecter try again\n\n");
   			printw("\n\nPress any key to continue...");
   			getch();
		}
 	}
	endwin();
}
