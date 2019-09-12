#include "MyMatrix.h"
#define PI 3.14159265358979323846f
Matrix Matrix::operator +(const Matrix& m) {
	Matrix tmpm;
	if (this->row == m.row && this->col == m.col) {
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				this->Data[i][j] += m.Data[i][j];
			}
		}
		tmpm = *this;
	}
	else {
		tmpm.flag = false;
	}
	return tmpm;
}

Matrix Matrix::operator -(const Matrix& m) {
	Matrix tmpm;
	if (this->row == m.row && this->col == m.col) {
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				this->Data[i][j] -= m.Data[i][j];
			}
		}
		tmpm = *this;
	}
	else {
		tmpm.flag = false;
	}
	return tmpm;
}

Matrix Matrix::operator *(Matrix& m) {
	Matrix tmpm(this->row, m.col);
	if (this->col == m.row && this->flag) {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < m.col; j++) {
				for (int k = 0; k < m.row; k++) {
					tmpm.Data[i][j] += this->Data[i][k] * m.Data[k][j];
				}
			}
		}
		tmpm.Name = this->Name;
	}
	else {
		tmpm.flag = false;
	}
	return tmpm;
}

Matrix Matrix::operator /(Matrix& m) {
	Matrix tmp;
	if (m.row == 1 && m.col == 1) {
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < this->col; j++) {
				this->Data[i][j] /= m.Data[0][0];
			}
		}
		tmp = *this;
	}
	else {
		tmp.flag = false;
	}
	return tmp;
}

int Matrix::rank() {
	std::vector<std::vector<double>> tmp = gaussian_elimination(this->Data);
	double result = this->Data.size();
	for (unsigned int i = 0; i < tmp.size(); i++) {
		if (tmp[i][i] == 0)
			result--;
	}
	return result;
}

Matrix Matrix::transpose() {
	Matrix tmp(this->col, this->row);
	for (int i = 0; i < tmp.row; i++) {
		for (int j = 0; j < tmp.col; j++) {
			tmp.Data[i][j] = this->Data[j][i];
		}
	}
	return tmp;
}

std::vector<double> Matrix::Det() {
	std::vector<double> sum;
	if (this->col != this->row) {
		sum.push_back(-1);
		sum.push_back(-1);
		return sum;
	}
	Matrix tmp = Det_gaussian_elimination(this->Data);
	double result = 1;
	for (int i = 0; i < this->row; i++) {
		result *= tmp.Data[i][i];
	}
	if (tmp.sign < 0) result *= -1;
	sum.push_back(result);
	return sum;
}

Matrix Matrix::inverse() {
	Matrix tmp;
	if (this->col != this->row) {
		tmp = *this;
		tmp.flag = false;
		return tmp;
	}
	else {
		tmp.row = this->row;
		tmp.col = this->col;
		std::vector<double> d = this->Det();
		if (fabs(d[0]) <= 1e-12) {
			tmp = *this;
			for (int i = 0; i < this->row; i++) {
				for (int j = 0; j < this->col; j++) {
					tmp.Data[i][j] = INFINITY;
				}
			}
			return tmp;
		}
		tmp.Data = gaussian_elimination(this->Data);

		return tmp;
	}
}

Matrix Matrix::adjoint() {
	if (this->col != this->row) {
		Matrix tmp;
		tmp.row = 0;
		tmp.col = 0;
		tmp.flag = false;
		return tmp;
	}
	Matrix TmpM = *this;
	std::vector<std::vector<double>> result = this->Data;
	std::vector<std::vector<double>> tempm1 = this->Data;
	for (unsigned int i = 0; i < result.size(); i++) {
		for (unsigned int j = 0; j < result[0].size(); j++) {
			tempm1 = this->Data;
			tempm1.erase(tempm1.begin() + i);	//清除row
			for (unsigned int k = 0; k < tempm1[0].size(); k++) {
				tempm1[k].erase(tempm1[k].begin() + j);	//清除collum
			}
			TmpM.Data = tempm1;
			TmpM.row = tempm1.size();
			TmpM.col = tempm1.size();
			result[i][j] = pow(-1, (i + j))* TmpM.Det()[0];
		}
	}
	this->Data = result;
	this->row = result.size();
	this->col = result.size();
	return this->transpose();
}

Matrix Matrix::LinearSystem(Matrix& m) {
	Matrix tmp = this->inverse();
	Matrix result = tmp * m;
	return result;
}

