#include "linkservice.h"

LinkService::LinkService()
{

}
LinkService::LinkService(Database db){
    _db = db;
    _linkList = db.getConnectionList();
    _compList = db.getComputerList();
    _persList = db.getList();
}
vector<Links> LinkService::getLinkList(){
    return _linkList;
}
vector<Comps> LinkService::getCompList(){
    return _compList;
}
vector<Person> LinkService::getPersList(){
    return _persList;
}
string LinkService::create(string computerID, string personID){

    bool flagc = false;
    bool flagp = false;

    int cID = stoi(computerID);
    int pID = stoi(personID);

    Comps c;
    Person p;
    for(unsigned int i=0; i<_compList.size(); i++){
        if(!flagc && _compList.at(i).getId() == cID){
            c = _compList.at(i);
            flagc = true;
        }
        if(!flagp && _persList.at(i).getId() == pID){
            p = _persList.at(i);
            flagp = true;
        }
    }

    if(!flagc)
        return "Computer " + computerID + " Not Found\n";
    if(!flagp)
        return "Person " + personID + " Not Found\n";
    if(exists(Links(c, p)))
        return "Link already exists\n";

    _db.addToConsDB(Links(c, p));
    return "Link added successfully\n";

}
bool LinkService::exists(Links l){
    for(unsigned int i=0; i<_linkList.size(); i++){
        if(l.compare(_linkList.at(i)))
            return true;
    }
    return false;
}
