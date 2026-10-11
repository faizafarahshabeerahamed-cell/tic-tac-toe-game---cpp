#include <iostream>
using namespace std;

//function to display the board

void displayBoard(char Board[3][3])
{
	cout<<"\n";
	cout<<" "<< Board[0][0] <<" | "<< Board[0][1] << " | " << Board[0][2] << endl;
	cout<<"---|---|---"<<endl;
	cout<<" "<< Board[1][0] <<" | "<< Board[1][1] << " | " << Board[1][2] << endl;
	cout<<"---|---|---"<<endl;
	cout<<" "<< Board[2][0] <<" | "<< Board[2][1] << " | " << Board[2][2] << endl;
}

//function to check if someone has won

bool checkWinner(char Board[3][3],char player)
{
	//check rows
	for(int i=0; i<3; i++)
	{
		if(Board[i][0] == player &&
		        Board[i][1] == player &&
		        Board[i][2] == player)
		{
			return true;
		}
	}

	//columns
	for (int i=0; i<3; i++)
	{
		if(Board[0][i] == player &&
		        Board[1][i] == player &&
		        Board[2][i] == player)
		{
			return true;
		}
	}

	//first diagnol
	for(int i=0; i<3; i++)
		if(Board[0][2] == player &&
		        Board[1][1] == player &&
		        Board[2][0] == player)
		{
			return true;
		}
	return false;
}

int main()
{
	char Board[3][3]= {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};

	char player = 'X';
	int position;
	int moves = 0;

	while (true)
	{
		displayBoard(Board);

		cout<<"\nPlayer "<< player << ", enter position (1-9):";
		cin>>position;

		//converting position into row and columns
		int row = (position - 1)/3;
		int column = (position - 1)%3;

		if(Board[row][column] =='X' || Board[row][column] == 'O' )
		{
			cout<<"\n position already chosen , try again:\n)";
			continue;
		}
		Board[row][column] = player;
		moves++;

		if (checkWinner(Board,player))
		{
		  displayBoard(Board);
		  cout<<"\nPlayer"<<player<<"yayy player winsss!!\n";
		  break;
		}
        if(moves == 9)
        {
        displayBoard(Board);
        cout<<"this is a draw:((\n";
        break;
        }
        if(player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
	}
	return 0;
}
