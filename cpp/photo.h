#ifndef PHOTO_H
#define PHOTO_H

#include "multimedia.h"

using namespace std;

/**
 * @brief This if the photo class.
 */
class Photo : public Multimedia {
protected:
    int lat;
    int longitude;
public:
    Photo(string typeName, string path, int lat,int longitude) :
        Multimedia(typeName, path), lat(lat),longitude(longitude) {

    }
    virtual ~Photo() {}

    /**
     * @brief Show the Name, path and shape
     */
    void showInfos(ostream & f) const override {
        Multimedia::showInfos(f);
        f << "latitude : " << lat << " - ";
        f << "longitude : " << longitude << "&&n"<<"============= &&n";
    }
     /**
     * @brief show photo
     * 
     */
    void play() const override {
        system(("imagej " + this->getPath() + '&').c_str());
    }
   
  
    /**
     * @brief setLat sets the latitude
     * @param lat
     */
    void setLat(int lat) {
        this->lat = lat;
    }

     /**
     * @brief setLongitude sets the longitude
     * @param longitude
     */
    void setLongitude(int longitude) {
        this->longitude = longitude;
    }

    /**
     * @brief getLat returns the latitude
     */
    int getLat() const {
        return lat;
    }
    /**
     * @brief getLongitude returns the longitude
     */
    int getLongitude() const {
        return longitude;
    }
    


};

#endif // PHOTO_H