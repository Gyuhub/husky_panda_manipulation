//
// Created by giuseppe on 30.01.21.
//

#pragma once
#include "husky_panda_msgs/Input.h"
#include "husky_panda_msgs/InputState.h"
#include "husky_panda_msgs/State.h"

#include <Eigen/Core>

namespace husky_panda_control::conversions {


// clang-format off
void msgToEigen(const husky_panda_msgs::State& stateRos,
                Eigen::VectorXd& state, double& time);

void eigenToMsg(const Eigen::VectorXd& state, const double& time,
                husky_panda_msgs::State&);

void msgToEigen(const husky_panda_msgs::Input& inputRos,
                Eigen::VectorXd& input);

void eigenToMsg(const Eigen::VectorXd& input, husky_panda_msgs::Input&);

// // for articulated object manipulation
// void toEigenState(const Eigen::Vector3d& base_pose,
//                   const Eigen::Vector3d& base_twist,
//                   const Eigen::Vector3d& base_effort,
//                   const Eigen::VectorXd& arm_position,
//                   const Eigen::VectorXd& arm_velocity,
//                   const Eigen::VectorXd& arm_effort,
//                   const double& object_position,
//                   const double& object_velocity,
//                   const bool& contact_state,
//                   Eigen::VectorXd& x);
//
// void fromEigenState(Eigen::Vector3d& base_pose,
//                     Eigen::Vector3d& base_twist,
//                     Eigen::Vector3d& base_effort,
//                     Eigen::VectorXd& arm_position,
//                     Eigen::VectorXd& arm_velocity,
//                     Eigen::VectorXd& arm_effort,
//                     double& object_position,
//                     double& object_velocity,
//                     bool& contact_state,
//                     const Eigen::VectorXd& x);
//
// void toMsg(const double& time,
//            const Eigen::Vector3d& base_pose,
//            const Eigen::Vector3d& base_twist,
//            const Eigen::Vector3d& base_effort,
//            const Eigen::VectorXd& arm_position,
//            const Eigen::VectorXd& arm_velocity,
//            const Eigen::VectorXd& arm_effort,
//            const double& object_position,
//            const double& object_velocity,
//            const bool& contact_state,
//            husky_panda_msgs::State&);
//
// std::string eigenToString(const Eigen::VectorXd& x);


//clang-format on
}  // namespace husky_panda_control::conversions