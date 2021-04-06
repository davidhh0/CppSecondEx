#include <cmath>
#include <array>
#include "Board.hpp"
using namespace ariel;

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main() {
	cout<<"Welcome to my PostBoard progRam!!"<<endl;
	ariel::Board board;
	board.post(0,5,Direction::Horizontal,"David Harush");
	//board->post(0,5,Direction::Horizontal,"David Harush");
	cout<<board.read(0,0,Direction::Horizontal,22)<<endl;
	//board->post(0,0,Direction::Horizontal,"David");
	board.show();

	return 0;
}

