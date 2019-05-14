//Jakob Zhang
//Battleship project

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
using namespace std;
int player[8][8], comp[8][8];
int num_ships;
int w, x, y, z;//these change often, are just placeholders
string a;
//make so 0=clear, 1=boat, 2=miss, 3=hit

void gen()//generates computer positions
{
	srand(time(NULL));
	for (int z = 0; z < num_ships; z++)//num_ships comes from somewhere else
	{
		
		y = rand() % 9;
		x = rand() % 9;
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
		if ((num_ships <= 8) && (num_ships >= 1))//validates and exits if true
		{
			break;
		}
	}
}

void grid()//sets array to 0
{
	int player[8][8] = { 0 }, comp[8][8] = { 0 };
}

void grid_cout()
{
	cout << "Player" << endl;
	for (x = 0; x < 8; x++)
	{
		cout << (x + 1) << "    ";
		for (y = 0; y < 8; y++)
		{
			if (player[y][x] == 0)
			{
				cout << ".    ";
			}
			else if (player[y][x] == 1)
			{
				cout << "S    ";
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
			if (comp[y][x] == 0)
			{
				cout << ".    ";
			}
			else if (comp[y][x] == 1)
			{
				cout << ".    ";
			}
			else if (comp[y][x] == 2)
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
			cout << "ex: A1" << endl;
		}
		cout << "Please enter the positions of ship " << (z + 1) << ": ";
		cin >> a;
		x = (int(a[1]) - 65);
		y = (int(a[2]) - 1);
		if (player[x][y] != 1)
		{
			player[x][y] = 1;//1 is with a ship in this case
		}
		else
		{
			--z;
		}
	}
}

int main()
{
	grid();
	ships();
	gen();
	grid_cout();//incomplete
	user_input();
	grid_cout();
	system("pause");
	return 0;
}




// \r will reset one line