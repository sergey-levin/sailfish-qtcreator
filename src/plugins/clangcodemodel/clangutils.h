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

#ifndef CPPTOOLS_CLANGUTILS_H
#define CPPTOOLS_CLANGUTILS_H

#include <cpptools/projectpart.h>

namespace ClangCodeModel {
namespace Utils {

QStringList createClangOptions(const CppTools::ProjectPart::Ptr &pPart,
                               CppTools::ProjectFile::Kind fileKind);
QStringList createClangOptions(const CppTools::ProjectPart::Ptr &pPart,
                               const QString &fileName = QString());
QStringList createPCHInclusionOptions(const QString &pchFile);

CppTools::ProjectPart::Ptr projectPartForFile(const QString &filePath);
CppTools::ProjectPart::Ptr projectPartForFileBasedOnProcessor(const QString &filePath);
bool isProjectPartLoaded(const CppTools::ProjectPart::Ptr projectPart);
QString projectPartIdForFile(const QString &filePath);

} // namespace Utils
} // namespace Clang

#endif // CPPTOOLS_CLANGUTILS_H
