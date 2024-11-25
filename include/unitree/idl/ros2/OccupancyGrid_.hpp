/****************************************************************

  Generated by Eclipse Cyclone DDS IDL to CXX Translator
  File name: OccupancyGrid_.idl
  Source: OccupancyGrid_.hpp
  Cyclone DDS: v0.10.2

*****************************************************************/
#ifndef DDSCXX_UNITREE_IDL_ROS2_OCCUPANCYGRID__HPP
#define DDSCXX_UNITREE_IDL_ROS2_OCCUPANCYGRID__HPP

#include "unitree/idl/ros2/MapMetaData_.hpp"

#include "unitree/idl/ros2/Header_.hpp"

#include <cstdint>
#include <vector>

namespace nav_msgs
{
namespace msg
{
namespace dds_
{
class OccupancyGrid_
{
private:
 ::std_msgs::msg::dds_::Header_ header_;
 ::nav_msgs::msg::dds_::MapMetaData_ info_;
 std::vector<uint8_t> data_;

public:
  OccupancyGrid_() = default;

  explicit OccupancyGrid_(
    const ::std_msgs::msg::dds_::Header_& header,
    const ::nav_msgs::msg::dds_::MapMetaData_& info,
    const std::vector<uint8_t>& data) :
    header_(header),
    info_(info),
    data_(data) { }

  const ::std_msgs::msg::dds_::Header_& header() const { return this->header_; }
  ::std_msgs::msg::dds_::Header_& header() { return this->header_; }
  void header(const ::std_msgs::msg::dds_::Header_& _val_) { this->header_ = _val_; }
  void header(::std_msgs::msg::dds_::Header_&& _val_) { this->header_ = _val_; }
  const ::nav_msgs::msg::dds_::MapMetaData_& info() const { return this->info_; }
  ::nav_msgs::msg::dds_::MapMetaData_& info() { return this->info_; }
  void info(const ::nav_msgs::msg::dds_::MapMetaData_& _val_) { this->info_ = _val_; }
  void info(::nav_msgs::msg::dds_::MapMetaData_&& _val_) { this->info_ = _val_; }
  const std::vector<uint8_t>& data() const { return this->data_; }
  std::vector<uint8_t>& data() { return this->data_; }
  void data(const std::vector<uint8_t>& _val_) { this->data_ = _val_; }
  void data(std::vector<uint8_t>&& _val_) { this->data_ = _val_; }

  bool operator==(const OccupancyGrid_& _other) const
  {
    (void) _other;
    return header_ == _other.header_ &&
      info_ == _other.info_ &&
      data_ == _other.data_;
  }

  bool operator!=(const OccupancyGrid_& _other) const
  {
    return !(*this == _other);
  }

};

}

}

}

#include "dds/topic/TopicTraits.hpp"
#include "org/eclipse/cyclonedds/topic/datatopic.hpp"

