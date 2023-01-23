//Cansin Narsahin
//29126

#include <iostream>
#include <string>

#ifndef cansinnarsahin_Narsahin_Cansin_hw6_board_H
#define cansinnarsahin_Narsahin_Cansin_hw6_board_H

template <class Type> struct cell
{
	Type value;
	int id;
};


template <class Type> 
class Board
{
	private:
        int row;
		int col;
        cell<Type> **myBoard; //matrix for board

	public:
		Board(int, int );			//construct the board with no owners of the cells 
		Board(const Board<Type> & );				// Deep Copy Constructor
		~Board();									// Destructor 

		void displayBoard() const;					//Displays the board
		void updateBoardCells(int, Type);	//populate all the cells owned by that player with that value
		int getPlayerCellsCount(int) const;		//returns the number of cells that player owns
		int knowTheOwner(int, int);				//returns the owner of that cell

		bool update(int, int, Type, int);	//modfy the value of cell
		bool unclaim(int, int,int);				//set id 0
		int get_row();
		int get_col();
};

#include "cansinnarsahin_Narsahin_Cansin_hw6_board.cpp"

#endif