/*!
 * @file     cost_base.cpp
 * @author   Giuseppe Rizzi
 * @date     01.07.2020
 * @version  1.0
 * @brief    description
 */

#include "husky_panda_control/core/cost.h"
#include <iostream>

namespace husky_panda_control {

void Cost::set_reference_trajectory(const reference_trajectory_t &traj) {
  // TODO try direct copy
  timed_ref_.tt.clear();
  timed_ref_.tt.reserve(traj.tt.size());
  timed_ref_.rr.clear();
  for (size_t i = 0; i < traj.tt.size(); i++) {
    timed_ref_.rr.push_back(traj.rr[i]);
    timed_ref_.tt.push_back(traj.tt[i]);
  }
}

void Cost::interpolate_reference(const observation_t & /*x*/, reference_t &ref,
                                 const double t) {
  auto lower = std::lower_bound(timed_ref_.tt.begin(), timed_ref_.tt.end(), t);
  size_t offset = std::distance(timed_ref_.tt.begin(), lower);
  if (lower == timed_ref_.tt.end()) offset -= 1;
  ref = timed_ref_.rr[offset];
}

double Cost::get_stage_cost(const husky_panda_control::observation_t &x,
                            const husky_panda_control::input_t &u, const double t) {
  interpolate_reference(x, r_, t);
  return compute_cost(x, u, r_, t);
}

}  // namespace husky_panda_control