Matrix Matrix::LeastSquare(Matrix& m) {		// (AT * A)^-1 * AT * B
	Matrix tmp;
	if (this->row != m.row) {
		tmp.flag = false;
		return tmp;
	}
	tmp = (this->transpose()) * *this;
	if (tmp.Det()[0] == 0) {
		tmp.flag = false;
		return tmp;
	}
	tmp = tmp.inverse();
	tmp = tmp * (this->transpose());
	tmp = tmp * m;
	return tmp;
}

Eigen Matrix::FindEigen() {
	Eigen tmp;
	if (this->row != this->col) {
		tmp.flag = false;
		return tmp;
	}
	if (this->row == 2) {
		double a = 0, b = 0, result1 = 0, result2 = 0;
		b = -1 * (this->Data[0][0] + this->Data[1][1]);
		a = (this->Data[0][0] * this->Data[1][1]) - (this->Data[0][1] * this->Data[1][0]);
		result1 = (sqrt(pow(b, 2) - 4 * a) - b) / 2.0f;
		result2 = (sqrt(pow(b, 2) - 4 * a) * -1 - b) / 2.0f;

		tmp.values.push_back(result1);
		tmp.values.push_back(result2);
		Vector tv;
		tv.Dimension = 2;
		tv.Data.push_back(this->Data[0][1]);
		tv.Data.push_back(result1 - this->Data[0][0]);

		if (tv.Data[0] < 0) {
			tv.Data[0] *= -1;
			tv.Data[1] *= -1;
		}
		tv = tv.normal();
		tmp.vectors.push_back(tv.Data);
		tv.Data.clear();
		tv.Data.push_back(this->Data[0][1]);
		tv.Data.push_back(result2 - this->Data[0][0]);

		if (tv.Data[0] < 0) {
			tv.Data[0] *= -1;
			tv.Data[1] *= -1;
		}

		tv = tv.normal();
		tmp.vectors.push_back(tv.Data);
	}
	else if (this->row == 3) {
		double Q = 0, R = 0, a = 0, b = 0, c = 0, tc = 1, t = 0;
		double result1 = 0, result2 = 0, result3 = 0;
		a = (this->Data[0][0] + this->Data[1][1] + this->Data[2][2])* -1;

		b = (this->Data[0][0] * this->Data[2][2]) + (this->Data[1][1] * this->Data[2][2]) + (this->Data[0][0] * this->Data[1][1])
			- (this->Data[0][2] * this->Data[2][0]) - (this->Data[1][2] * this->Data[2][1]) - (this->Data[0][1] * this->Data[1][0]);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j + i < 3)
					tc *= this->Data[2 - j][j + i];
				else tc *= this->Data[2 - j][j + i - 3];
			}
			c += tc;
			tc = 1;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (j + i < 3)
					tc *= this->Data[j][j + i];
				else tc *= this->Data[j][j + i - 3];
			}
			c -= tc;
			tc = 1;
		}
		Q = (pow(a, 2) - 3 * b) / 9.0f;
		R = (2 * pow(a, 3) - 9 * a*b + 27 * c) / 54.0f;
		t = acos(R / sqrt(pow(Q, 3)));
		result1 = -2 * sqrt(Q) * cos(t / 3.0f) - a / 3;
		result2 = -2 * sqrt(Q) * cos((t + 2 * PI) / 3.0f) - a / 3;
		result3 = -2 * sqrt(Q) * cos((t - 2 * PI) / 3.0f) - a / 3;
		tmp.values.push_back(result1);
		tmp.values.push_back(result2);
		tmp.values.push_back(result3);

		double x3, x2, x1;
		Vector tv;
		std::vector<std::vector<double>> tmpD = this->Data;
		for (int j = 0; j < 3; j++) {
			tmpD = this->Data;
			for (int i = 0; i < 3; i++) {
				if (j == 0) tmpD[i][i] -= result1;
				else if (j == 1) tmpD[i][i] -= result2;
				else tmpD[i][i] -= result3;
			}
			tmpD = gaussian_elimination(tmpD);
			if (tmpD[0][0] == 0) {
				x3 = 0;
				x2 = 0;
				x1 = 1;
			}
			else if (tmpD[1][1] == 0) {
				x3 = 0;
				x2 = 1;
				x1 = tmpD[0][1] * -1 / tmpD[0][0];
			}
			else if (tmpD[2][2] == 0) {
				x3 = 1;
				x2 = tmpD[1][2] * -1 / tmpD[1][1];
				x1 = (tmpD[0][2] * -1 + tmpD[0][1] * -1 * x2) / tmpD[0][0];
			}
			else {
				x3 = tmpD[2][2];
				x2 = (tmpD[1][2] * -1 * x3) / tmpD[1][1];
				x1 = ((tmpD[0][1] * -1 * x2 - (tmpD[0][2] * x3)) / tmpD[0][0]);
			}
			tv.Dimension = 3;
			tv.Data.push_back(x1);
			tv.Data.push_back(x2);
			tv.Data.push_back(x3);
			if (tv.Data[0] < 0) {
				for (int i = 0; i < 3; i++) tv.Data[i] *= -1;
			}
			tv = tv.normal();
			tmp.vectors.push_back(tv.Data);
			tv.Data.clear();
		}
	}
	return tmp;
}
Eigen Matrix::PowerMethodEigen() {
	Eigen tmp;
	if (this->row != this->col) {
		tmp.flag = false;
		return tmp;
	}
	int n = this->row;

	std::vector<double>start(n, 1);
	std::vector<double>c(n);
	double temp = 0;
	double d = 0;
	do
	{
		for (int i = 0; i < n; i++)
		{
			c[i] = 0;
			for (int j = 0; j < n; j++)
				c[i] += this->Data[i][j] * start[j];
		}
		for (int i = 0; i < n; i++)
			start[i] = c[i];

		temp = d;
		d = 0;

		for (int i = 0; i < n; i++)
		{
			if (fabs(start[i]) > fabs(d))
				d = start[i];
		}
		for (int i = 0; i < n; i++)
			start[i] /= d;
	} while (fabs(d - temp) > 0.000000000001);

	Vector tv;
	tv.Dimension = n;
	for (int k = 0; k < n; k++)	{
		tv.Data.push_back(start[k]);
	}
	if (tv.Data[0] < 0) {
		for (int i = 0; i < n; i++) tv.Data[i] *= -1;
	}
	tv = tv.normal();
	tmp.vectors.push_back(tv.Data);

	//std::cout << "Eigen value is : " << d << std::endl;
	tmp.values.push_back(d);
	//std::cout << "Eigenvector is: ";
	//for (int i = 0; i < n; i++)
		//std::cout << tv.Data[i] << std::endl;

	return tmp;
}
Matrix Matrix::rref(char mode) {
	Matrix tmpM(this->row, this->col);

	std::vector<std::vector<double>> result;
	if (mode == 'L') {
		tmpM.Data = gaussian_elimination(this->Data);
		tmpM = (*this * (tmpM.inverse()));
		for (unsigned int i = 0; i < tmpM.row; i++) {
			for (unsigned int j = 0; j < tmpM.col; j++) {
				if (fabs(tmpM.Data[i][j]) < 0.000001)
					tmpM.Data[i][j] = 0;
			}
		}
		return tmpM;
	}
	else {
		std::vector<std::vector<double>> tmp = this->Data;
		for (int i = 0; i < tmp.size(); ++i)
		{
			// 如果上方row的首項係數為零，則考慮與下方row交換。
			if (tmp[i][i] == 0)
				for (int j = i + 1; j < tmp.size(); ++j)
					if (tmp[j][i] != 0)
					{
						// 交換上方row與下方row。
						tmp[i].swap(tmp[j]);
						break;
					}

			if (tmp[i][i] == 0) continue;

			// 窮舉並消去下方row。
			for (int j = i + 1; j < tmp.size(); ++j) {
				if (tmp[j][i] != 0)
				{
					double t = tmp[j][i] / tmp[i][i];
					for (int k = i; k < tmp[0].size(); ++k) {
						tmp[j][k] -= tmp[i][k] * t;
						if (fabs(tmp[j][k]) < 0.000001)
							tmp[j][k] = 0;
					}
				}
			}
		}
		tmpM.Data = tmp;
		return tmpM;
	}
}