namespace org {
namespace eclipse {
namespace cyclonedds {
namespace topic {

template <> constexpr const char* TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::getTypeName()
{
  return "nav_msgs::msg::dds_::OccupancyGrid_";
}

template <> constexpr bool TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::isSelfContained()
{
  return false;
}

template <> constexpr bool TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::isKeyless()
{
  return true;
}

#ifdef DDSCXX_HAS_TYPE_DISCOVERY
template<> constexpr unsigned int TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::type_map_blob_sz() { return 2154; }
template<> constexpr unsigned int TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::type_info_blob_sz() { return 388; }
template<> inline const uint8_t * TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::type_map_blob() {
  static const uint8_t blob[] = {
 0xd7,  0x02,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0xf1,  0xa6,  0x7a,  0x91,  0x75,  0x57,  0xcb,  0x8b, 
 0xe9,  0x7b,  0x12,  0x9d,  0x77,  0xb3,  0xfd,  0x00,  0x68,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x58,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00, 
 0x19,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0xdc,  0xf1,  0x2c,  0xd2,  0xdd, 
 0x5e,  0x71,  0x2c,  0xb7,  0xb1,  0xe5,  0x1f,  0xa3,  0xf2,  0x09,  0x9f,  0xb9,  0x95,  0x00,  0x00,  0x00, 
 0x19,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x07,  0x57,  0xb7,  0x09,  0xbd, 
 0x5c,  0x8d,  0x18,  0x8f,  0x00,  0x60,  0x94,  0x68,  0x47,  0xca,  0xf9,  0xb6,  0xb9,  0x00,  0x00,  0x00, 
 0x10,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x80,  0xf3,  0x01,  0x00,  0x00,  0x02, 
 0x8d,  0x77,  0x7f,  0x38,  0xf1,  0xdc,  0xf1,  0x2c,  0xd2,  0xdd,  0x5e,  0x71,  0x2c,  0xb7,  0xb1,  0xe5, 
 0x1f,  0xa3,  0xf2,  0x00,  0x44,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,  0x01,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x34,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x19,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x56,  0x7c,  0x5a,  0x93,  0x54,  0x1c,  0x3b,  0x10,  0x86, 
 0xa4,  0xba,  0x46,  0xf9,  0x8d,  0x96,  0xb8,  0xc7,  0x8d,  0x00,  0x00,  0x00,  0x0c,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x70,  0x00,  0x4b,  0xb3,  0x9c,  0x5c,  0xf1,  0x56,  0x7c,  0x5a, 
 0x93,  0x54,  0x1c,  0x3b,  0x10,  0x86,  0xa4,  0xba,  0x46,  0xf9,  0x8d,  0x00,  0x33,  0x00,  0x00,  0x00, 
 0xf1,  0x51,  0x01,  0x00,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x23,  0x00,  0x00,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x04,  0x74, 
 0x45,  0x9c,  0xa3,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0xe2, 
 0x04,  0x64,  0xd5,  0xf1,  0x07,  0x57,  0xb7,  0x09,  0xbd,  0x5c,  0x8d,  0x18,  0x8f,  0x00,  0x60,  0x94, 
 0x68,  0x47,  0x00,  0x00,  0x81,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,  0x01,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x71,  0x00,  0x00,  0x00,  0x05,  0x00,  0x00,  0x00,  0x19,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x56,  0x7c,  0x5a,  0x93,  0x54,  0x1c,  0x3b,  0x10,  0x86, 
 0xa4,  0xba,  0x46,  0xf9,  0x8d,  0x66,  0x5b,  0xc6,  0xd3,  0x00,  0x00,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x09,  0xb7,  0xe1,  0x64,  0xb3,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0xea,  0xae,  0x26,  0xa6,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0xb4,  0x35,  0xe2,  0x27,  0x00,  0x19,  0x00,  0x00,  0x00, 
 0x04,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x2f,  0x93,  0xf0,  0x5b,  0x8c,  0xef,  0xbe,  0x11,  0x90, 
 0x31,  0xc4,  0x88,  0x17,  0xeb,  0x7c,  0x49,  0xb1,  0x53,  0xf1,  0x2f,  0x93,  0xf0,  0x5b,  0x8c,  0xef, 
 0xbe,  0x11,  0x90,  0x31,  0xc4,  0x88,  0x17,  0xeb,  0x51,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x41,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x19,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x5e,  0x73,  0x97,  0xe7,  0xe8, 
 0x64,  0x40,  0xdf,  0x64,  0xaf,  0x76,  0xcd,  0x4c,  0xbc,  0x47,  0x57,  0xfe,  0x07,  0x00,  0x00,  0x00, 
 0x19,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf1,  0x2e,  0xd7,  0x30,  0x7b,  0x8e, 
 0xc5,  0x7c,  0x4b,  0x34,  0x86,  0x46,  0xa9,  0x62,  0xa1,  0xda,  0x16,  0x39,  0x42,  0xf1,  0x5e,  0x73, 
 0x97,  0xe7,  0xe8,  0x64,  0x40,  0xdf,  0x64,  0xaf,  0x76,  0xcd,  0x4c,  0xbc,  0x43,  0x00,  0x00,  0x00, 
 0xf1,  0x51,  0x01,  0x00,  0x01,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x33,  0x00,  0x00,  0x00, 
 0x03,  0x00,  0x00,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x9d, 
 0xd4,  0xe4,  0x61,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x41, 
 0x52,  0x90,  0x76,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0xfb, 
 0xad,  0xe9,  0xe3,  0xf1,  0x2e,  0xd7,  0x30,  0x7b,  0x8e,  0xc5,  0x7c,  0x4b,  0x34,  0x86,  0x46,  0xa9, 
 0x62,  0xa1,  0x00,  0x00,  0x53,  0x00,  0x00,  0x00,  0xf1,  0x51,  0x01,  0x00,  0x01,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x43,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x9d,  0xd4,  0xe4,  0x61,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x41,  0x52,  0x90,  0x76,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0xfb,  0xad,  0xe9,  0xe3,  0x00,  0x0b,  0x00,  0x00,  0x00, 
 0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0xf1,  0x29,  0x01,  0x86,  0x00,  0xb0,  0x04,  0x00,  0x00, 
 0x07,  0x00,  0x00,  0x00,  0xf2,  0x9b,  0xfe,  0xf8,  0xd1,  0x93,  0x3f,  0x26,  0x1c,  0xef,  0x1f,  0x33, 
 0xfd,  0x62,  0x89,  0x00,  0xab,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,  0x2c,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x24,  0x00,  0x00,  0x00,  0x6e,  0x61,  0x76,  0x5f,  0x6d,  0x73,  0x67,  0x73, 
 0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x4f,  0x63,  0x63, 
 0x75,  0x70,  0x61,  0x6e,  0x63,  0x79,  0x47,  0x72,  0x69,  0x64,  0x5f,  0x00,  0x73,  0x00,  0x00,  0x00, 
 0x03,  0x00,  0x00,  0x00,  0x25,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0xe5, 
 0x76,  0x5e,  0xc4,  0x8c,  0xff,  0xd4,  0x19,  0xed,  0x7f,  0xe8,  0x4e,  0x2a,  0x55,  0x00,  0x00,  0x00, 
 0x07,  0x00,  0x00,  0x00,  0x68,  0x65,  0x61,  0x64,  0x65,  0x72,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x23,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0xaf,  0xf2,  0xbe,  0x67,  0xdd, 
 0x8e,  0x1b,  0x5c,  0x8c,  0x51,  0x02,  0x52,  0xab,  0x2d,  0x00,  0x00,  0x00,  0x05,  0x00,  0x00,  0x00, 
 0x69,  0x6e,  0x66,  0x6f,  0x00,  0x00,  0x00,  0x00,  0x17,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x80,  0xf3,  0x01,  0x00,  0x00,  0x02,  0x05,  0x00,  0x00,  0x00,  0x64,  0x61,  0x74,  0x61, 
 0x00,  0x00,  0x00,  0xf2,  0xe5,  0x76,  0x5e,  0xc4,  0x8c,  0xff,  0xd4,  0x19,  0xed,  0x7f,  0xe8,  0x4e, 
 0x2a,  0x55,  0x00,  0x00,  0x7b,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,  0x25,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x1d,  0x00,  0x00,  0x00,  0x73,  0x74,  0x64,  0x5f,  0x6d,  0x73,  0x67,  0x73, 
 0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x48,  0x65,  0x61, 
 0x64,  0x65,  0x72,  0x5f,  0x00,  0x00,  0x00,  0x00,  0x47,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x24,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0xd4,  0x85,  0x4f,  0x13,  0xae, 
 0xf3,  0x2d,  0xfe,  0x21,  0x57,  0xf3,  0xe6,  0x32,  0x0d,  0x00,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00, 
 0x73,  0x74,  0x61,  0x6d,  0x70,  0x00,  0x00,  0x00,  0x17,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x70,  0x00,  0x09,  0x00,  0x00,  0x00,  0x66,  0x72,  0x61,  0x6d,  0x65,  0x5f,  0x69,  0x64, 
 0x00,  0x00,  0x00,  0xf2,  0xd4,  0x85,  0x4f,  0x13,  0xae,  0xf3,  0x2d,  0xfe,  0x21,  0x57,  0xf3,  0xe6, 
 0x32,  0x0d,  0x00,  0x00,  0x72,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,  0x2d,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x25,  0x00,  0x00,  0x00,  0x62,  0x75,  0x69,  0x6c,  0x74,  0x69,  0x6e,  0x5f, 
 0x69,  0x6e,  0x74,  0x65,  0x72,  0x66,  0x61,  0x63,  0x65,  0x73,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a, 
 0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x54,  0x69,  0x6d,  0x65,  0x5f,  0x00,  0x00,  0x00,  0x00, 
 0x36,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00,  0x12,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x04,  0x00,  0x04,  0x00,  0x00,  0x00,  0x73,  0x65,  0x63,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x16,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0x00,  0x08,  0x00,  0x00,  0x00, 
 0x6e,  0x61,  0x6e,  0x6f,  0x73,  0x65,  0x63,  0x00,  0x00,  0x00,  0xf2,  0xaf,  0xf2,  0xbe,  0x67,  0xdd, 
 0x8e,  0x1b,  0x5c,  0x8c,  0x51,  0x02,  0x52,  0xab,  0x2d,  0x00,  0x00,  0x00,  0xe9,  0x00,  0x00,  0x00, 
 0xf2,  0x51,  0x01,  0x00,  0x2a,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x22,  0x00,  0x00,  0x00, 
 0x6e,  0x61,  0x76,  0x5f,  0x6d,  0x73,  0x67,  0x73,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64, 
 0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x4d,  0x61,  0x70,  0x4d,  0x65,  0x74,  0x61,  0x44,  0x61,  0x74,  0x61, 
 0x5f,  0x00,  0x00,  0x00,  0xb1,  0x00,  0x00,  0x00,  0x05,  0x00,  0x00,  0x00,  0x2c,  0x00,  0x00,  0x00, 
 0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0xd4,  0x85,  0x4f,  0x13,  0xae,  0xf3,  0x2d,  0xfe,  0x21, 
 0x57,  0xf3,  0xe6,  0x32,  0x0d,  0x00,  0x00,  0x00,  0x0e,  0x00,  0x00,  0x00,  0x6d,  0x61,  0x70,  0x5f, 
 0x6c,  0x6f,  0x61,  0x64,  0x5f,  0x74,  0x69,  0x6d,  0x65,  0x00,  0x00,  0x00,  0x19,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x09,  0x00,  0x0b,  0x00,  0x00,  0x00,  0x72,  0x65,  0x73,  0x6f, 
 0x6c,  0x75,  0x74,  0x69,  0x6f,  0x6e,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0x00,  0x06,  0x00,  0x00,  0x00,  0x77,  0x69,  0x64,  0x74, 
 0x68,  0x00,  0x00,  0x00,  0x15,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x07,  0x00, 
 0x07,  0x00,  0x00,  0x00,  0x68,  0x65,  0x69,  0x67,  0x68,  0x74,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x25,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0x0d,  0x47,  0x26,  0x4b,  0x4a, 
 0x66,  0xfa,  0x94,  0xbb,  0xfe,  0x34,  0xf3,  0x2f,  0x7d,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00, 
 0x6f,  0x72,  0x69,  0x67,  0x69,  0x6e,  0x00,  0x00,  0x00,  0xf2,  0x0d,  0x47,  0x26,  0x4b,  0x4a,  0x66, 
 0xfa,  0x94,  0xbb,  0xfe,  0x34,  0xf3,  0x2f,  0x7d,  0x92,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00, 
 0x28,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x20,  0x00,  0x00,  0x00,  0x67,  0x65,  0x6f,  0x6d, 
 0x65,  0x74,  0x72,  0x79,  0x5f,  0x6d,  0x73,  0x67,  0x73,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a, 
 0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x50,  0x6f,  0x73,  0x65,  0x5f,  0x00,  0x5e,  0x00,  0x00,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x27,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0x04, 
 0xac,  0x28,  0xf9,  0x19,  0x64,  0x23,  0x5d,  0xc9,  0x81,  0xe3,  0xf8,  0xfa,  0xdf,  0x00,  0x00,  0x00, 
 0x09,  0x00,  0x00,  0x00,  0x70,  0x6f,  0x73,  0x69,  0x74,  0x69,  0x6f,  0x6e,  0x00,  0x00,  0x00,  0x00, 
 0x2a,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0xf2,  0x6f,  0x01,  0xea,  0x49,  0x00, 
 0xbc,  0x02,  0x80,  0x58,  0xc3,  0xa8,  0xda,  0xe3,  0x52,  0x00,  0x00,  0x00,  0x0c,  0x00,  0x00,  0x00, 
 0x6f,  0x72,  0x69,  0x65,  0x6e,  0x74,  0x61,  0x74,  0x69,  0x6f,  0x6e,  0x00,  0x00,  0x00,  0xf2,  0x04, 
 0xac,  0x28,  0xf9,  0x19,  0x64,  0x23,  0x5d,  0xc9,  0x81,  0xe3,  0xf8,  0xfa,  0xdf,  0x00,  0x00,  0x00, 
 0x78,  0x00,  0x00,  0x00,  0xf2,  0x51,  0x01,  0x00,  0x29,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00, 
 0x21,  0x00,  0x00,  0x00,  0x67,  0x65,  0x6f,  0x6d,  0x65,  0x74,  0x72,  0x79,  0x5f,  0x6d,  0x73,  0x67, 
 0x73,  0x3a,  0x3a,  0x6d,  0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x50,  0x6f, 
 0x69,  0x6e,  0x74,  0x5f,  0x00,  0x00,  0x00,  0x00,  0x40,  0x00,  0x00,  0x00,  0x03,  0x00,  0x00,  0x00, 
 0x10,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x78,  0x00,  0x00,  0x00,  0x10,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x79,  0x00,  0x00,  0x00,  0x10,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x0a,  0x00,  0x02,  0x00,  0x00,  0x00,  0x7a,  0x00,  0x00,  0x00,  0xf2,  0x6f,  0x01,  0xea, 
 0x49,  0x00,  0xbc,  0x02,  0x80,  0x58,  0xc3,  0xa8,  0xda,  0xe3,  0x52,  0x00,  0x90,  0x00,  0x00,  0x00, 
 0xf2,  0x51,  0x01,  0x00,  0x2e,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x26,  0x00,  0x00,  0x00, 
 0x67,  0x65,  0x6f,  0x6d,  0x65,  0x74,  0x72,  0x79,  0x5f,  0x6d,  0x73,  0x67,  0x73,  0x3a,  0x3a,  0x6d, 
 0x73,  0x67,  0x3a,  0x3a,  0x64,  0x64,  0x73,  0x5f,  0x3a,  0x3a,  0x51,  0x75,  0x61,  0x74,  0x65,  0x72, 
 0x6e,  0x69,  0x6f,  0x6e,  0x5f,  0x00,  0x00,  0x00,  0x54,  0x00,  0x00,  0x00,  0x04,  0x00,  0x00,  0x00, 
 0x10,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x78,  0x00,  0x00,  0x00,  0x10,  0x00,  0x00,  0x00,  0x01,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00, 
 0x02,  0x00,  0x00,  0x00,  0x79,  0x00,  0x00,  0x00,  0x10,  0x00,  0x00,  0x00,  0x02,  0x00,  0x00,  0x00, 
 0x01,  0x00,  0x0a,  0x00,  0x02,  0x00,  0x00,  0x00,  0x7a,  0x00,  0x00,  0x00,  0x10,  0x00,  0x00,  0x00, 
 0x03,  0x00,  0x00,  0x00,  0x01,  0x00,  0x0a,  0x00,  0x02,  0x00,  0x00,  0x00,  0x77,  0x00,  0x00,  0x00, 
 0xd6,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  0x00,  0xf2,  0x9b,  0xfe,  0xf8,  0xd1,  0x93,  0x3f,  0x26, 
 0x1c,  0xef,  0x1f,  0x33,  0xfd,  0x62,  0x89,  0xf1,  0xa6,  0x7a,  0x91,  0x75,  0x57,  0xcb,  0x8b,  0xe9, 
 0x7b,  0x12,  0x9d,  0x77,  0xb3,  0xfd,  0xf2,  0xe5,  0x76,  0x5e,  0xc4,  0x8c,  0xff,  0xd4,  0x19,  0xed, 
 0x7f,  0xe8,  0x4e,  0x2a,  0x55,  0xf1,  0xdc,  0xf1,  0x2c,  0xd2,  0xdd,  0x5e,  0x71,  0x2c,  0xb7,  0xb1, 
 0xe5,  0x1f,  0xa3,  0xf2,  0xf2,  0xd4,  0x85,  0x4f,  0x13,  0xae,  0xf3,  0x2d,  0xfe,  0x21,  0x57,  0xf3, 
 0xe6,  0x32,  0x0d,  0xf1,  0x56,  0x7c,  0x5a,  0x93,  0x54,  0x1c,  0x3b,  0x10,  0x86,  0xa4,  0xba,  0x46, 
 0xf9,  0x8d,  0xf2,  0xaf,  0xf2,  0xbe,  0x67,  0xdd,  0x8e,  0x1b,  0x5c,  0x8c,  0x51,  0x02,  0x52,  0xab, 
 0x2d,  0xf1,  0x07,  0x57,  0xb7,  0x09,  0xbd,  0x5c,  0x8d,  0x18,  0x8f,  0x00,  0x60,  0x94,  0x68,  0x47, 
 0xf2,  0x0d,  0x47,  0x26,  0x4b,  0x4a,  0x66,  0xfa,  0x94,  0xbb,  0xfe,  0x34,  0xf3,  0x2f,  0x7d,  0xf1, 
 0x2f,  0x93,  0xf0,  0x5b,  0x8c,  0xef,  0xbe,  0x11,  0x90,  0x31,  0xc4,  0x88,  0x17,  0xeb,  0xf2,  0x04, 
 0xac,  0x28,  0xf9,  0x19,  0x64,  0x23,  0x5d,  0xc9,  0x81,  0xe3,  0xf8,  0xfa,  0xdf,  0xf1,  0x5e,  0x73, 
 0x97,  0xe7,  0xe8,  0x64,  0x40,  0xdf,  0x64,  0xaf,  0x76,  0xcd,  0x4c,  0xbc,  0xf2,  0x6f,  0x01,  0xea, 
 0x49,  0x00,  0xbc,  0x02,  0x80,  0x58,  0xc3,  0xa8,  0xda,  0xe3,  0x52,  0xf1,  0x2e,  0xd7,  0x30,  0x7b, 
 0x8e,  0xc5,  0x7c,  0x4b,  0x34,  0x86,  0x46,  0xa9,  0x62,  0xa1, };
  return blob;
}
template<> inline const uint8_t * TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::type_info_blob() {
  static const uint8_t blob[] = {
 0x80,  0x01,  0x00,  0x00,  0x01,  0x10,  0x00,  0x40,  0xb8,  0x00,  0x00,  0x00,  0xb4,  0x00,  0x00,  0x00, 
 0x14,  0x00,  0x00,  0x00,  0xf1,  0xa6,  0x7a,  0x91,  0x75,  0x57,  0xcb,  0x8b,  0xe9,  0x7b,  0x12,  0x9d, 
 0x77,  0xb3,  0xfd,  0x00,  0x6c,  0x00,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,  0x94,  0x00,  0x00,  0x00, 
 0x06,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf1,  0xdc,  0xf1,  0x2c,  0xd2,  0xdd,  0x5e,  0x71, 
 0x2c,  0xb7,  0xb1,  0xe5,  0x1f,  0xa3,  0xf2,  0x00,  0x48,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf1,  0x56,  0x7c,  0x5a,  0x93,  0x54,  0x1c,  0x3b,  0x10,  0x86,  0xa4,  0xba,  0x46,  0xf9,  0x8d,  0x00, 
 0x37,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf1,  0x07,  0x57,  0xb7,  0x09,  0xbd,  0x5c,  0x8d, 
 0x18,  0x8f,  0x00,  0x60,  0x94,  0x68,  0x47,  0x00,  0x85,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf1,  0x2f,  0x93,  0xf0,  0x5b,  0x8c,  0xef,  0xbe,  0x11,  0x90,  0x31,  0xc4,  0x88,  0x17,  0xeb,  0x00, 
 0x55,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf1,  0x5e,  0x73,  0x97,  0xe7,  0xe8,  0x64,  0x40, 
 0xdf,  0x64,  0xaf,  0x76,  0xcd,  0x4c,  0xbc,  0x00,  0x47,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf1,  0x2e,  0xd7,  0x30,  0x7b,  0x8e,  0xc5,  0x7c,  0x4b,  0x34,  0x86,  0x46,  0xa9,  0x62,  0xa1,  0x00, 
 0x57,  0x00,  0x00,  0x00,  0x02,  0x10,  0x00,  0x40,  0xb8,  0x00,  0x00,  0x00,  0xb4,  0x00,  0x00,  0x00, 
 0x14,  0x00,  0x00,  0x00,  0xf2,  0x9b,  0xfe,  0xf8,  0xd1,  0x93,  0x3f,  0x26,  0x1c,  0xef,  0x1f,  0x33, 
 0xfd,  0x62,  0x89,  0x00,  0xaf,  0x00,  0x00,  0x00,  0x06,  0x00,  0x00,  0x00,  0x94,  0x00,  0x00,  0x00, 
 0x06,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf2,  0xe5,  0x76,  0x5e,  0xc4,  0x8c,  0xff,  0xd4, 
 0x19,  0xed,  0x7f,  0xe8,  0x4e,  0x2a,  0x55,  0x00,  0x7f,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf2,  0xd4,  0x85,  0x4f,  0x13,  0xae,  0xf3,  0x2d,  0xfe,  0x21,  0x57,  0xf3,  0xe6,  0x32,  0x0d,  0x00, 
 0x76,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf2,  0xaf,  0xf2,  0xbe,  0x67,  0xdd,  0x8e,  0x1b, 
 0x5c,  0x8c,  0x51,  0x02,  0x52,  0xab,  0x2d,  0x00,  0xed,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf2,  0x0d,  0x47,  0x26,  0x4b,  0x4a,  0x66,  0xfa,  0x94,  0xbb,  0xfe,  0x34,  0xf3,  0x2f,  0x7d,  0x00, 
 0x96,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00,  0xf2,  0x04,  0xac,  0x28,  0xf9,  0x19,  0x64,  0x23, 
 0x5d,  0xc9,  0x81,  0xe3,  0xf8,  0xfa,  0xdf,  0x00,  0x7c,  0x00,  0x00,  0x00,  0x14,  0x00,  0x00,  0x00, 
 0xf2,  0x6f,  0x01,  0xea,  0x49,  0x00,  0xbc,  0x02,  0x80,  0x58,  0xc3,  0xa8,  0xda,  0xe3,  0x52,  0x00, 
 0x94,  0x00,  0x00,  0x00, };
  return blob;
}
#endif //DDSCXX_HAS_TYPE_DISCOVERY

} //namespace topic
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

namespace dds {
namespace topic {

template <>
struct topic_type_name<::nav_msgs::msg::dds_::OccupancyGrid_>
{
    static std::string value()
    {
      return org::eclipse::cyclonedds::topic::TopicTraits<::nav_msgs::msg::dds_::OccupancyGrid_>::getTypeName();
    }
};

}
}

REGISTER_TOPIC_TYPE(::nav_msgs::msg::dds_::OccupancyGrid_)

namespace org{
namespace eclipse{
namespace cyclonedds{
namespace core{
namespace cdr{

template<>
propvec &get_type_props<::nav_msgs::msg::dds_::OccupancyGrid_>();

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool write(T& streamer, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.header(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!write(streamer, instance.info(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!write(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !write(streamer, instance.data()[0], se_1))
        return false;
      }  //end sequence 1
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool write(S& str, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, bool as_key) {
  auto &props = get_type_props<::nav_msgs::msg::dds_::OccupancyGrid_>();
  str.set_mode(cdr_stream::stream_mode::write, as_key);
  return write(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool read(T& streamer, ::nav_msgs::msg::dds_::OccupancyGrid_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.header(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!read(streamer, instance.info(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!read(streamer, se_1))
        return false;
      instance.data().resize(se_1);
      if (se_1 > 0 &&
          !read(streamer, instance.data()[0], se_1))
        return false;
      }  //end sequence 1
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool read(S& str, ::nav_msgs::msg::dds_::OccupancyGrid_& instance, bool as_key) {
  auto &props = get_type_props<::nav_msgs::msg::dds_::OccupancyGrid_>();
  str.set_mode(cdr_stream::stream_mode::read, as_key);
  return read(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool move(T& streamer, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.header(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!move(streamer, instance.info(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = uint32_t(instance.data().size());
      if (!move(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !move(streamer, uint8_t(), se_1))
        return false;
      }  //end sequence 1
      if (!streamer.finish_consecutive())
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool move(S& str, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, bool as_key) {
  auto &props = get_type_props<::nav_msgs::msg::dds_::OccupancyGrid_>();
  str.set_mode(cdr_stream::stream_mode::move, as_key);
  return move(str, instance, props.data()); 
}

template<typename T, std::enable_if_t<std::is_base_of<cdr_stream, T>::value, bool> = true >
bool max(T& streamer, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, entity_properties_t *props) {
  (void)instance;
  if (!streamer.start_struct(*props))
    return false;
  auto prop = streamer.first_entity(props);
  while (prop) {
    switch (prop->m_id) {
      case 0:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.header(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 1:
      if (!streamer.start_member(*prop))
        return false;
      if (!max(streamer, instance.info(), prop))
        return false;
      if (!streamer.finish_member(*prop))
        return false;
      break;
      case 2:
      if (!streamer.start_member(*prop))
        return false;
      if (!streamer.start_consecutive(false, true))
        return false;
      {
      uint32_t se_1 = 0;
      if (!max(streamer, se_1))
        return false;
      if (se_1 > 0 &&
          !max(streamer, uint8_t(), se_1))
        return false;
      }  //end sequence 1
      if (!streamer.finish_consecutive())
        return false;
      streamer.position(SIZE_MAX);
      if (!streamer.finish_member(*prop))
        return false;
      break;
    }
    prop = streamer.next_entity(prop);
  }
  return streamer.finish_struct(*props);
}

template<typename S, std::enable_if_t<std::is_base_of<cdr_stream, S>::value, bool> = true >
bool max(S& str, const ::nav_msgs::msg::dds_::OccupancyGrid_& instance, bool as_key) {
  auto &props = get_type_props<::nav_msgs::msg::dds_::OccupancyGrid_>();
  str.set_mode(cdr_stream::stream_mode::max, as_key);
  return max(str, instance, props.data()); 
}

} //namespace cdr
} //namespace core
} //namespace cyclonedds
} //namespace eclipse
} //namespace org

#endif // DDSCXX_UNITREE_IDL_ROS2_OCCUPANCYGRID__HPP
