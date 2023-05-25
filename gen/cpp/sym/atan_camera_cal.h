// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     cam_package/CLASS.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <ostream>
#include <random>
#include <vector>

#include <Eigen/Dense>

#include <sym/ops/storage_ops.h>

namespace sym {

/**
 * Autogenerated C++ implementation of `symforce.cam.atan_camera_cal.ATANCameraCal`.
 *
 * ATAN camera with 5 parameters [fx, fy, cx, cy, omega].
 *
 * (fx, fy) representing focal length, (cx, cy) representing principal point,
 * and omega representing the distortion parameter.
 *
 * See here for more details:
 * https://hal.inria.fr/inria-00267247/file/distcalib.pdf
 */
template <typename ScalarType>
class ATANCameraCal {
 public:
  // Typedefs
  using Scalar = ScalarType;
  using Self = ATANCameraCal<Scalar>;
  using DataVec = Eigen::Matrix<Scalar, 5, 1>;

  // Construct from focal_length, principal_point, and omega.
  ATANCameraCal(const Eigen::Matrix<Scalar, 2, 1>& focal_length,
                const Eigen::Matrix<Scalar, 2, 1>& principal_point, const Scalar omega)
      : ATANCameraCal(
            (Eigen::Matrix<Scalar, sym::StorageOps<Self>::StorageDim(), 1>() << focal_length,
             principal_point, omega)
                .finished()) {}

  // Construct from data vec
  explicit ATANCameraCal(const DataVec& data) : data_(data) {}

  // Access underlying storage as const
  inline const DataVec& Data() const {
    return data_;
  }

  // --------------------------------------------------------------------------
  // StorageOps concept
  // --------------------------------------------------------------------------

  static constexpr int32_t StorageDim() {
    return sym::StorageOps<Self>::StorageDim();
  }

  void ToStorage(Scalar* const vec) const {
    return sym::StorageOps<Self>::ToStorage(*this, vec);
  }

  static ATANCameraCal FromStorage(const Scalar* const vec) {
    return sym::StorageOps<Self>::FromStorage(vec);
  }

  // --------------------------------------------------------------------------
  // Camera model methods
  // --------------------------------------------------------------------------

  /**
   * Return the focal length.
   */
  Eigen::Matrix<Scalar, 2, 1> FocalLength() const;

  /**
   * Return the principal point.
   */
  Eigen::Matrix<Scalar, 2, 1> PrincipalPoint() const;

  /**
   * Project a 3D point in the camera frame into 2D pixel coordinates.
   *
   * Returns:
   *     pixel: (x, y) coordinate in pixels if valid
   *     is_valid: 1 if the operation is within bounds else 0
   */
  Eigen::Matrix<Scalar, 2, 1> PixelFromCameraPoint(const Eigen::Matrix<Scalar, 3, 1>& point,
                                                   const Scalar epsilon,
                                                   Scalar* const is_valid = nullptr) const;

  /**
   * Project a 3D point in the camera frame into 2D pixel coordinates.
   *
   * Return:
   *     pixel: (x, y) coordinate in pixels if valid
   *     is_valid: 1 if the operation is within bounds else 0
   *     pixel_D_cal: Derivative of pixel with respect to intrinsic calibration parameters
   *     pixel_D_point: Derivative of pixel with respect to point
   */
  Eigen::Matrix<Scalar, 2, 1> PixelFromCameraPointWithJacobians(
      const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon,
      Scalar* const is_valid = nullptr, Eigen::Matrix<Scalar, 2, 5>* const pixel_D_cal = nullptr,
      Eigen::Matrix<Scalar, 2, 3>* const pixel_D_point = nullptr) const;

  /**
   * Backproject a 2D pixel coordinate into a 3D ray in the camera frame.
   *
   * Returns:
   *     camera_ray: The ray in the camera frame (NOT normalized)
   *     is_valid: 1 if the operation is within bounds else 0
   */
  Eigen::Matrix<Scalar, 3, 1> CameraRayFromPixel(const Eigen::Matrix<Scalar, 2, 1>& pixel,
                                                 const Scalar epsilon,
                                                 Scalar* const is_valid = nullptr) const;

  /**
   * Backproject a 2D pixel coordinate into a 3D ray in the camera frame.
   *
   * Return:
   *     camera_ray: The ray in the camera frame (NOT normalized)
   *     is_valid: 1 if the operation is within bounds else 0
   *     point_D_cal: Derivative of point with respect to intrinsic calibration parameters
   *     point_D_pixel: Derivation of point with respect to pixel
   */
  Eigen::Matrix<Scalar, 3, 1> CameraRayFromPixelWithJacobians(
      const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon,
      Scalar* const is_valid = nullptr, Eigen::Matrix<Scalar, 3, 5>* const point_D_cal = nullptr,
      Eigen::Matrix<Scalar, 3, 2>* const point_D_pixel = nullptr) const;

  // --------------------------------------------------------------------------
  // General Helpers
  // --------------------------------------------------------------------------

  bool IsApprox(const Self& b, const Scalar tol) const {
    // isApprox is multiplicative so we check the norm for the exact zero case
    // https://eigen.tuxfamily.org/dox/classEigen_1_1DenseBase.html#ae8443357b808cd393be1b51974213f9c
    if (b.Data() == DataVec::Zero()) {
      return Data().norm() < tol;
    }

    return Data().isApprox(b.Data(), tol);
  }

  template <typename ToScalar>
  ATANCameraCal<ToScalar> Cast() const {
    return ATANCameraCal<ToScalar>(Data().template cast<ToScalar>());
  }

  bool operator==(const ATANCameraCal& rhs) const {
    return data_ == rhs.Data();
  }

 protected:
  DataVec data_;
};

// Shorthand for scalar types
using ATANCameraCald = ATANCameraCal<double>;
using ATANCameraCalf = ATANCameraCal<float>;

// Print definitions
std::ostream& operator<<(std::ostream& os, const ATANCameraCal<double>& a);
std::ostream& operator<<(std::ostream& os, const ATANCameraCal<float>& a);

}  // namespace sym

// Externs to reduce duplicate instantiation
extern template class sym::ATANCameraCal<double>;
extern template class sym::ATANCameraCal<float>;

// Concept implementations for this class
#include "./ops/atan_camera_cal/group_ops.h"
#include "./ops/atan_camera_cal/lie_group_ops.h"
#include "./ops/atan_camera_cal/storage_ops.h"
