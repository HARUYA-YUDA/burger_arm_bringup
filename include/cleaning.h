#include "my_dxl_ctrl_table.h"
#include <unistd.h>

#include "mikata_arm_toolbox/dxl_util.h"
#include "mikata_arm_toolbox/dxl_ctrl_table.h"
#include "mikata_arm_toolbox/conversion_util.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include "dynamixel_sdk/dynamixel_sdk.h"
#include "mikata_arm_toolbox/dxl_util.h"
#include "mikata_arm_toolbox/parameters.h"

void setcleaning(void)
{
  dxl_write(1, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(2, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(3, CURRENT_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(4, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(5, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
}

void setnormal(void)
{
  dxl_write(1, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(2, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(3, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(4, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
  dxl_write(5, POSITION_CONTROL_MODE, ADDR_X_OPERATING_MODE, sizeof(int8_t));
}


inline void setCurAll(std::vector<int> id_vec, std::vector<int> val) {
  dxl_writeAll(id_vec, val, ADDR_X_GOAL_CURRENT, sizeof(int16_t));
}

inline int torque2dxl(double val){ 
    if(val>=1193) return 1193;
    else if(val<=-1193) return -1193;
    else return ceil(val);
}

inline std::vector<int> torque2dxl(std::vector<double> val){
    std::vector<int> res;
    for(int i=0; i<val.size(); i++) res.push_back(torque2dxl(val[i]));
    return res;
}
