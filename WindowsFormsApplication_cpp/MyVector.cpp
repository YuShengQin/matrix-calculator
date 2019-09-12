#include "MyVector.h"
#include "MyMatrix.h"
#include<iostream>
#include<sstream>
#include<cmath>

Vector Vector::operator + (const Vector &v) {
	Vector tmp;
	if (v.Dimension == Dimension) {
		tmp = *this;
		for (int i = 0; i < v.Dimension; i++) {
			tmp.Data[i] += v.Data[i];
		}
	}
	else {
		tmp.flag = false;
	}
	return tmp;
}

Vector Vector::operator-(const Vector &v) {
	Vector tmp;
	if (v.Dimension == this->Dimension) {
		tmp = *this;
		for (int i = 0; i < v.Dimension; i++) {
			tmp.Data[i] -= v.Data[i];
		}
	}
	else {
		tmp.flag = false;
	}
	return tmp;
}

Vector Vector::operator*(Vector &v) {
	Vector tmp;
	double sum = 0;
	if (v.Dimension == this->Dimension) {
		for (int i = 0; i < v.Dimension; i++) {
			sum += v.Data[i] * this->Data[i];
		}
		tmp.Dimension = 1;
		tmp.Data.push_back(sum);
	}
	else {
		if (v.Dimension == 1) {
			tmp = *this;
			for (int i = 0; i < this->Dimension; i++) {
				tmp.Data[i] *= v.Data[0];
			}
		}
		else if (this->Dimension == 1) {
			tmp = v;
			for (int i = 0; i < v.Dimension; i++) {
				tmp.Data[i] *= this->Data[0];
			}
		}
		else tmp.flag = false;
	}
	return tmp;
}

Vector Vector::operator/(Vector &v) {
	Vector tmp;
	tmp = *this;
	if (v.Dimension == 1) {
		for (int i = 0; i < this->Dimension; i++) {
			tmp.Data[i] /= v.Data[0];
		}
	}
	else tmp.flag = false;
	return tmp;
}

Vector Vector::norm() {
	Vector tmpV;
	tmpV.Dimension = 1;
	double num = 0;
	for (int i = 0; i < Data.size(); i++) {
		num += Data[i] * Data[i];
	}
	num = sqrt(num);
	tmpV.Data.push_back(num);
	return tmpV;
}

Vector Vector::normal() {
	Vector tmpV;
	double num = 0;
	tmpV.Dimension = this->Dimension;
	tmpV.Name = this->Name;
	for (int i = 0; i < Data.size(); i++) {
		num += Data[i] * Data[i];
	}
	num = sqrt(num);
	for (int i = 0; i < Data.size(); i++) {
		if (num != 0) tmpV.Data.push_back(Data[i] / num);
		else tmpV.Data.push_back(0.0f);
	}
	return tmpV;
}

Vector Vector::cross(Vector &v) {
	Vector tmpV;
	if (v.Dimension != this->Dimension) {
		tmpV.flag = false;
	}
	else if (v.Dimension == 3) {
		tmpV.Name = Name;
		tmpV.Dimension = v.Dimension;
		tmpV.Data.push_back(Data[1] * v.Data[2] - Data[2] * v.Data[1]);
		tmpV.Data.push_back((Data[0] * v.Data[2] - Data[2] * v.Data[0])*-1);
		tmpV.Data.push_back(Data[0] * v.Data[1] - Data[1] * v.Data[0]);
	}
	return tmpV;
}

Vector Vector::com(Vector &v) {
	return (*this * v / v.norm());
}

Vector Vector::proj(Vector &v) {
	Vector tmp;
	if (Dimension != v.Dimension) {
		tmp.flag = false;
	}
	else
	{
		return (v * (this->com(v) / v.norm()));
	}
}

Vector Vector::area(Vector &v) {
	Vector tmp;
	tmp = (this->norm() * this->norm()) * (v.norm() * v.norm()) - ((*this * v) * (*this * v));
	double result = tmp.Data[0];
	result = sqrt(result) / 2.0f;
	tmp.Data[0] = result;
	return tmp;
}

