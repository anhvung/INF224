#include "manipulator.h"


Manipulator::Manipulator()
{

}

void Manipulator::showInfos(string typeName, ostream& f) {
    auto item = searchMultimedia(typeName);
    if(item == nullptr) {
        cerr << typeName  << " does not exist " << endl;
        return;
    }
    item->showInfos(f);
}


void Manipulator::playItem(string typeName) {
    auto item = searchMultimedia(typeName);
    if(item == nullptr) {
         cerr << typeName  << " does not exist " << endl;
        return;
    }
    item->play();
}

string Manipulator::multimediaAll() {
    string result = "";
    for(auto &item: all_multimedias) {
        result += "TITLE : " + item.first + " Path :" +  item.second->getPath() + "&&n"; //&&n is the separator
    }
    return result;
}

shared_ptr<Multimedia> Manipulator::searchMultimedia(string typeName) {
  
    for(auto &item: all_multimedias) {
        if (item.first == typeName){
            
            return item.second;
        }

    }
    return nullptr;
}

shared_ptr<Video> Manipulator::newVideo(string typeName, string path, int duration) {
    shared_ptr<Video> video(new Video(typeName, path, duration));
    all_multimedias[typeName] = video;
    return video;
}

shared_ptr<Photo> Manipulator::newPhoto(string typeName, string path, double latitude, double longitude) {
    shared_ptr<Photo> photo(new Photo(typeName, path, latitude, longitude));
    all_multimedias[typeName] = photo ;
    return photo;
}


shared_ptr<Film> Manipulator::newFilm(string typeName, string path, int duration, int chapterCount, int *chaptersArray) {
    shared_ptr<Film> film(new Film(typeName, path, duration, chapterCount,chaptersArray));
    all_multimedias[typeName] = film;
    return film;
}


shared_ptr<Group> Manipulator::newGroup(string typeName) {
    all_groups[typeName] = shared_ptr<Group>(new Group(typeName));
    return all_groups[typeName];
}



shared_ptr<Group> Manipulator::searchGroup(string typeName) {
    auto item = all_groups.find(typeName);
    if(item == all_groups.end())
        return nullptr;
    else
        return item->second;
}


   

bool Manipulator::processRequest(TCPConnection& cnx, const string& request, string& response) {

    
    stringstream stream, response_stream;
    stream << request;

    string operation, target;
    stream >> operation >> target;

    TCPLock lock(cnx);
                                                                                   
    int code =std::stoi(operation);
    shared_ptr<Multimedia> result =nullptr;

    switch(code) {
  
    case 0: //"FIND"

        result = searchMultimedia(target);
        if(result == nullptr) {
            response =  target + "does not exist";
        }
        else {
            result->showInfos(response_stream);
            response = response_stream.str();
        }

    break;
    case 1://"OPEN"
        result = searchMultimedia(target);
        if(result == nullptr) {
            response =  target + "does not exist";
        }
        else {
            result->play();
            response = "Opening " + target;
        }
    break;
    
    case 2://"SHOW_ALL"
        response = multimediaAll();

    break;
    case 3://EXIT
        response = "Turning the server off";
        return false;

    break;
    default:
        response = "Request not found";
    }//end switch
    return true;
}