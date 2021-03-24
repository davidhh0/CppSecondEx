
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace ariel{

class Board{
	public:
		Board();
		void post(unsigned int,unsigned int,Direction,const string &str);
		string read(unsigned int row,unsigned int col,Direction d,unsigned int length);
        void show();

	private:
        vector<vector<char>> matrix;
        unsigned int numberOfChangeDim=1;
        vector<vector<int>> biggestStringInRow;
        vector<bool> isThereChar;
		
        string readHorizontally(unsigned int row, unsigned int col, unsigned int howmany);
        string readVertically(unsigned int row,unsigned int col,unsigned int howmany);
        void insertHorizonially(unsigned int row,unsigned int col,string str);
        void insertVertically(unsigned int row,unsigned int col,string str);
	    void changeDim();
        static void checkThrow(unsigned int row,unsigned int col,unsigned int length);
        
		
    };
}
#endif
