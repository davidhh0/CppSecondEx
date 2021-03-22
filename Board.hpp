
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
		void post(int,int,Direction,const string str);
		string read(int row,int col,Direction d,int length);
        void show();

	private:
        vector<vector<char>> matrix;
        int numberOfChangeDim=1;
        vector<vector<int>> biggestStringInRow;
        vector<bool> isThereChar;
		
        string readHorizontally(int row, int col, int howmany);
        string readVertically(int row,int col,int howmany);
        void insertHorizonially(int row,int col,string str);
        void insertVertically(int row,int col,string str);
	    void changeDim();
        static void checkThrow(int row,int col,int length);
        
		
    };
}
#endif