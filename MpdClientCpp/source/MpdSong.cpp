#include "MpdSong.h"

namespace Mpd
{

Song::Song(mpd_song *song):
  m_song(song)
{

}

Song::~Song()
{
  mpd_song_free(m_song);
}

std::string Song::getAlbum() const
{
  return getTagValue(MPD_TAG_ALBUM);
}

std::string Song::getArtist() const
{
  return getTagValue(MPD_TAG_ARTIST);
}

std::string Song::getDate() const
{
  return getTagValue(MPD_TAG_DATE);
}

unsigned Song::getDuration() const
{
  return mpd_song_get_duration(m_song);
}

std::string Song::getGenre() const
{
  return getTagValue(MPD_TAG_GENRE);
}

unsigned Song::getId() const
{
  return mpd_song_get_id(m_song);
}

time_t Song::getLastModified() const
{
  return mpd_song_get_last_modified(m_song);
}

unsigned Song::getPos() const
{
  return mpd_song_get_pos(m_song);
}

std::string Song::getTagValue(enum mpd_tag_type tag) const
{
  const char* tag_value = mpd_song_get_tag(m_song, tag, 0);
  return (tag_value != NULL) ? tag_value : "";
}

std::string Song::getTitle() const
{
  return getTagValue(MPD_TAG_TITLE);
}

std::string Song::getTrack() const
{
  return getTagValue(MPD_TAG_TRACK);
}

std::string Song::getUri() const
{
  const char *uri = mpd_song_get_uri(m_song);
  return (uri != NULL) ? uri : "";
}

std::ostream& operator<<(std::ostream& stream, const Song& song)
{
  return stream
    << " Album: " << song.getAlbum() << std::endl
    << " Artist: " << song.getArtist() << std::endl
    << " Date: " << song.getDate() << std::endl
    << " Duration (s): " << song.getDuration() << std::endl
    << " Genre: " << song.getGenre() << std::endl
    << " ID: " << song.getId() << std::endl
    << " Last modified: " << song.getLastModified() << std::endl
    << " Position: " << song.getPos() << std::endl
    << " Title: " << song.getTitle() << std::endl
    << " Track: " << song.getTrack() << std::endl
    << " URI: " << song.getUri() << std::endl
  ;
}

} /* namespace Mpd */

