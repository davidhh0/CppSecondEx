#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <vector>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;
using std::string;
const int ROW = 200;
const int COL = 200;
const int stringSize=50;
namespace ariel {

		ariel::Board::Board() {
            this->matrix.resize(ROW, vector<char>(COL));
            for(int i=0;i<ROW;i++){
                for(int j=0;j<COL;j++){
                    this->matrix[i][j] = '_';
                }
            }
            numberOfChangeDim=1;
            biggestStringInRow.resize(ROW, vector<int>(stringSize, 0));
            isThereChar.resize(ROW);
        }
		void Board::changeDim() {
		numberOfChangeDim++;
        this->matrix.resize(numberOfChangeDim * ROW);
        for(int i=0;i<numberOfChangeDim*ROW;i++){
            this->matrix[i].resize(numberOfChangeDim*COL);
        }
        for(int i=(numberOfChangeDim-1) * ROW;i<numberOfChangeDim * COL;i++){
            for(int j=(numberOfChangeDim-1)*COL ; j< numberOfChangeDim*COL;j++){
                this->matrix[i][j]='_';
            }
        }
        this->biggestStringInRow.resize(numberOfChangeDim * ROW);
        this->isThereChar.resize(numberOfChangeDim * ROW);
		}
	
        void Board::post(int row, int col, Direction d, string str) {
        checkThrow(row,col,str.size());

        if ((d == Direction::Horizontal && col+str.size()>this->matrix[0].size())
            || (d==Direction::Vertical && row+str.size()> this->matrix.size())){
            changeDim();
        }
        if (d == Direction::Horizontal) {
            insertHorizonially(row, col, str);
        } else {
            insertVertically(row, col, str);
        }
        }

        string Board::read(int row, int col, Direction d, int length) {
            checkThrow(row,col,length);
            if (row >= this->matrix.size() || col >= this->matrix[0].size()) {
            changeDim();
            }   
            if (d == Direction::Horizontal) {
                return readHorizontally(row, col, length);
            }
            return readVertically(row, col, length);
            
        }
        void Board::show(){
            
        }
        string Board::readHorizontally(int row, int col, int howmany) {
            string str;
            for (int j = col; j < howmany + col; j++) {
                str += this->matrix[row][j];
            }
             return str;
        }
        void Board::checkThrow(int row,int col,int length){
            if(row<0 || col <0 || length>ROW){
                throw std::invalid_argument("invalid");

            }
        }

        string Board::readVertically(int row, int col, int howmany) {
            string str;
            for (int i = row; i < row + howmany; i++) {
                str += this->matrix[i][col];
                str += '\n';
            }
            return str;
        }

        void Board::insertHorizonially(int row, int col, string str) {
            int stringIndex = 0;
            this->isThereChar[row] = true;
            for (int j = col; j < str.size() + col; j++) {
                this->matrix[row][j] = str[stringIndex++];
            
            }
        }

        void Board::insertVertically(int row, int col, string str) {
            int stringIndex = 0;
            this->isThereChar[row] = true;
            for (int i = row; i < str.size() + row; i++) {
                this->matrix[i][col] = str[stringIndex++];
            }

        }
		
};
