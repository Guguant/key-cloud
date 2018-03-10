# samlock 数据库设计

##  login.html

- user.table 用户信息表

  | 字段       | 描述   |
  | -------- | ---- |
  | username | 用户名  |
  | passwd   | 密码   |

## status.shtml

- lockrealfacus.table 用户关注的锁的状态信息

- lockrealstatus.table 锁的状态信息（同facus.table字段）

  | 字段           | 描述     |
  | ------------ | ------ |
  | sId          | 设备编号   |
  | sBuilding    | 楼号     |
  | sFloor       | 楼层号    |
  | sPosition    | 方位号    |
  | sRoom        | 房间号    |
  | sOpen        | 开关     |
  | sIP          | IP地址信息 |
  | sDeviceModel | 传感器型号  |

## analysis.shtml

在lockrealstaus.table遍历数据

## configure.shtml

- sensorDevice.table 传感器信息表，记录所有的传感器信息


- facusDevice.table 用户关注的传感器信息

| 字段          | 描述     |
| ----------- | ------ |
| sId         | 设备编号   |
| sBuilding   | 楼号     |
| sFloor      | 楼层号    |
| sPosition   | 方位号    |
| sRoom       | 房间号    |
| sOpen       | 开关     |
| sIP         | IP地址信息 |
| sDeviceMode | 传感器型号  |

## system.shtml

- 【版本】version.table

  | 字段                  | 描述        |
  | ------------------- | --------- |
  | pNewFunciton        | 本次更新的功能   |
  | pVersionHistory     | 版本历史记录URL |
  | pVersionCurrent     | 版本号（主键）   |
  | pVersionReleaseTime | 版本发布时间    |
  | pPublishCompany     | 开发商       |
  | pSize               | 版本大小      |
  | pCompatibility      | 兼容性       |
  | pLanguage           | 语言        |
  | pDeveloper          | 开发者网站     |
  | pPrivacyPolicy      | 隐私政策      |

- 【升级】

- 【日志】

- 【帮助】

## history.shtml

| 字段           | 描述      |
| ------------ | ------- |
| hVersion     | 版本号（主键） |
| hReleaseTime | 发行时间    |
| hNewFunciton | 新功能     |

