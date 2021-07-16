#pragma once

#include <Eigen/Dense>
#include <symforce/opt/values.h>

#include <lcmtypes/sym/optimizer_params_t.hpp>

namespace bundle_adjustment {

struct BundleAdjustmentProblemParams {
  double epsilon = 1e-10;
  int num_views = 2;
  int num_landmarks = 20;
  double reprojection_error_gnc_scale = 10;
  double noise_px = 5;
  double num_outliers = 0;
  double landmark_relative_range_noise = 0.2;
  double pose_difference_std = 2;
  double pose_noise = 0.1;
  double pose_prior_noise = 0.3;
  Eigen::Vector2i image_shape{1280, 720};
  bool debug_stats = false;
  bool check_derivatives = false;
};

enum Var : char {
  VIEW = 'v',                  // Pose3d
  CALIBRATION = 'c',           // Vector4d
  POSE_PRIOR_T = 'T',          // Pose3d
  POSE_PRIOR_SQRT_INFO = 's',  // Matrix6d
  LANDMARK = 'l',              // Scalar
  LANDMARK_PRIOR = 'P',        // Scalar
  LANDMARK_PRIOR_SIGMA = 'S',  // Scalar
  MATCH_SOURCE_COORDS = 'm',   // Vector2d
  MATCH_TARGET_COORDS = 'M',   // Vector2d
  MATCH_WEIGHT = 'W',          // Scalar
  GNC_MU = 'u',                // Scalar
  GNC_SCALE = 'C',             // Scalar
  EPSILON = 'e',               // Scalar
};

/**
 * Build the Values for a small bundle adjustment problem.  Generates multiple posed cameras, with
 * Gaussian priors on their relative poses, as well as noisy correspondences and landmarks.
 */
sym::Valuesd BuildValues(std::mt19937& gen, const BundleAdjustmentProblemParams& params);

}  // namespace bundle_adjustment