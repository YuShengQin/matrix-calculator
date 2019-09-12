#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "MyVector.h"
#include "MyMatrix.h"
//定義向量資料結構

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	std::vector<Matrix> Matrixs;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;
	int  MatrixVariableIndex;
	//紀錄檔案路徑名稱
	std::string FileName;
public:
	int mode = 0;
	DataManager();
	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();
	std::vector<Matrix> GetMatrixs();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
	std::vector<double> fillData(std::string str, int dimention);
};

struct InputToPostfix{
	std::string result = "";
	int size = 0;
	int ValueNum = 0;
	int index = 0;

	int priority(char op) {		//比較優先權
		switch (op) {
		case '+': case '-': return 2;
		case '*': case '/': return 3;
		case '!': case '@': case '#': case '$': case '%':   case '&': 
		case '1': case '2': case '3':  case '4': case '5':  case '6': case '7': case '8': case '9': return 4;
		default:            return 0;
		}
	}

	void Postfix(std::string str);	//轉為後序表示法
};