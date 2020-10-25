cmake_minimum_required(VERSION 3.17)
project(cpp_university_assigment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
#include_directories(database)
#include_directories(gui)
#include_directories(logic)
#include_directories(model)
#include_directories(service)

add_executable(cpp_university_assigment
#        main.cpp
        main.cpp model/Date.cpp model/Date.h model/Person.cpp model/Person.h model/Worker.cpp model/Worker.h model/AnnualLeave.cpp model/AnnualLeave.h service/WorkerService.cpp service/WorkerService.h service/CsvFormatter.cpp service/CsvFormatter.h service/CsvFormatterUtil.h service/CsvFormatterUtil.cpp util/Util.cpp util/Util.h model/Clerk.cpp model/Clerk.h model/Driver.cpp model/Driver.h model/Warehouseman.cpp model/Warehouseman.h)
