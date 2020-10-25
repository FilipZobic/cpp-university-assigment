#include "Util.h"


void cuaUtil::parseStringIntoVector(string &target, vector<string> &vectorStrings,string sep){
    size_t sepL = sep.length();
    size_t pos;
    do {
        pos = target.find(sep);
        if (pos<target.size()){
            vectorStrings.push_back(target.substr(0,pos));
            target.erase(target.begin(),target.begin()+pos+sepL);
        } else {
            vectorStrings.push_back(target.substr(0,target.length()));
            target.erase(target.begin(),target.end());
            break;
        }
    } while (true);
}
