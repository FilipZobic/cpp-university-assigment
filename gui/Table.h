#ifndef CPP_UNIVERSITY_ASSIGMENT_TABLE_H
#define CPP_UNIVERSITY_ASSIGMENT_TABLE_H

#include <FL/Fl_Table_Row.H>
#include "AbstractTableModel.h"

template <typename T>
class Table  : public Fl_Table_Row {
public:
    void updateRows();
    Table(int x, int y, int w, int h, const char *l, AbstractTableModel<T> *model);
    AbstractTableModel<T> *model;
protected:
    void draw_cell(TableContext context, int row = 0, int column = 0, int x = 0, int y = 0, int w = 0, int h = 0) override;
};



#endif
