// Copyright 2011 Joe Ranieri.
//
// IP2MIDI is free software: you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the Free Software
// Foundation, either version 2 of the License, or (at your option) any later
// version.
//
// IP2MIDI is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// IP2MIDI. If not, see <http://www.gnu.org/licenses/>.

#pragma once
#import "IP2MIDIDocument.h"

class DatabaseLocker {
public:
	DatabaseLocker(IP2MIDIDocument *document) :
		mDocument([document retain])
	{
		mDatabase = [document acquireDatabase];
	}
	
	~DatabaseLocker()
	{
		[mDocument releaseDatabase];
		[mDocument release];
	}
	
	sqlite3 * Database()
	{
		return mDatabase;
	}

private:
	IP2MIDIDocument *mDocument;
	sqlite3 *mDatabase;
};
