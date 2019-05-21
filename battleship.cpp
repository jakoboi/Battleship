//Jakob Zhang
//Battleship project

#include<iostream>//io
#include<Windows.h>//for sleep
#include<ctime>//time
#include<cstdlib>//various things
#include<string>//string

using namespace std;
int player[8][8], comp[8][8];//grids
int num_ships, comp_ships, user_ships;//number of ships, number of ships left, number of ships left
int turns = 0;//turns played
int w, x, y, z;//these change often, are just placeholders for loops and such
string a, user_bombs;//input for ships, input for bombs
bool game_end;//control the ending of the game

// 0=empty, 1=boat, 2=miss, 3=hit
//system cls resets screen

void gen()//generates computer positions
{
	srand(time(NULL));
	for (int z = 0; z < num_ships; z++)//num_ships comes from somewhere else
	{
		y = rand() % 8;
		x = rand() % 8;
		if (comp[x][y] != 1)
		{
			comp[x][y] = 1;//1 is with a ship in this case
		}
		else
		{
			--z;
		}
	}
}

void ships()//creates ships
{
	while (true)
	{
		cout << "How many ships would you like to play with? Max of 8, minimum of 1" << endl;
		cin >> num_ships;
		user_ships = num_ships;
		comp_ships = num_ships;
		if ((num_ships <= 8) && (num_ships >= 1))//validates and exits if true
		{
			break;
		}
		else
		{
			exit(0);//causes to quit program is the number is not good
		}
	}
}

void grid()//sets array to 0
{
	int player[8][8] = { 0 }, comp[8][8] = { 0 };
}

void grid_cout()
{
	system("CLS");
	cout << "Player" << endl;
	for (x = 0; x < 8; x++)
	{
		cout << (x + 1) << "    ";
		for (y = 0; y < 8; y++)
		{
			if (player[y][x] == 0)//i know im supposed to use a switch here but it gave me errors (cant use variable in array) so i used if statements
			{
				cout << ".    ";
			}
			else if (player[y][x] == 1)
			{
				cout << "S    ";
			}
			else if (player[y][x] == 2)
			{
				cout << "M    ";
			}
			else if (player[y][x] == 3)
			{
				cout << "H    ";
			}
			else
			{
				cout << 'e' << " ";
			}
		}
		cout << endl << endl;
	}
	
	
	char rows;
	rows = 'A';
	cout << "     ";
	for (rows = 'A'; rows <= 'H'; rows++)
	{
		cout << rows << "    ";
	}
	cout << endl;
	
	
	cout << "Computer" << endl;//computer
	for (x = 0; x < 8; x++)
	{
		cout << (x + 1) << "    ";
		for (y = 0; y < 8; y++)
		{
			if (comp[y][x] == 0 || comp[y][x] == 1)
			{
				cout << ".    ";
			}
			else if (comp[y][x] == 2)
			{
				cout << "M    ";
			}
			else if (comp[y][x] == 3)
			{
				cout << "H    ";
			}
			else
			{
				cout << 'e' << " ";
			}
		}
		cout << endl << endl;
	}
	cout << "     ";
	for (rows = 'A'; rows <= 'H' ; rows++)
	{
		cout << rows << "    ";
	}
	cout << endl;
} 

void user_input()
{
	for (int z = 0; z < num_ships; z++)//num_ships comes from somewhere else
	{
		if (z == 0)
		{
			cout << "ex: A1 (use this for all future inputs)\nThe grid is 8 x 8 and ships are 1 x 1" << endl;
		}
		cout << "Please enter the positions of ship " << (z + 1) << ": ";
		cin >> a;
		x = (a[0]) - 65;//removes 65 from ascii value
		y = (a[1]) - 49;//because its in a string its stored as an ascii so you must remove 49
		if ((x >= 0) && (x < 8) && (y >= 0) && (y < 8) && (a.size() == 2))
		{
			if (player[x][y] != 1)
			{
				player[x][y] = 1;//1 is with a ship in this case
			}
			else
			{
				cout << "Sorry, that input was invalid, please try again" << endl;
				--z;
			}
		}
		else
		{
			cout << "Sorry, that input was invalid, please try again" << endl;
			--z;
		}
	}
}

void user_bomb()
{
	for (z = 0; z < 1; z++)
	{
		user_bombs = "00";
		cout << "Please enter where you want the bomb to be placed: ";
		cin >> user_bombs;
		x = (user_bombs[0]) - 65;//removes 65 from ascii value
		y = (user_bombs[1]) - 49;//because its in a string its stored as an ascii so you must remove 49
		if ((x >= 0) && (x < 8) && (y >= 0) && (y < 8) && (a.size() == 2))
		{
			if (comp[x][y] == 0)
			{
				comp[x][y] = 2;
				cout << "Haha you missed!" << endl;
				//u missed
			}
			else if (comp[x][y] == 1)
			{
				comp[x][y] = 3;
				cout << "Lucky Shot!" << endl;
				--comp_ships;
				//hit;
			}
			else if (comp[x][y] == 3 || comp[x][y] == 2)
			{
				cout << "You've already picked this spot." << endl;
				--z;
			}
			else
			{
				cout << "Sorry, that input was invalid, please try again" << endl;
				--z;
			}
		}
		else
		{
			cout << "Sorry, that input was invalid, please try again" << endl;
			--z;
		}
		
	}
}

void bombs_gen()
{
	srand(time(NULL));
	for (int z = 0; z < 1; z++)//num_ships comes from somewhere else
	{
		y = rand() % 8;
		x = rand() % 8;
		if (player[x][y] == 0)
		{
			player[x][y] = 2;
			cout << "Dang! I missed!" << endl;
			//u missed
		}
		else if (comp[x][y] == 1)
		{
			player[x][y] = 3;
			cout << "Yes!" << endl;
			--user_ships;
			//hit;
		}
		else if (comp[x][y] == 3 || comp[x][y] == 2)
		{
			--z;
		}
	}
}

int main()
{
	grid();//creates grid
	ships();//asks for amount of ships
	gen();//created computer positions
	user_input();//inputs ships
	grid_cout();//couts it
	do
	{
		cout << "You are playing with " << num_ships << " ships." << endl;
		user_bomb();
		Sleep(1000);
		bombs_gen();
		Sleep(1000);
		grid_cout();
		++turns;
		//using loops find comp ships, user ships
		if (user_ships == 0 || comp_ships == 0)//these are inserted into the other functions, 
		//i figured this would be easier and more efficient to do than another seperate function
		{
			game_end = 1;
		}
	} while (game_end == 0);
	grid_cout();
	cout << "It took " << turns << " turns" << endl;
	system("pause");
	return 0;
}
