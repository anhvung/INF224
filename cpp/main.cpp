//
// main.cpp
// Created on 21/12/2020
//
#include <stdio.h>
#include <iostream>


#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "group.h"
#include "manipulator.h"
#include "tcpserver.h"

using namespace cppu;
using namespace std;

const int PORT = 3331;

int main(int argc, const char* argv[])
{
    std::cout << "Formatting has been changed for the JAVA part, it may display unwanted characters." << std::endl;

    
   #ifdef QUESTIONS_PRECEDENTES
	
    // QUESTION 1,2,3
	Multimedia *multi = new Multimedia("titre", "path");
	multi->showInfos(cout);
    
	// QUESTION 4,5
	int len = 4;
	Multimedia *multiList[len];
	multiList[0] = new Video("video", "video.mp4",0);
	multiList[1] = new Photo("tpt", "7.PNG", 0, 0);
	multiList[2] = new Photo("video", "6.PNG", 0, 0);
	multiList[3] = new Photo("tpt", "5.PNG", 0, 0);
	for(int i = 0; i < len; i++) {
	       multiList[i]->play();
	}
	#endif
	// films

	int chapterDurations[]= {3, 2};
	Film *film = new Film("Titanic", "video.mp4", 5, 2,chapterDurations);
	film->showInfos(cout);
	int newChapterDurations[]= {3, 1, 2};
	film->changeChapters(newChapterDurations,3);
	film->showInfos(cout);
    

	
	

    // Question 10, manipulator manipule et cree les donnees
    shared_ptr<Manipulator> manipulator(new Manipulator());

    // création des objets dans le manager
    shared_ptr<Photo> photo1 = manipulator->newPhoto("photo1", "6.PNG", 50, 50);//une photo
    shared_ptr<Photo> photo2 = manipulator->newPhoto("photo2", "5.PNG", 50, 50);//une photo
    shared_ptr<Photo> photo3 = manipulator->newPhoto("photo3", "7.PNG", 50, 50);//une photo
    shared_ptr<Video> video = manipulator->newVideo("video_name", "video.mp4", 6); // une video
    
    shared_ptr<Group> group = manipulator->newGroup("photosAndVids");//un groupe
    group->push_back(photo1);
    group->push_back(photo2);
    group->push_back(photo3);
    group->push_back(video);
    group->showInfos(cout);
    


     // On demarre le serveur TCP pour que il puisse communiquer avec le programme JAVA
    shared_ptr<TCPServer> server(new TCPServer());
    server->setCallback(*manipulator, &Manipulator::processRequest);
    
    int status = server->run(PORT);
    if (status < 0) {
      cerr << "Error could not start server "  << endl;
      return 1;
    }

	

    return 0;
}