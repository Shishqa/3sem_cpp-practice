/*============================================================================*/
#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP
/*============================================================================*/
#include <cmath>
/*============================================================================*/
namespace ShishGL {

    template <typename T>
    struct Vector2 {

        T x, y;

        T length() const {
            return sqrt(*this ^ *this);
        }

        Vector2<T> operator-() const;

        Vector2<T> operator!() const;

        Vector2<T>& operator+=(const Vector2<T>& right);
        Vector2<T>  operator+ (const Vector2<T>& right) const;

        Vector2<T>& operator-=(const Vector2<T>& right);
        Vector2<T>  operator- (const Vector2<T>& right) const;

        Vector2<T>& operator*=(const T& mul);

        T operator^(const Vector2<T>& right) const;

        Vector2<T>& operator|=(const Vector2<T>& right);
        Vector2<T>  operator| (const Vector2<T>& right) const;

        //bool        operator||(const Vector2<T>& right) const;

        template <typename P>
        explicit operator Vector2<P>() const {
            return Vector2<P>{
                static_cast<P>(x),
                static_cast<P>(y)
            };
        }

    };

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& vec);

    /*========================================================================*/
    /* Implementations                                                        */
    /*========================================================================*/

    template <typename T>
    Vector2<T> Vector2<T>::operator-() const {
        return Vector2<T>{-x, -y};
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& right) {
        x += right.x;
        y += right.y;
        return *this;
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) const {
        return (Vector2<T>{*this} += right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right) {
        return (*this += (-right));
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) const {
        return (Vector2<T>{*this} -= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator*=(const T& mul) {
        x *= mul;
        y *= mul;
        return *this;
    }

    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& vec) {
        return (Vector2<T>{vec} *= mul);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    T Vector2<T>::operator^(const Vector2<T>& right) const {
        return x * right.x + y * right.y;
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator|=(const Vector2<T> &right) {
        *this = ((*this ^ right) / (right ^ right)) * right;
        return *this;
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator|(const Vector2<T>& right) const {
        return (Vector2<T>{*this} |= right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T> Vector2<T>::operator!() const {

        T len = this->length();

        if (len == 0) {
            return *this;
        }

        Vector2<T> copy{*this};
        return (1 / len) * copy;
    }

}
/*============================================================================*/
#endif //VECTOR_2_HPP
/*============================================================================*/
