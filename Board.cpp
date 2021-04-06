#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <vector>
#include "Direction.hpp"
#include "Board.hpp"
#include <array>
using namespace std;
using std::string;
const int ROW = 200;
const int COL = 200;
namespace ariel {
		// Basic Destructor
	Board::~Board(){

	}
	// Simple constructor - init the matrix to 200x200 and the isThereChar
	ariel::Board::Board() {
            this->matrix.resize(ROW, vector<char>(COL));
            for(unsigned int i=0;i<ROW;i++){
                for(unsigned int j=0;j<COL;j++){
                    this->matrix[i][j] = '_';
                }
            }

            isThereChar.resize(ROW);
        }
        
        // int max -> desired new matrix size
        // just simply resize the matrix to (max)
	void Board::changeDim(unsigned int max) {
        unsigned int PrevRowCount = this->matrix.size();
        unsigned int PrevColCount = this->matrix[0].size();
        unsigned int newRowCount = max;
        unsigned int newColCount = max;

        this->matrix.resize(max);
        for(unsigned int i=0;i<max;i++){
            this->matrix[i].resize(max);
        }

        this->isThereChar.resize(max);
	}
	
	
        void Board::post(unsigned int row, unsigned int col, Direction d, const string &str) {
        checkThrow(row,col,str.size());
        if(str.empty()){
            return;
        }
        // Checking if putting the string in the matrix is out of bounds 
        // if so , call changeDim for max(row,col) and the string size
        if ((col+str.size()>this->matrix[0].size())
            || (row+str.size()> this->matrix.size())){
            changeDim(max(row,col)+str.size()+1);
        }
        // indexOfTheBiggestStr will hold the INDEX of the biggest string in the matrix for a nicer show() performance
        // biggestStringInRow will hold the length of the biggest string
        if(this->biggestStringInRow<str.size()){
            this->biggestStringInRow = str.size();
            this->indexOfTheBiggestStr = col;    
        }
        if (d == Direction::Horizontal) {
            insertHorizonially(row, col, str);
        } else {
            insertVertically(row, col, str);
        }
        }

        string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int length) {
            checkThrow(row,col,length);
            
            // in case someone wants to read out of bounds - not an exception - just more '_'
            if (row >= this->matrix.size() || col >= this->matrix[0].size()) {
                changeDim(max(row,col)+length+1);
            }   
            if (d == Direction::Horizontal) {
                return readHorizontally(row, col, length);
            }
            return readVertically(row, col, length);
            
        }
        
        void Board::show(){
            string str;
            // indexOfTheBiggestStr will hold the INDEX of the biggest string in the matrix for a nicer show() performance
            unsigned int index = this->indexOfTheBiggestStr;
 	    // biggestStringInRow will hold the length of the biggest string
            unsigned int max = this->biggestStringInRow;
            for(unsigned int i=0;i<this->matrix.size();i++){
                if(this->isThereChar[i]){
                    str+=to_string(i);
                    str+=":__";
                    for (unsigned int j = index; j < max+index; j++)
                    {
                        str+=this->matrix[i][j];
                    }
                    str+="__\n";
                }
            }
            cout<<str<<endl;
        }
        string Board::readHorizontally(unsigned int row, unsigned int col, unsigned int howmany) {
            string str;
            for (unsigned int j = col; j < howmany + col; j++) {
                str+=this->matrix[row][j] == 0?'_':this->matrix[row][j];
            }
             return str;
        }
        void Board::checkThrow(unsigned int row,unsigned int col,unsigned int length){
            if(row<0 || col <0 || length>ROW){
                throw std::invalid_argument("invalid");
            }
        }

        string Board::readVertically(unsigned int row, unsigned int col, unsigned int howmany) {
            string str;
            for (unsigned int i = row; i < row + howmany; i++) {
                str+=this->matrix[i][col] == 0?'_':this->matrix[i][col];
            }
            return str;
        }

        void Board::insertHorizonially(unsigned int row, unsigned int col, string str) {
            unsigned int stringIndex = 0;
            this->isThereChar[row] = true;
            for (unsigned int j = col; j < str.size() + col; j++) {
                this->matrix[row][j] = str[stringIndex++];
            }
        }

        void Board::insertVertically(unsigned int row, unsigned int col, string str) {
            unsigned int stringIndex = 0;
            this->isThereChar[row] = true;
            for (unsigned int i = row; i < str.size() + row; i++) {
                this->matrix[i][col] = str[stringIndex++];
                this->isThereChar[i]=true;
            }

        }
		

		
};
