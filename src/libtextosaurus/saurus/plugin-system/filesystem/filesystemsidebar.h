// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef FILESYSTEMSIDEBAR_H
#define FILESYSTEMSIDEBAR_H

#include "saurus/gui/sidebars/basesidebar.h"

class BaseTextEdit;
class FilesystemModel;
class FilesystemView;
class FavoritesListWidget;
class QTabWidget;
class QComboBox;
class FilesystemPlugin;

class FilesystemSidebar : public BaseSidebar {
  Q_OBJECT

  public:
    explicit FilesystemSidebar(FilesystemPlugin* plugin, QWidget* parent = nullptr);
    virtual ~FilesystemSidebar() = default;

    virtual Qt::DockWidgetArea initialArea() const override;
    virtual bool initiallyVisible() const override;
    virtual int initialWidth() const override;

  public slots:
    void saveFavorites() const;

  private slots:
    void reloadDrives();
    void openDrive(int index);
    void openFavoriteItem(const QModelIndex& idx);
    void openFileFolder(const QModelIndex& idx);

    void saveCurrentFolder(const QModelIndex& idx);
    void saveCurrentFolder(const QString& path);

    void addToFavorites();

  signals:
    void openFileRequested(const QString& file_path);

  private:
    void makeExplorerVisible() const;
    void makeFavoritesVisible() const;
    virtual void load() override;

  private:
    const QString m_settingsSection = "filesystem";
    FilesystemPlugin* m_plugin;
    BaseTextEdit* m_txtPath;
    QComboBox* m_cmbDrives;
    FilesystemModel* m_fsModel;
    FilesystemView* m_fsView;
    FavoritesListWidget* m_lvFavorites;
    QTabWidget* m_tabWidget;
    QComboBox* m_cmbFilters;
};

#endif // FILESYSTEMSIDEBAR_H
