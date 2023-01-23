//Cansin Narsahin
//00029126

#include "cansinnarsahin_Narsahin_Cansin_hw3_TwoDLinkedList.h"

TwoDLinkedList:: TwoDLinkedList()
{
	head=new node;
	head->down=NULL;
}

void TwoDLinkedList:: add_row_sorted(string s)
{
	if(head->down==NULL) //matrix is emty
	{
		node* temp = new node(s.at(0),NULL,NULL);
		head->down= temp;

		for(int i=1; i<s.length(); i++)
		{
			node* q=new node(s.at(i),NULL,NULL);
			temp->right=q;
			temp=q;	
		}
	}

	else //matrix is not emty
	{
		if(s.at(0)< head->down->data) //adding to the beginning
		{
			node* post=head->down;

			node* temp = new node(s.at(0),NULL,post);
			post=post->right;
			head->down=temp;

			for(int i=1; i<s.length(); i++)
			{
				node* q=new node(s.at(i),NULL,post);
				temp->right=q;
				temp=q;	
				post=post->right;
			}
		}

		else // adding to the middle or to the end
		{
			node* pre=head->down;
			bool continuee=false;
			while(pre->down!=NULL)//adding to the middle
			{
				if(pre->data<s.at(0) && pre->down->data>=s.at(0))
				{
					node* precop=pre;
					node* temp = new node(s.at(0),NULL,precop->down);
					precop->down=temp;
					precop=precop->right;

					for(int i=1; i<s.length(); i++)
					{
						node* q=new node(s.at(i),NULL,precop->down);
						temp->right=q;
						temp=q;	
						precop->down=q;
						precop=precop->right;
					}
					continuee=true;
				}
				pre=pre->down;

			}

			if(pre->down==NULL && !continuee) //adding to the end
			{
				node*temp=new node(s.at(0),NULL,NULL);
				pre->down=temp;
				pre=pre->right;

				for (int i=1; i<s.length(); i++)
				{
					node* q=new node(s.at(i),NULL,NULL);
					pre->down=q;
					pre=pre->right;
					temp->right=q;
					temp=q;
				}
			}
		}
	}
}

void TwoDLinkedList::displayFullMatrix() const
{
	node * temp=head->down;
	while(temp!=NULL)
	{
		node* tempRow=temp;
		while(tempRow!=NULL)
		{
			cout<<tempRow->data;
			tempRow=tempRow->right;
		}
		cout<<endl;
		temp=temp->down;
	}
}

void recursivePrint(node*temp)
{
	if(temp!=NULL)
	{
		recursivePrint(temp->down);
		node*tempRow=temp;
		while(tempRow!=NULL)
		{
			cout<<tempRow->data;
			tempRow=tempRow->right;
		}
		cout<<endl;
	}
}

void TwoDLinkedList:: displayFullMatrixReversed() const
{recursivePrint(head->down);}

void TwoDLinkedList:: display_rows_starting_with(char c) const
{
	node*temp=head->down;
	while(temp!=NULL)
	{
		if(temp->data==c)
		{
			node* tempRow=temp;
			while(tempRow!=NULL)
			{
				cout<<tempRow->data;
				tempRow=tempRow->right;
			}
			cout<<endl;
		}
		temp=temp->down;
	}
}

void TwoDLinkedList:: display_cols_starting_with(char c) const
{
	node*temp=head->down;
	while(temp!=NULL)
	{
		if(temp->data==c)
		{
			node*tempCol=temp;
			while(tempCol!=NULL)
			{
				cout<<tempCol->data<<endl;
				tempCol=tempCol->down;
			}
			cout<<endl;
		}
		temp=temp->right;
	}
}

int TwoDLinkedList:: delete_rows_starting_with(char c)
{
	if(head->down==NULL){return 0;}
	int count=0;
	node*temp=head->down;
	node*pre=head->down;
	int control=0;
	while(temp->down!=NULL)
	{
		if(temp->data==c)
		{
			if(temp==head->down) //deletion from beginning
			{
				head->down=temp->down;
				node*toDel;
				node*tempCop=temp;
				temp=temp->down;
				pre=pre->down;
				while(tempCop!=NULL)
				{
					toDel=tempCop->right;
					delete tempCop;
					tempCop=toDel;
				}
				count++;
			}

			else //in the middle
			{
				node*toDel;
				node*tempCop=temp;	node*preCop=pre;
				temp=temp->down;	
				while(tempCop!=NULL)
				{
					preCop->down=tempCop->down;
					toDel=tempCop->right;
					delete tempCop;
					tempCop=toDel;
					preCop=preCop->right;
				}
				count++;
			}
		}

		else
		{
			if(control==0)
			{temp=temp->down;	control++;}
			else
			{temp=temp->down;	pre=pre->down;}
		}
	}

	if(temp->data==c && temp->down==NULL) //delte the last row
	{
		if(temp==head->down)
		{
			head->down=NULL;
			node*toDel;
		
			while(temp!=NULL)
			{
				toDel=temp->right;
				delete temp;
				temp=toDel;
			}
			count++;
		}
		else{
			node*toDel;
			node*preCop=pre;
			while(temp!=NULL)
			{
				preCop->down=NULL; 
				toDel=temp->right;
				delete temp;
				temp=toDel;
				preCop=preCop->right;
			}
			count++;}
	}
	return count;
}

int TwoDLinkedList:: delete_cols_starting_with(char c)
{
	if(head->down==NULL){return 0;}
	int count=0;
	node*temp=head->down;
	node*pre=head->down;
	int control=0;
	while(temp->right!=NULL)
	{
		if(temp->data==c)
		{
			if(temp==head->down) //deletion from beginning
			{
				head->down=temp->right;
				node*toDel;
				node*tempCop=temp;
				temp=temp->right;
				pre=pre->right;
				while(tempCop!=NULL)
				{
					toDel=tempCop->down;
					delete tempCop;
					tempCop=toDel;
				}
				count++;
			}

			else //in the middle
			{
				node*toDel;
				node*tempCop=temp;	node*preCop=pre;
				temp=temp->right;	
				while(tempCop!=NULL)
				{
					preCop->right=tempCop->right;
					toDel=tempCop->down;
					delete tempCop;
					tempCop=toDel;
					preCop=preCop->down;
				}
				count++;
			}
		}

		else
		{
			if(control==0)
			{temp=temp->right;	control++;}
			else
			{temp=temp->right;	pre=pre->right;}
		}
	}

	if(temp->data==c && temp->right==NULL) //delte the last row
	{
		
		if(temp==head->down)
		{
			head->down=NULL;
			node*toDel;
		
			while(temp!=NULL)
			{
				toDel=temp->down;
				delete temp;
				temp=toDel;
			}
			count++;
		}
		else{
			node*toDel;
			node*preCop=pre;
			while(temp!=NULL)
			{
				preCop->right=NULL; 
				toDel=temp->down;
				delete temp;
				temp=toDel;
				preCop=preCop->down;
			}
			count++;}
	}
	return count;
}

void TwoDLinkedList:: clear()
{	
	while(head->down!=NULL)
	{
		node*temp=head->down;
		head->down=temp->down;
		while(temp!=NULL)
		{
			node*toDel=temp;
			temp=temp->right;
			delete toDel;
		}
	}
	delete head;
}
