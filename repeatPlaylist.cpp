#include <stdexcept>
#include <iostream>
#include <set>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }
    
    std::string getName() {
        return name;
    }
    
    Song* getNextSong() {
        return nextSong;
    }

    bool isRepeatingPlaylist()
    {
        std::set <std::string> aPlaylistSet;
        int aPlaylistSize = 0;
        Song * aCurrerntSong = this;
		
        while (aCurrerntSong->getNextSong() != NULL) {
            aPlaylistSet.insert(aCurrerntSong->getName());
            ++aPlaylistSize;
            if (aPlaylistSet.size() < aPlaylistSize) return true;
            aCurrerntSong = aCurrerntSong->getNextSong();
        }
        return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Eye of the tiger");
    Song* second = new Song("Hello");
    Song* third = new Song("Hell");
    Song* last = new Song("Eye of the tiger");
    
    
    first->next(second);
    second->next(third);
    third->next(last)
    last->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif