#ifndef SEM1D_CONCEPTS_GUARD_H
#define SEM1D_CONCEPTS_GUARD_H

#include <complex>
#include <concepts>

namespace SEM1D {

// Concepts for floating point numbers
template <typename T> struct IsComplexFloatingPoint : public std::false_type {};

template <typename T>
struct IsComplexFloatingPoint<std::complex<T>>
    : public std::bool_constant<std::is_floating_point_v<T>> {};

template <typename T>
concept RealFloatingPoint = std::floating_point<T>;

template <typename T>
concept ComplexFloatingPoint =
    IsComplexFloatingPoint<std::remove_const_t<T>>::value;

template <typename T>
concept RealOrComplexFloatingPoint =
    RealFloatingPoint<T> or ComplexFloatingPoint<T>;

template <typename T> struct RemoveComplexHelper {
  using value_type = T;
};

template <typename T> struct RemoveComplexHelper<std::complex<T>> {
  using value_type = T;
};

template <typename T>
using RemoveComplex = typename RemoveComplexHelper<T>::value_type;
} // namespace SEM1D

#endif // SEM1D_CONCEPTS_GUARD_H