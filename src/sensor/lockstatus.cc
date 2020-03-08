/*
 * Copyright (c) 2017 - 2020.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#include "lockstatus.h"

namespace sensorinfo
{
    void SensorStatus::set_cpu(double real_cpu)
    {
        real_cpu_ = real_cpu;
    }

    double SensorStatus::get_cpu() const
    {
        return real_cpu_;
    }
} // namespace sensorinfo
