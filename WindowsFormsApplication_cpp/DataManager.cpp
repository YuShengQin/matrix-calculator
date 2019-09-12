#include"DataManager.h"
#include<iostream>
#include<sstream>
#include<cmath>

DataManager::DataManager()
{
	VectorVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		this->Vectors.clear();
		this->VectorVariableIndex = 0;
		this->Matrixs.clear();
		this->MatrixVariableIndex = 0;

		std::vector<double> tmpVectorData;
		std::vector<std::vector<double>> tmpMatrixData;
		std::string tmp;
		Vector myVector;
		Matrix myMatrix;
		std::getline(fin, tmp);//讀入個數

		int count = std::stod(tmp);
		for (int i = 0; i < count; i++) {
			std::getline(fin, tmp);
			if (tmp == "V") {		//Read Vector
				mode = 0;
				std::getline(fin, tmp); //vector維度
				myVector.Dimension = std::stod(tmp);
				std::getline(fin, tmp);
				tmpVectorData = fillData(tmp, myVector.Dimension);
				char name[2] = { 0 };
				name[0] = 'A' + this->VectorVariableIndex++;
				myVector.Name = (name);
				myVector.Data = tmpVectorData;
				this->Vectors.push_back(myVector);
			}
			else if (tmp == "M") {
				mode = 1;
				std::getline(fin, tmp); //matrix 維度
				std::istringstream ss(tmp);
				ss >> myMatrix.row;
				ss >> myMatrix.col;
				for (int j = 0; j < myMatrix.row; j++) {
					std::getline(fin, tmp);
					std::istringstream ss(tmp);
					tmpVectorData = fillData(tmp, myMatrix.col);
					tmpMatrixData.push_back(tmpVectorData);
				}
				char name[2] = { 0 };
				name[0] = 'A' + this->MatrixVariableIndex++;
				myMatrix.Name = (name);
				myMatrix.Data = tmpMatrixData;
				this->Matrixs.push_back(myMatrix);
				tmpMatrixData.clear();
			}
		}
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}

std::vector<Matrix> DataManager::GetMatrixs()
{
	return Matrixs;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

std::vector<double> DataManager::fillData(std::string str, int dimention) {
	std::string tmp;
	std::vector<double> data;
	std::istringstream ss(str);
	for (int i = 0; i < dimention; i++) {
		ss >> tmp;
		data.push_back(std::stod(tmp));
	}
	return data;
}

void InputToPostfix::Postfix(std::string str) {
	str = "(" + str + ")";
	std::cout << str << std::endl;
	char *postfix = new char[str.size() - 2];
	char *stack = new char[str.size()];
	int pi = 0;

	for (int i = 0, top = 0; i < str.size(); i++) {
		switch (str[i]) {
		case '(':              // 運算子堆疊
			stack[++top] = str[i];
			break;
		case '+': case '-': case '*': case '/':case '!': case '@': case '#': case '$': case '%':  case '&':
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8':case '9':
			while (priority(stack[top]) >= priority(str[i])) {
				postfix[pi++] = stack[top--];
			}
			stack[++top] = str[i]; // 存入堆疊
			break;
		case ')':
			while (stack[top] != '(') { // 遇 ) 輸出至 (
				postfix[pi++] = stack[top--];
			}
			top--;  // 不輸出 (
			break;
		default:  // 運算元直接輸出
			postfix[pi++] = str[i];
			ValueNum++;
			break;
		}
	}
	std::string tmps(postfix);
	result.assign(tmps, 0, pi);
	size = pi;
	free(postfix);
	free(stack);
}