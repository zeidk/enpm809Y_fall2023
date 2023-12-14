#ifndef ARIAC_LOGICAL_CAMERA_PLUGIN_HPP_
#define ARIAC_LOGICAL_CAMERA_PLUGIN_HPP_

#include <mage_msgs/msg/sensors.hpp>
#include <gazebo/common/Plugin.hh>
#include <memory>

namespace ariac_sensors
{

class AriacLogicalCameraPluginPrivate;

/// Plugin to attach to a gazebo AriacLogicalCameraPlugin sensor and publish ROS message of output
class AriacLogicalCameraPlugin : public gazebo::SensorPlugin
{
public:
  /// Constructor.
  AriacLogicalCameraPlugin();
  /// Destructor.
  virtual ~AriacLogicalCameraPlugin();

  // Documentation Inherited
  void Load(gazebo::sensors::SensorPtr _sensor, sdf::ElementPtr _sdf) override;

  void SensorHealthCallback(const mage_msgs::msg::Sensors::SharedPtr msg);

 private:
  /// Private data pointer
  std::unique_ptr<AriacLogicalCameraPluginPrivate> impl_;
};

}  // namespace ariac_sensors

#endif  // ARIAC_LOGICAL_CAMERA_PLUGIN_HPP_
