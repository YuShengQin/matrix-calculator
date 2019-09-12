#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "MyVector.h"

struct Eigen {
	std::vector<double> values;
	std::vector<std::vector<double>> vectors;
	bool flag = true;
};

struct Matrix
{
public:
	int row, col;
	bool flag = true;
	int sign = 1;
	std::string Name;
	std::vector<std::vector<double>> Data;

	Matrix() {
		row = 0;
		col = 0;
	}

	Matrix(int x, int y) {
		row = x, col = y;
		Name = "";
		for (int i = 0; i < row; i++) {
			std::vector<double>tmpVector;
			tmpVector.clear();
			for (int j = 0; j < col; j++) {
				tmpVector.push_back(0);
			}
			Data.push_back(tmpVector);
		}
	}

	void operator = (Matrix& m) {
		Name = m.Name;
		this->Data = m.Data;
		this->row = m.row;
		this->col = m.col;
		flag = m.flag;
	}

	Matrix operator +(const Matrix& m);
	Matrix operator -(const Matrix& m);
	Matrix operator *(Matrix& m);
	Matrix operator /(Matrix& m);
	int rank();
	Matrix transpose();
	std::vector<double> Det();
	Matrix inverse();
	Matrix adjoint();
	Matrix LinearSystem(Matrix &m);
	Eigen FindEigen();
	Eigen PowerMethodEigen();
	Matrix LeastSquare(Matrix &m);
	Matrix rref(char mode);
		
};

std::vector<std::vector<double>> gaussian_elimination(const std::vector<std::vector<double>>& m);
Matrix Det_gaussian_elimination(const std::vector<std::vector<double>>& m);
int det(Matrix &m, int n);
std::vector<std::vector<double>> IdentityMatrix(const std::vector<std::vector<double>>& m);
void printMatrix(const std::vector<std::vector<double>>& m);