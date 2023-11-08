//
// Created by Dani on 2023. 11. 08..
//


#include "Matrix.h"
#include <random>
#include <iostream>

using namespace std;

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    mElements = new double *[mRows];
    for (int i = 0; i < mRows; i++) {
        mElements[i] = new double[mCols];
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    mElements = what.mElements;
    what.mElements = nullptr;

}

Matrix::~Matrix() {
    if (this->mElements != nullptr) {
        for (int i = 0; i < this->mRows; i++) {
            delete[] this->mElements[i];
        }
        delete[] this->mElements;
    }

}

void Matrix::fillMatrix(double value) {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = value;
        }
    }
}

void Matrix::randomMatrix(int a, int b) {
    random_device rd; // seed the random number generator named rd
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(a, b); // return a number in the given range

    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            mElements[i][j] = dist(mt);
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            os << mElements[i][j] << " ";
        }
        os << endl;
    }

}

bool Matrix::isSquare() const {
    return mRows == mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows == y.mRows && x.mCols == y.mCols) {
        throw std::out_of_range("Cannot add matrices with different dimensions.");
    }
    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            result.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }
    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mCols != y.mRows) {
        throw std::out_of_range("Cannot multiply matrices with different dimensions.");
    }
    Matrix result(x.mRows, y.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < x.mCols; ++j) {
            for (int k = 0; k < y.mCols; ++k) {
                result.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }
    }
    return Matrix();
}

istream &operator>>(istream &is, Matrix &mat) {

    for (int i = 0; i < mat.mRows; ++i) {
        for (int j = 0; j < mat.mCols; ++j) {
            is >> mat.mElements[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix(os);
    return os;
}

double *Matrix::operator[](int index) {
    return mElements[index];
}

double *Matrix::operator[](int index) const {
    return mElements[index];
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if (this == &mat) {
        return  *this;
    }
    if(this->mRows != mat.mRows || this->mCols != mat.mCols){
        throw std::out_of_range("Cannot copy matrices with different dimensions.");
    }
    for (int i = 0; i < mRows; ++i) {
        for (int j = 0; j < mCols; ++j) {
            this->mElements[i][j] = mat.mElements[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&mat) {
    if (this == &mat) {
        return  *this;
    }
    if(this->mElements != nullptr){
        for (int i = 0; i < mRows; ++i) {
            delete[] this->mElements[i];
        }
        delete[] this->mElements;
    }
    this->mElements = mat.mElements;
    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    mat.mElements = nullptr;
    mat.mRows = 0;
    mat.mCols = 0;
    return *this;
}


