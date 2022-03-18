/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#ifndef KNO_LOG_KNOLOG_H_
#define KNO_LOG_KNOLOG_H_

/* 禁止使用拷贝构造函数和赋值操作的宏 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName &);            \
    void operator=(const TypeName &)

namespace logger
{
class Knolog
{
  public:
    explicit Knolog() {}
    virtual ~Knolog() {}

  private:
    DISALLOW_COPY_AND_ASSIGN(Knolog);
};
} // namespace logger

#endif // KNO_LOG_KNOLOG_H_