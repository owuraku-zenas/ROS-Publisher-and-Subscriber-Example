#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
// #include <>


int main(int argc, char **argv) {

    ros::init(argc, argv, "talker");

    ros::NodeHandle node;

    ros::Publisher chatter = node.advertise<std_msgs::String>("chatter", 1000);

    ros::Rate loop_rate(10);

    int count = 0;

    while (ros::ok())
    {
        std_msgs::String message;

        std::stringstream ss;

        ss << "Hello World" << count;

        message.data = ss.str();

        ROS_INFO("%s", message.data.c_str());

        chatter.publish(message);
        ros::spinOnce();

        loop_rate.sleep();

        ++count;

    }

    return 0;
}