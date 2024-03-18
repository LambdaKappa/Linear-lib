#pragma once

#include <ostream>

namespace ln {

    template <typename DTYPE>
    struct vector2 {
        DTYPE x, y;
        
        vector2() {
            this->x = 0;
            this->y = 0;
        }

        vector2(DTYPE& x, DTYPE& y) {
            this->x = x;
            this->y = y;
        }

        vector2(const DTYPE& x,const DTYPE& y) {
            this->x = x;
            this->y = y;
        }

        friend bool operator==(const vector2<DTYPE>& lhs, const vector2<DTYPE>& rhs) {
            return (lhs.x == rhs.x && lhs.y == rhs.y);
        }
    };

    template <typename DTYPE>
    std::ostream& operator<<(std::ostream& os, const vector2<DTYPE>& vector) {
        os << '(' << vector.x << ", " << vector.y << ')'; 
        return os;
    }
}