//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <algorithm>
#include <cmath>

#include "./lie_group_ops.h"

namespace geo {
namespace pose2 {

template <typename Scalar>
geo::Pose2<Scalar> LieGroupOps<Scalar>::FromTangent(const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon) {
    // Input arrays

    // Intermediate terms (5)
    const Scalar _tmp0 = std::cos(vec[2]);
    const Scalar _tmp1 = std::sin(vec[2]);
    const Scalar _tmp2 = 1.0 / (epsilon + vec[2]);
    const Scalar _tmp3 = _tmp2*(-_tmp0 + 1);
    const Scalar _tmp4 = _tmp1*_tmp2;

    // Output terms (1)
    Eigen::Matrix<Scalar, 4, 1> _res;
    _res[0] = _tmp0;
    _res[1] = _tmp1;
    _res[2] = -_tmp3*vec[1] + _tmp4*vec[0];
    _res[3] = _tmp3*vec[0] + _tmp4*vec[1];

    return geo::Pose2<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> LieGroupOps<Scalar>::ToTangent(const geo::Pose2<Scalar>& a, const Scalar epsilon) {
    // Input arrays
    const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

    // Intermediate terms (5)
    const Scalar _tmp0 = std::atan2(_a[1], _a[0] + epsilon*((((_a[0]) > 0) - ((_a[0]) < 0)) + 0.5));
    const Scalar _tmp1 = 0.5*_tmp0;
    const Scalar _tmp2 = _a[3]*_tmp1;
    const Scalar _tmp3 = _a[2]*_tmp1;
    const Scalar _tmp4 = _a[1]/std::max<Scalar>(epsilon, -_a[0] + 1);

    // Output terms (1)
    Eigen::Matrix<Scalar, 3, 1> _res;
    _res(0, 0) = _tmp2 + _tmp3*_tmp4;
    _res(1, 0) = _tmp2*_tmp4 - _tmp3;
    _res(2, 0) = _tmp0;

    return _res;
}

template <typename Scalar>
geo::Pose2<Scalar> LieGroupOps<Scalar>::Retract(const geo::Pose2<Scalar>& a, const Eigen::Matrix<Scalar, 3, 1>& vec, const Scalar epsilon) {
    // Input arrays
    const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

    // Intermediate terms (7)
    const Scalar _tmp0 = std::sin(vec[2]);
    const Scalar _tmp1 = std::cos(vec[2]);
    const Scalar _tmp2 = 1.0 / (epsilon + vec[2]);
    const Scalar _tmp3 = _tmp0*_tmp2;
    const Scalar _tmp4 = _tmp2*(-_tmp1 + 1);
    const Scalar _tmp5 = _tmp3*vec[1] + _tmp4*vec[0];
    const Scalar _tmp6 = _tmp3*vec[0] - _tmp4*vec[1];

    // Output terms (1)
    Eigen::Matrix<Scalar, 4, 1> _res;
    _res[0] = _a[0]*_tmp1 - _a[1]*_tmp0;
    _res[1] = _a[0]*_tmp0 + _a[1]*_tmp1;
    _res[2] = _a[0]*_tmp6 - _a[1]*_tmp5 + _a[2];
    _res[3] = _a[0]*_tmp5 + _a[1]*_tmp6 + _a[3];

    return geo::Pose2<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> LieGroupOps<Scalar>::LocalCoordinates(const geo::Pose2<Scalar>& a, const geo::Pose2<Scalar>& b, const Scalar epsilon) {
    // Input arrays
    const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
    const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

    // Intermediate terms (10)
    const Scalar _tmp0 = 1.0 / ((_a[0] * _a[0]) + (_a[1] * _a[1]));
    const Scalar _tmp1 = _a[0]*_tmp0;
    const Scalar _tmp2 = _a[1]*_tmp0;
    const Scalar _tmp3 = -_b[0]*_tmp2 + _b[1]*_tmp1;
    const Scalar _tmp4 = _b[0]*_tmp1 + _b[1]*_tmp2;
    const Scalar _tmp5 = std::atan2(_tmp3, _tmp4 + epsilon*((((_tmp4) > 0) - ((_tmp4) < 0)) + 0.5));
    const Scalar _tmp6 = 0.5*_tmp5;
    const Scalar _tmp7 = _tmp6*(_a[2]*_tmp2 - _a[3]*_tmp1 - _b[2]*_tmp2 + _b[3]*_tmp1);
    const Scalar _tmp8 = _tmp6*(-_a[2]*_tmp1 - _a[3]*_tmp2 + _b[2]*_tmp1 + _b[3]*_tmp2);
    const Scalar _tmp9 = _tmp3/std::max<Scalar>(epsilon, -_tmp4 + 1);

    // Output terms (1)
    Eigen::Matrix<Scalar, 3, 1> _res;
    _res(0, 0) = _tmp7 + _tmp8*_tmp9;
    _res(1, 0) = _tmp7*_tmp9 - _tmp8;
    _res(2, 0) = _tmp5;

    return _res;
}


}  // namespace pose2
}  // namespace geo

// Explicit instantiation
template struct geo::pose2::LieGroupOps<double>;
template struct geo::pose2::LieGroupOps<float>;