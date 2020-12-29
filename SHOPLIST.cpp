#include<string>
#include<iomanip>
#include<algorithm>
#include <ncurses.h>
using namespace std;
int i,size=1000,l; //q moved to string
string product,s, q;
char c,n='0';
class shoplist
{
	private:
		string name,type,quantity;
	public:
		// to show information
		void printdata(int i)
		{
			mvaddstr(i,0,name.c_str());
			mvaddstr(i,10,"|"); //addch() changed to mvaddstr because addch() takes only 2 arguments, 3 was provided
			mvaddstr(i,11,quantity.c_str());
			mvaddstr(i,14,"|");//addch() changed to mvaddstr
			mvaddstr(i,15,type.c_str());
			mvaddstr(i,25,"|");//addch() changed to mvaddstr
		}
		// to add two quantity
		void add(string x)
		{
			string some,qu=quantity;
			int a=0,carry=0,sum=0,diff=0,i,k=0;
			int len1=quantity.length(),len2=x.length();
			if(len1<len2)
			{
				qu=x;
				x=quantity;
				a=len1;
				len1=len2;
				len2=a;
			}
			diff=len1-len2;
			for(i=len2-1;i>=0;i--)
			{
				sum=x[i]-'0'+qu[i+diff]-'0'+carry;
				carry=sum/10;
				sum%=10;
				some[k]=sum+'0';
				k++;
			}
			for(i=diff-1;i>=0;i--)
			{
				sum=qu[i]-'0'+carry;
				carry=sum/10;
				sum%=10;
				some[k]=sum+'0';
				k++;
			}
			if(carry=1)
			{
				some[k]=sum+'0';
				k++;
			}
			for(i=0;i<k;i++)
			quantity[i]=some[k-i-1];
		}
		//read information
		void Read(string x)
		{
			char quantityChar[20]; //create char array for quantity
			char typeChar[20];//create char array for type
			name=x;
			printw("Enter the Quantity: ");
			getstr(quantityChar);
			printw("Enter the type: ");
			getstr(typeChar);
			//convert char array to string and assign them to string quantity and string type
			string str1(quantityChar);
			string str2(typeChar);
			
			quantity = quantityChar;
			type = typeChar;
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
};
bool cmp1(shoplist const &a, shoplist const &b)
{
	return (a.name < b.name);
}
bool cmp2(shoplist const &a, shoplist const &b)
{
	return (a.quantity < b.quantity);
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
		printw("In order to add item on the list - press 1\nPrint data - press 2,\nSort and print - press click 3\nRemove element on list - press 4,\nFind element on list - press 5\nIn order to exit - press 6\n\n");
		n = getch(); //getch(n) - wrong, getch() takes no arguments
		//for adding item in the list
		if(n=='1')
		{
			printw("\nEnter the product name: ");
			char productChar[20]; //create char array for product
			getstr(productChar);
			string str3(productChar); //convert char array to string
			product = productChar; //assign to product
			convert(product);
			for(i=0;i<k;i++)
			if(product==a[i].checkn())
			break;
			if(product!=a[i].checkn())
			{
				a[k].Read(product);
				k++;
				printw("\n\nItem added to the list!\n\nPress any key to continue..."); getch(); //Item added to the list!
			}
			else
			{
				printw("\nEnter the Quantity: ");
				char qChar[20]; //create char array for q
				getstr(qChar);
				string str4(qChar);//convert char array to string
				q = qChar;//assign to q
				
				a[i].add(q);
				printw("\n\nItem added to the list!\n\nPress any key to continue..."); getch(); //Item added to the list!
			}
		}
		// for showing date
		else if(n=='2')
		{
			refresh();
			if(k==0) {printw("\n\nNo items in the list..."); printw("\n\nPress any key to continue..."); getch();} //in case of no items
			for(i=0;i<k;i++)
			{
				clear();
				printw("%d|", i+1);
   				a[i].printdata(i);
   				printw("\n\nPress any key to continue...");
   				getch();
			}
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
			}
			for(i=0;i<k;i++)
			{
				clear();
				printw("%d|", i+1);
   				a[i].printdata(i);
   				printw("\n\nPress any key to continue...");
   				getch();
			}
			}
		}
		//for removing elemnt
		else if(n=='4')
		{
			if(k==0) {printw("\n\nNo items in the list..."); printw("\n\nPress any key to continue..."); getch();} //in case of no items
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
				for(i=0;i<k;i++)
				if(s==a[i].checkn())
				break;
				k--;
				for(;i<k;i++)
				{
					a[i].checkn()==a[i+1].checkn();
					a[i].checkt()==a[i+1].checkt();
					a[i].checkq()==a[i+1].checkq();
				}

			}
			else if(c=='2')
			{
				printw("\nEnter the product type: ");
				char sChar[20]; //create char array for s
				getstr(sChar);
				string str6(sChar); //convert char array to string
				s = sChar; //assign to s
				for(i=0;i<k;i++)
				if(s==a[i].checkt())
				{
	 				a[i].checkn()==a[i+1].checkn();
					a[i].checkt()==a[i+1].checkt();
					a[i].checkq()==a[i+1].checkq();
					i--;
					k--;
				}
			}
			else
			{
				printw("\nIncorrect charecter try again\n\n");
			}
		}
		//for finding elemet
		else if(n=='5')
		{
			printw("\nEnter the product name: ");
			char sChar[20]; //create char array for s
			getstr(sChar);
			string str7(sChar); //convert char array to string
			s = sChar; //assign to s
			for(i=0;i<k;i++)
			if(s==a[i].checkn())
			break;
   			a[i].printdata(i);
		}
		else
		{
			printw("\nIncorrect charecter try again\n\n");
		}
	}
	endwin();
}