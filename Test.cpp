
//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Direction.hpp"
#include "Board.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include "doctest.h"

using namespace ariel;
using namespace std;
Board* board;
/*
	READ from the board -> int row , int col , Direction , int length
	POST to the board   -> int row , int col , Direction , string str
*/

TEST_CASE("Init value"){
	string str_hor,str_ver;
	for(int i=0;i<200;i++){
		 str_hor+='_';
		// str_ver+="_\n";
	}
	string check_hor,check_ver;
	check_hor=board->read(0,0,Direction::Horizontal,200);
	check_ver=board->read(0,0,Direction::Vertical,200);
	CHECK(check_hor == str_hor);
	CHECK(check_ver == str_ver);
}


TEST_CASE("Simple non throwing"){
	CHECK_NOTHROW(board->post(0,0,Direction::Horizontal,"WELCOME"));

	CHECK_NOTHROW(board->read(0,0,Direction::Horizontal,7));

	CHECK_NOTHROW(board->show());
}


TEST_CASE("Post&Read"){
	//Posting in the beggining:
	board->post(0,0,Direction::Horizontal,"David");
	CHECK(board->read(0,0,Direction::Horizontal,5) == string("David"));
	// Over posting:
	board->post(0,3,Direction::Horizontal,"Harush");
	CHECK(board->read(0,0,Direction::Horizontal,9) == string("DavHarush"));
	CHECK(board->read(0,0,Direction::Vertical,5) == string("D\n_\n_\n_\n_\n"));

}
TEST_CASE("Exceptions"){

	// Reading more than 200 words
	CHECK_THROWS(board->read(0,0,Direction::Horizontal,201));
	CHECK_THROWS(board->read(0,0,Direction::Vertical,201));
	
	//Posting more than 200 words
	string str;
	for(int i=0;i<201;i++){
		str+='a';
	}
	CHECK_THROWS(board->post(0,0,Direction::Horizontal,str));
	CHECK_THROWS(board->post(0,0,Direction::Vertical,str));

	
}
TEST_CASE("Change dim"){
	//Post over dim
	board->post(250,250,Direction::Horizontal,"Game");
	CHECK(board->read(250,250,Direction::Vertical,4) == string("G\n_\n_\n_\n"));
	CHECK(board->read(250,250,Direction::Horizontal,4) == string("Game"));
	CHECK(board->read(300,300,Direction::Horizontal,5) == string("_____"));
	CHECK(board->read(300,300,Direction::Vertical,5) == string("_____"));
	//Post after post after redim
	board->post(250,254,Direction::Horizontal,"_Over");
	//cout<<board->read(250,250,Direction::Horizontal,4);
	CHECK(board->read(250,250,Direction::Horizontal,9) == string("Game_Over"));
	CHECK(board->read(250,250,Direction::Vertical,5) == string("G____"));

	//Post over post after redim
	board->post(250,255,Direction::Horizontal,"DavidHarush");
	CHECK(board->read(250,250,Direction::Horizontal,16) == string("Game_DavidHarush"));
	CHECK(board->read(250,250,Direction::Horizontal,10) == string("Game_David"));

	

}
