#include <iostream>

// 定义状态枚举
enum State { START, SEARCH, MOVE_FORWARD, OBSTACLE_AVOIDANCE, AT_DESTINATION };

// 机器人类
class RobotFSM {
private:
  State state; // 当前状态

public:
  RobotFSM() : state(START) {} // 构造函数初始化为START状态

  // 处理状态转移的函数
  void onEvent(const std::string &event) {
    switch (state) {
    case START:
      // 从启动状态转移到搜索状态
      if (event == "start") {
        state = SEARCH;
      }
      break;
    case SEARCH:
      // 假设发现目标
      if (event == "target_found") {
        state = MOVE_FORWARD;
      }
      break;
    case MOVE_FORWARD:
      // 遇到障碍物
      if (event == "obstacle_detected") {
        state = OBSTACLE_AVOIDANCE;
      } else if (event == "destination_reached") {
        state = AT_DESTINATION;
      }
      break;
    case OBSTACLE_AVOIDANCE:
      // 障碍物已避开
      if (event == "obstacle_cleared") {
        state = MOVE_FORWARD;
      }
      break;
    case AT_DESTINATION:
      // 完成任务，可能会返回到搜索状态重新开始
      state = SEARCH;
      break;
    }
  }

  // 获取当前状态的描述
  std::string getStateDescription() const {
    switch (state) {
    case START:
      return "Starting the system.";
    case SEARCH:
      return "Searching for destination.";
    case MOVE_FORWARD:
      return "Moving forward.";
    case OBSTACLE_AVOIDANCE:
      return "Avoiding obstacle.";
    case AT_DESTINATION:
      return "Reached destination.";
    default:
      return "Unknown state.";
    }
  }
};

int main() {
  RobotFSM robot;
  std::cout << "Initial State: " << robot.getStateDescription() << std::endl;
  robot.onEvent("start");
  std::cout << "State after event 'start': " << robot.getStateDescription()
            << std::endl;
  // 模拟事件
  robot.onEvent("target_found");
  std::cout << "State after event 'target_found': "
            << robot.getStateDescription() << std::endl;

  robot.onEvent("obstacle_detected");
  std::cout << "State after event 'obstacle_detected': "
            << robot.getStateDescription() << std::endl;

  robot.onEvent("obstacle_cleared");
  std::cout << "State after event 'obstacle_cleared': "
            << robot.getStateDescription() << std::endl;

  robot.onEvent("destination_reached");
  std::cout << "State after event 'destination_reached': "
            << robot.getStateDescription() << std::endl;

  robot.onEvent("restart");
  std::cout << "State after event 'restart': " << robot.getStateDescription()
            << std::endl;

  return 0;
}