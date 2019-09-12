#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "MyVector.h"
#include "MyMatrix.h"
//�w�q�V�q��Ƶ��c

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	std::vector<Matrix> Matrixs;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	int  MatrixVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	int mode = 0;
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	std::vector<Matrix> GetMatrixs();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
	std::vector<double> fillData(std::string str, int dimention);
};

struct InputToPostfix{
	std::string result = "";
	int size = 0;
	int ValueNum = 0;
	int index = 0;

	int priority(char op) {		//����u���v
		switch (op) {
		case '+': case '-': return 2;
		case '*': case '/': return 3;
		case '!': case '@': case '#': case '$': case '%':   case '&': 
		case '1': case '2': case '3':  case '4': case '5':  case '6': case '7': case '8': case '9': return 4;
		default:            return 0;
		}
	}

	void Postfix(std::string str);	//�ର��Ǫ�ܪk
};