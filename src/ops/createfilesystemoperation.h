/*************************************************************************
 *  Copyright (C) 2008 by Volker Lanz <vl@fidra.de>                      *
 *  Copyright (C) 2016 by Andrius Štikonas <andrius@stikonas.eu>         *
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

#if !defined(KPMCORE_CREATEFILESYSTEMOPERATION_H)

#define KPMCORE_CREATEFILESYSTEMOPERATION_H

#include "util/libpartitionmanagerexport.h"

#include "ops/operation.h"

#include "fs/filesystem.h"

#include <QString>

class Partition;
class OperationStack;

class DeleteFileSystemJob;
class CreateFileSystemJob;
class CheckFileSystemJob;

/** Create a FileSystem.

    Creates a FileSystem on a given Partition and Device.

    @author Volker Lanz <vl@fidra.de>
*/
class LIBKPMCORE_EXPORT CreateFileSystemOperation : public Operation
{
    friend class OperationStack;

    Q_DISABLE_COPY(CreateFileSystemOperation)

public:
    CreateFileSystemOperation(Device& d, Partition& p, FileSystem::Type newType);
    ~CreateFileSystemOperation();

public:
    QString iconName() const override {
        return QStringLiteral("draw-eraser");
    }
    QString description() const override;
    void preview() override;
    void undo() override;
    bool execute(Report& parent) override;

    bool targets(const Device& d) const override;
    bool targets(const Partition& p) const override;

protected:
    Device& targetDevice() {
        return m_TargetDevice;
    }
    const Device& targetDevice() const {
        return m_TargetDevice;
    }

    Partition& partition() {
        return m_Partition;
    }
    const Partition& partition() const {
        return m_Partition;
    }

    FileSystem* newFileSystem() const {
        return m_NewFileSystem;
    }
    FileSystem* oldFileSystem() const {
        return m_OldFileSystem;
    }

    DeleteFileSystemJob* deleteJob() {
        return m_DeleteJob;
    }
    CreateFileSystemJob* createJob() {
        return m_CreateJob;
    }
    CheckFileSystemJob* checkJob() {
        return m_CheckJob;
    }

private:
    Device& m_TargetDevice;
    Partition& m_Partition;
    FileSystem* m_NewFileSystem;
    FileSystem* m_OldFileSystem;
    DeleteFileSystemJob* m_DeleteJob;
    CreateFileSystemJob* m_CreateJob;
    CheckFileSystemJob* m_CheckJob;
};

#endif
