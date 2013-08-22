/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=========================================================================*/

// Qt includes
#include <QApplication>
#include <QTextStream>
#include <QTimer>

// CTK includes
#include "ctkPythonConsole.h"
#include "ctkAbstractPythonManager.h"


//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{

  QApplication app(argc, argv);

  ctkAbstractPythonManager pythonManager;

  ctkPythonConsole console;
  console.initialize(&pythonManager);
  console.setAttribute(Qt::WA_QuitOnClose, true);
  console.resize(600, 280);
  console.setProperty("isInteractive", true);
  console.show();

  pythonManager.addObjectToPythonMain("_ctkPythonConsoleInstance", &console);

  int exitCode = app.exec();
  return exitCode;
}
