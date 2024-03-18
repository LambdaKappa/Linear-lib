#include "../Base/Matrix.hpp"

namespace ln {
    /// @brief 
    /// @tparam DTYPE 
    /// @return 
    template <typename DTYPE>
    DTYPE Matrix<DTYPE>::sum() {
        DTYPE sum = 0;
        for (int i = 0; i < this->size0; ++i) {
            for (int j = 0; j < this->size1; ++j) {
                sum += this->data[i][j];
            }
        }
        return sum;
    }
    
    /// @brief 
    /// @tparam DTYPE 
    /// @return 
    template <typename DTYPE>
    DTYPE Matrix<DTYPE>::product() {
        DTYPE product = 1;
        for (int i = 0; i < this->size0; ++i) {
            for (int j = 0; j < this->size1; ++j) {
                product *= this->data[i][j];
            }
        }
        return product;
    }

    /// @brief Finds Matrix transpose 
    /// @return Returns transposed Matrix
    template <typename DTYPE>
    Matrix<DTYPE> Matrix<DTYPE>::T() { // Transpose
        Matrix<DTYPE> newMatrix = Matrix<DTYPE>(this->size1, this->size0);

        for (int i = 0; i < this->size1; ++i) {
            for (int j = 0; j < this->size0; ++j) {
                newMatrix[i][j] = this->data[j][i];
            }
        }
        return newMatrix;
    }

}