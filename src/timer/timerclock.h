/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 * get format time through class timerclock.
 */

#ifndef KNO_TIMER_TIMERCLOCK_H_
#define KNO_TIMER_TIMERCLOCK_H_

#include <string>
// 禁止使用拷贝构造函数和赋值操作的宏
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator=(const TypeName &)

namespace knotimer
{
struct StandardTime
{
    int year_;
    int mon_;
    int day_;
    int hour_;
    int min_;
    int sec_;
};

class Timer
{
  public:
    explicit Timer()
    {
        current_time_.year_ = 2017;
        current_time_.mon_ = 1;
        current_time_.day_ = 1;
        current_time_.hour_ = 6;
        current_time_.min_ = 0;
        current_time_.sec_ = 0;
    }
    virtual ~Timer() {}

    // get string type's time
    std::string GetStringTime(std::string &st);
    void set_current_time();
    StandardTime get_current_time() const;

  private:
    StandardTime current_time_;
};
} // namespace knotimer

#endif //
