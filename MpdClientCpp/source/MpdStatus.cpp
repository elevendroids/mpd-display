#include "MpdStatus.h"

namespace Mpd
{

Status::Status(mpd_status *status):
  m_audio_format(mpd_status_get_audio_format(status)),
  m_status(status)
{

}

Status::~Status()
{
  mpd_status_free(m_status);
}

const AudioFormat& Status::getAudioFormat() const
{
  return m_audio_format;
}

unsigned Status::getBitrate() const
{
  return mpd_status_get_kbit_rate(m_status);
}

bool Status::getConsume() const
{
  return mpd_status_get_consume(m_status);
}

unsigned Status::getCrossfade() const
{
  return mpd_status_get_crossfade(m_status);
}

unsigned Status::getElapsedTime() const
{
  return mpd_status_get_elapsed_time(m_status);
}

std::string Status::getError() const
{
  const char *error = mpd_status_get_error(m_status);
  return (error != NULL) ? (error) : ("");
}

unsigned Status::getQueueLength() const
{
  return mpd_status_get_queue_length(m_status);
}

unsigned Status::getQueueVersion() const
{
  return mpd_status_get_queue_version(m_status);
}

bool Status::getRandom() const
{
  return mpd_status_get_random(m_status);
}

bool Status::getRepeat() const
{
  return mpd_status_get_repeat(m_status);
}

bool Status::getSingle() const
{
  return mpd_status_get_single(m_status);
}

int Status::getSongId() const
{
  return mpd_status_get_song_id(m_status);
}

int Status::getSongPos() const
{
  return mpd_status_get_song_pos(m_status);
}

State Status::getState() const
{
  return static_cast<State>(mpd_status_get_state(m_status));
}

unsigned Status::getTotalTime() const
{
  return mpd_status_get_total_time(m_status);
}

unsigned Status::getUpdateId() const
{
  return mpd_status_get_update_id(m_status);
}

int Status::getVolume() const
{
  return mpd_status_get_volume(m_status);
}

std::ostream& operator<<(std::ostream& stream, const AudioFormat& audio_format)
{
    return stream << audio_format.getSampleRate() << ":" << (unsigned)audio_format.getBits() << ":" << (unsigned)audio_format.getChannels();
}

std::ostream& operator<<(std::ostream& stream, const State state)
{
  std::string state_str;

  switch(state)
  {
    case State::Stop:
      state_str = "stop";
      break;
    case State::Play:
      state_str = "play";
      break; 
    case State::Pause:
      state_str = "pause";
      break;
    default:
      state_str = "unknown";
      break;
  }

  return stream << state_str;
}

std::ostream& operator<<(std::ostream& stream, const Status& status)
{
  return stream
    << " Audio format: " << status.getAudioFormat() << std::endl
    << " Bitrate (kbps): " << status.getBitrate() << std::endl
    << " Consume mode: " << status.getConsume() << std::endl
    << " Crossfade: " << status.getCrossfade() << std::endl
    << " Elapsed time (s): " << status.getElapsedTime() << std::endl
    << " Error: " << status.getError() << std::endl
    << " Queue length: " << status.getQueueLength() << std::endl
    << " Queue version: " << status.getQueueVersion() << std::endl
    << " Random: " << status.getRandom() << std::endl
    << " Repeat: " << status.getRepeat() << std::endl
    << " Single: " << status.getSingle() << std::endl
    << " Song ID: " << status.getSongId() << std::endl
    << " Song position: " << status.getSongPos() << std::endl
    << " State: " << status.getState() << std::endl
    << " Total time: " << status.getTotalTime() << std::endl
    << " Update job ID: " << status.getUpdateId() << std::endl
    << " Volume: " << status.getVolume() << std::endl
    ;
}

} /* namespace Mpd */
