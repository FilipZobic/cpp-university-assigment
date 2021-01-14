#include "Util.h"
#include "../model/Worker.h"

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

string cuaUtil::roundDouble(double number, std::size_t pos) {
    string roundDouble(double number, std::size_t pos = 2);
        string toReturn = to_string(number);
        string patternText = "\\-{0,1}[0-9]*\\.{1}[0-9]{" + to_string(pos) + "}";
        regex pattern(patternText);

        for(std::sregex_iterator i = std::sregex_iterator(toReturn.begin(), toReturn.end(), pattern);
            i != std::sregex_iterator();
            ++i )
        {
            std::smatch m = *i;
            return m.str();
        }

}

bool cuaUtil::patternPhoneNumberCheck(string number) {
    if (number.empty()){
        return true;
    }
    if (regex_match(number,regex("\\[a-Z]"))){
        return true;
    }

    regex pattern("\\s*|\\/*\\-*");
    number = regex_replace(number,pattern,"");

    if (!regex_match(number,regex("\\+{0,1}[0-9]{7,15}"))){
        return true;
    }

    return false;
}



//template cuaUtil::findIndex<Worker*>;