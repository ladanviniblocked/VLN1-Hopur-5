#include "compservice.h"

CompService::CompService()
{

}
CompService::CompService(Database db){
    _db = db;
    computers = _db.getComputerList();

}
// Create
string CompService::create(int id, string name, string type, int yearBuilt, bool built){

    Comps* newComputer = new Comps(id, name, type, yearBuilt, built);
    bool flag = false;

     if((yearBuilt > 100 ||!(yearBuilt != 0 && yearBuilt < 2016 )))
        return "unacceptable value in one of the fields\n";

        if(_db.existsInCompDB(*newComputer)) {
            flag = true;
    }
    if(flag) {
       return "Computer already exists\n";
    }
    computers.push_back(*newComputer);

    _db.updateCompDB(computers);
    _db.writeToCompDB(*newComputer);
    return "Added successfully\n";
}



//Search

vector<Comps> CompService::searchByName(string name){

        transform(name.begin(), name.end(), name.begin(), ::tolower);
        string _name = "";

        vector<Comps> result;

        for(size_t i = 0; i < computers.size(); i++) {

            _name = computers.at(i).getName();
            transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
            if(_name.find(name) != std::string::npos) {
                result.push_back(computers.at(i));
            }
        }

        return result;
    }


    vector<Comps> CompService::searchById(int id){

        vector<Comps> result;

        for (size_t i = 0; i < computers.size(); i++){

            if(id == computers.at(i).getId()){
                result.push_back(computers.at(i));

            }


        }

    }

    vector<Comps> CompService::searchByType(string type){

        vector<Comps> result;

        for(size_t i = 0; i < computers.size(); i++){

            if(type == computers.at(i).getType()){

                result.push_back(computers.at(i));
            }
        }



    }
vector<Comps> CompService::searchByBuilt(int yearBuilt){

        vector<Comps> result;

        for(size_t i = 0; i < computers.size(); i++){

            if(yearBuilt == computers.at(i).getYearBuilt()){

                result.push_back(computers.at(i));

            }
         }
}

// Sort

    vector<Comps> CompService::sortByName() {

    vector<string> names;
        vector<Comps> sorted;
            for(unsigned int i = 0; i < computers.size(); i++)
             names.push_back(computers.at(i).getName());

     std::sort(names.begin(), names.end());

        for(unsigned int i = 0; i < names.size(); i++) {
            for(unsigned int j = 0; j < computers.size(); j++)
                if(names.at(i) == computers.at(j).getName())
                 sorted.push_back(computers.at(j));
    }

    return sorted;
}
vector<Comps> CompService::sortByType() {
    vector<string> types;
        vector<Comps> sorted;
    for(unsigned int i = 0; i < computers.size(); i++)
        types.push_back(computers.at(i).getType());

      std::sort(types.begin(), types.end());

        for(unsigned int i = 0; i < types.size(); i++) {
            for(unsigned int j = 0; j < computers.size(); j++)
                if(types.at(i) == computers.at(j).getType())
                sorted.push_back(computers.at(j));
    }

    return sorted;

}


vector<Comps> CompService::sortByBuilt() {

    vector<bool> builtComps;
        vector<Comps> sorted;
            for(unsigned int i = 0; i < computers.size(); i++)
             builtComps.push_back(computers.at(i).getBuilt());

    std::sort(builtComps.begin(), builtComps.end());

    for(unsigned int i = 0; i < builtComps.size(); i++) {
        for(unsigned int j = 0; j < computers.size(); j++)
            if(builtComps.at(i) == computers.at(j).getBuilt())
                sorted.push_back(computers.at(j));
    }

    return sorted;

}
//DELETE
string CompService::deleteComputers(string name, string type){
    bool flag = false;
    string c_name;
    Comps result;

    for(unsigned int i=0; i<computers.size(); i++) {
        c_name = computers.at(i).getName();

        if(c_name.find(name) != std::string::npos && computers.at(i).getType() == type ) {
            result = computers.at(i);
            computers.erase(computers.begin() + i);
            flag = true;
        }
    }

    if(flag) {
        _db.updateCompDB(computers);
        _db.reWriteDb();
        return result.showComputer() +
                "Erased successfully\n";
    }

    return "Computer: \n" + result.getName() + "\n not found\n";
}
// Edit
// Showing
string showComputers(vector<Comps> results) {

    string temp = "";

    for(unsigned int i = 0; i < results.size(); i++) {
        temp = temp + "--------------------------------------------------------------\n";
        temp = temp + results.at(i).showComputer();
    }
    if(results.size() == 0) {
        temp = "#########################################################################\n";
        temp = temp + "No Results Found!\n";
    }
    temp =  temp + "--------------------------------------------------------------\n";
    return temp;
}