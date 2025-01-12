#include "manip.h"

std::ostream& manipFunc(std::ostream& os, int width, int precision, char fill) {
    os.width(width);
    os.precision(precision);
    os.fill(fill);
    return os;
}

std::ostream& operator<<(std::ostream& os, const MyManip& manip) {
    return manip.func(os, manip.width, manip.precision, manip.fill);
}

MyManip setMyManip(int width, int precision, char fill) {
    return MyManip(width, precision, fill);
}
