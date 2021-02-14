#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;
/**
 * @brief The Multimedia class | La classe multimédia de base :'Cette classe de base contiendra ce qui est commun à tous les objets multimédia'
 */
class Multimedia
{
protected:
    
    string typeName;
    string path;
    
public:
    Multimedia();
    Multimedia(string typeName, string path) : typeName(typeName), path(path) {}
	
    virtual ~Multimedia() {}
	
  
	 /// @brief Play the file with system programs
    virtual void play() const{

    }
    /// @brief print file type and path
    virtual void showInfos(ostream & flux) const;
    void setTypeName(string typeName) {
        this->typeName = typeName;
    }
    /// @brief setter of path
    void setPath(string path) {
        this->path = path;
    }
   
	/// @brief getter of file typeName
    string getTypeName() const{
        return typeName;
    }
	/// @brief getter of path
    string getPath() const {
        return path;
    }
	/// @brief setter of file typeName
    

  

};

#endif // MULTIMEDIA_H