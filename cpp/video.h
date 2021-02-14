#ifndef VIDEO_H
#define VIDEO_H

#include "multimedia.h"

using namespace std;

/**
 * @brief This if the video class.
 */
class Video : public Multimedia {
protected:
    int duration;
public:
    Video(string typeName, string path, int duration) :
        Multimedia(typeName, path), duration(duration) {

    }
    virtual ~Video() {}
     /**
     * @brief show video with mpv
     * 
     */

    void play() const override {
        system(("mpv " + this->getPath() + '&').c_str());
    }

     /**
     * @brief setDuration gives the duration
     * @param duration
     */
    void setDuration(int length_seconds) {
        this->duration = length_seconds;
    }

    /**
     * @brief getDuration returns the duration
     * @return
     */
    int getDuration() const { // const for question 6
        return duration;
    }


    /**
     * @brief showInfos shoes the Nama, path and duration
     */
    void showInfos(ostream & f) const override {
        Multimedia::showInfos(f);
        f << "duration : " << duration << "\n";
    }

  
   
    


};

#endif // VIDEO_H