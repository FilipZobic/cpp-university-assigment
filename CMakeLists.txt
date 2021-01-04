cmake_minimum_required(VERSION 3.17)
project(cpp_university_assigment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_university_assigment
#        main.cpp
        main.cpp model/Date.cpp model/Date.h model/Person.cpp model/Person.h model/Worker.cpp model/Worker.h model/AnnualLeave.cpp model/AnnualLeave.h service/WorkerService.cpp service/WorkerService.h service/CsvFormatter.cpp service/CsvFormatter.h service/CsvFormatterUtil.h service/CsvFormatterUtil.cpp util/Util.cpp util/Util.h model/Clerk.cpp model/Clerk.h model/Driver.cpp model/Driver.h model/Warehouseman.cpp model/Warehouseman.h logic/CRUDWorker.cpp logic/CRUDWorker.h service/DepartmentMultiService.cpp service/DepartmentMultiService.h service/Service.cpp service/Service.h logic/CRUD.cpp logic/CRUD.h logic/CRUDBusiness.cpp logic/CRUDBusiness.h model/Department.cpp model/Department.h logic/CRUDDepartment.cpp logic/CRUDDepartment.h model/Business.cpp model/Business.h service/BusinessMultiService.cpp service/BusinessMultiService.h service/MultiService.cpp service/MultiService.h service/Entity.cpp service/Entity.h gui/MainWindow.cpp gui/MainWindow.h gui/AbstractTable.cpp gui/AbstractTable.h gui/BusinessTable.cpp gui/BusinessTable.h gui/BusinessWindow.cpp gui/BusinessWindow.h gui/DepartmentWindow.cpp gui/DepartmentWindow.h gui/WorkerWindow.cpp gui/WorkerWindow.h gui/AbstractNewEntity.cpp gui/AbstractNewEntity.h gui/AbstractReplaceEntity.cpp gui/AbstractReplaceEntity.h gui/AddAnualLeave.cpp gui/AddAnualLeave.h gui/WorkerCard.cpp gui/WorkerCard.h gui/AbstractShowEntity.cpp gui/AbstractShowEntity.h)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include_directories(/home/filipz/fltk-1.3.5)
link_directories(/home/filipz/fltk-1.3.5/lib)
target_link_libraries(cpp_university_assigment /home/filipz/fltk-1.3.5/lib/libfltk.a Xrender Xcursor Xfixes Xext Xft fontconfig Xinerama pthread dl m X11)

#fltk