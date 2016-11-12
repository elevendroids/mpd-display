#ifndef _MPD_STATUS_H_
#define _MPD_STATUS_H_

#include <iostream>
#include <string>

#include <mpd/client.h>

#include "MpdAudioFormat.h"

namespace Mpd
{

  enum class State
  {
    Unknown = MPD_STATE_UNKNOWN,
    Stop    = MPD_STATE_STOP,
    Play    = MPD_STATE_PLAY,
    Pause   = MPD_STATE_PAUSE,
  };

  class Status
  {
  public:
    Status(mpd_status *status);

    ~Status();

    const AudioFormat& getAudioFormat() const;
    unsigned getBitrate() const;
    bool getConsume() const;
    unsigned getCrossfade() const;
    unsigned getElapsedTime() const;
    std::string getError() const;
    unsigned getQueueLength() const;
    unsigned getQueueVersion() const;
    bool getRandom() const;
    bool getRepeat() const;
    bool getSingle() const;
    int getSongId() const;
    int getSongPos() const;
    State getState() const;
    unsigned getTotalTime() const;
    unsigned getUpdateId() const;
    int getVolume() const;

  private:
    AudioFormat m_audio_format;
    mpd_status *m_status;
  };

  std::ostream& operator<<(std::ostream& stream, const AudioFormat& audio_format);
  std::ostream& operator<<(std::ostream& stream, const State state);
  std::ostream& operator<<(std::ostream& stream, const Status& status);

} /* namespace Mpd */


#endif
