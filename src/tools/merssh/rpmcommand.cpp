/****************************************************************************
**
** Copyright (C) 2012 - 2014 Jolla Ltd.
** Contact: http://jolla.com/
**
** This file is part of Qt Creator.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Digia.
**
****************************************************************************/

#include "rpmcommand.h"

#include "merremoteprocess.h"

#include <mer/merconstants.h>

#include <QDir>
#include <QEventLoop>
#include <QFile>
#include <QStringList>

RpmCommand::RpmCommand()
{

}

QString RpmCommand::name() const
{
    return QLatin1String("rpm");
}

int RpmCommand::execute()
{
    const QString projectPathParameter = projectPath().isEmpty() ? QString() : QLatin1String(" -p ") +
    QLatin1String("'") + projectPath() +   QLatin1String("'");
    const QString targetParameter = QLatin1String(" -t ") +  targetName();
    QString command = QLatin1String("mb2") +
                      projectPathParameter +
                      targetParameter +
                      QLatin1Char(' ') + arguments().join(QLatin1String(" ")) + QLatin1Char(' ');
    MerRemoteProcess process;
    process.setSshParameters(sshParameters());
    process.setCommand(remotePathMapping(command));
    return process.executeAndWait();
}

bool RpmCommand::isValid() const
{
    return Command::isValid() && !targetName().isEmpty();
}
