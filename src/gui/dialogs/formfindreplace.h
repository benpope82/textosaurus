// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef FORMFINDREPLACE_H
#define FORMFINDREPLACE_H

#include <QDialog>

#include "ui_formfindreplace.h"

namespace Ui {
  class FormFindReplace;
}

class TextApplication;

class FormFindReplace : public QDialog {
  Q_OBJECT

  public:
    explicit FormFindReplace(TextApplication* app, QWidget* parent = nullptr);
    virtual ~FormFindReplace();

  public slots:
    void display();

  private slots:
    void searchNext();

  private:
    Ui::FormFindReplace m_ui;
    TextApplication* m_application;
};

#endif // FORMFINDREPLACE_H