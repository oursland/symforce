// ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// ----------------------------------------------------------------------------
#pragma once

#include <cassert>
#include <vector>

namespace codegen_multi_function_ns {
namespace StorageOps {

template<>
inline size_t StorageDim<inputs_constants_t>() {
  return 1;
};

template<>
inline void ToStorage<inputs_constants_t>(const inputs_constants_t& value, std::vector<double>* vec) {
  assert(vec != nullptr);
  std::vector<double>& v = (*vec);
  v.resize(1);

  v[0] = value.epsilon;
}

template<typename Container>
void FromStorage(const Container& elements, inputs_constants_t* out) {
  assert(out != nullptr);
  out->epsilon = elements[0];
}

}  // namespace StorageOps
}  // namespace codegen_multi_function_ns