// Copyright (c) 2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROS2_UTILS__EXECUTION_TIMER_HPP_
#define ROS2_UTILS__EXECUTION_TIMER_HPP_

#include <chrono>

namespace ros2_utils
{

// Measures execution time of code between calls to start and end
class ExecutionTimer
{
public:
  using Clock = std::chrono::high_resolution_clock;
  using nanoseconds = std::chrono::nanoseconds;

  // Call just prior to code you want to measure
  void start() {start_ = Clock::now();}

  // Call just after the code you want to measure
  void end() {end_ = Clock::now();}

  // Extract the measured time as an integral std::chrono::duration object
  nanoseconds elapsed_time() {return end_ - start_;}

  // Extract the measured time as a floating point number of seconds.
  double elapsed_time_in_seconds()
  {
    return std::chrono::duration<double>(end_ - start_).count();
  }

protected:
  Clock::time_point start_;
  Clock::time_point end_;
};

}  // namespace ros2_utils

#endif  // ROS2_UTILS__EXECUTION_TIMER_HPP_