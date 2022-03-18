# kno 数据库设计

##  login.html

user.table : the users' information table.

  | Field    | Description |
  | -------- | ---- |
  | username | username |
  | passwd   | passwd   |

## status.shtml

lockrealstatus.table : the sensors' status infomation.

  | Field        | Description |
  | ------------ | -------- |
  | sroomId      | room id  |
  | sPosition    | postion  |
  | sOpen        | on, off or wrong |
  | sIP          | ip       |
  | sPort        | port     |
  | sFacus       | facus    |

## analysis.shtml

Traverse Sensors' status data in lockrealstatus.table.

## configure.shtml

sensorDevice.table : the sensors' infomation lists.

  | Field        | Description |
  | ------------ | -------- |
  | sroomId      | room id  |
  | sPosition    | postion  |
  | sOpen        | on, off or wrong |
  | sIP          | ip       |
  | sPort        | port     |
  | sFacus       | facus    |

## system.shtml

version.table : intro the version infomation.

  | Field        | Description |
  | ------------------- | --------- |
  | pNewFunciton        | New Function         |
  | pVersionHistory     | Version History URL  |
  | pVersionCurrent     | Version Current      |
  | pVersionReleaseTime | Version Release Time |
  | pPublishCompany     | PublishCompany       |
  | pSize               | Size of Software     |
  | pCompatibility      | System Compatibility |
  | pLanguage           | Languge           |
  | pDeveloper          | Developer Website |
  | pPrivacyPolicy      | Privacy Policy    |

- 【UPDATE】

- 【LOG】

- 【HELP】

## history.shtml

  | Field        | Description |
  | ------------ | ------- |
  | hVersion     | Version |
  | hReleaseTime | Release Time |
  | hNewFunciton | New Funciton |
