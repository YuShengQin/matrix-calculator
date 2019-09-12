#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include "MyMatrix.h"

struct Vector
{
public:
	std::string Name;
	std::vector<double> Data;
	int Dimension;
	bool flag = true;

	void operator = (Vector& v) {
		Name = v.Name;
		this->Data = v.Data;
		this->Dimension = v.Dimension;
		flag = v.flag;
	}

	Vector operator +(const Vector& v);
	Vector operator -(const Vector& v);
	Vector operator *(Vector& v);
	Vector operator /(Vector& v);
	Vector norm();
	Vector normal();
	Vector cross(Vector &v);
	Vector com(Vector &v);
	Vector proj(Vector &v);
	Vector area(Vector &v);
	int parallel(Vector &v);
	int orthogonal(Vector &v);
	Vector angle(Vector &v);
	int isLi(std::vector<Vector> LinearSystem);
	std::vector<Vector> OrthonormalBasis(std::vector<Vector> LinearSystem);
	//Vector plane(Vector &v);
};

