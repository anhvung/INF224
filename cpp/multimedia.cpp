#include "multimedia.h"

Multimedia::Multimedia()
{

}


void Multimedia::showInfos(ostream &flux) const {

    flux << "=============" << "&&n";
    flux << "file type : " << typeName << "&&n";
    flux << "path : " << path << "&&n";
	
}