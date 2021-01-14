cmake_minimum_required(VERSION 3.17)
project(cpp_university_assigment)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_university_assigment
#        main.cpp
        main.cpp model/Date.cpp model/Date.h model/Person.cpp model/Person.h model/Worker.cpp model/Worker.h model/AnnualLeave.cpp model/AnnualLeave.h service/WorkerService.cpp service/WorkerService.h service/CsvFormatter.cpp service/CsvFormatter.h service/CsvFormatterUtil.h service/CsvFormatterUtil.cpp util/Util.cpp util/Util.h model/Clerk.cpp model/Clerk.h model/Driver.cpp model/Driver.h model/Warehouseman.cpp model/Warehouseman.h logic/CRUDWorker.cpp logic/CRUDWorker.h service/DepartmentMultiService.cpp service/DepartmentMultiService.h service/Service.cpp service/Service.h logic/CRUD.cpp logic/CRUD.h logic/CRUDBusiness.cpp logic/CRUDBusiness.h model/Department.cpp model/Department.h logic/CRUDDepartment.cpp logic/CRUDDepartment.h model/Business.cpp model/Business.h service/BusinessMultiService.cpp service/BusinessMultiService.h service/MultiService.cpp service/MultiService.h service/Entity.cpp service/Entity.h gui/MainWindow.cpp gui/MainWindow.h gui/BusinessGUI/BusinessWindow.cpp gui/BusinessGUI/BusinessWindow.h gui/DepartmentGUI/DepartmentWindow.cpp gui/DepartmentGUI/DepartmentWindow.h gui/WorkerGUI/WorkerWindow.cpp gui/WorkerGUI/WorkerWindow.h gui/WorkerGUI/AnnualLeaveWindow.cpp gui/WorkerGUI/AnnualLeaveWindow.h gui/WorkerGUI/WorkerCard.cpp gui/WorkerGUI/WorkerCard.h gui/BusinessGUI/BusinessTableModel.cpp gui/BusinessGUI/BusinessTableModel.h gui/AbstractGroup.cpp gui/AbstractGroup.h gui/BusinessGUI/BusinessGroup.cpp gui/BusinessGUI/BusinessGroup.h gui/AbstractTable/AbstractTableModel.cpp gui/AbstractTable/AbstractTableModel.h gui/AbstractTable/Table.cpp gui/AbstractTable/Table.h gui/AbstractEntityWindow.cpp gui/AbstractEntityWindow.h gui/DepartmentGUI/DepartmentGroup.cpp gui/DepartmentGUI/DepartmentGroup.h gui/DepartmentGUI/DepartmentTableModel.cpp gui/DepartmentGUI/DepartmentTableModel.h gui/AbstractDisplay/NavigationDisplay.cpp gui/AbstractDisplay/NavigationDisplay.h gui/AbstractDisplay/AbstractNavigationDisplayModel.cpp gui/AbstractDisplay/AbstractNavigationDisplayModel.h gui/DepartmentGUI/BusinessDisplayModel.cpp gui/DepartmentGUI/BusinessDisplayModel.h gui/AbstractDisplay/AbstractNavigatorImplementation.cpp gui/AbstractDisplay/AbstractNavigatorImplementation.h gui/WorkerGUI/DepartmentDisplayModel.cpp gui/WorkerGUI/DepartmentDisplayModel.h gui/WorkerGUI/WorkerGroup.cpp gui/WorkerGUI/WorkerGroup.h gui/WorkerGUI/WorkerTableModel.cpp gui/WorkerGUI/WorkerTableModel.h)


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include_directories(/home/filipz/fltk-1.3.5)
link_directories(/home/filipz/fltk-1.3.5/lib)
target_link_libraries(cpp_university_assigment /home/filipz/fltk-1.3.5/lib/libfltk.a Xrender Xcursor Xfixes Xext Xft fontconfig Xinerama pthread dl m X11)

#fltk