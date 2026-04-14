//=========================================================
//  MusE
//  Linux Music Editor
//    $Id: marker.cpp,v 1.2 2003/12/10 18:34:22 wschweer Exp $
//  (C) Copyright 2000 Werner Schweer (ws@seh.de)
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; version 2 of
//  the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//=========================================================

#include "marker.h"

namespace MusECore {

<<<<<<< HEAD:src/muse/marker/marker.cpp
// Static.
EventID_t Marker::_idGen = 0;
=======
Marker* MarkerList::add(const Marker& marker)
      {
      iMarker i = insert(std::pair<const int, Marker> (marker.tick(), Marker(marker)));
      return &i->second;
      }

Marker* MarkerList::add(const QString& s, int t)
      {
      Marker marker(s);
      marker.setTick(t);
      iMarker i = insert(std::pair<const int, Marker> (t, marker));
      return &i->second;
      }
>>>>>>> origin/audiostreams:muse2/muse/marker/marker.cpp

//---------------------------------------------------------
//   read
//---------------------------------------------------------

void Marker::read(Xml& xml)
      {
      for (;;) {
            Xml::Token token = xml.parse();
            const QString& tag = xml.s1();
            switch (token) {
                  case Xml::Error:
                  case Xml::End:
                        return;
                  case Xml::TagStart:
                        xml.unknown("Marker");
                        break;
                  case Xml::Attribut:
                        if (tag == "tick")
<<<<<<< HEAD:src/muse/marker/marker.cpp
                        {
                              setType(TICKS);
                              setTick(xml.s2().toUInt());
                        }
                        else if (tag == "frame")
                        {
                              setType(FRAMES);
                              setFrame(xml.s2().toUInt());
                        }

                        else if (tag == "lock")  // Obsolete.
                        {
                              setType(xml.s2().toInt() ? FRAMES:TICKS);
                        }
=======
                              setTick(xml.s2().toInt());
                        else if (tag == "lock")
                              printf("WARNING: Marker was set to be locked to the current frame. Ignoring this, as it's no more supported!\n");
>>>>>>> origin/audiostreams:muse2/muse/marker/marker.cpp
                        else if (tag == "name")
                        {
                              _name = xml.s2();
                        }      
                        break;
                  case Xml::TagEnd:
                        if (xml.s1() == "marker")
                              return;
                  default:
                        break;
                  }
            }
      }

//---------------------------------------------------------
//  assign
//   Assigns the members of the given marker to this one, EXCEPT for the ID.
//   Returns this marker.
//---------------------------------------------------------

Marker& Marker::assign(const Marker& m)
{
  setCurrent(m.current());
  setName(m.name());
  setTick(m.tick());
  setType(m.type());
  return *this;
}

//---------------------------------------------------------
//  copy
//   Creates a copy of this marker but with a new ID.
//---------------------------------------------------------

Marker Marker::copy() const
{
  return Marker().assign(*this);
}

Marker* MarkerList::add(const Marker& marker)
      {
      iMarker i = MixedPosList_t::add(Marker(marker));
      return &i->second;
      }

Marker* MarkerList::add(const QString& s, unsigned t, bool lck)
      {
      Marker marker(s);
      marker.setType(lck ? Pos::FRAMES : Pos::TICKS);
      marker.setTick(t);
      iMarker i = MixedPosList_t::add(marker);
      return &i->second;
      }

//---------------------------------------------------------
//   write
//---------------------------------------------------------

void MarkerList::write(int level, Xml& xml) const
      {
      for (ciMarker i = begin(); i != end(); ++i) {
            const Marker& m = i->second;
<<<<<<< HEAD:src/muse/marker/marker.cpp
            if(m.type()==Pos::TICKS)
              xml.put(level, "<marker tick=\"%u\" name=\"%s\" />",
                 m.tick(), Xml::xmlString(m.name()).toUtf8().constData());
            else if(m.type()==Pos::FRAMES)
              xml.put(level, "<marker frame=\"%u\" name=\"%s\" />",
                 m.frame(), Xml::xmlString(m.name()).toUtf8().constData());
=======
            xml.put(level, "<marker tick=\"%d\" lock=\"%d\" name=\"%s\" />",
               m.tick(), false, Xml::xmlString(m.name()).toLatin1().constData());
>>>>>>> origin/audiostreams:muse2/muse/marker/marker.cpp
            }
      }

//---------------------------------------------------------
//   remove
//---------------------------------------------------------

void MarkerList::remove(Marker* m)
      {
      for (iMarker i = begin(); i != end(); ++i) {
            Marker* mm = &i->second;
            if (mm == m) {
                  erase(i);
                  return;
                  }
            }
      fprintf(stderr, "MarkerList::remove(): marker not found\n");
      }

void MarkerList::remove(const Marker& m)
      {
      const QString& s = m.name();
      const EventID_t id = m.id();
      std::pair<iMarker, iMarker> rng = equal_range(m.tick());
      for(iMarker i = rng.first; i != rng.second; ++i) {
            const Marker& mm = i->second;
            if(mm.id() == id && mm.name() == s) {
                  erase(i);
                  return;
                  }
            }
      fprintf(stderr, "MarkerList::remove(): marker not found\n");
      }

iMarker MarkerList::findId(EventID_t id)
{
  for(iMarker i = begin(); i != end(); ++i)
    if(i->second.id() == id)
      return i;
  return end();
}

ciMarker MarkerList::findId(EventID_t id) const
{
  for(ciMarker i = begin(); i != end(); ++i)
    if(i->second.id() == id)
      return i;
  return end();
}

} // namespace MusECore
