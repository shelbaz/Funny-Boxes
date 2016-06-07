//
//  main.cpp
//  Programming Project : Funny Boxes
//
//  Created by Shawn Elbaz on 2014-04-28.
//  Copyright (c) 2014 Shawn Elbaz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

// co_o = Cordinate 1 , co_t = Cordinate 2

const int ROWS=5;
const int COLUMNS=5;
void initializeBoard ( char grid[][COLUMNS]) ;
void displayBoard ( char grid[][COLUMNS]);
bool isInputValid ( int co_o, int co_t);
bool isBoxFree ( char boxvalue) ;
void getnumbers (int& co_o, int& co_t);
bool IsGameOver ( char boxvalue );
void computernumb (int& co_o, int& co_t);
bool IsGameOver ( char grid[][COLUMNS] );
bool FullBoard (char grid [] [COLUMNS]);
int variable ;



int main()
{
    char grid[ROWS][COLUMNS];
    int co_o=0 , co_t=0 ;
    
    srand (time_t (NULL));
    initializeBoard(grid);
    displayBoard(grid);
        do
    {
        do
        {
            do {
                getnumbers (co_o, co_t);
                
            } while (!isInputValid (co_o, co_t));
            
        } while (!isBoxFree (grid[co_o][co_t]));
        
                 grid[co_o][co_t]='H' ;
                 displayBoard (grid);
                 
                 do
                 {
                     computernumb (co_o,co_t);
                     
                 } while (!isBoxFree (grid[co_o][co_t]) && !FullBoard(grid));
                 grid[co_o][co_t]= 'P' ;
                 cout << "Player P>" << co_o << " " << co_t ;
                 cout << endl;
            displayBoard (grid);
        
        
 
    
    }
                
    while (!IsGameOver(grid));
                 {
                                          cout << "Game Over" << endl;
                 }
    system ("pause");
                     return 0;

}



void initializeBoard(char grid[][COLUMNS])
{
    
	for(int co_o = 0; co_o < ROWS; co_o++)
	{
		for(int co_t = 0; co_t < COLUMNS; co_t++)
		{
        grid[co_o][co_t] = '-';
		}
	}
}

void displayBoard ( char grid[][COLUMNS])
{
    cout << "   0    1   2   3   4" << endl;

    int co_t  = 0;
	for(int co_o = 0; co_o < ROWS; co_o++)
	{
		cout << co_o << " | " ;
		for(co_t = 0; co_t < COLUMNS; co_t++)
		{
			cout << grid[co_o][co_t];
            cout << " | ";
        }
        
		cout << endl;
	}
}



bool isInputValid ( int co_o, int co_t)

{ if
    ( int (co_o > 4) | int (co_o < 0) | int (co_t > 4) | int (co_t <0) )
{
    cout << "This is not a valid input " << endl;
    return (false);
}

    return (true);
        }
bool isBoxFree (char boxvalue )
{
    if (boxvalue == '-' )
    {  return (true); }
    
    return (false);
    
    
}

void getnumbers (int& co_o, int& co_t)
{
    cout << "Please input the co-ordinates for the table" << endl;
    cin >> co_o >> co_t ;
    
}

void computernumb (int& co_o, int& co_t)
{
    co_o=rand() % ROWS;
    co_t=rand() % COLUMNS;
}

bool IsGameOver ( char grid[][COLUMNS] )
{
    if ((grid[0][0]=='H' && grid[1][1]=='H' && grid[2][2]=='H' && grid[3][3] == 'H' && grid[4][4] == 'H') || (grid[0][4]=='H' && grid[1][3]=='H' && grid[2][2]=='H' && grid[3][1] == 'H' && grid[4][0] == 'H') || (grid[0][4]=='P' && grid[1][3]=='P' && grid[2][2]=='P' && grid[3][1] == 'P' && grid[4][0] == 'P') ||
        (grid[0][0]=='P' && grid[1][1]=='P' && grid[2][2]=='P' && grid[3][3] == 'P' && grid[4][4] == 'P') )       
         
    {
        return true;
    }

	if(FullBoard(grid))
	{
		return true;
	}
    return false;
}

bool FullBoard (char grid [] [COLUMNS])
{ 
	for (int i=0; i< ROWS ; i++)
	{ for (int j=0; j<COLUMNS; j++) 
		{ if (grid[i][j] == '-') 
		return false; }
	} 
return true;
} 