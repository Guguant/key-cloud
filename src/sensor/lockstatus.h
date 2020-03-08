/*
 * Copyright (c) 2017 - 2020.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#ifndef SAMLOCK_SENSOR_LOCKSTATUS_H_
#define SAMLOCK_SENSOR_LOCKSTATUS_H_

/* 禁止使用拷贝构造函数和赋值操作的宏 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator=(const TypeName &)

namespace sensorinfo
{
class SensorStatus
{
  public:
    explicit SensorStatus(double a = 0) : real_cpu_(a) {}
    virtual ~SensorStatus() {}

    void set_cpu(double real_cpu);
    double get_cpu() const;

  private:
    DISALLOW_COPY_AND_ASSIGN(SensorStatus);
    double real_cpu_;
};
} // namespace sensorinfo

#endif // SAMLOCK_SENSOR_LOCKSTATUS_H_
