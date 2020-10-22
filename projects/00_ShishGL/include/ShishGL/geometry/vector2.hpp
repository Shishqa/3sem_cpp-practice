/*============================================================================*/
#ifndef VECTOR_2_HPP
#define VECTOR_2_HPP
/*============================================================================*/
namespace ShishGL {

    template <typename T>
    struct Vector2 {

        T x, y;

        Vector2<T> operator-();

        Vector2<T>& operator+=(const Vector2<T>& right);
        Vector2<T>  operator+ (const Vector2<T>& right);

        Vector2<T>& operator-=(const Vector2<T>& right);
        Vector2<T>  operator- (const Vector2<T>& right);

        Vector2<T>& operator*=(const T& mul);

    };

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T> operator*(const T& mul, const Vector2<T>& vec);

    /*========================================================================*/
    /* Implementations                                                        */
    /*========================================================================*/

    template <typename T>
    Vector2<T> Vector2<T>::operator-() {
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
    Vector2<T> Vector2<T>::operator+(const Vector2<T>& right) {
        return (Vector2<T>{*this} += right);
    }

    /*------------------------------------------------------------------------*/

    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& right) {
        return (*this += (-right));
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T>& right) {
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

}
/*============================================================================*/
#endif //VECTOR_2_HPP
/*============================================================================*/
