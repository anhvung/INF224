#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <string>
#include <memory>
#include "multimedia.h"
#include "video.h"
using namespace std;

/**
 * @brief Classe Group : regroupe plusieurs medias
 */

class Group : public list<shared_ptr<Multimedia>>
{
    string name;

public:
    Group() {}
    /**
     * @brief Group
     * @param name
     */
    Group(string name) : name(name) {}
    ~Group() {
       
        for(auto myvar = this->begin(); myvar != this->end(); myvar++) {
          
            myvar->reset();
        }
    }

    /**
     * @brief setName explicite
     */
    void setName(string name) {
        this->name = name;
    }
    /**
     * @brief getName explicite
     */
    string getName() const {
        return name;
    }

    /**
     * @brief printGroup shows name and items in group
     */

    void showInfos(ostream &flux) {
        
        flux << "Group name" << name << endl;

        for(auto it = this->begin(); it != this->end(); it++) {
            (*it)->showInfos(flux);
        }
    }

    
};

#endif // GROUP_H