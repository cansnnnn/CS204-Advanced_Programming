//Cansin Narsahin
//00029126

#include <iostream>
#include <string>
using namespace std;

struct node 
{ 
	char data; 
	node *right; 
	node *down; 

	node()
	{}
	node(char letter, node * p, node*q)
		: data(letter), right(p), down(q)
	{};
};

class TwoDLinkedList
{
	private:

		node * head; //a pointer to the head node of the data structure

	public:

		// constructors
		TwoDLinkedList(); // constructs a head pointer for the whole matrix in the cpp

		//add to the matrix
		void add_row_sorted(string s); // adds a string to the matrix as a row and in order

		//display functions
		void displayFullMatrix()				const;	//Display the full Matrix
		void displayFullMatrixReversed()		const;	//Display the full matrix in reverse order
		void display_rows_starting_with(char c)	const;	//Display all the rows starting with a specific character
		void display_cols_starting_with(char c)	const;	//Display all the columns starting with a specific character

		//delete functions
		int delete_rows_starting_with(char c);			//Delete all the rows starting with a specific character
		int delete_cols_starting_with(char c);			//Delete all the columns starting with a specific character
		void clear();									//Clear the data structure and exit
		
};