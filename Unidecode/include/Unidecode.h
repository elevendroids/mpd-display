#ifndef UNIDECODE_H
#define UNIDECODE_H

#include <string>
#include <unicode/translit.h>

/**
 * Simple Unicode -> ASCII transliteration class.
 * libicuuc and libicui18n have to linked with the application.
 */
class Unidecode
{
public:

  /**
   * Class constructor
   */
  Unidecode();

  /**
   * Class destructor
   */
  ~Unidecode();

  /**
   * Transliterates an UTF8 string converting all characters to ASCII
   *
   * @param source - source string
   * @return - transliterated string
   */
  std::string transliterate(const std::string& source);

private:
  UErrorCode m_status;
  Transliterator* m_transliterator;  
};

#endif
