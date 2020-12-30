*******************************************************************
* TERSY is created by Misha Makharadze and Makrine Tskipurishvili *
*******************************************************************

TERSY - Mini Terminal Assistant is a friendly assistant which works in your terminal and helps you 
with various things such as shopping and lets you know about your Zodiac signs.

Tersy is made with Ncurses library.

Features of Tersy:
Manage your shopping list
Get your astrological information

The shopping list feature lets you enter the items you plan to buy to help you with your shopping. The item information includes
* Name
* Quantity
* Type

You can add, delete and sort the items.
The above feature uses an OOP approach.

The astrological feature provides you information about your astrological profile including your Western zodiac sign, your Eastern zodiac sign and your life path number. 
In this feature you can add, delete and sort the data of users by alphabetical order.
The user data contains:
* First Name
* Last Name
* Birthdate
The above feature uses an OOP approach.


In order to use the particular feature the main file “tersy” is executed in the terminal and the either of the following arguments are added
-shopping
-zodiac
In case of needing any help the following command is entered:

./tersy -help 

HOW TO USE:

After downloading all the project files:

1) Compile tersy.cpp
2) Compile SHOPPING.cpp and zod.cpp using -lncurses
3) Run ./tersy
4) Don't forget to enjoy :)
