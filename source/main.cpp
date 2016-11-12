#include <mpd/client.h>

#include <cstdlib>
#include <cstdint>
#include <iostream>

#include "MpdClient.h"

int main()
{
  Mpd::Client client;

  if (client.connect("homesrv.darknet", 6600, 1000))
  {
    Mpd::Status *status = client.getStatus();
    if (status)
    {
      std::cout << "Status:" << std::endl;
      std::cout << *status;
      delete status;
    }

    std::cout << std::endl;

    Mpd::Song *song = client.getCurrentSong();
    if (song)
    {
      std::cout << "Current song:" << std::endl;
      std::cout << *song;
      delete song;
    }

    std::cout << std::endl;

    Mpd::SongList queue;
    if (client.getQueue(queue))
    {
      std::cout << "Queue:" << std::endl;

      for (auto* song: queue)
      {
        std::cout << song->getArtist() << " - " << song->getTitle() << std::endl;
        delete song;
      }
      queue.clear();
    }

    client.disconnect();
  }

  return 0;
}