int Vector::parallel(Vector &v) {
	Vector tmp;
	tmp = ((this->normal()) - (v.normal()));
	if (!tmp.flag) return -1;
	int flag = 1;
	for (int i = 0; i < tmp.Dimension; i++) {
		if (abs(tmp.Data[i]) >= 0.000001) flag = 0;
	}
	return flag;
}

int Vector::orthogonal(Vector &v) {
	Vector tmp;
	tmp = *this * v;
	if (tmp.flag == -1) return -1;
	if (abs(tmp.Data[0]) < 0.000000001) return 1;
	else return 0;
}

Vector Vector::angle(Vector &v) {
	Vector tmp;
	tmp = ((*this * v) / ((this->norm()) * (v.norm())));
	double result = acos(tmp.Data[0]) / 3.14159265358979323846 * 180.0f;
	tmp.Data[0] = result;
	return tmp;
}

int Vector::isLi(std::vector<Vector> LinearSystem) {
	int Dim = LinearSystem[0].Dimension;
	Matrix m(LinearSystem.size(), Dim);
	Matrix Tm(LinearSystem.size(), Dim);
	if(LinearSystem.size() != Dim) return -1;
	for (int i = 1; i < LinearSystem.size(); i++) {
		if (LinearSystem[i].Dimension != Dim) return -1;
	}
	for (int i = 0; i < LinearSystem.size(); i++) {
		for (int j = 0; j < Dim ; j++) {
			m.Data[i][j] = LinearSystem[i].Data[j];
		}
	}
	int sum = det(m, Dim);
	return sum;
}

std::vector<Vector> Vector::OrthonormalBasis(std::vector<Vector> LinearSystem) {
	//Matrix result;
	Vector tmp;
	std::vector<Vector> result;
	//std::vector<std::vector<double>> result;
	//判斷每條向量的維度是否與向量數一致
	for (int i = 0; i < LinearSystem.size(); i++)
	{
		if (LinearSystem[i].Dimension != LinearSystem.size()) {
			Vector error;
			error.flag = false;
			result.push_back(error);
			return result;
		}
	}
	//判斷每條向量彼此是否線性獨立
	if (tmp.isLi(LinearSystem) != 0 && tmp.isLi(LinearSystem) != -1)
	{
		result.push_back(LinearSystem[0].normal());
		//result.push_back(normal(v[0]));
		for (int i = 1; i < LinearSystem.size(); i++)
		{
			std::vector<Vector> dotResult;
			dotResult.push_back((LinearSystem[i] * result[i - 1]) / ((result[i - 1].norm()) * (result[i - 1].norm())));
		//	dotResult.push_back(dot(v[i], result[i - 1]) / (norm(result[i - 1]) * norm(result[i - 1])));
			tmp = LinearSystem[i] - (dotResult[0] * result[i - 1]);
			//tmp = Subtration(v[i], ScalarMuiti(dotResult, result[i - 1]));
			dotResult.clear();
			for (int j = i - 1; j > 0; j--)
			{
				dotResult.push_back((LinearSystem[i] * result[j - 1]) / ((result[j - 1].norm()) * (result[j - 1].norm())));
				//dotResult.push_back(dot(v[i], result[j - 1]) / (norm(result[j - 1]) * norm(result[j - 1])));
				tmp = tmp - (dotResult[0] * result[j - 1]);
			//	tmp = Subtration(tmp, ScalarMuiti(dotResult, result[j - 1]));
				dotResult.clear();
			}
			result.push_back(tmp.normal());
		}
		for (int i = 0; i < result.size(); i++)
			for (int j = 0; j < result[i].Dimension; j++)
			{
				if (abs(result[i].Data[j]) < 0.00000000000001)
					result[i].Data[j] = 0;
			}
	}
	return result;
}

