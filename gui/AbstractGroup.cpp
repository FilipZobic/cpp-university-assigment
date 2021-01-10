#include "AbstractGroup.h"

#include <string>
using namespace std;

#include "AbstractEntityWindow.h"

template<typename T>
AbstractGroup<T>::AbstractGroup(const char *string, const char *purpose, CRUD<T> *crud, AbstractTableModel<T> *tableModel, Fl_Window *parent)
: Fl_Group(parent->x(), parent->y(), parent->w(), parent->h(), string), crud(crud){

    purposeLabel = new Fl_Box(20, 116, 220, 24, purpose);

    btnCreate = new Fl_Button(45, 150, 165, 50, "CREATE");
    btnCreate->callback(AbstractGroup::createEventHandler,this);

    btnChange = new Fl_Button(220, 150, 165, 50,"MODIFY");
    btnChange->callback(AbstractGroup::modifyEventHandler, this);

    btnDelete = new Fl_Button(395, 150, 165, 50,"DELETE");
    btnDelete->callback(AbstractGroup::deleteEventHandler, this);

    btnLoad = new Fl_Button(570, 150, 165, 50,"LOAD");

    this->turnOffButtons();

    this->tableModel = new BusinessTableModel(crud->getService()->getEntities());

    tableDisplay = new Table<Business*>(0, 215, 1100, 240, "", this->tableModel);

    //tableModel->updateTable();
    tableDisplay->col_header();
    tableDisplay->row_header();
    tableDisplay->callback(AbstractGroup::checkButtons, this);

    // this->resizable();
    this->end();
}

template<typename T>
void AbstractGroup<T>::turnOnButtons(AbstractGroup::SwitchType switchType) {
    if (switchType == ALL) {
        btnChange->activate();
        btnDelete->activate();
        btnLoad->activate();
    } else if (switchType == ONE) {
        btnDelete->activate();
    }
}

template<typename T>
void AbstractGroup<T>::turnOffButtons(AbstractGroup::SwitchType switchType) {
    btnChange->deactivate();
    btnDelete->deactivate();
    btnLoad->deactivate();
}

template<typename T>
void AbstractGroup<T>::checkButtons(Fl_Widget *widget, void *data) {
    auto *mainWindow = (AbstractGroup<T>*)data;
    int startRow;
    int endRow;
    int colLeft;
    int colRight;
    mainWindow->tableDisplay->get_selection(startRow, colLeft, endRow, colRight);

    mainWindow->turnOffButtons();

    if (startRow != -1){
        if( startRow == endRow) {
            mainWindow->turnOnButtons();
        }else {
            mainWindow->turnOnButtons(ONE);
        }
    }
}

template<typename T>
void AbstractGroup<T>::createEventHandler(Fl_Widget *widget, void *data) {
    AbstractGroup<T> *abstractGroup = (AbstractGroup<T>*)data;

    abstractGroup->create();
}

template<typename T>
void AbstractGroup<T>::modifyEventHandler(Fl_Widget *widget, void *data) {
    AbstractGroup<T> *abstractGroup = (AbstractGroup<T>*)data;

    abstractGroup->modify();
}

template<typename T>
void AbstractGroup<T>::deleteEventHandler(Fl_Widget *widget, void *data) {
    AbstractGroup<T> *abstractGroup = (AbstractGroup<T>*)data;

    TableSelection region = abstractGroup->getSelection();

    for(int i = region.endRow ; i >= region.startRow ; i--){
        cout << i << endl;
        long id = abstractGroup->tableDisplay->model->at(i)->getId();
        abstractGroup->crud->removeEntity(id);
    }
    abstractGroup->reRender();
    abstractGroup->turnOffButtons();
}

template<typename T>
void AbstractGroup<T>::loadEventHandler(Fl_Widget *widget, void *data) {

}

template<typename T>
CRUD<T> *AbstractGroup<T>::getCrud() const {
    return crud;
}

template<typename T>
void AbstractGroup<T>::reRender() {
    this->tableDisplay->updateRows();
    this->tableDisplay->redraw();
}

template<typename T>
TableSelection AbstractGroup<T>::getSelection() {
    TableSelection tableSelection;
    this->tableDisplay->get_selection(tableSelection.startRow, tableSelection.startColumn, tableSelection.endRow, tableSelection.endColumn);
    return tableSelection;
}

template class AbstractGroup<Business*>;