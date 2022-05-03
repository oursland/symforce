// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cpp_templates/function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <Eigen/Dense>

namespace buffer_test {

/**
 * This function was autogenerated. Do not modify by hand.
 *
 * Args:
 *     buffer: Scalar
 *     a: Scalar
 *     b: Scalar
 *
 * Outputs:
 *     result: Scalar
 */
template <typename Scalar>
Scalar BufferFunc(const Scalar* const buffer, const Scalar a, const Scalar b) {
  // Total ops: 8

  // Input arrays

  // Intermediate terms (1)
  const Scalar _tmp0 = a + b;

  // Output terms (1)
  Scalar _result;

  _result = _tmp0 + buffer[static_cast<size_t>(_tmp0 * (-a + b))] +
            buffer[static_cast<size_t>(-std::pow(a, Scalar(2)) + std::pow(b, Scalar(2)))];

  return _result;
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace buffer_test
