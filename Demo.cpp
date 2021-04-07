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
	cout<<"Welcome to my PostBoard program!!"<<endl;
	ariel::Board b;
	b.post(0,5,Direction::Horizontal,"David Harush");
	//board->post(0,5,Direction::Horizontal,"David Harush");
	cout<<b.read(0,0,Direction::Horizontal,22)<<endl;
	//board->post(0,0,Direction::Horizontal,"David");
	
	b.post(0, 0, Direction::Horizontal, "        \\\\|||||//        ");
	b.post(1, 0, Direction::Horizontal, "        ( O   O )        ");
	b.post(2, 0, Direction::Horizontal, "|--ooO-----(_)----------|");
	b.post(3, 0, Direction::Horizontal, "|                       |");
	b.post(4, 0, Direction::Horizontal, "|                       |");
	b.post(5, 0, Direction::Horizontal, "|     Message Board     |");
	b.post(6, 0, Direction::Horizontal, "|                       |");
	b.post(7, 0, Direction::Horizontal, "|                       |");
	b.post(8, 0, Direction::Horizontal, "|------------------Ooo--|");
	b.post(9, 0, Direction::Horizontal, "        |__|  |__|       ");
	b.post(10, 0, Direction::Horizontal, "         ||    ||        ");
	b.post(11, 0, Direction::Horizontal, "        ooO    Ooo       ");
	b.post(0,7,Direction::Vertical,"Ariel Blah Blah");
	
	
	b.show();

	return 0;
}

