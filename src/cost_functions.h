/*
 * cost_functions.h
 *
 *  Created on: Aug 25, 2017
 *      Author: ramiz
 */

#ifndef COST_FUNCTIONS_H_
#define COST_FUNCTIONS_H_

#include <vector>
#include "trajectory.h"
#include "vehicle.h"

using namespace std;

class CostFunctions {
public:
  CostFunctions();
  virtual ~CostFunctions();

  /**
   * Penalizes trajectories that span a duration which is longer or
   * shorter than the duration requested.
   *
   * @param delta,
   * delta - a length 6 array indicating the offset we are aiming for between us
   *    and the target_vehicle. So if at time 5 the target vehicle will be at
   *   [100, 10, 0, 0, 0, 0] and delta is [-10, 0, 0, 4, 0, 0], then our goal
   *   state for t = 5 will be [90, 10, 0, 4, 0, 0]. This would correspond to a
   *   goal of "follow 10 meters behind and 4 meters to the right of target vehicle"
   *
   */
  double time_diff_cost(const Trajectory &trajectory,
                        int target_vehicle_id,
                        const VectorXd &delta,
                        double T,
                        const vector<Vehicle> &predictions);


  /**
   * Penalizes trajectories whose d coordinate (and derivatives)
   * differ from the goal.
   *
   * @param delta,
   * delta - a length 6 array indicating the offset we are aiming for between us
   *    and the target_vehicle. So if at time 5 the target vehicle will be at
   *   [100, 10, 0, 0, 0, 0] and delta is [-10, 0, 0, 4, 0, 0], then our goal
   *   state for t = 5 will be [90, 10, 0, 4, 0, 0]. This would correspond to a
   *   goal of "follow 10 meters behind and 4 meters to the right of target vehicle"
   */
  double d_diff_cost(const Trajectory &trajectory,
                     int target_vehicle_id,
                     const VectorXd &delta,
                     double T,
                     const vector<Vehicle> &predictions);

  /**
     * Penalizes trajectories whose s coordinate (and derivatives)
     * differ from the goal.
     *
     * @param delta,
     * delta - a length 6 array indicating the offset we are aiming for between us
     *    and the target_vehicle. So if at time 5 the target vehicle will be at
     *   [100, 10, 0, 0, 0, 0] and delta is [-10, 0, 0, 4, 0, 0], then our goal
     *   state for t = 5 will be [90, 10, 0, 4, 0, 0]. This would correspond to a
     *   goal of "follow 10 meters behind and 4 meters to the right of target vehicle"
     */
    double s_diff_cost(const Trajectory &trajectory,
                       int target_vehicle_id,
                       const VectorXd &delta,
                       double T,
                       const vector<Vehicle> &predictions);
};

#endif /* COST_FUNCTIONS_H_ */
