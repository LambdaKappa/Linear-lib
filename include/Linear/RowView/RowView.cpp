#include "RowView.hpp"
#include "../Warnings.hpp"

namespace ln {

    template<typename DTYPE>
    DTYPE RowView<DTYPE>::item() {
        if (this->size0 == 1) return this->row[0];
        else throw std::length_error(E_NOT_ITEMABLE);
    }
}