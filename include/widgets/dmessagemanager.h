// SPDX-FileCopyrightText: 2022 - 2024 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#ifndef DMESSAGEMANAGER_H
#define DMESSAGEMANAGER_H

#include <DObject>
#include <QWidget>
#include <dtkwidget_global.h>
#include <dtkgui_global.h>

DGUI_BEGIN_NAMESPACE
class DDciIcon;
DGUI_END_NAMESPACE

DWIDGET_BEGIN_NAMESPACE
class DFloatingMessage;
class DMessageManagerPrivate;
class DMessageManager: public QObject, public DCORE_NAMESPACE::DObject
{
    Q_OBJECT
    D_DECLARE_PRIVATE(DMessageManager)

private:
    DMessageManager();                    //构造函数是私有的

public:
    static DMessageManager *instance();

    void sendMessage(QWidget *par, DFloatingMessage *floMsg);
    void sendMessage(QWidget *par, const QIcon &icon, const QString &message);
    void sendMessage(QWidget *par, const DGUI_NAMESPACE::DDciIcon &icon, const QString &message);
    bool setContentMargens(QWidget *par, const QMargins &margins);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

DWIDGET_END_NAMESPACE

#endif // DMESSAGEMANAGER_H
