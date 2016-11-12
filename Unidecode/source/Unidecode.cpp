#include <Unidecode.h>

Unidecode::Unidecode():
  m_status(U_ZERO_ERROR),
  m_transliterator(Transliterator::createInstance("Any-Latin; Latin-ASCII", UTRANS_FORWARD, m_status))
{

}

Unidecode::~Unidecode()
{
  delete m_transliterator;
}

std::string Unidecode::transliterate(const std::string& source)
{
  UnicodeString u_str = UnicodeString::fromUTF8(source);
  std::string result;

  m_transliterator->transliterate(u_str);

  u_str.toUTF8String(result);
  return result;
}

