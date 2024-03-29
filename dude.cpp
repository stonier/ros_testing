/*
 * Copyright (c) 2012, Yujin Robot.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Yujin Robot nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
/**
 * @file /kobuki_node/src/nodelet/kobuki_nodelet.cpp
 *
 * @brief Implementation for the ROS Dude nodelet
 **/

/*****************************************************************************
 ** Includes
 *****************************************************************************/

#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include <string>
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace dude
{

class DudeNodelet : public nodelet::Nodelet
{
public:
  DudeNodelet(){};
  virtual void onInit()
  {
    std::string name = this->getName();
    std::string parent_namespace = ros::names::parentNamespace(name);
    ros::NodeHandle nh = this->getNodeHandle();
    ros::NodeHandle pnh = this->getPrivateNodeHandle();
    public_pub = nh.advertise<std_msgs::String>("public", 1000);
    private_pub = pnh.advertise<std_msgs::String>("private", 1000);

    NODELET_INFO_STREAM("Dude : initialising nodelet..." << name);
    NODELET_INFO_STREAM("Dude : parent namespace -> " << parent_namespace);
    NODELET_INFO_STREAM("Dude : public topic -> " << public_pub.getTopic());
    NODELET_INFO_STREAM("Dude : private topic -> " << private_pub.getTopic());
  }
private:
  ros::Publisher public_pub, private_pub;
};

} // namespace dude

PLUGINLIB_EXPORT_CLASS(dude::DudeNodelet, nodelet::Nodelet);
