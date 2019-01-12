#ifndef _STEERING_PLUGIN_HH_
#define _STEERING_PLUGIN_HH_


#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <thread>
#include "ros/ros.h"
#include "ros/callback_queue.h"
#include "ros/subscribe_options.h"
#include "std_msgs/Float32.h"
namespace gazebo
{
  class SteeringPlugin : public ModelPlugin
  {
    /// \brief Constructor
    public: SteeringPlugin() {}

    /// \brief The load function is called by Gazebo when the plugin is
    /// inserted into simulation
    /// \param[in] _model A pointer to the model that this plugin is
    /// attached to.
    /// \param[in] _sdf A pointer to the plugin's SDF element.
    public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
  // Safety check
  if (_model->GetJointCount() == 0)
  {
    std::cerr << "Invalid joint count, Velodyne plugin not loaded\n";
    return;
  }

  // Store the model pointer for convenience.
  this->model = _model;

  // Get the first joint. We are making an assumption about the model
  // having one joint that is the rotational joint.
  this->jointRLW = _model->GetJoints()[5];
this->jointRRW = _model->GetJoints()[6];
this->jointFSR = _model->GetJoints()[4];
this->jointFSL = _model->GetJoints()[3];

  // Setup a P-controller, with a gain of 0.1.
  this->pid = common::PID(10, 0, 0);
this->pid_S = common::PID(20, 0.001, 2);

  // Apply the P-controller to the joint.
  this->model->GetJointController()->SetVelocityPID(
      this->jointRRW ->GetScopedName(), this->pid);


  // Apply the P-controller to the joint.
  this->model->GetJointController()->SetVelocityPID(
      this->jointRLW ->GetScopedName(), this->pid);


  // Apply the P-controller to the joint.
  this->model->GetJointController()->SetPositionPID(
      this->jointFSR  ->GetScopedName(), this->pid_S);

// Apply the P-controller to the joint.
  this->model->GetJointController()->SetPositionPID(
      this->jointFSL  ->GetScopedName(), this->pid_S);
 this->SetVelocity(0);
 this->SetPosition(0);

// Initialize ros, if it has not already bee initialized.
if (!ros::isInitialized())
{
  int argc = 0;
  char **argv = NULL;
  ros::init(argc, argv, "gazebo_client",
      ros::init_options::NoSigintHandler);
}

// Create our ROS node. This acts in a similar manner to
// the Gazebo node
this->rosNode.reset(new ros::NodeHandle("gazebo_client"));

// Create a named topic, and subscribe to it.
ros::SubscribeOptions so =
  ros::SubscribeOptions::create<std_msgs::Float32>(
      "/" + this->model->GetName() + "/vel_cmd",
      1,
      boost::bind(&SteeringPlugin::OnRosMsg, this, _1),
      ros::VoidPtr(), &this->rosQueue);
ros::SubscribeOptions so1 =
  ros::SubscribeOptions::create<std_msgs::Float32>(
      "/" + this->model->GetName() + "/pos_cmd",
      1,
      boost::bind(&SteeringPlugin::OnRosMsg1, this, _1),
      ros::VoidPtr(), &this->rosQueue);


this->rosSub = this->rosNode->subscribe(so);
this->rosSub1 = this->rosNode->subscribe(so1);
// Spin up the queue helper thread.
this->rosQueueThread =
  std::thread(std::bind(&SteeringPlugin::QueueThread, this));

    }
public: void SetVelocity(const double &_vel)
{
  // Set the joint's target velocity.
  this->model->GetJointController()->SetVelocityTarget(
      this->jointRRW->GetScopedName(), _vel);

 this->model->GetJointController()->SetVelocityTarget(
      this->jointRLW->GetScopedName(), _vel);
}

public: void SetPosition(const double &_pos)
{
  // Set the joint's target velocity.
  this->model->GetJointController()->SetPositionTarget(
      this->jointFSR->GetScopedName(), _pos);

 this->model->GetJointController()->SetPositionTarget(
      this->jointFSL->GetScopedName(), _pos);
}

/// \brief Pointer to the model.
private: physics::ModelPtr model;

/// \brief Pointer to the joint.

private: physics::JointPtr jointRRW;
private: physics::JointPtr jointRLW;
private: physics::JointPtr jointFSR;
private: physics::JointPtr jointFSL;
/// \brief A PID controller for the joint.
private: common::PID pid;
private: common::PID pid_S;

/// \brief A node use for ROS transport
private: std::unique_ptr<ros::NodeHandle> rosNode;

/// \brief A ROS subscriber
private: ros::Subscriber rosSub;
private: ros::Subscriber rosSub1;
/// \brief A ROS callbackqueue that helps process messages
private: ros::CallbackQueue rosQueue;

/// \brief A thread the keeps running the rosQueue
private: std::thread rosQueueThread;


public: void OnRosMsg(const std_msgs::Float32ConstPtr &_msg)
{
  this->SetVelocity(_msg->data);

}

public: void OnRosMsg1(const std_msgs::Float32ConstPtr &_msg)
{
  this->SetPosition(_msg->data);
}

/// \brief ROS helper function that processes messages
private: void QueueThread()
{
  static const double timeout = 0.01;
  while (this->rosNode->ok())
  {
    this->rosQueue.callAvailable(ros::WallDuration(timeout));
  }
}
  };

  // Tell Gazebo about this plugin, so that Gazebo can call Load on this plugin.
  GZ_REGISTER_MODEL_PLUGIN(SteeringPlugin)
}
#endif
