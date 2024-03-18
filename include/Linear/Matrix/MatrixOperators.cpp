#include "../Base/Matrix.hpp"

namespace ln {

    /// @brief Creates a deep copy of the Matrix
    /// @param other - Matrix that is taken as a reference to create a new Matrix 
    /// @return Deep copy of the Matrix object
    template <typename DTYPE>
    Matrix<DTYPE>& Matrix<DTYPE>::operator=(const Matrix<DTYPE>& other) {
        if (this == &other) return *this;

        size_t newSize0 = other.size0;
        size_t newSize1 = other.size1;
        DTYPE** newData = other.data;

        this->deallocate();

        this->data = new DTYPE*[newSize0];
        for (int i = 0; i < newSize0; ++i) {
            this->data[i] = new DTYPE[newSize1];
            std::copy(newData[i], newData[i] + newSize1, this->data[i]);
        }

        this->size0 = newSize0;
        this->size1 = newSize1;
        return *this;
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE>& Matrix<DTYPE>::operator+=(const Matrix<DTYPE>& other) {
        bool isSameShape = this->shape() == other.shape();
        if (isSameShape) {
            for(int i = 0; i < this->size0; ++i) {
                for (int j = 0; j < this->size1; ++j) {
                    this->data[i][j] += other.data[i][j];
                }
            }
            return *this;
        }

        bool columnwise = this->size1 == other.size1 && other.size0 == 1;
        if (columnwise) {
            for (int j = 0; j < this->size1; ++j) {
                DTYPE elementToAdd = other.data[0][j];
                for (int i = 0; i < this->size0; ++i)
                    this->data[i][j] += elementToAdd;
            }
            return *this;
        }

        bool rowwise = this->size0 == other.size0 && other.size1 == 1;
        if (rowwise) {
            for (int i = 0; i < this->size0; ++i) {
                DTYPE elementToAdd = other.data[i][0];
                for (int j = 0; j < this->size1; ++j)
                    this->data[i][j] += elementToAdd;
            }
            return *this;
        }
        throw std::length_error(E_MATRIX_SUM);
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE>& Matrix<DTYPE>::operator-=(const Matrix<DTYPE>& other) {
        bool isSameShape = this->shape() == other.shape();
        if (isSameShape) {
            for(int i = 0; i < this->size0; ++i) {
                for (int j = 0; j < this->size1; ++j) {
                    this->data[i][j] -= other.data[i][j];
                }
            }
            return *this;
        }

        bool columnwise = this->size1 == other.size1 && other.size0 == 1;
        if (columnwise) {
            for (int j = 0; j < this->size1; ++j) {
                DTYPE elementToAdd = other.data[0][j];
                for (int i = 0; i < this->size0; ++i)
                    this->data[i][j] -= elementToAdd;
            }
            return *this;
        }

        bool rowwise = this->size0 == other.size0 && other.size1 == 1;
        if (rowwise) {
            for (int i = 0; i < this->size0; ++i) {
                DTYPE elementToAdd = other.data[i][0];
                for (int j = 0; j < this->size1; ++j)
                    this->data[i][j] -= elementToAdd;
            }
            return *this;
        }
        throw std::length_error(E_MATRIX_SUM);
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE> Matrix<DTYPE>::operator+(const Matrix<DTYPE>& other) {
        Matrix result = Matrix((*this)); // Deep copy constructor.

        bool isSameShape = result.shape() == other.shape();
        if (isSameShape) {
            for(int i = 0; i < result.size0; ++i) {
                for (int j = 0; j < result.size1; ++j) {
                    result.data[i][j] += other.data[i][j];
                }
            }
            return result;
        }

        bool columnwise = result.size1 == other.size1 && other.size0 == 1;
        if (columnwise) {
            for (int j = 0; j < result.size1; ++j) {
                DTYPE elementToAdd = other.data[0][j];
                for (int i = 0; i < result.size0; ++i)
                    result.data[i][j] += elementToAdd;
            }
            return result;
        }

        bool rowwise = result.size0 == other.size0 && other.size1 == 1;
        if (rowwise) {
            for (int i = 0; i < result.size0; ++i) {
                DTYPE elementToAdd = other.data[i][0];
                for (int j = 0; j < result.size1; ++j)
                    result.data[i][j] += elementToAdd;
            }
            return result;
        }
        throw std::length_error(E_MATRIX_SUM);
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE> Matrix<DTYPE>::operator-(const Matrix<DTYPE>& other) {
        Matrix result = Matrix((*this)); // Deep copy constructor.

        bool isSameShape = result.shape() == other.shape();
        if (isSameShape) {
            for(int i = 0; i < result.size0; ++i) {
                for (int j = 0; j < result.size1; ++j) {
                    result.data[i][j] -= other.data[i][j];
                }
            }
            return result;
        }

        bool columnwise = result.size1 == other.size1 && other.size0 == 1;
        if (columnwise) {
            for (int j = 0; j < result.size1; ++j) {
                DTYPE elementToAdd = other.data[0][j];
                for (int i = 0; i < result.size0; ++i)
                    result.data[i][j] -= elementToAdd;
            }
            return result;
        }

        bool rowwise = result.size0 == other.size0 && other.size1 == 1;
        if (rowwise) {
            for (int i = 0; i < result.size0; ++i) {
                DTYPE elementToAdd = other.data[i][0];
                for (int j = 0; j < result.size1; ++j)
                    result.data[i][j] -= elementToAdd;
            }
            return result;
        }
        throw std::length_error(E_MATRIX_SUM);
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE> Matrix<DTYPE>::operator*(const Matrix<DTYPE>& other) {
        if constexpr (!isNumeric<DTYPE>) return std::logic_error(E_MATRIX_MUL_DTYPE);
        if (this->size1 != other.size0) throw std::length_error(E_MATRIX_MUL_SHAPE);

        size_t newSize0 = this->size0;
        size_t newSize1 = other.size1;

        Matrix newMatrix = Matrix(newSize0, newSize1);
        
        for (int i = 0; i < this->size0; ++i) {
            for (int j = 0; j < other.size1; ++j) {
                DTYPE sum = 0;
                for (int k = 0; k < this->size1; ++k) {
                    sum += this->data[i][k] * other[k][j];
                }
                newMatrix[i][j] = sum;
            }
        }
        return newMatrix;
    }

    /// @brief 
    /// @tparam DTYPE 
    /// @param other 
    /// @return 
    template <typename DTYPE>
    Matrix<DTYPE>& Matrix<DTYPE>::operator*=(const Matrix<DTYPE>& other) {
        if constexpr (!isNumeric<DTYPE>) return std::logic_error(E_MATRIX_MUL_DTYPE);
        if (this->size1 != other.size0) throw std::length_error(E_MATRIX_MUL_SHAPE);

        size_t newSize0 = this->size0;
        size_t newSize1 = other.size1;

        Matrix result = Matrix(newSize0, newSize1);

        for (int i = 0; i < newSize0; ++i) {
            for (int j = 0; j < newSize1; ++j) {
                DTYPE sum = 0;
                for (int k = 0; k < other.size0; ++k) {
                    sum += this->data[i][k] * other.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }

        // Deallocate unused memory
        for (int i = 0; i < this->size0; ++i) {
            if (i >= newSize0) {
                delete[] this->data[i];
            } else {
                // Resize each row of the matrix to newSize1
                DTYPE* newRow = new DTYPE[newSize1];
                std::copy(result.data[i], result.data[i] + newSize1, newRow);
                delete[] this->data[i];
                this->data[i] = newRow;
            }
        }

        // Delete any extra rows
        for (int i = newSize0; i < this->size0; ++i) {
            delete[] this->data[i];
        }

        // Update size0 and size1
        this->size0 = newSize0;
        this->size1 = newSize1;

        return *this;
    }
}