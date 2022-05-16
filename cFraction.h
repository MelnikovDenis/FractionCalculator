#pragma once
#include <iostream>
#include <exception>
#include <cmath>
using namespace std;
class cFraction {
private:
	int numer = 1;
	int denumer = 1;
	int sign = 1;
public:
	//конструкторы, деструктор и оператор присваивания
	cFraction() {

	}
	cFraction(const int& numerator, const int& denumerator, const int& sign = 1) {
		setSign(sign);
		setNumer(numerator);
		setDenumer(denumerator);		
	}
	cFraction(const cFraction& cf) {
		setNumer(cf.getNumer());
		setDenumer(cf.getDenumer());
		setSign(cf.getSign());
	}
	cFraction& operator=(const cFraction& cf) {
		setNumer(cf.getNumer());
		setDenumer(cf.getDenumer());
		setSign(cf.getSign());
		return *this;
	}
	~cFraction() {

	}

	//геттеры
	int getNumer() const { return numer; }
	int getDenumer() const { return denumer; }
	int getSign() const { return sign; }

	//сеттеры
	void setNumer(const int& numerator) {
		if (numerator > 0) numer = numerator;
		else if (numerator == 0) {
			numer = numerator;
			denumer = 1;
			sign = 1;
		}
		else throw invalid_argument("Числитель должен быть >= 0");
	}
	void setDenumer(const int& denumerator) {
		if (denumerator > 0) denumer = denumerator;
		else throw invalid_argument("Знаменталь должен быть > 0");
	}
	void setSign(const int& sign) {
		if (numer == 0) {
			if (sign == 1) this->sign = sign;
			else throw invalid_argument("Знак должен быть положительным, если дробь равна 0");
		}
		else {
			if (sign == 1 || sign == -1) this->sign = sign;
			else throw invalid_argument("Знак должен быть равен 1 или -1");
		}

	}

	//алгоритм евклида
	static int getGCD(int num1, int num2) {
		while (num1 != 0 && num2 != 0) {
			if (num1 > num2) num1 %= num2;
			else num2 %= num1;
		}
		return num1 + num2;
	}
	//сокращение дроби
	void reduce() {
		if (numer == 0) {
			setDenumer(1);
			setSign(1);
		}
		else {
			int gcd = getGCD(numer, denumer);
			setNumer(numer / gcd);
			setDenumer(denumer / gcd);
		}
	}
	//перевод обыкновенной дроби в десятичную
	double toDouble() const {
		return double(sign) * double(numer) / double(denumer);
	}
	//десятичная дробь в обыкновенную
	static cFraction toCFraction(double num) {
		if (num != 0) {
			cFraction result;
			if (num < 0) {
				num *= -1.0;
				result.setSign(-1);
			}
			int rNum_i = int(num);
			double rNum_d = double(rNum_i);
			while (num - rNum_d > 0 && rNum_i < 214748364) {
				num *= 10;
				rNum_i = int(num);
				rNum_d = double(rNum_i);
				result.setDenumer(result.denumer * 10);
			}
			result.setNumer(rNum_i);
			result.reduce();
			return result;
		}
		else return cFraction(0, 1, 1);
	}
	//обратная дробь
	cFraction getReverse() const {
		if (denumer != 0) return cFraction(denumer, numer, sign);
		else return *this;
	}

	cFraction operator+(const double& num) const {
		cFraction cf = toCFraction(num);
		return *this + cf;
	}
	cFraction operator*(const double& num) const {
		cFraction cf = toCFraction(num);
		return *this * cf;
	}
	cFraction operator/(const double& num) const {
		cFraction cf = toCFraction(num);
		return *this / cf;
	}
	cFraction operator-(const double& num) const {
		cFraction cf = toCFraction(num);
		return *this - cf;
	}

	static double Sum_d(const double& num, const cFraction& cf) {
		return num + cf.toDouble();
	}
	static double Mul_d(const double& num, const cFraction& cf) {
		return num * cf.toDouble();
	}
	static double Div_d(const double& num, const cFraction& cf) {
		return num / cf.toDouble();
	}
	static double Sub_d(const double& num, const cFraction& cf) {
		return num - cf.toDouble();
	}

	cFraction operator*(const int& num) const {
		if (this->getNumer() != 0) {
			cFraction result;
			result.setNumer(abs(num) * numer);
			result.setDenumer(denumer);
			result.setSign((abs(num) / num) * sign);
			result.reduce();
			return result;
		}
		else return cFraction(0, 1, 1);
	}
	cFraction operator+(const cFraction& cf) const {
		cFraction result;
		if (this->sign == 1) {
			if (cf.sign == 1) {
				result.setNumer(this->numer * cf.denumer + this->denumer * cf.numer);
				result.setDenumer(cf.denumer * this->denumer);
			}
			else {
				if (abs(this->toDouble()) > abs(cf.toDouble())) {
					result.setNumer(this->numer * cf.denumer - this->denumer * cf.numer);
					result.setDenumer(cf.denumer * this->denumer);

				}
				else if (abs(this->toDouble()) < abs(cf.toDouble())) {
					result.setNumer(this->denumer * cf.numer - this->numer * cf.denumer);
					result.setDenumer(cf.denumer * this->denumer);
					result.setSign(-1);
				}
				else {
					result.setNumer(0);
				}
			}
		}
		else {
			if (cf.sign == -1) {
				result.setNumer(this->numer * cf.denumer + this->denumer * cf.numer);
				result.setDenumer(cf.denumer * this->denumer);
				result.setSign(-1);
			}
			else {
				if (abs(this->toDouble()) < abs(cf.toDouble())) {
					result.setNumer(this->denumer * cf.numer - this->numer * cf.denumer);
					result.setDenumer(cf.denumer * this->denumer);
				}
				else if (abs(this->toDouble()) > abs(cf.toDouble())) {
					result.setNumer(this->numer * cf.denumer - this->denumer * cf.numer);
					result.setDenumer(cf.denumer * this->denumer);
					result.setSign(-1);
				}
				else {
					result.setNumer(0);
				}
			}
		}
		result.reduce();
		return result;
	}
	cFraction operator-(const cFraction& cf) const {
		return *this + (cf * -1);
	}
	cFraction operator*(const cFraction& cf) const {
		cFraction result;
		result.setNumer(this->numer * cf.numer);
		result.setDenumer(this->denumer * cf.denumer);
		result.setSign(this->sign * cf.sign);
		result.reduce();
		return result;
	}
	cFraction operator/(const cFraction& cf) const {
		return *this * cf.getReverse();
	}
};

