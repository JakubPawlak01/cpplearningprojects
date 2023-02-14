#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
#include <iostream>

template <typename T>
class Matrix{
    private:
        int rows;
        int cols;
    public:
        std::vector<std::vector<T>> matrix;
        Matrix();
        Matrix(int rows, int cols);
        void SetMatrix();
        void EnterValue();
        Matrix<T> operator=(const Matrix<T>& matrix);
        Matrix<T> operator+(const Matrix<T>& matrix);
        Matrix<T> operator-(const Matrix<T>& matrix);
        Matrix<T> operator*(const Matrix<T>& matrix);
        Matrix<T> operator*(const T& value);
        Matrix<T> operator/(const T& value);

        friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix){
            for(int i=0; i<matrix.rows; i++){
                for(int j=0; j<matrix.cols; j++){
                    os << matrix.matrix[i][j] << " ";
                }
                os << std::endl;
            }
            return os;
        }


        ~Matrix()=default;
};

template <typename T>
Matrix<T>::Matrix() : rows(0), cols(0), matrix(0,std::vector<T>(0)){};

template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols), matrix(rows, std::vector<T>(cols)){};

template <typename T>
void Matrix<T>::SetMatrix(){
    std::cout<<"Enter value of rows and cols"<<std::endl;
    std::cin>>rows>>cols;
    matrix.resize(rows,std::vector<T>(cols));
}

template <typename T>
void Matrix<T>::EnterValue(){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            std::cout << i << " " << j << " " << std::endl;
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& second){
    this->rows = second.rows;
    this->cols = second.cols;
    this->matrix = second.matrix;
    for (int i = 0; i < second.rows; i++){
        for (int j = 0; j < second.cols; j++){
            this->matrix[i][j] = second.matrix[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& second){
    if(this->rows!= second.rows || this->cols!= second.cols){
        throw std::invalid_argument("Matrix dimensions do not match!");

    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->matrix[i][j] = this->matrix[i][j] + second.matrix[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& second){
if(this->rows!= second.rows || this->cols!= second.cols){
        throw std::invalid_argument("Matrix dimensions do not match!");
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->matrix[i][j] = this->matrix[i][j] - second.matrix[i][j];
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& second){
    if(this->rows!= second.cols){
        throw std::invalid_argument("Matrix dimensions do not match!");
    }
    Matrix<T> result(rows, second.cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < second.cols; j++){
            for(int k = 0; k < cols; k++){
                result.matrix[i][j] += this->matrix[i][k] * second.matrix[k][j];
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& value){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->matrix[i][j] = this->matrix[i][j] * value;
        }
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T& value){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            this->matrix[i][j] = this->matrix[i][j] / value;
        }
    }
    return *this;
}

#endif // MATRIX_HPP