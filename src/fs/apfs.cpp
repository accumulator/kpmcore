/*************************************************************************
 *  Copyright (C) 2019 by Andrius Štikonas <stikonas@kde.org>            *
 *                                                                       *
 *  This program is free software; you can redistribute it and/or        *
 *  modify it under the terms of the GNU General Public License as       *
 *  published by the Free Software Foundation; either version 3 of       *
 *  the License, or (at your option) any later version.                  *
 *                                                                       *
 *  This program is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *  GNU General Public License for more details.                         *
 *                                                                       *
 *  You should have received a copy of the GNU General Public License    *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 *************************************************************************/

#include "fs/apfs.h"

namespace FS
{
FileSystem::CommandSupportType apfs::m_Move = FileSystem::cmdSupportCore;
FileSystem::CommandSupportType apfs::m_Copy = FileSystem::cmdSupportCore;
FileSystem::CommandSupportType apfs::m_Backup = FileSystem::cmdSupportCore;

apfs::apfs(qint64 firstsector, qint64 lastsector, qint64 sectorsused, const QString& label) :
    FileSystem(firstsector, lastsector, sectorsused, label, FileSystem::Type::Apfs)
{
}
}
