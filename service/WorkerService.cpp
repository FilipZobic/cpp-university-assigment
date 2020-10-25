#include "WorkerService.h"
#include "../util/Util.h"

// mogu staviti template za to ali svaki koji saljem ce imati tu klasu CsvFormater i onda zavisnosti od cega je formiraj klasu
void WorkerService::ParseWorker(string workerString,Worker *worker) {
    string csvS = Worker::sep;
    vector<string> params;cuaUtil::parseStringIntoVector(workerString,params,csvS);

    for (int i = 0; i < params.size(); ++i) {
        std::cout << params[i] << endl;
    }

    worker->Parse(&params); // passe ither by pointer or refrence
};