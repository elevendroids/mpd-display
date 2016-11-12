#ifndef _MPD_CLIENT_H_
#define _MPD_CLIENT_H_

#include <string>
#include <mpd/client.h>

#include "MpdSong.h"
#include "MpdStatus.h"

namespace Mpd
{

  class Client
  {
  public:

    Client();

    ~Client();

    bool connect(const std::string& host, unsigned port, unsigned timeout);

    void disconnect();

    Song* getCurrentSong();
    bool  getQueue(SongList& queue);
    Song* getQueueSongById(unsigned song_id);
    Status* getStatus();

    void play();    
  private:
    mpd_connection *m_connection;
  };

} /* namespace Mpd */

#endif
