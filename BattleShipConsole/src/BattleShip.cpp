
#include <iostream>
#include <vector>
#include <string>

#include "BattleShip.h"

using namespace std;

Player::Player(){
	busCount = 1;
	bikeCount = 1;
	carCount = 1;
};


Game::Game(){
	boardSize = 10;
	Player playa;
	playerOne = playa;
	playerTwo = playa;
	vector<vector<string>> b(boardSize, vector<string> (boardSize, "X"));
	pOneboard = b;
	pTwoboard = b;
}

void Game::SetBoard(vector<vector<string>>& board, Player playerX){
	int tempX;
	int tempY;
	string direction;
	bool canPlace;
	while (playerX.carCount > 0){
		cout << "Choose X,Y coordinates for your Car (0-9)" << endl;
		cout << "X:";
		cin >> tempX;
		cout << "Y:";
		cin >> tempY;
		cout << "Type 'V' for Vertical Placement" << endl;
		cout << "Type 'H' for Horizontal Placement" << endl;
		cout << "Direction:";
		cin >> direction;
		canPlace = ValidPlacement(board,tempX,tempY,direction,"Car");
		if (canPlace == true){
			PlaceShip(board,tempX,tempY,direction,"Car");
			playerX.carCount = playerX.carCount - 1;
		} else{
			cout << "Try again, that spot is taken or a ship cannot be placed there" << endl;
		}
	}
	while (playerX.busCount > 0){
		cout << "Choose X,Y coordinates for your Bus (0-9)" << endl;
		cout << "X:";
		cin >> tempX;
		cout << "Y:";
		cin >> tempY;
		cout << "Type 'V' for Vertical Placement" << endl;
		cout << "Type 'H' for Horizontal Placement" << endl;
		cout << "Direction:";
		cin >> direction;
		canPlace = ValidPlacement(board,tempX,tempY,direction,"Bus");
		if (canPlace == true){
			PlaceShip(board,tempX,tempY,direction,"Bus");
			playerX.busCount = playerX.busCount - 1;
		} else{
			cout << "Try again, that spot is taken or a ship cannot be placed there" << endl;
		}
	}
	while (playerX.bikeCount > 0){
		cout << "Choose X,Y coordinates for your Bike (0-9)" << endl;
		cout << "X:";
		cin >> tempX;
		cout << "Y:";
		cin >> tempY;
		cout << "Type 'V' for Vertical Placement" << endl;
		cout << "Type 'H' for Horizontal Placement" << endl;
		cout << "Direction:";
		cin >> direction;
		canPlace = ValidPlacement(board,tempX,tempY,direction,"Bike");
		if (canPlace == true){
			PlaceShip(board,tempX,tempY,direction,"Bike");
			playerX.bikeCount = playerX.bikeCount - 1;
		} else{
			cout << "Try again, that spot is taken or a ship cannot be placed there" << endl;
		}
	}
}

Player Game::getPlayerOne(){return playerOne;}
Player Game::getPlayerTwo(){return playerTwo;}

bool Game::ValidPlacement(vector<vector<string>>& board, int x, int y,
			string direction, string type){
	int width;
	int height;

	if (type == "Car"){
		height = car.height;
		width = car.width;
	} else if (type == "Bus"){
		height = bus.height;
		width = bus.width;
	} else {
		height = bike.height;
		width = bike.width;
	}

	if (direction == "V"){
		if ( (x+width <= boardSize) && (y+height <= boardSize) ){
			for (int i = y; i < y+height; i++){
				for(int j = x; j < x+width; j++){
					if (board[i][j] != "X"){return false;}
				}
			}
		} else{return false;}
	} else {     // Horizontal
		if ( (x+height <= boardSize) && (y+width <= boardSize) ){
					for (int i = y; i < y+width; i++){
						for(int j = x; j < x+height; j++){
							if (board[i][j] != "X"){return false;}
						}
					}
				} else{return false;}
	}

	return true;
}

void Game::PlaceShip(vector<vector<string>>& board, int x, int y,
		string direction, string type){
	int width;
	int height;
	string identifier;

	if (type == "Car"){
		height = car.height;
		width = car.width;
		identifier = "C";
	} else if (type == "Bus"){
		height = bus.height;
		width = bus.width;
		identifier = "B";
	} else {
		height = bike.height;
		width = bike.width;
		identifier = "P";
	}

	if (direction == "V"){
			for (int i = y; i < y+height; i++){
				for(int j = x; j < x+width; j++){
					board[i][j] = identifier;
				}
			}
	} else {     // Horizontal
		for (int i = y; i < y+width; i++){
			for(int j = x; j < x+height; j++){
				board[i][j] = identifier;
				}
			}
		}
}


void Game::TakeTurn(vector<vector<string>>& board){
	int X, Y;
	cout << "Choose X,Y coordinates for your shot!!!" << endl;
	cout << "X:";
	cin >> X;
	cout << "Y:";
	cin >> Y;
	if (board[Y][X].compare("H") == 0){
			cout << "Already hit this tile!" << endl << endl;
	} else if (board[Y][X].compare("X") != 0){
		board[Y][X] = "H";
		cout << "HIT" << endl << endl;
	} else{
		cout << "MISS" << endl << endl;
	}
}

bool Game::checkWin(vector<vector<string>>& board){
	bool trigger(true);
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j].compare("C") == 0 || board[i][j].compare("B") == 0 || board[i][j].compare("P") == 0 ){
				trigger =  false;
			}
		}
	}
	return trigger;
}


void Game::PrintBoard(vector<vector<string>>& board){
	for (int i = 0; i < board.size(); i++){
			    for (int j = 0; j < board[i].size(); j++){
			        cout << board[i][j] << " ";
			    }
			    cout << endl;
			}
}
