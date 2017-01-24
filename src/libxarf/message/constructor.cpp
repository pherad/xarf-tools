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

#include <xarf/message.hpp>


using xarf::message;
using mimetic::ContentType;
using mimetic::Field;


/** \brief Constructor.
 *
 * \details The empty constructor creates a new \ref message object with
 *  predefinded default values.
 */
message::message() : MimeEntity()
{
  /* As MultipartMixed can't be used as base class, the headers for multipart
   * messages have to be setup here. */
  ContentType ct("multipart", "mixed");
  ct.paramList().push_back(
      ContentType::Param("boundary", ContentType::Boundary()));
  m_header.contentType(ct);


  /* As described in X-ARF specification v0.2 and in RFC3834, the auto-submitted
   * header will be set to indicate, that this mail was auto-generated. This
   * should be fine for almost any automatic X-ARF generation like fail2ban and
   * similar software. */
  m_header.push_back(Field("Auto-Submitted: auto-generated"));

  /* Set X-XARF header for X-ARF specification v0.2. This class may parse v1.0
   * reports but only emit v2.0. This class will only handle X-XARF: PLAIN, as
   * signing or packing the reports should be done by other components and all
   * types encapsulate the PLAIN report. */
  m_header.push_back(Field("X-XARF: PLAIN"));


  /* Add body parts for X-ARF message. A X-ARF message has (as described in
   * X-ARF specification v0.2) the following parts:
   *  1. Human readable text which contains at least basic information about the
   *     reported incident. It may be accessed via the info method.
   *  2. The actual report, a JSON formated key-value YAML formatted list named
   *     "report.txt".
   *  3. An optional evidence file, like a log file.
   */
  m_body.parts().clear();
  m_body.parts().push_back(new dynamicEntity);
}


/** \brief Constructor for parsing streams.
 *
 * \details This constructor parses the RFC822 conform mail from strem \p is and
 *  evaluates all required values.
 */
message::message(std::istream &is) : MimeEntity(is)
{
}
