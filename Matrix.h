//
// Created by Сергей Новичков on 23.10.16.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <vector>

template <class T>
class Matrix {
public:
    Matrix(size_t n = 0, size_t m = 0);
    Matrix(const Matrix &mt);
    Matrix(Matrix &&mt);
    ~Matrix();
    bool operator==(const Matrix &mt) const;
    bool operator!=(const Matrix &mt) const;
    Matrix& operator=(const Matrix &mt);
    Matrix& operator=(Matrix &&mt);
    T* operator[](int i);
    T getIJ(int i, int j) const;
    void setIJ(int i, int j, T val);
    const Matrix operator-() const;
    const Matrix operator+() const;
    Matrix operator+(const Matrix &mt) const;
    Matrix operator-(const Matrix &mt) const;
    Matrix operator*(const T &x) const;
    Matrix operator/(const T &x) const;
    Matrix& operator+=(const Matrix &mt);
    Matrix& operator-=(const Matrix &mt);
    Matrix& operator*=(const T &x);
    Matrix& operator/=(const T &x);
    Matrix operator*(const Matrix &mt) const;
    Matrix& operator*=(const Matrix &mt);
    void swap(Matrix &other);
    size_t getHeight();
    size_t getWidth();
private:
    T** matr;
    size_t n, m;
};

template <class T>
Matrix<T>::Matrix(size_t n, size_t m) : n(n), m(m) {
    matr = n ? (new T*[n]) : 0;
    for (int i = 0; i < n; ++i)
        matr[i] = m ? (new T[m]) : 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] = 0;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T> &mt) {
    n = mt.n;
    m = mt.m;
    matr = n ? (new T*[n]) : 0;
    for (int i = 0; i < n; ++i)
        matr[i] = m ? (new T[m]) : 0;
    n = mt.n;
    m = mt.m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] = mt.matr[i][j];
}

template <class T>
Matrix<T>::Matrix(Matrix<T> &&mt) {
    matr = mt.matr;
    n = mt.n;
    m = mt.m;
    mt.matr = 0;
}

template <class T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < n; ++i)
        if (matr[i])
            delete[] matr[i];
    if (matr)
        delete[] matr;
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T> &mt) const {
    if (n != mt.n || m != mt.m)
        return false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matr[i][j] != mt.matr[i][j])
                return false;
    return true;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &mt) const {
    if (n != mt.n || m != mt.m)
        return true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matr[i][j] != mt.matr[i][j])
                return true;
    return false;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T> &mt) {
    if (this != &mt) {
        Matrix<T> copied(mt);
        this->swap(copied);
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(Matrix &&mt) {
    swap(mt);
    return (*this);
}

template <class T>
T* Matrix<T>::operator[](int i) {
    if (i < 0 || i >= n) {
        std::cerr << "Index error\n";
        exit(1);
    }
    return matr[i];
}

template <class T>
T Matrix<T>::getIJ(int i, int j) const {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        std::cerr << "Index error in getIJ\n";
        exit(1);
    }
    return matr[i][j];
}

template <class T>
void Matrix<T>::setIJ(int i, int j, T val) {
    if (i < 0 || j < 0 || i >= n || j >= m) {
        std::cerr << "Index error in setIJ\n";
        exit(1);
    }
    matr[i][j] = val;
}

template <class T>
const Matrix<T> Matrix<T>::operator-() const {
    Matrix<T> ans(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans.matr[i][j] = -matr[i][j];
    return ans;
}

template <class T>
const Matrix<T> Matrix<T>::operator+() const {
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &mt) const {
    if (n != mt.n || m != mt.m) {
        std::cerr << "Error operator + do not match the dimensions of the matrices\n";
    }
    Matrix<T> ans(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans.matr[i][j] = matr[i][j] + mt.matr[i][j];
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &mt) const {
    if (n != mt.n || m != mt.m) {
        std::cerr << "Error operator - do not match the dimensions of the matrices\n";
    }
    Matrix<T> ans(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans.matr[i][j] = matr[i][j] - mt.matr[i][j];
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T &x) const {
    Matrix<T> ans(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans.matr[i][j] = matr[i][j] * x;
    return ans;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T &x) const {
    Matrix<T> ans(n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans.matr[i][j] = matr[i][j] / x;
    return ans;
}

template <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &mt) {
    if (n != mt.n || m != mt.m) {
        std::cerr << "Error operator += do not match the dimensions of the matrices\n";
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] += mt.matr[i][j];
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &mt) {
    if (n != mt.n || m != mt.m) {
        std::cerr << "Error operator -= do not match the dimensions of the matrices\n";
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] -= mt.matr[i][j];
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const T &x) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] *= x;
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator/=(const T &x) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matr[i][j] /= x;
    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix &mt) const {
    if (m != mt.n) {
        std::cerr << "Don't correct size matrices in operator *\n";
        exit(1);
    }
    Matrix<T> ans(n, mt.m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            for (int k = 0; k < m; ++k) {
                ans.matr[i][j] += matr[i][k] * mt.matr[k][j];
            }
        }
    }
    return ans;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix &mt) {
    if (m != mt.n) {
        std::cerr << "Don't correct size matrices in operator *=\n";
        exit(1);
    }
    T** ans;
    ans = n ? (new T*[n]) : 0;
    for (int i = 0; i < n; ++i) {
        ans[i] = mt.m ? (new T[mt.m]) : 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mt.m; ++j) {
            for (int k = 0; k < m; ++k) {
                ans[i][j] += matr[i][k] * mt.matr[k][j];
            }
        }
    }
    for (int i = 0; i < n; ++i)
        if (matr[i])
            delete[] matr[i];
    if (matr)
        delete[] matr;
    m = mt.m;
    matr = ans;
    return *this;
}

template <class T>
void Matrix<T>::swap(Matrix<T> &other) {
    std::swap(n, other.n);
    std::swap(m, other.m);
    std::swap(matr, other.matr);
}

template <class T>
size_t Matrix<T>::getHeight() {
    return n;
}

template <class T>
size_t Matrix<T>::getWidth() {
    return m;
}

#endif //MATRIX_MATRIX_H
