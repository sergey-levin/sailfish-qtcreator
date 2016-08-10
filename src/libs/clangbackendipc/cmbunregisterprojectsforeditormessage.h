/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#ifndef CLANGBACKEND_UNREGISTERPROJECTSFOREDITOR_H
#define CLANGBACKEND_UNREGISTERPROJECTSFOREDITOR_H

#include "clangbackendipc_global.h"

#include <utf8stringvector.h>

namespace ClangBackEnd {

class CMBIPC_EXPORT UnregisterProjectPartsForEditorMessage
{
    friend CMBIPC_EXPORT QDataStream &operator<<(QDataStream &out, const UnregisterProjectPartsForEditorMessage &message);
    friend CMBIPC_EXPORT QDataStream &operator>>(QDataStream &in, UnregisterProjectPartsForEditorMessage &message);
    friend CMBIPC_EXPORT bool operator==(const UnregisterProjectPartsForEditorMessage &first, const UnregisterProjectPartsForEditorMessage &second);
    friend void PrintTo(const UnregisterProjectPartsForEditorMessage &message, ::std::ostream* os);

public:
    UnregisterProjectPartsForEditorMessage() = default;
    UnregisterProjectPartsForEditorMessage(const Utf8StringVector &projectPartIds);

    const Utf8StringVector &projectPartIds() const;

private:
    Utf8StringVector projectPartIds_;
};

CMBIPC_EXPORT QDataStream &operator<<(QDataStream &out, const UnregisterProjectPartsForEditorMessage &message);
CMBIPC_EXPORT QDataStream &operator>>(QDataStream &in, UnregisterProjectPartsForEditorMessage &message);
CMBIPC_EXPORT bool operator==(const UnregisterProjectPartsForEditorMessage &first, const UnregisterProjectPartsForEditorMessage &second);

CMBIPC_EXPORT QDebug operator<<(QDebug debug, const UnregisterProjectPartsForEditorMessage &message);
void PrintTo(const UnregisterProjectPartsForEditorMessage &message, ::std::ostream* os);

DECLARE_MESSAGE(UnregisterProjectPartsForEditorMessage);
} // namespace ClangBackEnd

#endif // CLANGBACKEND_UNREGISTERPROJECTSFOREDITOR_H
