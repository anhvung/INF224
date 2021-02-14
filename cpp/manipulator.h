#ifndef MANIPULATOR_H
#define MANIPULATOR_H


#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "tcpserver.h"

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <memory>
using namespace std;
using namespace cppu;
/**
 * @brief Manipulator manipulates all the multiledia items and process the requests
 */
class Manipulator
{
private:
    map <string, shared_ptr <Multimedia> > all_multimedias;
    map <string, shared_ptr <Group> > all_groups;

public:
    Manipulator();

    bool processRequest(TCPConnection& cnx, const string& request, string& response);

     /**
     * @brief searchMultimedia
     * @param fileName
     * @return
     */

    shared_ptr<Multimedia> searchMultimedia(string typeName);
     /**
     * @brief newVideo same param as for Video
     */
    shared_ptr<Video> newVideo(string typeName, string path, int duration);
    /**
     * @brief newPhoto same param as for Photo
     * @return
     */
    shared_ptr<Photo> newPhoto(string typeName, string path, double latitude, double longitude);
   
    /**
     * @brief newFilm same param as for Flim
     * @return
     */
    shared_ptr<Film> newFilm(string typeName, string path, int duration, int chapterCount, int *chaptersArray);
    /**
     * @brief newGroup same param as for Group
     * @return
     */
    shared_ptr<Group> newGroup(string typeName);

   
    /**
     * @brief searchGroup
     * @param fileName
     * @return
     */
    shared_ptr<Group> searchGroup(string typeName);

     /**
     * @brief playItem
     * @param fileName
     */
    void playItem(string typeName);
    /**
     * @brief multimediaAll
     */
    string multimediaAll();
    /**
     * @brief showInfos
     * @param fileName
     * @param flux
     */
    void showInfos(string typeName, ostream& flux);
   
 

   
    
};

#endif // MANIPULATOR_H