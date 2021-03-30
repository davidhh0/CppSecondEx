
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Direction.hpp"
using namespace std;
namespace ariel{

class Board{
	public:
		Board();
		void post(unsigned int,unsigned int,Direction,const string &str);
		string read(unsigned int row,unsigned int col,Direction d,unsigned int length);
        void show();
		~Board();

	private:
        vector<vector<char>> matrix; 
	unsigned int indexOfTheBiggestStr=1;
        unsigned int biggestStringInRow=1;
        vector<bool> isThereChar;
		
        string readHorizontally(unsigned int row, unsigned int col, unsigned int howmany);
        string readVertically(unsigned int row,unsigned int col,unsigned int howmany);
        void insertHorizonially(unsigned int row,unsigned int col,string str);
        void insertVertically(unsigned int row,unsigned int col,string str);
	    void changeDim(unsigned int);
        static void checkThrow(unsigned int row,unsigned int col,unsigned int length);
        

		
    };
}
#endif
