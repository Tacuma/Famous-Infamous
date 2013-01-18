//Tacuma Solomon
//Computer Science III
//Famous and Infamous - Computer guesses player's famous or infamous person
//Node definition - represents node that stores a question in a binary tree

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Game.h"
using namespace std;

void DisplayInstructions();
void Footer();

int main()
{
	char again;
	DisplayInstructions();
	do
	{
		Game famousInfamous;
		ifstream profile;
		string	file;
		string file2;
		char cCurrentPath[FILENAME_MAX];
		ostringstream fPath;
		string profiles = "\\Profiles";

		// Sets up the file input
		fPath << cCurrentPath << profiles;
		profiles = fPath.str();	
		cout << "Existing game profiles" << endl;
		cout << "--------------------------------------------" << endl;
		system("dir Profiles\\");
		cout << endl;
		cout << "Please enter the name of a game to load (e.g. game1): ";
		cin >> file;
		file2 = "Profiles/" + file;
		profile.open(file2.c_str());

		if(!profile)
		{
			cout << "No existing game with that name was found" << endl;
			cout << "The game \"" << file << "\" has been created!" 
						 << endl << endl << endl;
		}

		else // Load (restore) game from file
		{
			famousInfamous.Load(profile); //Passes the input stream into the function
		}

		famousInfamous.Play();
		cout << endl << "Play again? (y/n): ";
		cin >> again;
		//Saves the game to a file
		famousInfamous.Save(file2);
		cout << endl << endl;
	} while (again == 'y');
	Footer();
	system("pause");	
	return 0;
}


//displays instructions
void DisplayInstructions()
{
	cout << "\tWelcome to Famous and Infamous";
	cout << endl << endl;
	cout << "Think of a famous or infamous person ";
	cout <<"and I'll try to guess his or her name.";
	cout << endl << endl;
}


void Footer()
{
	cout << endl << endl;
	cout << "() Code by Tacuma Solomon " << endl;
	cout << "() Not for Redistribution or Reuse." << endl << endl;
}

/*
         Welcome to Famous and Infamous

Think of a famous or infamous person and I'll try to guess his or her name.

Existing game profiles
--------------------------------------------
 Volume in drive C has no label.
 Volume Serial Number is 82E8-827B

 Directory of C:\Users\TaKuma\Documents\Visual Studio 2012\Projects\famous-infam
ous\famous-infamous\Profiles

01/16/2013  02:46 PM    <DIR>          .
01/16/2013  02:46 PM    <DIR>          ..
01/16/2013  02:46 PM               187 d
01/16/2013  03:12 PM               440 game1
01/16/2013  03:07 PM                94 game2
01/16/2013  03:08 PM               231 game3
               4 File(s)            952 bytes
               2 Dir(s)  140,508,839,936 bytes free

Please enter the name of a game to load (e.g. game1): game1
Is/was the person real? (y/n): n
Is he Blue and Fast? (y/n): y
Are you thinking of Sonic The Hedgehog? (y/n): y
I guessed it!


Play again? (y/n): y


Existing game profiles
--------------------------------------------
 Volume in drive C has no label.
 Volume Serial Number is 82E8-827B

 Directory of C:\Users\TaKuma\Documents\Visual Studio 2012\Projects\famous-infam
ous\famous-infamous\Profiles

01/16/2013  02:46 PM    <DIR>          .
01/16/2013  02:46 PM    <DIR>          ..
01/16/2013  02:46 PM               187 d
01/16/2013  03:13 PM               440 game1
01/16/2013  03:07 PM                94 game2
01/16/2013  03:08 PM               231 game3
               4 File(s)            952 bytes
               2 Dir(s)  140,507,787,264 bytes free

Please enter the name of a game to load (e.g. game1): game2
Is/was the person real? (y/n): y
Are you thinking of Gandhi? (y/n): y
I guessed it!


Play again? (y/n): n




() Code by Tacuma Solomon
() Not for Redistribution or Reuse.

Press any key to continue . . .
*/