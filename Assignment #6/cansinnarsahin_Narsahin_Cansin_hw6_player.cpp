//Cansin Narsahin
//29126

#include "cansinnarsahin_Narsahin_Cansin_hw6_player.h"


template <class Type> Player<Type>::Player(Board<Type> & connected_Board) : myBoard(connected_Board)
{
	playerNum++;
    player_id = playerNum;
    
}

template <class Type> bool Player<Type>::updateCell(int row, int col, Type value)
{//update retruns tur if it updates
	return myBoard.update(row, col, value, player_id);   
}

template <class Type> void Player<Type>::updateMyCells(Type value)
{//checks matrix in for loop and updates
	for(int i=0; i<myBoard.get_row();i++)
	{
		for (int x=0; x<myBoard.get_col();x++)
		{
			if (player_id==myBoard.knowTheOwner(i,x))
			{ myBoard.update(i, x, value, player_id); }
		}
	}
}

template <class Type> bool Player<Type>::unclaimOwnership(int row, int col)
{//unclaim returns true if it is unclaimed
	return myBoard.unclaim(row, col,player_id);
}

template <class Type> void Player<Type>::unclaimOwnerships()
{//checks matrix in for loop and unclaims the owner of the cells 
	int row_num=myBoard.get_row();
	int col_num=myBoard.get_col();

    for(int i=0; i<row_num;i++)
	{
		for (int x=0; x<col_num;x++)
		{
			if (player_id==myBoard.knowTheOwner(i,x))
			{ myBoard.unclaim(i, x,player_id); }
		}
	}
}
