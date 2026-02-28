# MiniStudentDB

A simple student management system using C++ and SQLite.

## Build
make

## Run
./studentdb

## 项目结构
```
MiniStudentDB/
├── README.md
├── .gitignore
├── Makefile
├── data/
│   └── student.db
├── src/
│   ├── main.cpp
│   ├── student.h
│   ├── student.cpp
│   ├── database.h
│   └── database.cpp
└── screenshots/
    ├── sqlite/
    │   ├── insert5.png
    │   ├── insert5_result.png
    │   ├── order_by.png
    │   ├── WHERE + ORDER BY.png
    │   ├── GROUP BY+count.png
    │   └── GROUP BY+average.png
    └── cpp/
        ├── add.png
        ├── delete.png
        ├── update.png
        ├── list.png
        └── exit.png
```

## Git 迭代说明

本项目通过6次Git提交完成开发：

1. **init project structure** - 初始化项目结构
2. **add main menu framework** - 添加菜单框架
3. **implement Student class** - 实现Student类
4. **add SQLite database wrapper** - 添加SQLite数据库封装
5. **implement student CRUD operations** - 实现学生增删改查功能
6. **refactor code and add comments** - 重构代码并添加注释
