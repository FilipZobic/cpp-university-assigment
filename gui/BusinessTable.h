//
// Created by filipz on 1/4/21.
//

#ifndef CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLE_H
#define CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLE_H


#include <FL/Fl_Table.H>
#include <FL/Fl_Table_Row.H>
#include "BusinessTableModel.h"

class BusinessTable : public Fl_Table_Row{
public:
    BusinessTable(int x, int y, int w, int h, const char *l, BusinessTableModel *model);
    BusinessTableModel *model;
    void updateRows();

    BusinessTableModel *getModel() const;

protected:
    void draw_cell(TableContext context, int row = 0, int column = 0, int x = 0, int y = 0, int w = 0, int h = 0) override;

};


#endif //CPP_UNIVERSITY_ASSIGMENT_BUSINESSTABLE_H
