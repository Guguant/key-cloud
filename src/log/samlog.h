/*
 * Copyright (c) 2017 - 2020.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#ifndef SAMLOCK_LOG_SAMLOG_H_
#define SAMLOCK_LOG_SAMLOG_H_

/* 禁止使用拷贝构造函数和赋值操作的宏 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator=(const TypeName &)

namespace logger
{
class Samlog
{
  public:
    explicit Samlog() {}
    virtual ~Samlog() {}

  private:
    DISALLOW_COPY_AND_ASSIGN(Samlog);
};
} // namespace logger

#endif // SAMLOCK_LOG_SAMLOG_H_