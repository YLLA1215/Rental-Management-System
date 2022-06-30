# Rental management system

这是一个租房的管理系统。  
系统中包含了“租客登记”、“查看/更新房间信息”、“查看/更新租客信息”、“每月房租计算”、“租客退房”等功能。  
  
使用时要先将File.c文件中的"WritePeopleDataUser"、"UpdatePeopleDataUser"、"WritePeopleDataManagement"、"UpdatePeopleDataManagement"、"ReadPeopleData"等10个函数里的fopen函数的文件路径实参进行修改。否则无法正常使用。  
  
有任何使用上的问题或bug可以在"问题"分区向我提出，谢谢大家。
  
  
# 更新日志
【2022.6.30】:发布了第一个demo版本。  
【2022.7.1】:修复了上个版本中完成“租客登记”后“room”文件中对应房间未同步更新的问题。修复了上个版本中完成“租客退房”后“room”文件中对应房间未同步更新的问题。
