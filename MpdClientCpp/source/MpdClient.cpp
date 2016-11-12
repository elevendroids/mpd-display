#include "MpdClient.h"

#include <mpd/client.h>

namespace Mpd
{

Client::Client():
  m_connection(NULL)
{

}

Client::~Client()
{
  disconnect();
}

bool Client::connect(const std::string& host, unsigned port, unsigned timeout)
{
  if (m_connection != NULL)
  {
    disconnect();
  }

  m_connection = mpd_connection_new(host.c_str(), port, timeout);

  return (m_connection != NULL);
}

void Client::disconnect()
{
  if (m_connection != NULL)
  {
    mpd_connection_free(m_connection);
    m_connection = NULL;
  }
}

Song* Client::getCurrentSong()
{
  Song *result = nullptr;
  mpd_song *song = mpd_run_current_song(m_connection);

  if (song != NULL)
  {
    result = new Song(song);
  }

  return result;
}

bool  Client::getQueue(SongList& queue)
{
  bool result = mpd_send_list_queue_meta(m_connection);

  queue.clear();

  if (result)
  {
    mpd_song *song = mpd_recv_song(m_connection);
    while (song != NULL)
    {
      Song *queue_song = new Song(song);
      queue.push_back(queue_song);
      song = mpd_recv_song(m_connection);
    }
  }

  return result;
}

Song* Client::getQueueSongById(unsigned song_id)
{
  Song *result = nullptr;
  mpd_song *song = mpd_run_get_queue_song_id(m_connection, song_id);

  if (song != NULL)
  {
    result = new Song(song);
  }

  return result;
}

Status* Client::getStatus()
{
  Status *result = nullptr;
  mpd_status *status = mpd_run_status(m_connection);
  if (status != NULL)
  {
    result = new Status(status);
  }

  return result;
}

} /* namespace Mpd */
