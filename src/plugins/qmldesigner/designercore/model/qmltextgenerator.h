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

#ifndef QMLTEXTGENERATOR_H
#define QMLTEXTGENERATOR_H

#include <QString>

#include "abstractproperty.h"
#include "modelnode.h"

namespace QmlDesigner {
namespace Internal {

class QmlTextGenerator
{
public:
    explicit QmlTextGenerator(const PropertyNameList &propertyOrder, int indentDepth = 0);

    QString operator()(const AbstractProperty &property) const
    { return toQml(property, m_indentDepth); }

    QString operator()(const ModelNode &modelNode) const
    { return toQml(modelNode, m_indentDepth); }

private:
    QString toQml(const AbstractProperty &property, int indentDepth) const;
    QString toQml(const ModelNode &modelNode, int indentDepth) const;
    QString propertiesToQml(const ModelNode &node, int indentDepth) const;
    QString propertyToQml(const AbstractProperty &property, int indentDepth) const;

    static QString escape(const QString &value);

private:
    PropertyNameList m_propertyOrder;
    int m_indentDepth;
};

} // namespace Internal
} // namespace QmlDesigner

#endif // QMLTEXTGENERATOR_H