Matrix Det_gaussian_elimination(const std::vector<std::vector<double>>& m) {
	Matrix tmp;
	tmp.Data = m;
	int sign = 1;
	for (int i = 0; i < tmp.Data.size(); ++i)
	{
		// 如果上方row的首項係數為零，則考慮與下方row交換。
		if (fabs(tmp.Data[i][i]) <= 0.0000000000001)
			for (int j = i + 1; j < tmp.Data.size(); ++j)
				if (fabs(tmp.Data[j][i]) > 0.0000000000001)
				{
					tmp.sign *= -1;
					// 交換上方row與下方row。
					tmp.Data[i].swap(tmp.Data[j]);
					break;
				}

		if (fabs(tmp.Data[i][i]) <= 0.0000000000001) continue;
		// 上方row的首項係數調整成一。目的是為了讓對角線皆為一。
		double t = tmp.Data[i][i];

		for (int j = i + 1; j < tmp.Data.size(); ++j) {
			if (fabs(tmp.Data[j][i]) > 0.0000000000001)
			{
				double t = tmp.Data[j][i] / tmp.Data[i][i];
				for (int k = i; k < tmp.Data[0].size(); ++k) {
					tmp.Data[j][k] -= tmp.Data[i][k] * t;
					//if (abs(tmp.Data[j][k]) < 0.0000000000001)
					//	tmp.Data[j][k] = 0;
				}
			}
		}
	}
	return tmp;
}

