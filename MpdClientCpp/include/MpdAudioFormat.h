#ifndef _MPD_AUDIO_FORMAT_H_
#define _MPD_AUDIO_FORMAT_H_

#include <cstdint>
#include <mpd/client.h>

namespace Mpd
{

  class AudioFormat
  {
  public:
    AudioFormat(const mpd_audio_format *audio_format):
      m_audio_format(audio_format)
    { }

    uint8_t getBits() const
    {
      return (m_audio_format != NULL) ? m_audio_format->bits : 0;
    }

    uint8_t getChannels() const
    {
      return (m_audio_format != NULL) ? m_audio_format->channels : 0;
    }

    uint32_t getSampleRate() const
    {
      return (m_audio_format != NULL) ? m_audio_format->sample_rate : 0;
    }

  private:
    const mpd_audio_format *m_audio_format;
  };

} /* namespace Mpd */

#endif
