/*
 * Copyright (c) 2017 An.AI Inc.
 * All rights reserved.
 *
 * License boilerplate.
 *
 * Sun Yiming. Email: hi@anai.co
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
