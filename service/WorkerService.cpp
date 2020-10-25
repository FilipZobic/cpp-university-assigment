#include "WorkerService.h"

// mogu staviti template za to ali svaki koji saljem ce imati tu klasu CsvFormater i onda zavisnosti od cega je formiraj klasu
void WorkerService::ParseWorker(string workerString,Worker *worker) {
    string csvS = Worker::sep;
    size_t csvL = csvS.length();
    vector<string> params;

    int pos;
    do {
        pos = workerString.find(csvS);
        if (pos<workerString.size()){
            params.push_back(workerString.substr(0,pos));
            workerString.erase(workerString.begin(),workerString.begin()+pos+csvL);
        } else {
            params.push_back(workerString.substr(0,workerString.length()));
            workerString.erase(workerString.begin(),workerString.end());
            break;
        }
    } while (true);

    for (int i = 0; i < params.size(); ++i) {
        std::cout << params[i] << endl;
    }

    worker->Parse(&params); // passe ither by pointer or refrence
};