std::vector<std::vector<double>> gaussian_elimination(const std::vector<std::vector<double>>& m) {
	std::vector<std::vector<double>> tmp = m;
	std::vector<std::vector<double>> Identy = IdentityMatrix(m);

	for (int i = 0; i < tmp.size(); ++i)
	{
		// 如果上方row的首項係數為零，則考慮與下方row交換。
		if (fabs(tmp[i][i]) <= 0.0000000000001)
			for (int j = i + 1; j < tmp.size(); ++j)
				if (fabs(tmp[j][i]) > 0.0000000000001)
				{
					// 交換上方row與下方row。
					tmp[i].swap(tmp[j]);
					Identy[i].swap(Identy[j]);
					break;
				}
		if (fabs(tmp[i][i]) <= 0.0000000000001) continue;
		// 上方row的首項係數調整成一。目的是為了讓對角線皆為一。

		for (int j = i + 1; j < tmp.size(); ++j) {
			if (fabs(tmp[j][i]) > 0.0000000000001)
			{
				double t = tmp[j][i] / tmp[i][i];
				for(int k = 0; k < tmp[0].size();k++)
					Identy[j][k] -= Identy[i][k] * t;
				for (int k = i; k < tmp[0].size(); ++k) {
					tmp[j][k] -= tmp[i][k] * t;
					
					if (fabs(tmp[j][k]) < 1e-12)
						tmp[j][k] = 0;
				//	if (abs(Identy[j][k]) < 1e-12) Identy[j][k] = 0;
				}
			}
		}
	}
	
	int size = tmp.size();
	double tt = tmp[0][0];
	Identy[0][0] /= tt;
	for (int k = 0; k < tmp.size(); k++) {
		if (fabs(tmp[0][k]) < 1e-12) continue;
		tmp[0][k] /= tt;
	}

	for (int i = tmp.size()-1; i > 0; i--) {
		if(fabs(tmp[i][i]) < 1e-12) continue;
		double t = tmp[i][i];
		tmp[i][i] /= t;

		for (int k = 0; k < tmp.size(); k++) {
			Identy[i][k] /= t;
		}
		for (int j = 0; j < i; j++) {
			if (fabs(tmp[i - 1 - j][i]) < 1e-12) continue;
			t = tmp[i - 1 - j][i] / tmp[i][i];
			tmp[i - 1 - j][i] -= tmp[i][i] * t;
			for (int k = 0; k < tmp.size(); k++) {
				Identy[i - j-1][k] -= (Identy[i][k] * t);
			}
		}
	}
	return Identy;
}

int det(Matrix &m, int n) {
	if (n == 2) return m.Data[0][0] * m.Data[1][1] - m.Data[1][0] * m.Data[0][1];
	else {
		std::vector<std::vector<double>>tmp = gaussian_elimination(m.Data);
		int flag = 1;
		for (int i = 0; i < n; i++) {
			if (tmp[i][i] == 0) flag = 0;
		}
		return flag;
	}
}

std::vector<std::vector<double>> IdentityMatrix(const std::vector<std::vector<double>>& m) {
	std::vector<std::vector<double>> matrix = m;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if (i == j) matrix[i][j] = 1;
			else matrix[i][j] = 0;
		}
	}
	return matrix;
}

void printMatrix(const std::vector<std::vector<double>>& m) {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			std::cout << m[i][j] << " ";
		}
		std::cout << "\n";
	}
}