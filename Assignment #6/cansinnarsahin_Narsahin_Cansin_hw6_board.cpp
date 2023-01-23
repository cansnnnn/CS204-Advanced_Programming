//Cansin Narsahin
//29126

#include "cansinnarsahin_Narsahin_Cansin_hw6_board.h"

template <class Type> Board<Type>::Board(int row_num, int col_num)
{
	//construct the board with no owners of the cells 
	//all ids are = 0
	//the value fields of the cells will be left uninitialized

	myBoard = new cell<Type>*[row_num]; //constructs a new dynamic array matrix

	for(int i = 0; i < row_num; i++)
	{
		myBoard[i] = new cell<Type>[col_num];
		
		for(int x=0; x<col_num; x++)
		{ myBoard[i][x].id=0; }

	}

	row=row_num;
	col=col_num;
}

template <class Type> Board<Type>::Board(const Board<Type> & cboard)
{//Deep Copy Constructor

	row=cboard.row;
	col=cboard.col;
	myBoard = new cell<Type>*[row]; //creates rows

	for (int i = 0; i < row; i++) //creates cols and assign cell values and ids
	{
		myBoard[i] = new cell<Type>[col];
		for(int x=0; x<col; x++)
		{ 
			myBoard[i][x].id=cboard.myBoard[i][x].id;
			myBoard[i][x].value=cboard.myBoard[i][x].value;
		}
    }
}

template <class Type> Board<Type>::~Board()
{//Destructor
	for (int i = 0; i < row; i++)
	{ 
		delete[] myBoard[i];
	}
    delete[] myBoard;
	myBoard=NULL;
	row=0;
	col=0;
}

template <class Type> void Board<Type>::displayBoard() const
{//prints the function
	cout << "Displaying the board: Each cell is shown as tuple (CURRENT OWNER ID, VALUE): " << endl;
	for(int i = 0; i < col; i++)
	{ 
		cout << "\t"<< i;
	}
	cout<<endl;

	for(int i = 0; i < row; i++)
	{ 
		cout<<i<<"\t";
		for(int x = 0; x < col; x++)
		{
			cout << "(" <<myBoard[i][x].id<< ","<< myBoard[i][x].value << ")\t";
		}
		cout<<endl;
	}
}

template <class Type> void Board<Type>:: updateBoardCells(int ID, Type Value)
{//populate all the cells owned by that player with that value
	
	for(int i = 0; i < row; i++)
	{ 
		for(int x = 0; x < col; x++)
		{
			if(myBoard[i][x].id==ID)
			{
				myBoard[i][x].value=Value;
			}
		}
	}
}

template <class Type> int Board<Type>:: getPlayerCellsCount(int id) const
{
	int count=0;
	for(int i = 0; i < row; i++)
	{ 
		for(int x = 0; x < col; x++)
		{
			if(myBoard[i][x].id==id) { count++; }
		}
	}
	return count;
}

template <class Type> int Board<Type>:: knowTheOwner(int r, int c)
{ //returns the owner of that cell
	return myBoard[r][c].id;
}

template <class Type> bool Board<Type>::update(int row, int col, Type value, int id)
{//modify the value
	if(myBoard[row][col].id==id||myBoard[row][col].id==0)
    {
		myBoard[row][col].value = value;
		myBoard[row][col].id = id;
		return true;
	}
	return false;
}

template <class Type> bool Board<Type>::unclaim(int row, int col,int id)
{ //makes id 0
	if(myBoard[row][col].id==id)
	{
		myBoard[row][col].id = 0;
		return true;
	}
	return false;

}

template <class Type> int Board<Type>::get_row()
{
	return row;
}

template <class Type> int Board<Type>::get_col()
{
	return col;
}
