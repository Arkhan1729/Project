#include<iostream>
using namespace std;
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

char current_marker;
int current_player;
//CREATION OF BOARD//
void
draw_board ()
{
  cout << "    " << board[0][0] << " | " << board[0][1] << " | " << board[0][2]
    << endl;
  cout << "   -----------\n";
  cout << "    " << board[1][0] << " | " << board[1][1] << " | " << board[1][2]
    << endl;
  cout << "   -----------\n";
  cout << "    " << board[2][0] << " | " << board[2][1] << " | " << board[2][2]
    << endl;

}

//PLACING OF MARKER('X' OR 'O') AT THE POSTIONS//
bool
placemarker (int slot)
{
  int row = slot / 3;
  int col;
  if (slot % 3 == 0)
    {
      row = row - 1;
      col = 2;
    }
  else
    col = (slot % 3) - 1;
  if (board[row][col] != 'O' && board[row][col] != 'X')
    {
      board[row][col] = current_marker;
      return true;
    }
  else
    return false;
}

//TO DECIDE THE WINNER PLAYER1 OR PLAYER2//
int
winner ()
{
  int i;
  for (i = 0; i < 3; i++)
    {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
	return current_player;
      if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
	return current_player;
    }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return current_player;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return current_player;
  else
    return 0;
}

//SWAPPING OF PLAYER AND MARKER OF THE BOARD//
void
swap_player_and_marker ()
{
  if (current_player == 1)
    current_player = 2;
  else
    current_player = 1;
  if (current_marker == 'X')
    current_marker = 'O';
  else
    current_marker = 'X';
}

//THE BASE OF THE GAME//
void
game ()
{
  cout << "PLAYER ONE, CHOOSE YOUR MARKER\n";
  char marker_pi;
  cin >> marker_pi;
  current_player = 1;
  current_marker = marker_pi;
  draw_board ();
  int player_won;
  for (int i = 0; i < 9; i++)
    {
      int slot;
      cout << "ITS PLAYER'S " << current_player << " TURN, ENTER YOUR SLOT\n";
      cin >> slot;
      if (!placemarker (slot))
	{
	  cout << "ALREADY OCCUPIED SLOT\n";
	  i--;
	  continue;
	}
      draw_board ();
      player_won = winner ();
      if (player_won == 1)
	{
	  cout << "WINNER IS PLAYER 1,CONGRATULATIONS :)\n";
	  break;
	}
      if (player_won == 2)
	{
	  cout << "WINNER IS PLAYER 2,CONGRATULATIONS :)\n";
	  break;
	}
      swap_player_and_marker ();
    }
  if (player_won == 0)
    {
      cout << "GAME IS A TIE\n";
    }
}

//MAIN FUNCTION//
int
main ()
{
  game ();
  return 0;
}