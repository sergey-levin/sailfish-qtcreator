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

#ifndef GLSLEDITORPLUGIN_H
#define GLSLEDITORPLUGIN_H

#include <extensionsystem/iplugin.h>
#include <glsl/glsl.h>

namespace GlslEditor {
namespace Internal {

class GlslEditorWidget;

class GlslEditorPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "GLSLEditor.json")

public:
    GlslEditorPlugin();
    ~GlslEditorPlugin();

    // IPlugin
    bool initialize(const QStringList &arguments, QString *errorMessage = 0);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

    struct InitFile
    {
        InitFile(GLSL::Engine *engine = 0, GLSL::TranslationUnitAST *ast = 0)
            : engine(engine), ast(ast)
        {}

        ~InitFile();

        GLSL::Engine *engine;
        GLSL::TranslationUnitAST *ast;
    };

    static const InitFile *fragmentShaderInit(int variant);
    static const InitFile *vertexShaderInit(int variant);
    static const InitFile *shaderInit(int variant);
};

} // namespace Internal
} // namespace GlslEditor

#endif // GLSLEDITORPLUGIN_H
