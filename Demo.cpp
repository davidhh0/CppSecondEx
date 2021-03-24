/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */
 #include "Direction.hpp"
#include <iostream>
#include "Board.hpp"
#include <stdexcept>
#include <string>
using namespace ariel;
using namespace std;

int main() {
	cout<<"Welcome to my PostBoard program!!"<<endl;
	Board* board = new Board;
	board->post(0,5,Direction::Horizontal,"David Harush");
	cout<<board->read(0,0,Direction::Horizontal,22)<<endl;
	

	return 0;
}

