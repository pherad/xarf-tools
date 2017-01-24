/* This file is part of X-ARF tools.
 *
 * X-ARF tools is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * X-ARF tools is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see
 *
 *  http://www.gnu.org/licenses/
 *
 *
 * Copyright (c)
 *   2015-2017 Alexander Haase <ahaase@mksec.de>
 */

#include <xarf/dynamicEntity.hpp>

#include <sstream>


using xarf::dynamicEntity;
using mimetic::Base64;
using mimetic::ContentTransferEncoding;
using std::getline;
using std::istringstream;
using std::string;


/** \brief RFC822 recommended line length.
 */
#define RFC822_RECOMMENDED_LINE_LENGTH 78


/** \brief Default constructor.
 */
dynamicEntity::dynamicEntity() : TextPlain("")
{
}


/** \brief Constructor for initialization with value.
 */
dynamicEntity::dynamicEntity(const std::string &text) : TextPlain("")
{
  assign(text);
}


/** \brief Assign \p text to entity body.
 *
 * \details This method assigns the new text \p text to the body of this entity.
 *  If at least one line exceeds the limit of 78 characters, the text will be
 *  converted to Base64 automatically.
 *
 *
 * \param text The text to be assigned.
 */
void
dynamicEntity::assign(const std::string &text)
{
  istringstream iss(text);
  for (string line; getline(iss, line);)
    if (line.length() > RFC822_RECOMMENDED_LINE_LENGTH)
      goto base64;

  /* If all lines are shorter than the RFC822 recommended maximum line length,
   * so the body doesn't need to be converted to base64. */
  m_body.assign(text);
  return;

base64:
  /* A line was longer than the RFC822 recommended maximum line length, so the
   * text has to be converted to base64. */
  Base64::Encoder b64(RFC822_RECOMMENDED_LINE_LENGTH);
  char dest[text.length() * 2];
  encode(text.begin(), text.end(), b64, dest);
  m_body.assign(dest);
  m_header.contentTransferEncoding(ContentTransferEncoding::base64);
}


/** \brief Get content of body.
 *
 * \details This method fetches the body of the message. If the message is
 *  Base64 encoded, the content will be decoded on demand.
 *
 *
 * \return The (encoded) body of the entity.
 */
const std::string
dynamicEntity::fetch() const
{
  /* Check if the body is encoded with base64. If it is, the body has to be
   * decoded first before returning. */
  if (m_header.contentTransferEncoding().str() ==
      ContentTransferEncoding::base64) {
    Base64::Decoder b64;
    char dest[m_body.length()];
    decode(m_body.begin(), m_body.end(), b64, dest);

    return dest;
  }

  /* Otherwise return the body as it is. */
  return m_body;
}
