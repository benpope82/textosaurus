// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef MAIN_TOOLBAR_H
#define MAIN_TOOLBAR_H

#include "gui/basetoolbar.h"

class ToolBar : public BaseToolBar {
  Q_OBJECT

  public:
    explicit ToolBar(const QString& title, QWidget* parent = nullptr);
    virtual ~ToolBar() = default;

    virtual QList<QAction*> availableActions() const override;
    virtual QList<QAction*> changeableActions() const override;
    virtual void saveChangeableActions(const QStringList& actions) override;
    virtual QList<QAction*> getSpecificActions(const QStringList& actions) override;
    virtual void loadSpecificActions(const QList<QAction*>& actions) override;
    virtual QStringList defaultActions() const override;
    virtual QStringList savedActions() const override;

    void refreshVisualProperties();
};

#endif // MAIN_TOOLBAR_H
