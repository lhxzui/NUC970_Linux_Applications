/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Assistant of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef BOOKMARKMANAGERWIDGET_H
#define BOOKMARKMANAGERWIDGET_H

#include "ui_bookmarkmanagerwidget.h"

#include <QtCore/QPersistentModelIndex>

#include <QtGui/QMenu>

QT_BEGIN_NAMESPACE

class BookmarkModel;
class QCloseEvent;
class QString;

class BookmarkManagerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BookmarkManagerWidget(BookmarkModel *bookmarkModel,
        QWidget *parent = 0);
    ~BookmarkManagerWidget();

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void setSource(const QUrl &url);
    void setSourceInNewTab(const QUrl &url);

    void managerWidgetAboutToClose();

private:
    void renameItem(const QModelIndex &index);
    void selectNextIndex(bool direction) const;
    bool eventFilter(QObject *object, QEvent *event);

private slots:
    void findNext();
    void findPrevious();

    void importBookmarks();
    void exportBookmarks();

    void refeshBookmarkCache();
    void textChanged(const QString &text);

    void removeItem(const QModelIndex &index = QModelIndex());

    void customContextMenuRequested(const QPoint &point);
    void setSourceFromIndex(const QModelIndex &index, bool newTab = false);

private:
    QMenu importExportMenu;
    Ui::BookmarkManagerWidget ui;
    QList<QPersistentModelIndex> cache;

    BookmarkModel *bookmarkModel;
};

QT_END_NAMESPACE

#endif  // BOOKMARKMANAGERWIDGET_H