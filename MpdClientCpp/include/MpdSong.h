#ifndef _MPD_SONG_H_
#define _MPD_SONG_H_

#include <ctime>
#include <iostream>
#include <vector>
#include <string>

#include <mpd/client.h>

namespace Mpd
{

  class Song
  {
  public:
    Song(mpd_song *song);
    ~Song();

    std::string getAlbum() const;
    std::string getArtist() const;
    std::string getDate() const;
    unsigned getDuration() const;
    std::string getGenre() const;
    unsigned getId() const;
    time_t getLastModified() const;
    unsigned getPos() const;
    std::string getTitle() const;
    std::string getTrack() const;
    std::string getUri() const;

  private:
    std::string getTagValue(enum mpd_tag_type tag) const;
    
    mpd_song *m_song; 
  };

  using SongList = std::vector<Song*>;

  std::ostream& operator<<(std::ostream& stream, const Song& song);
} /* namespace Mpd */

#endif
