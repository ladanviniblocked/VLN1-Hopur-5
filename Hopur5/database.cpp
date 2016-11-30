#include "database.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
Database::Database(){

}
Database::Database(string dbFile)
{
    vector<string> strstr;
    ifstream fin;
    _dbFile = dbFile;
    fin.open(dbFile);

    if(fin.is_open())
        cout << "success!" << endl;
    else
        cerr << "failed oppening :( " << dbFile << endl;

    char* str = new char[512];
    fin.getline(str, 255);


    while(!fin.eof()){

        strstr.push_back(string(str));
//cout << str << endl;
        fin.getline(str, 255);
    }
    string line = "";
    string name;
    char sex;
    string birth;
    string death;
    string contribution;
    string ty;
    string age;
    for(int i=0; i<strstr.size(); i++){
        line = strstr.at(i);
        while(i<strstr.size() && strstr.at(i) != "#" && strstr.at(i) != "$"){
 //name
            int count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            name = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                name = name + line[count];
                count++;
            }
            //cout <<"name " << i <<" " << name << endl;

//Age
            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            age = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                age = age + line[count];
                count++;
            }
 //Sex
            i++;
            line = strstr.at(i);

            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                sex = line[count];
                count++;
            }
            //cout <<"Sex: " <<i << " " << sex << endl;
//Birth

            i++;
            line = strstr.at(i);
            count = 0;

            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;

            birth ="";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                birth = birth + line[count];

                count++;
            }

            //cout << i << " birthyear: " <<birth << endl;

//death

            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            death = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                death = death + line[count];

                count++;
            }
            //cout << "deathyear: " << death << endl;

//contribution

            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            //cout << "count: " << count << endl;

            contribution = "";

            while(i<strstr.size() && line[count] != '\n' && count < line.size()){
                contribution = contribution + line[count];
                count++;

            }
            //cout <<"contribution: " << contribution << endl;

//turing award year


            i++;
            line = strstr.at(i);
            count = 0;
            while(i<strstr.size() && line[count] != ':' && count < line.size()){
                count ++;
            }
            count++;
            ty = "";
            while(i<strstr.size() && line[count] != '\n' && count < line.size()){

                ty = ty + line[count];

                count++;
            }
            //cout <<"turing year: " <<ty << endl;
            i++;
//            string age = "";
            Person* p = new Person(name, age, sex, birth, death, contribution, ty);
            people.push_back(*p);
        }



    }



}
/*Person Database::getPerson()
{

}
*/
vector<Person> Database::getList()
{
    /*for(int i=0; i<people.size(); i++){
        cout << "----  " << i <<"  ----"<< endl;
        people.at(i).showPerson();
    }*/

  return people;
}
void Database::update(vector<Person> peeps){
    vector<string> names;
    vector<Person> sorted;
    for(int i=0; i<peeps.size(); i++)
        names.push_back(peeps.at(i).getName());

    std::sort(names.begin(), names.end());

    for(int i=0; i<names.size(); i++){
        for(int j=0; j<peeps.size(); j++)
            if(names.at(i) == peeps.at(j).getName())
                sorted.push_back(peeps.at(j));
    }


    people = sorted;
    //writeToDB();
}
void Database::writeToDB(Person p){

    ofstream fout(_dbFile, ios::app);
    //fout.open(_dbFile);
    string name = "Name: ";
    string age = "Age: ";
    string sex = "Sex: ";
    string birth = "BirthYear: ";
    string death = "DeathYear: ";
    string contribution = "Contribution: ";
    string turingYear = "TuringAwardYear: ";
    string end = "#\n";
    string all = "";

        name = name + p.getName() + '\n';
        age = age + p.getAge() + '\n';
        sex = sex + p.getSex() + '\n';
        birth = birth + p.getBirth() + '\n';
        death = death + p.getDeath() + '\n';
        contribution = contribution + p.getContribution() + '\n';
        turingYear = turingYear + p.getTuringYear() + '\n';
        all = all + name + age + sex + birth + death + contribution + turingYear + end;



    fout << all;
    fout.close();
}
bool Database::exists(Person p){

    for(int i=0; i<people.size(); i++)
    {
        //cout << i << " ";
        if(people.at(i) == (p))
            return true;
    }

}
void Database::reWriteDb(){
    ofstream fout(_dbFile);
    //fout.open(_dbFile);
    string name = "Name: ";
    string age = "Age: ";
    string sex = "Sex: ";
    string birth = "BirthYear: ";
    string death = "DeathYear: ";
    string contribution = "Contribution: ";
    string turingYear = "TuringAwardYear: ";
    string end = "#\n";
    string all = "";
    for(int i=0; i<people.size(); i++){
        name = "Name: ";
        name = name + people.at(i).getName() + '\n';
        age = "Age: ";
        age = age + people.at(i).getAge() + '\n';
        sex = "Sex: ";
        sex = sex + people.at(i).getSex() + '\n';
        birth = "BirthYear: ";
        birth = birth + people.at(i).getBirth() + '\n';
        death = "DeathYear: ";
        death = death + people.at(i).getDeath() + '\n';
        contribution = "Contribution: ";
        contribution = contribution + people.at(i).getContribution() + '\n';
        turingYear = "TuringAwardYear: ";
        turingYear = turingYear + people.at(i).getTuringYear() + '\n';
        all = all + name + age + sex + birth + death + contribution + turingYear + end;
    }


    fout << all;
    fout.close();
}
