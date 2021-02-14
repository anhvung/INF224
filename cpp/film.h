#ifndef FILM_H
#define FILM_H
#include "video.h"

/**
 * @brief classe film qui herite de Video
 */
class Film : public Video
{
protected:
    int chapterCount;
    int *chapters;
public:
     /**
     * @brief Constructeur de la classe Film
     */
   
    Film(string name, string fileName, int duration, int chapterCount, int *chaptersArray)
        : Video(name, fileName, duration)
    {   
        this->chapterCount=chapterCount;
        this->chapters = new int[chapterCount];
        for (int i = 0; i < chapterCount; i++)
        {
            chapters[i] = chaptersArray[i];
        }
    }


    ~Film() {
        delete[] chapters;
    }
    /**
     * @brief showInfos
     * @param flux f
     */
    void showInfos(ostream & f) const override {
      
        Video::showInfos(f);
        for(int i = 0; i < chapterCount; i++) {
            f << "Chapter " << i + 1 << " - duration  " << chapters[i]<<" seconds &&n";
        }
    }

      /**
     * @brief getChapters
     */

    const int* getChapters() const{
        return chapters;
    }

    /**
     * @brief getChapterCount
     */
    int getChapterCount() const {
        return chapterCount;
    }

  
    /**
     * @brief getChapter
     */
    int getChapter(int index) {
        if(index >= chapterCount)
            return -1; // index not valid
        
        return chapters[index];

    }

    /**
     * @brief changeChapters
     */
    void changeChapters(const int *chapters, int chapterCount) {
        this->chapterCount = chapterCount;

        delete[] this->chapters;
        

        this->chapters = new int[chapterCount];

        for(int i = 0; i < chapterCount; i++) {
            this->chapters[i] = chapters[i];
        }

    }
   

};

#endif 