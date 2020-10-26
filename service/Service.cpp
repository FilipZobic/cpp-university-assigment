#include "Service.h"
//#include <istream>
//#include <ostream>
#include <fstream>
#include <stdexcept>
#include "../util/Util.h"
#include "CsvFormatter.h"

template <typename T>
Service<T>::Service(const string &filename,vector<T>* entities) : filename(filename),entities(entities) {
    amountOfItems = 0;
    lastUsedId = 0;
    readFromFile();
}

template <typename T>
ifstream& Service<T>::readFirstLine(ifstream& file){
    string line;
    getline(file,line); // napravi funkciju koja cita ova 2 parametra i vraca file file posle moramo zatvoriti

    vector<string> lines; // moramo deletovati u funkcji gde zovemo

    cuaUtil::parseStringIntoVector(line, lines, "|*|");

    this->amountOfItems = stol(lines.at(0));
    this->lastUsedId = stol(lines.at(1));

    lines.erase(lines.begin(), lines.end()); // this can be safely removed
    return file; // we can turn function into void
};

template <typename T>
void Service<T>::readAllLines(vector<string>& lines,ifstream &file){
    string line;
    int i = 0;
    while (i<amountOfItems){
        getline(file,line);
        lines.push_back(line);
        i++;
    }
};

template <typename T>
template<typename Y>
void Service<T>::openFile(Y &file){

    file.open("../database/"+this->filename);
    if (!file.is_open()){ // add error function which opens file
        throw std::runtime_error("Could not open file"); //parse entity function samo redifinisemo sve ostalo moze da bude csv separator
    }

}

// funkcija koja ucitava ta dva parametra
//vrati vector stringova linije
template <typename T>
void Service<T>::readFromFile(){ // path to file change

    //Opening
    ifstream file;
    openFile<ifstream>(file);

    //Reading
    readFirstLine(file);
    vector<string> lines;
    readAllLines(lines,file);

    //Closing
    file.close();

    //Parsing those vectors
    //parseentity ce biti pure virtual metoda na pocetku cemo definisiati kao za workere pa cemo je prebaciti posle

}

template <typename T>
void Service<T>::writeAllLines(ofstream &file) const{
    string firstLine = to_string(this->amountOfItems) + "|*|" + to_string(this->lastUsedId);
    file << firstLine << "\n";
    for (T entity : (*this->entities)) {
        file << entity->Serialize() << "\n";
    }
};

template <typename T>
void Service<T>::writeToFile() {

    //Opening
    ofstream file;
    openFile<ofstream>(file);

    writeAllLines(file);

    file.close();
}

template class Service<Worker*>;